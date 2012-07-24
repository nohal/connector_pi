/******************************************************************************
* $Id: connector_pi.h,v 1.0 2011/02/26 01:54:37 nohal Exp $
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

#ifndef _CONNECTORPI_H_
#define _CONNECTORPI_H_

#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include <wx/fileconf.h>

#define     PLUGIN_VERSION_MAJOR    0
#define     PLUGIN_VERSION_MINOR    1

#define     MY_API_VERSION_MAJOR    1
#define     MY_API_VERSION_MINOR    9

#include "../../../include/ocpn_plugin.h"

#include "connectorgui_impl.h"
#include "serialconnection.h"

//----------------------------------------------------------------------------------------------------------
//    The PlugIn Class Definition
//----------------------------------------------------------------------------------------------------------

#define CONNECTOR_TOOL_POSITION    -1          // Request default positioning of toolbar tool

class ConnectorCfgDlgImpl;
class wxArrayOfConnPrm;
class ConnectionHandler;

class connector_pi : public opencpn_plugin_19
{
public:
    connector_pi(void *ppimgr);

    //    The required PlugIn Methods
    int Init(void);
    bool DeInit(void);

    int GetAPIVersionMajor();
    int GetAPIVersionMinor();
    int GetPlugInVersionMajor();
    int GetPlugInVersionMinor();
    wxBitmap *GetPlugInBitmap();
    wxString GetCommonName();
    wxString GetShortDescription();
    wxString GetLongDescription();

    //    The required override PlugIn Methods
    void ShowPreferencesDialog( wxWindow* parent );

    //    Optional plugin overrides
    void SetColorScheme(PI_ColorScheme cs);

    void OnConnectorDialogClose();

    wxArrayOfConnPrm *m_pConnectionParams;

    void SetNMEASentence(wxString &sentence, wxString &source);
    void SetAISSentence(wxString &sentence, wxString &source);

    void SendSentenceToCore(wxString &msg);

private:
    wxFileConfig     *m_pconfig;
    bool              LoadConfig(void);
    bool              SaveConfig(void);

    ConnectorCfgDlgImpl *m_pConnectorDialog;

    ConnectionHandler *connectionhandler;
};

#endif
