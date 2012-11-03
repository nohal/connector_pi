/******************************************************************************
* $Id: serialconnnection.h,v 1.0 2011/02/26 01:54:37 nohal Exp $
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

#ifndef _SERIALCONNECTION_H_
#define _SERIALCONNECTION_H_

#include "wx/wxprec.h"
#include "wx/ctb/serport.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "connector_pi.h"

#define TIMER_CONN           789
#define CONNECTOR_PI _T("CONNECTOR_PI")

//Forward declarations
class connector_pi;
class ConnectionParams;
class SerialConnection;

//Array type declarations
WX_DEFINE_ARRAY(ConnectionParams *, wxArrayOfConnPrm);
WX_DEFINE_ARRAY(SerialConnection *, wxArrayOfSerialConnection);

//Type definitions
typedef enum 
{
    Serial = 0,
    Network = 1
} ConnectionType;

typedef enum 
{
    TCP = 0,
    UDP = 1,
    GPSD = 2
} NetworkProtocol;

typedef enum 
{
    WHITELIST = 0,
    BLACKLIST = 1
} ListType;

typedef enum
{
    NMEA0183 = 0,
    SEATALK = 2,
    NMEA2000 = 1
} DataProtocol;

typedef enum
{
    PNone = 0,
    Odd = 1,
    Even = 2,
    Mark = 3,
    Space = 4
} ParityType;

typedef enum
{
    CrLf = 0,
    Lf = 1,
    Cr = 2,
    LfCr = 3,
    NoEOS = 4
} EOSType;




//----------------------------------------------------------------------------------------------------------
//    Connection parameters class
//----------------------------------------------------------------------------------------------------------
class ConnectionParams
{
public:
    ConnectionParams();
    ConnectionParams(wxString configStr);

    ConnectionType  Type;
    NetworkProtocol NetProtocol;
    wxString        NetworkAddress;
    int             NetworkPort;

    DataProtocol    Protocol;
    wxString        Port;
    int             Baudrate;
    int             Wordlen;
    ParityType      Parity;
    int             Stopbits;
    bool            RtsCts;
    bool            XonXoff;
    EOSType         EOS;
    bool            ChecksumCheck;
    bool            Output;
    ListType        InputSentenceListType;
    wxArrayString   InputSentenceList;
    ListType        OutputSentenceListType;
    wxArrayString   OutputSentenceList;
    int             Priority;

    wxString        Serialize();
    void            Deserialize(wxString configStr);

    wxString GetSourceTypeStr();
    wxString GetAddressStr();
    wxString GetParametersStr();
    wxString GetOutputValueStr();
    wxString GetFiltersStr();

    bool            Valid;
private:
    wxString FilterTypeToStr(ListType type);
};

//----------------------------------------------------------------------------------------------------------
//    Connection handler class
//----------------------------------------------------------------------------------------------------------
class ConnectionHandler: public wxEvtHandler
{
public:
    ConnectionHandler(connector_pi *plugin) {
        p_plugin = plugin;
        busy = false;
        TimerCon.SetOwner(this, TIMER_CONN);
        StartTimer();
    };
    ~ConnectionHandler() {
        StopTimer();
    };
    void            StartTimer() { TimerCon.Start(100); }
    void            StopTimer() { TimerCon.Stop(); }
    void            CloseAndDestroyAllConnections();
    void            CreateConnections(wxArrayOfConnPrm *configs);
    void            SendNMEAMessage(wxString &message, wxString &source);
    void            DistributeNMEAMessage(wxString &message, wxString &sourcePort);
    void            ReadAllPorts();

private:
    wxArrayOfSerialConnection Connections;
    void            OnTimer(wxTimerEvent& event);

    wxTimer         TimerCon;
    bool            busy;
    connector_pi   *p_plugin;

    DECLARE_EVENT_TABLE()
};


//----------------------------------------------------------------------------------------------------------
//    Serial Port class
//----------------------------------------------------------------------------------------------------------
class SerialConnection
{
protected:
    wxSerialPort    m_dev;
    bool            m_rts;
    bool            m_dtr;
public:
    SerialConnection(ConnectionHandler *handler) {
        m_buffer = wxEmptyString;
        m_pHandler = handler;
    };
    int             OpenDevice( char* dev, void* dcs );
    int             CloseDevice() { return m_dev.Close(); };
    int             IsOpen() { return m_dev.IsOpen(); };
    int             ReadDevice( char* buf, size_t len );
    void            ResetDevice();
    bool            SetBaudrate( wxBaud baudrate );
    void            SetInputMode( int mode );
    int             WriteDevice( char* buf, size_t len );
    void            SetDTR( bool state );
    void            SetRTS( bool state );

    bool            OutputAllowed;
    wxArrayString   OutputFilterList;
    ListType        OutputFilterType;
    wxArrayString   InputFilterList;
    ListType        InputFilterType;
    void            SetEos(wxString eos) { m_EOS = eos; };
	DataProtocol	Protocol ;

    void            SendNMEAMessage(wxString &message, wxString &source);
    virtual void    PushBuffer(const char * b, unsigned int l);
    int             SentenceBoundary();
    wxString        GetPortName() { return m_portName; };
	//GA
	wxString        m_buffer;
	wxString        m_EOS;
	wxString        m_portName;
	bool            FilterInput(wxString &message, wxString &source);
	  ConnectionHandler *m_pHandler;
private:
    bool            FilterOutput(wxString &message, wxString &source);
   
    
  
   
    
   
};

#endif
