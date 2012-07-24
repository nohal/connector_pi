/******************************************************************************
* $Id: connectorgui_impl.h,v 1.0 2012/06/25 01:54:37 nohal Exp $
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

#ifndef _OpenCPNCONNECTORGUI_IMPL_H_
#define _OpenCPNCONNECTORGUI_IMPL_H_

#include "connectorgui.h"
#include "connector_pi.h"

//Forward declarations
class connector_pi;
class ConnectionParams;
class ConnectorSourceDlgImpl;
class SentenceListDlgImpl;

class ConnectorCfgDlgImpl : public ConnectorCfgDlg
{
public:
    ConnectorCfgDlgImpl( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connector Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,450 ), long style = wxDEFAULT_DIALOG_STYLE ); 
    ~ConnectorCfgDlgImpl();
    connector_pi *m_pPlugin;
    void LinkToPlugin(connector_pi *plugin);
protected:
    void OnSelectDatasource( wxCommandEvent& event );
    void OnAddClick( wxCommandEvent& event );
    void OnEditClick( wxCommandEvent& event );
    void OnRemoveClick( wxCommandEvent& event );
    void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
    void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
private:
    ConnectorSourceDlgImpl *sourcedlg;
    void FillSourceList();
};

class ConnectorSourceDlgImpl : public ConnectorSourceDlg 
{
public:
    ConnectorSourceDlgImpl( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data source properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,480 ), long style = wxDEFAULT_DIALOG_STYLE ); 
    ~ConnectorSourceDlgImpl();
    void SetConnectionParams(ConnectionParams *cp);
protected:
    void OnComSelected( wxCommandEvent& event ) { event.Skip(); }
    void OnNetSelected( wxCommandEvent& event ) { event.Skip(); }
    void OnPortChoice( wxCommandEvent& event ) { event.Skip(); }
    void OnBaudrateChoice( wxCommandEvent& event ) { event.Skip(); }
    void OnProtocolChoice( wxCommandEvent& event ) { event.Skip(); }
    void OnCrcCheck( wxCommandEvent& event ) { event.Skip(); }
    void OnRbInput( wxCommandEvent& event ) { event.Skip(); }
    void OnBtnIStcs( wxCommandEvent& event );
    void OnCbOutput( wxCommandEvent& event ) { event.Skip(); }
    void OnRbOutput( wxCommandEvent& event ){ event.Skip(); }
    void OnBtnOStcs( wxCommandEvent& event );
    void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
    void OnOkClick( wxCommandEvent& event );
private:
    ConnectionParams *m_pConnectionParams;
    SentenceListDlgImpl *m_stcdialog;
    wxArrayString ScanPorts();
};

class SentenceListDlgImpl : public SentenceListDlg 
{
private:
    wxArrayString m_sentences;
    void FillSentences();
protected:
    void OnStcSelect( wxCommandEvent& event );
    void OnAddClick( wxCommandEvent& event );
    void OnDeleteClick( wxCommandEvent& event );
    void OnDeleteAllClick( wxCommandEvent& event );
    void OnCancelClick( wxCommandEvent& event );
    void OnOkClick( wxCommandEvent& event );
public:
    SentenceListDlgImpl( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Sentences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 284,361 ), long style = wxDEFAULT_DIALOG_STYLE ); 
    ~SentenceListDlgImpl();
    void SetSentenceList(wxArrayString sentences);
    wxString GetSentencesAsText();
};

#endif