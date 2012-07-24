/******************************************************************************
* $Id: connectorgui_impl.cpp,v 1.0 2012/06/25 01:54:37 nohal Exp $
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

#include "connectorgui_impl.h"

#include <wx/tokenzr.h>
#include <wx/textdlg.h>
#include <wx/progdlg.h>
#include <wx/ctb/serport.h>
#include "enumser.h"

wxString StringArrayToString(wxArrayString arr)
{
    wxString ret = wxEmptyString;
    for (size_t i = 0; i < arr.Count(); i++)
    {
        if (i > 0)
            ret.Append(_T(","));
        ret.Append(arr[i]);
    }
    return ret;
}

//ConnectorCfgDlgImpl::ConnectorCfgDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : ConnectorCfgDlg( parent, id, title, pos, size, style )
ConnectorCfgDlgImpl::ConnectorCfgDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : ConnectorCfgDlg( parent, id, title, pos, size, style )
{
    sourcedlg = new ConnectorSourceDlgImpl(this);
}

ConnectorCfgDlgImpl::~ConnectorCfgDlgImpl()
{
    delete sourcedlg;
}

void ConnectorCfgDlgImpl::LinkToPlugin(connector_pi *plugin)
{
    m_pPlugin = plugin;
    FillSourceList();
}

void ConnectorCfgDlgImpl::FillSourceList()
{
    m_buttonEdit->Enable(false);
    m_buttonRemove->Enable(false);
    m_lbDatasources->Clear();
    for (size_t i = 0; i < m_pPlugin->m_pConnectionParams->Count(); i++)
        m_lbDatasources->Append(m_pPlugin->m_pConnectionParams->Item(i)->Port);
}

ConnectorSourceDlgImpl::ConnectorSourceDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : ConnectorSourceDlg( parent, id, title, pos, size, style ) 
{
    m_stcdialog = new SentenceListDlgImpl(this);
    wxArrayString ports = ScanPorts();
    for(size_t i=0;i<ports.Count();i++) {
	   m_comboPort->Append(ports.Item(i));
    }
}

ConnectorSourceDlgImpl::~ConnectorSourceDlgImpl()
{
    delete m_stcdialog;
    m_stcdialog = NULL;
}

void ConnectorSourceDlgImpl::SetConnectionParams(ConnectionParams *cp)
{
    m_pConnectionParams = cp;
    m_comboPort->Select(m_comboPort->FindString(cp->Port));
    m_cbCheckCRC->SetValue(cp->ChecksumCheck);
    m_cbOutput->SetValue(cp->Output);
    if(cp->InputSentenceListType == WHITELIST)
        m_rbIAccept->SetValue(true);
    else
        m_rbIIgnore->SetValue(true);
    if(cp->OutputSentenceListType == WHITELIST)
        m_rbOAccept->SetValue(true);
    else
        m_rbOIgnore->SetValue(true);
    m_tcInputStc->SetValue(StringArrayToString(cp->InputSentenceList));
    m_tcOutputStc->SetValue(StringArrayToString(cp->OutputSentenceList));
    m_choiceBaudRate->Select(cp->Baudrate); //TODO
    m_choiceSerialProtocol->Select(cp->Protocol); //TODO
    m_choiceDataBits->Select(cp->Wordlen - 8);
    m_choiceParity->Select(cp->Parity);
    m_choiceStopBits->Select(cp->Stopbits - 1);
    m_cbRtsCts->SetValue(cp->RtsCts);
    m_cbXonXoff->SetValue(cp->XonXoff);
    m_choiceEOS->Select(cp->EOS);
}



void ConnectorCfgDlgImpl::OnSelectDatasource( wxCommandEvent& event )
{
    m_buttonEdit->Enable();
    m_buttonRemove->Enable();
}

void ConnectorCfgDlgImpl::OnAddClick( wxCommandEvent& event )
{
    ConnectionParams *cp = new ConnectionParams();
    sourcedlg->SetConnectionParams(cp);
    if (sourcedlg->ShowModal() == wxID_OK)
        m_pPlugin->m_pConnectionParams->Add(cp);
    FillSourceList();
}

void ConnectorCfgDlgImpl::OnEditClick( wxCommandEvent& event )
{
    sourcedlg->SetConnectionParams(m_pPlugin->m_pConnectionParams->Item(m_lbDatasources->GetSelection()));
    sourcedlg->ShowModal();
    FillSourceList();
}

void ConnectorCfgDlgImpl::OnRemoveClick( wxCommandEvent& event )
{
    m_pPlugin->m_pConnectionParams->RemoveAt(m_lbDatasources->GetSelection());
    FillSourceList();
}

void ConnectorSourceDlgImpl::OnOkClick( wxCommandEvent& event )
{
    if (m_comboPort->GetStringSelection() == wxEmptyString)
    {
        wxMessageBox(_("You must select or enter the port..."), _("Error!"));
        return;
    }
    m_pConnectionParams->Baudrate = wxAtoi(m_choiceBaudRate->GetStringSelection());
    m_pConnectionParams->ChecksumCheck = m_cbCheckCRC->GetValue();
    m_pConnectionParams->InputSentenceList = wxStringTokenize(m_tcInputStc->GetValue());
    if (m_rbIAccept->GetValue())
        m_pConnectionParams->InputSentenceListType = WHITELIST;
    else
        m_pConnectionParams->InputSentenceListType = BLACKLIST;
    m_pConnectionParams->Output = m_cbOutput->GetValue();
    m_pConnectionParams->OutputSentenceList = wxStringTokenize(m_tcOutputStc->GetValue());
    if (m_rbOAccept->GetValue())
        m_pConnectionParams->OutputSentenceListType = WHITELIST;
    else
        m_pConnectionParams->OutputSentenceListType = BLACKLIST;
    m_pConnectionParams->Port = m_comboPort->GetStringSelection();
    m_pConnectionParams->Protocol = NMEA0183;
    m_pConnectionParams->Wordlen = m_choiceDataBits->GetSelection();
    m_pConnectionParams->Parity = (ParityType)m_choiceParity->GetSelection();
    m_pConnectionParams->Stopbits = m_choiceStopBits->GetSelection() + 1;
    m_pConnectionParams->RtsCts = m_cbRtsCts->GetValue();
    m_pConnectionParams->XonXoff = m_cbXonXoff->GetValue();
    m_pConnectionParams->EOS = (EOSType)m_choiceEOS->GetSelection();
    event.Skip();
}

void ConnectorSourceDlgImpl::OnBtnIStcs( wxCommandEvent& event )
{
    m_stcdialog->SetSentenceList(wxStringTokenize(m_tcInputStc->GetValue(), _T(",")));
    if (m_stcdialog->ShowModal() == wxID_OK)
        m_tcInputStc->SetValue(m_stcdialog->GetSentencesAsText());
}

void ConnectorSourceDlgImpl::OnBtnOStcs( wxCommandEvent& event )
{
    m_stcdialog->SetSentenceList(wxStringTokenize(m_tcOutputStc->GetValue(), _T(",")));
    if (m_stcdialog->ShowModal() == wxID_OK)
        m_tcOutputStc->SetValue(m_stcdialog->GetSentencesAsText());
}

SentenceListDlgImpl::SentenceListDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : SentenceListDlg( parent, id, title, pos, size, style )
{
}

SentenceListDlgImpl::~SentenceListDlgImpl()
{
}

void SentenceListDlgImpl::SetSentenceList(wxArrayString sentences)
{
    m_sentences = sentences;
    FillSentences();
}

wxString SentenceListDlgImpl::GetSentencesAsText()
{
    return StringArrayToString(m_sentences);
}

void SentenceListDlgImpl::FillSentences()
{
    m_lbSentences->Clear();
    for (size_t i = 0; i < m_sentences.Count(); i++)
        m_lbSentences->Append(m_sentences[i]);
    m_btnDel->Enable(false);
    if (m_sentences.Count() == 0)
        m_btnDelAll->Enable(false);
    else
        m_btnDelAll->Enable();
}

void SentenceListDlgImpl::OnStcSelect( wxCommandEvent& event )
{
    m_btnDel->Enable();
}

void SentenceListDlgImpl::OnAddClick( wxCommandEvent& event )
{
    wxString stc = wxGetTextFromUser(_("Enter the NMEA sentence (2, 3 or 5 characters)"), _("Enter the NMEA sentence"));
    if (stc.Length() == 2 ||stc.Length() == 3 || stc.Length() == 5)
    {
        m_sentences.Add(stc);
        m_lbSentences->Append(stc);
        m_btnDelAll->Enable();
    }
    else
        wxMessageBox(_("A NMEA sentence is actually 3 characters long (like RMC, GGA etc.) It can also have a two letter prefix identifying the source of the message (The whole sentences then looks like GPGGA or AITXT). You can also filter out all the sentences with certain prefix (like GP, AI etc.). The filter accepts just these three formats. No wildcard characters are used (Don't enter any *s anywhere.)"), _("Wrong length of the NMEA filter value"));
}

void SentenceListDlgImpl::OnDeleteClick( wxCommandEvent& event )
{
    m_sentences.RemoveAt(m_lbSentences->GetSelection());
    FillSentences();
}

void SentenceListDlgImpl::OnDeleteAllClick( wxCommandEvent& event )
{
    m_sentences.Clear();
    m_lbSentences->Clear();
    m_btnDel->Enable(false);
    m_btnDelAll->Enable(false);
}
void SentenceListDlgImpl::OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
void SentenceListDlgImpl::OnOkClick( wxCommandEvent& event ) { event.Skip(); }

wxArrayString ConnectorSourceDlgImpl::ScanPorts()
{
    const char* ports[] = {
        wxCOM1,wxCOM2,wxCOM3,wxCOM4,wxCOM5,wxCOM6,wxCOM7,wxCOM8,wxCOM9,wxCOM10,wxCOM11,wxCOM12,wxCOM13,wxCOM14,wxCOM15,wxCOM16,wxCOM17,wxCOM18,wxCOM19,wxCOM20,wxCOM21,wxCOM22,wxCOM23,wxCOM24,wxCOM25,wxCOM26,wxCOM27,wxCOM28,wxCOM29,wxCOM30,wxCOM31,wxCOM32,
#if defined(__WIN32__)
        wxCOM33,wxCOM34,wxCOM35,wxCOM36,wxCOM37,wxCOM38,wxCOM39,wxCOM40,wxCOM41,wxCOM42,wxCOM43,wxCOM44,wxCOM45,wxCOM46,wxCOM48,wxCOM49,wxCOM50,wxCOM51,wxCOM52,wxCOM53,wxCOM54,wxCOM55,wxCOM56,wxCOM57,wxCOM58,wxCOM59,wxCOM60,wxCOM61,wxCOM62,wxCOM63,wxCOM64,wxCOM65,wxCOM66,wxCOM67,wxCOM68,wxCOM69,
#else
        "/dev/ttyUSB0","/dev/ttyUSB1","/dev/ttyUSB2","/dev/ttyUSB3","/dev/ttyUSB4","/dev/ttyUSB5","/dev/ttyUSB6","/dev/ttyUSB7","/dev/ttyUSB8","/dev/ttyUSB9"
#endif
    };

    wxProgressDialog progress( _("Please wait"), _("Search for new serial ports..."), sizeof( ports ) >> 2 );

    wxArrayString result;

    wxSerialPort com;

#if defined (__WIN32__)
    CSimpleArray<UINT> detectedports;
    CEnumerateSerial::UsingGetDefaultCommConfig(detectedports);
#endif

    for(int i=0; i < ( sizeof( ports ) >> 2 ); i++, progress.Update( i ) ) {
#if !defined (__WIN32__)
        if(com.Open(ports[i]) < 0) {
            continue;
        }
        result.Add(wxString::FromUTF8(ports[i]));
        com.Close();
#else
        if (-1 != detectedports.Find(i+1))
            result.Add(wxString::FromUTF8(ports[i]));
        /*
        //size_t alloc_len = strlen(ports[i]) + 1;
        //wchar_t* szComPort = new wchar_t[alloc_len];
        //size_t res = mbstowcs(szComPort, ports[i], alloc_len);

        TCHAR szDevices[65535];
        wchar_t* p = new wchar_t[6];
        wsprintf(p, L"COM%i", i);
        unsigned long dwChars = QueryDosDevice(p, szDevices, 65535);
        TCHAR *ptr = szDevices;

        if (dwChars > 0)
            result.Add(wxString::FromUTF8(ports[i-1])); //TODO: Perhaps filter out what can't be a data source (Like BthModem in HKEY_LOCAL_MACHINE\HARDWARE\DEVICEMAP\SERIALCOMM)
        */
#endif
    }
    return result;
}