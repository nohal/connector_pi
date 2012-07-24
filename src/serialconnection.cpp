/******************************************************************************
* $Id: serialconnection.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
*
* Project:  OpenCPN
* Purpose:  Connector Plugin
* Author:   Pavel Kalian
*
***************************************************************************
*   Copyright (C) 2012 by Pavel Kalian   *
*   $EMAIL$   *
*                                                                         *
*   This program is free software; you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation; either version 2 of the License, or     *
*   (at your option) any later version.                                   *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program; if not, write to the                         *
*   Free Software Foundation, Inc.,                                       *
*   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
***************************************************************************
*/

#include <wx/tokenzr.h>

#include "serialconnection.h"

//ConnectionParams implementation
ConnectionParams::ConnectionParams(wxString configStr)
{
    Deserialize(configStr);
}

void ConnectionParams::Deserialize(wxString configStr)
{
    wxArrayString prms = wxStringTokenize(configStr, _T(";"));
    Protocol = (DataProtocol)wxAtoi(prms[0]);
    Port = prms[1];
    Baudrate = wxAtoi(prms[2]);
    Wordlen = 8 - wxAtoi(prms[3]);
    Parity = (ParityType)wxAtoi(prms[4]);
    Stopbits = wxAtoi(prms[5]);
    RtsCts = !!wxAtoi(prms[6]);
    XonXoff = !!wxAtoi(prms[7]);
    EOS = (EOSType)wxAtoi(prms[8]);
    ChecksumCheck = !!wxAtoi(prms[9]);
    Output = !!wxAtoi(prms[10]);
    InputSentenceListType = (ListType)wxAtoi(prms[11]);
    InputSentenceList = wxStringTokenize(prms[12], _T(","));
    OutputSentenceListType = (ListType)wxAtoi(prms[13]);
    if (prms.Count() > 14) //If the list is empty, the tokenizer does not produce array item
        OutputSentenceList = wxStringTokenize(prms[14], _T(","));
}

wxString ConnectionParams::Serialize()
{
    wxString istcs;
    for(size_t i = 0; i < InputSentenceList.Count(); i++)
    {
        if (i > 0)
            istcs.Append(_T(","));
        istcs.Append(InputSentenceList[i]);
    }
    wxString ostcs;
    for(size_t i = 0; i < OutputSentenceList.Count(); i++)
    {
        if (i > 0)
            ostcs.Append(_T(","));
        ostcs.Append(OutputSentenceList[i]);
    }
    wxString ret = wxString::Format(_T("%d;%s;%d;%d;%d;%d;%d;%d;%d;%d;%d;%d;%s;%d;%s"), Protocol, Port.c_str(), Baudrate, Wordlen, Parity, Stopbits, RtsCts, XonXoff, EOS, ChecksumCheck, Output, InputSentenceListType, istcs.c_str(), OutputSentenceListType, ostcs.c_str());

    return ret;
}

ConnectionParams::ConnectionParams()
{
    Protocol = NMEA0183;
    Port = wxEmptyString;
    Baudrate = 4800;
    Wordlen = 8;
    Parity = None;
    Stopbits = 1;
    RtsCts = false;
    XonXoff = false;
    EOS = CrLf;
    ChecksumCheck = true;
    Output = false;
    InputSentenceListType = WHITELIST;
    OutputSentenceListType = WHITELIST;
}

//ConnectionHandler implementation
void ConnectionHandler::OnTimer(wxTimerEvent& event)
{ 
    if (busy) 
        return; 
    busy = true; 
    wxLogMessage(_T("timer"));
    ReadAllPorts();
    //event.Skip();
    busy = false; 
}

void ConnectionHandler::ReadAllPorts()
{
    for (size_t i = 0; i < Connections.Count(); i++)
    {
        if(Connections[i]->IsOpen()) 
        {
            char b[8192];
            memset(b, 0, sizeof(b));
            // read maximum 80 Bytes, Read never blocks, so we can
            // do it whenever we wanted (you can decrease the timer
            // interval or growup the buffer size, if you have many
            // datas and a high speed
            int n = Connections[i]->ReadDevice(b,sizeof(b));
            if(n > 0) {
                Connections[i]->PushBuffer(wxString::FromAscii(b));
            }
        }
    }
}

void ConnectionHandler::CloseAndDestroyAllConnections()
{
    for (size_t i = 0; i < Connections.Count(); i++)
    {
        Connections[i]->CloseDevice();
    }
    Connections.Clear();
}

void ConnectionHandler::CreateConnections(wxArrayOfConnPrm *configs)
{
    CloseAndDestroyAllConnections();
    for (size_t i = 0; i < configs->Count(); i++)
    {
        Connections.Add(new SerialConnection(this));
        wxCharBuffer buffer = configs->Item(i)->Port.ToUTF8();
        wxSerialPort_DCS portconfig;
        portconfig.baud = (wxBaud)configs->Item(i)->Baudrate;
        portconfig.parity = (wxParity)configs->Item(i)->Parity;
        portconfig.rtscts = configs->Item(i)->RtsCts;
        portconfig.stopbits = configs->Item(i)->Stopbits;
        portconfig.wordlen = configs->Item(i)->Wordlen;
        portconfig.xonxoff = configs->Item(i)->XonXoff;
        Connections[i]->OutputAllowed = configs->Item(i)->Output;
        Connections[i]->OutputFilterList = configs->Item(i)->OutputSentenceList;
        Connections[i]->OutputFilterType = configs->Item(i)->OutputSentenceListType;
        Connections[i]->InputFilterList = configs->Item(i)->InputSentenceList;
        Connections[i]->InputFilterType = configs->Item(i)->InputSentenceListType;
        Connections[i]->SetEos(wxString::FromAscii(EOSVals[configs->Item(i)->EOS]));
        //TODO: Set the other params
        Connections[i]->OpenDevice(buffer.data(), &portconfig);
    }
}

void ConnectionHandler::SendNMEAMessage(wxString &message, wxString &source)
{
    if (source != wxEmptyString && source != CONNECTOR_PI) //Until we get rid of the current core implementation, accepting these causes an event storm
        DistributeNMEAMessage(message, source);
}

void ConnectionHandler::DistributeNMEAMessage(wxString &message, wxString &sourcePort)
{
    for (size_t i = 0; i < Connections.Count(); i++)
    {
        SerialConnection *conn = Connections[i];
        if (sourcePort != conn->GetPortName()) //Not repeat to self
            conn->SendNMEAMessage(message, sourcePort);
    }
    p_plugin->SendSentenceToCore(message.Append(_T("\r\n")));
}

//SerialConnection implementation

int SerialConnection::OpenDevice( char* dev, void* dcs )
{
    int ret = m_dev.Open(dev, dcs);
    m_portName = wxString::FromUTF8(dev);
    return ret;
};

int SerialConnection::ReadDevice( char* buf,size_t len )
{
    int rd = m_dev.Read(buf,len);
    return rd;
};

void SerialConnection::ResetDevice()
{
    if(m_dev.IsOpen())
        m_dev.SendBreak(0);
};

bool SerialConnection::SetBaudrate( wxBaud baudrate )
{
    if(m_dev.IsOpen())
	   return m_dev.SetBaudRate(baudrate) == 0;
    return false;
};

void SerialConnection::SetDTR( bool state ) 
{
    if(!state)
        m_dev.ClrLineState(wxSERIAL_LINESTATE_DTR);
    else 
        m_dev.SetLineState(wxSERIAL_LINESTATE_DTR);
    // windows doesn't allow to query the state of
    // RTS and DTR, so we must notice the state of both
    m_dtr = state;
};

void SerialConnection::SetRTS( bool state )
{
    if(!state)
        m_dev.ClrLineState(wxSERIAL_LINESTATE_RTS);
    else
        m_dev.SetLineState(wxSERIAL_LINESTATE_RTS);
    // windows doesn't allow to query the state of
    // RTS and DTR, so we must notice the state of both
    m_rts = state;
};

int SerialConnection::WriteDevice( char* buf, size_t len )
{
    int rd = m_dev.Write(buf,len);
    return rd;
};

void SerialConnection::SendNMEAMessage(wxString &message, wxString &source)
{
    if (!IsOpen())
        return;
    if (FilterOutput(message, source))
    {
        wxCharBuffer buffer = message.ToAscii();
        WriteDevice( buffer.data(), strlen(buffer.data()) );
        buffer = m_EOS.ToAscii();
        WriteDevice( buffer.data(), strlen(buffer.data()) );
    }
}

bool SerialConnection::FilterOutput(wxString &message, wxString &source)
{
    if (OutputAllowed)
    {
        for (size_t i = 0; i < OutputFilterList.Count(); i++)
            if (OutputFilterList[i] == message.SubString(3,3) || OutputFilterList[i] == message.SubString(1,2) || OutputFilterList[i] == message.SubString(1,5))
                if (OutputFilterType == BLACKLIST)
                    return false;
                else
                    return true;
        if (OutputFilterType == BLACKLIST)
            return true;
        else
            return false;
    }
    return false;
}

bool SerialConnection::FilterInput(wxString &message, wxString &source)
{
    for (size_t i = 0; i < OutputFilterList.Count(); i++)
        if (InputFilterList[i] == message.SubString(3,3) || InputFilterList[i] == message.SubString(1,2) || InputFilterList[i] == message.SubString(1,5))
            if (InputFilterType == BLACKLIST)
                return false;
            else
                return true;
    if (InputFilterType == BLACKLIST)
        return true;
    else
        return false;
}

void SerialConnection::PushBuffer(wxString buf)
{
    m_buffer.Append(buf);
    int boundary = SentenceBoundary();
    while(boundary > -1)
    {
        wxString msg = m_buffer.Left(boundary);
        m_buffer.Remove(0, boundary + m_EOS.Length());
        //TODO: honor the CRC if we should
        m_pHandler->DistributeNMEAMessage(msg, m_portName);
        boundary = SentenceBoundary();
    }
}

int SerialConnection::SentenceBoundary()
{
    if (m_EOS != wxEmptyString)
        return m_buffer.Find(m_EOS);
    //TODO: handle the situation when EOL is not used at all and errors (like we already have 999 chars and still no EOL)...
    return -2;
}