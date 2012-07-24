/******************************************************************************
* $Id: connector_pi.cpp,v 1.0 2011/02/26 01:54:37 nohal Exp $
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


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include <wx/tokenzr.h>
#include <wx/notebook.h>

#include "connector_pi.h"

#include "wx/ctb/getopt.h"
#include "wx/ctb/iobase.h"
#include "wx/ctb/serport.h"
#include "wx/ctb/timer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// the class factories, used to create and destroy instances of the PlugIn

extern "C" DECL_EXP opencpn_plugin* create_pi(void *ppimgr)
{
    return new connector_pi(ppimgr);
}

extern "C" DECL_EXP void destroy_pi(opencpn_plugin* p)
{
    delete p;
}

//---------------------------------------------------------------------------------------------------------
//
//    Connector PlugIn Implementation
//
//---------------------------------------------------------------------------------------------------------

#include "icons.h"

//---------------------------------------------------------------------------------------------------------
//
//          PlugIn initialization and de-init
//
//---------------------------------------------------------------------------------------------------------

BEGIN_EVENT_TABLE(ConnectionHandler, wxEvtHandler)
    EVT_TIMER(TIMER_CONN, ConnectionHandler::OnTimer)
END_EVENT_TABLE()

connector_pi::connector_pi(void *ppimgr)
    :opencpn_plugin_19(ppimgr)
{
    // Create the PlugIn icons
    initialize_images();
}

wxBaud baudrate = wxBAUD_4800;
char *devname = wxCOM1;
int timeout = 1000;

int connector_pi::Init(void)
{
    AddLocaleCatalog( _T("opencpn-connector_pi") );

    m_pConnectionParams = new wxArrayOfConnPrm();

    //    Get a pointer to the opencpn configuration object
    m_pconfig = GetOCPNConfigObject();

    //    And load the configuration items
    LoadConfig();

    m_pConnectorDialog = NULL;

    connectionhandler = new ConnectionHandler(this);
    connectionhandler->CreateConnections(m_pConnectionParams);

    return (WANTS_PREFERENCES         |
        WANTS_NMEA_SENTENCES      |
        WANTS_AIS_SENTENCES       |
        WANTS_CONFIG
        );
}

bool connector_pi::DeInit(void)
{
    SaveConfig();
    delete connectionhandler;
    return true;
}

int connector_pi::GetAPIVersionMajor()
{
    return MY_API_VERSION_MAJOR;
}

int connector_pi::GetAPIVersionMinor()
{
    return MY_API_VERSION_MINOR;
}

int connector_pi::GetPlugInVersionMajor()
{
    return PLUGIN_VERSION_MAJOR;
}

int connector_pi::GetPlugInVersionMinor()
{
    return PLUGIN_VERSION_MINOR;
}

wxBitmap *connector_pi::GetPlugInBitmap()
{
    return _img_connector_pi;
}

wxString connector_pi::GetCommonName()
{
    return _("Connector");
}


wxString connector_pi::GetShortDescription()
{
    return _("Connector PlugIn for OpenCPN");
}

wxString connector_pi::GetLongDescription()
{
    return _("Connects various datasources and listeners\n\
             to the NMEA pipeline in OpenCPN.");
}

void connector_pi::SetColorScheme(PI_ColorScheme cs)
{
    if (NULL == m_pConnectorDialog)
        return;

    //DimeDialog
}

bool connector_pi::LoadConfig(void)
{
    wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

    if(pConf)
    {
        pConf->SetPath ( _T( "/Settings/Connector" ) );
        wxString connectionconfigs;
        pConf->Read ( _T( "DataConnections" ),  &connectionconfigs, wxEmptyString );

        wxArrayString confs = wxStringTokenize(connectionconfigs, _T("|"));
        for (size_t i = 0; i < confs.Count(); i++)
        {
            ConnectionParams * prm = new ConnectionParams(confs[i]);
            m_pConnectionParams->Add(prm);
        }

        return true;
    }
    else
        return false;
}

bool connector_pi::SaveConfig(void)
{
    wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

    if(pConf)
    {
        pConf->SetPath ( _T ( "/Settings/Connector" ) );
        wxString connectionconfigs;

        for (size_t i = 0; i < m_pConnectionParams->Count(); i++)
        {
            if (i > 0)
                connectionconfigs.Append(_T("|"));
            connectionconfigs.Append(m_pConnectionParams->Item(i)->Serialize());
        }

        pConf->Write ( _T ( "DataConnections" ), connectionconfigs );

        return true;
    }
    else
        return false;
}

void connector_pi::ShowPreferencesDialog( wxWindow* parent )
{
    if (!m_pConnectorDialog) 
    {
        m_pConnectorDialog = new ConnectorCfgDlgImpl( parent, wxID_ANY, _("Connector Preferences") );
        m_pConnectorDialog->LinkToPlugin(this);
        //m_pConnectorDialog->Fit();
    }
    DimeWindow(m_pConnectorDialog);

    connectionhandler->StopTimer();
    if(m_pConnectorDialog->ShowModal() == wxID_OK)
    {
        SaveConfig();
        connectionhandler->CreateConnections(m_pConnectionParams);
    }
    connectionhandler->StartTimer();
    delete m_pConnectorDialog;
    m_pConnectorDialog = NULL;
}

void connector_pi::SetNMEASentence(wxString &sentence, wxString &source)
{
    wxLogMessage(_T("CONNECTOR received NMEA: %s : %s"), source.c_str(), sentence.c_str());
    connectionhandler->SendNMEAMessage(sentence, source);
}

void connector_pi::SetAISSentence(wxString &sentence, wxString &source)
{
    wxLogMessage(_T("CONNECTOR received AIS: %s : %s"), source.c_str(), sentence.c_str());
    connectionhandler->SendNMEAMessage(sentence, source);
}

void connector_pi::SendSentenceToCore(wxString &msg)
{
    PushNMEABufferEx(msg, CONNECTOR_PI);
}