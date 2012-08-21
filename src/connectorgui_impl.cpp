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
#if defined(__WIN32__)
#include "enumser.h"
#endif

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

void ConnectorSourceDlgImpl::LinkToPlugin(connector_pi *plugin)
{
    m_pPlugin = plugin;
    FillSourceList();
}

void ConnectorSourceDlgImpl::FillSourceList()
{
    m_buttonRemove->Enable(false);
    m_lcSources->DeleteAllItems();
    for (size_t i = 0; i < m_pPlugin->m_pConnectionParams->Count(); i++)
    {
        long itemIndex = m_lcSources->InsertItem(i, m_pPlugin->m_pConnectionParams->Item(i)->GetSourceTypeStr());
        m_lcSources->SetItem(itemIndex, 1, m_pPlugin->m_pConnectionParams->Item(i)->GetAddressStr());
        m_lcSources->SetItem(itemIndex, 2, m_pPlugin->m_pConnectionParams->Item(i)->GetParametersStr());
        m_lcSources->SetItem(itemIndex, 3, m_pPlugin->m_pConnectionParams->Item(i)->GetOutputValueStr());
        m_lcSources->SetItem(itemIndex, 4, m_pPlugin->m_pConnectionParams->Item(i)->GetFiltersStr());
    }

    m_lcSources->SetColumnWidth( 0, wxLIST_AUTOSIZE );
    m_lcSources->SetColumnWidth( 1, wxLIST_AUTOSIZE );
    m_lcSources->SetColumnWidth( 2, wxLIST_AUTOSIZE );
    m_lcSources->SetColumnWidth( 3, wxLIST_AUTOSIZE );
    m_lcSources->SetColumnWidth( 4, wxLIST_AUTOSIZE );
}

ConnectorSourceDlgImpl::ConnectorSourceDlgImpl( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : ConnectorSourceDlg( parent, id, title, pos, size, style ) 
{
    wxListItem col0;
    col0.SetId(0);
    col0.SetText( _("Type") );
    m_lcSources->InsertColumn(0, col0);

    wxListItem col1;
    col1.SetId(1);
    col1.SetText( _("Source") );
    m_lcSources->InsertColumn(1, col1);

    wxListItem col2;
    col2.SetId(2);
    col2.SetText( _("Parameters") );
    m_lcSources->InsertColumn(2, col2);

    wxListItem col3;
    col3.SetId(3);
    col3.SetText( _("Output") );
    m_lcSources->InsertColumn(3, col3);

    wxListItem col4;
    col4.SetId(4);
    col4.SetText( _("Filters") );
    m_lcSources->InsertColumn(4, col4);

    m_lcSources->Refresh();

    m_stcdialog = new SentenceListDlgImpl(this);
    wxArrayString ports = ScanPorts();
    for(size_t i=0;i<ports.Count();i++) {
	   m_comboPort->Append(ports.Item(i));
    }
    ShowCommon( false );
    ShowSerial( false );
    ShowNet( false );
    m_sdbSizerDlgButtonsApply->Disable();
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
    m_choiceBaudRate->Select(m_choiceBaudRate->FindString(wxString::Format(_T("%d"),cp->Baudrate)));
    m_choiceSerialProtocol->Select(cp->Protocol); //TODO
    m_choiceDataBits->Select(cp->Wordlen - 8);
    m_choiceParity->Select(cp->Parity);
    m_choiceStopBits->Select(cp->Stopbits - 1);
    m_cbRtsCts->SetValue(cp->RtsCts);
    m_cbXonXoff->SetValue(cp->XonXoff);
    m_choiceEOS->Select(cp->EOS);

    m_tNetAddress->SetValue(cp->NetworkAddress);
    m_tNetPort->SetValue(wxString::Format(wxT("%i"), cp->NetworkPort));
    if(cp->NetProtocol == TCP)
        m_rbNetProtoTCP->SetValue(true);
    else if (cp->NetProtocol == UDP)
        m_rbNetProtoUDP->SetValue(true);
    else
        m_rbNetProtoGPSD->SetValue(true);

    if ( cp->Type == Serial )
    {
        m_rbTypeSerial->SetValue( true );
        SetFormToSerial();
    }
    else
    {
        m_rbTypeNet->SetValue( true );
        SetFormToNet();
    }
}


void ConnectorSourceDlgImpl::OnSelectDatasource( wxListEvent& event )
{
    SetConnectionParams(m_pPlugin->m_pConnectionParams->Item(event.GetIndex()));
    m_buttonRemove->Enable();
    m_sdbSizerDlgButtonsApply->Enable();
    event.Skip();
}

void ConnectorSourceDlgImpl::OnAddClick( wxCommandEvent& event )
{
    ConnectionParams *cp = new ConnectionParams();
    SetConnectionParams( cp );
    SetFormToSerial();
    params_saved = false;

    long itemIndex = -1;
    for ( ;; ) 
    {
        itemIndex = m_lcSources->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 )
            break;
        m_lcSources->SetItemState( itemIndex, 0, wxLIST_STATE_SELECTED|wxLIST_STATE_FOCUSED );
    }
    m_sdbSizerDlgButtonsApply->Enable();
    m_buttonRemove->Enable( false );
}

void ConnectorSourceDlgImpl::OnRemoveClick( wxCommandEvent& event )
{
    long itemIndex = -1;
    for ( ;; ) 
    {
        itemIndex = m_lcSources->GetNextItem( itemIndex, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
        if ( itemIndex == -1 )
            break;
        m_pPlugin->m_pConnectionParams->RemoveAt( itemIndex );
    }
    FillSourceList();
    m_sdbSizerDlgButtonsApply->Enable( false );
    ShowCommon( false );
    ShowNet( false );
    ShowSerial( false );
}

bool ConnectorSourceDlgImpl::SaveConnectionParams()
{
    //TODO: The error handling is still way too naive... Same for input validation.
    if ( m_rbTypeSerial->GetValue() && m_comboPort->GetStringSelection() == wxEmptyString )
    {
        wxMessageBox( _("You must select or enter the port..."), _("Error!") );
        return false;
    }
    else if ( m_rbTypeNet->GetValue() && m_tNetAddress->GetValue() == wxEmptyString )
    {
        wxMessageBox( _("You must enter the address..."), _("Error!") );
        return false;
    }
    
    m_pConnectionParams->Valid = true;
    if ( m_rbTypeSerial->GetValue() )
        m_pConnectionParams->Type = Serial;
    else
        m_pConnectionParams->Type = Network;
    m_pConnectionParams->NetworkAddress = m_tNetAddress->GetValue();
    m_pConnectionParams->NetworkPort = wxAtoi(m_tNetPort->GetValue());
    if ( m_rbNetProtoTCP->GetValue() )
        m_pConnectionParams->NetProtocol = TCP;
    else if ( m_rbNetProtoUDP->GetValue() )
        m_pConnectionParams->NetProtocol = UDP;
    else
        m_pConnectionParams->NetProtocol = GPSD;

    m_pConnectionParams->Baudrate = wxAtoi( m_choiceBaudRate->GetStringSelection() );
    m_pConnectionParams->ChecksumCheck = m_cbCheckCRC->GetValue();
    m_pConnectionParams->InputSentenceList = wxStringTokenize( m_tcInputStc->GetValue() );
    if ( m_rbIAccept->GetValue() )
        m_pConnectionParams->InputSentenceListType = WHITELIST;
    else
        m_pConnectionParams->InputSentenceListType = BLACKLIST;
    m_pConnectionParams->Output = m_cbOutput->GetValue();
    m_pConnectionParams->OutputSentenceList = wxStringTokenize( m_tcOutputStc->GetValue() );
    if ( m_rbOAccept->GetValue() )
        m_pConnectionParams->OutputSentenceListType = WHITELIST;
    else
        m_pConnectionParams->OutputSentenceListType = BLACKLIST;
    m_pConnectionParams->Port = m_comboPort->GetStringSelection();
    m_pConnectionParams->Protocol = NMEA0183;
    m_pConnectionParams->Wordlen = wxAtoi(m_choiceDataBits->GetStringSelection());
    m_pConnectionParams->Parity = (ParityType)m_choiceParity->GetSelection();
    m_pConnectionParams->Stopbits = m_choiceStopBits->GetSelection() + 1;
    m_pConnectionParams->RtsCts = m_cbRtsCts->GetValue();
    m_pConnectionParams->XonXoff = m_cbXonXoff->GetValue();
    m_pConnectionParams->EOS = (EOSType)m_choiceEOS->GetSelection();
    return true;
}

void ConnectorSourceDlgImpl::OnOkClick( wxCommandEvent& event )
{
    if(SaveConnectionParams() && !params_saved)
    {
        m_pPlugin->m_pConnectionParams->Add(m_pConnectionParams);
        params_saved = true;
    }
    event.Skip();
}

void ConnectorSourceDlgImpl::OnApplyClick( wxCommandEvent& event )
{
    long itemIndex = m_lcSources->GetNextItem( -1, wxLIST_NEXT_ALL, wxLIST_STATE_SELECTED );
    if(SaveConnectionParams() && !params_saved)
    {
        m_pPlugin->m_pConnectionParams->Add(m_pConnectionParams);
        params_saved = true;
        itemIndex = m_pPlugin->m_pConnectionParams->Count() - 1;
    }
    FillSourceList();
    m_lcSources->SetItemState(itemIndex, wxLIST_STATE_SELECTED, wxLIST_STATE_SELECTED);
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

void ConnectorSourceDlgImpl::ShowCommon(bool visible)
{
    if ( visible )
    {
        m_rbTypeSerial->Show();
        m_rbTypeNet->Show();
        m_rbIAccept->Show();
        m_rbIIgnore->Show();
        m_rbOAccept->Show();
        m_rbOIgnore->Show();
        m_tcInputStc->Show();
        m_btnInputStcList->Show();
        m_tcOutputStc->Show();
        m_btnOutputStcList->Show();
        m_cbOutput->Show();
        m_choicePriority->Show();
        m_stPriority->Show();
    }
    else
    {
        m_rbTypeSerial->Hide();
        m_rbTypeNet->Hide();
        m_rbIAccept->Hide();
        m_rbIIgnore->Hide();
        m_rbOAccept->Hide();
        m_rbOIgnore->Hide();
        m_tcInputStc->Hide();
        m_btnInputStcList->Hide();
        m_tcOutputStc->Hide();
        m_btnOutputStcList->Hide();
        m_cbOutput->Hide();
        m_choicePriority->Hide();
        m_stPriority->Hide();
    }
}

void ConnectorSourceDlgImpl::ShowNet(bool visible)
{
    if ( visible )
    {
        m_stNetAddr->Show();
        m_tNetAddress->Show();
        m_stNetPort->Show();
        m_tNetPort->Show();
        m_stNetProto->Show();
        m_rbNetProtoGPSD->Show();
        m_rbNetProtoTCP->Show();
        m_rbNetProtoUDP->Show();
    }
    else
    {
        m_stNetAddr->Hide();
        m_tNetAddress->Hide();
        m_stNetPort->Hide();
        m_tNetPort->Hide();
        m_stNetProto->Hide();
        m_rbNetProtoGPSD->Hide();
        m_rbNetProtoTCP->Hide();
        m_rbNetProtoUDP->Hide();
    }
}

void ConnectorSourceDlgImpl::ShowSerial(bool visible)
{
    if ( visible )
    {
        m_stSerBaudrate->Show();
        m_choiceBaudRate->Show();
        m_stSerDatabits->Show();
        m_choiceDataBits->Show();
        m_stSerEos->Show();
        m_choiceEOS->Show();
        m_stSerParity->Show();
        m_choiceParity->Show();
        m_stSerPort->Show();
        m_comboPort->Show();
        m_stSerProtocol->Show();
        m_choiceSerialProtocol->Show();
        m_stSerStopbits->Show();
        m_choiceStopBits->Show();
        m_cbCheckCRC->Show();
        m_cbRtsCts->Show();
        m_cbXonXoff->Show();
        gSizerNetProps->SetDimension(0,0,0,0);
    }
    else
    {
        m_stSerBaudrate->Hide();
        m_choiceBaudRate->Hide();
        m_stSerDatabits->Hide();
        m_choiceDataBits->Hide();
        m_stSerEos->Hide();
        m_choiceEOS->Hide();
        m_stSerParity->Hide();
        m_choiceParity->Hide();
        m_stSerPort->Hide();
        m_comboPort->Hide();
        m_stSerProtocol->Hide();
        m_choiceSerialProtocol->Hide();
        m_stSerStopbits->Hide();
        m_choiceStopBits->Hide();
        m_cbCheckCRC->Hide();
        m_cbRtsCts->Hide();
        m_cbXonXoff->Hide();
        gSizerSerProps->SetDimension(0,0,0,0);
    }
}

void ConnectorSourceDlgImpl::SetFormToSerial()
{
    ShowCommon( true );
    ShowNet( false );
    ShowSerial( true );
    this->Layout();
    this->Refresh();
}

void ConnectorSourceDlgImpl::SetFormToNet()
{
    ShowCommon( true );
    ShowNet( true );
    ShowSerial( false );
    this->Layout();
    this->Refresh();
}

void ConnectorSourceDlgImpl::OnTypeSerialSelected( wxCommandEvent& event )
{
    SetFormToSerial();
}

void ConnectorSourceDlgImpl::OnTypeNetSelected( wxCommandEvent& event )
{
    SetFormToNet();
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
#endif
    }
    return result;
}
