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
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 */


#include "wx/wxprec.h"

#ifndef  WX_PRECOMP
  #include "wx/wx.h"
#endif //precompiled headers

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

connector_pi::connector_pi(void *ppimgr)
      :opencpn_plugin(ppimgr)
{
      // Create the PlugIn icons
      initialize_images();
}

wxBaud baudrate = wxBAUD_115200;
char *devname = wxCOM1;
int timeout = 1000;

int connector_pi::Init(void)
{
      /*
      // like a virtual instrument in NI
      wxIOBase* dev;

      // device is a serial port
	dev = new wxSerialPort();
	// try to open the given port
	if(dev->Open(devname) < 0) {
		printf("Cannot open %s\n",devname);
		delete dev;
		//return -1;
	}
	// set the baudrate
	((wxSerialPort*)dev)->SetBaudRate(baudrate);
      int to = 0;
      timer t(timeout,&to,NULL);
      t.start();

      char* receivedString = NULL;
      size_t readedBytes = 0;
      dev->Writev("*idn?\n",6,&to);
      int state = dev->ReadUntilEOS(receivedString,
						      &readedBytes,
						      "\n",
						      timeout);
      if(readedBytes > 0) {
	      receivedString[readedBytes] = 0;
	      printf("answer (%i): %s\n",readedBytes,receivedString);
      }

      dev->Close();
      delete dev;
      */
      AddLocaleCatalog( _T("opencpn-connector_pi") );

      // Set some default private member parameters
      m_connector_dialog_x = 0;
      m_connector_dialog_y = 0;

      ::wxDisplaySize(&m_display_width, &m_display_height);

      //    Get a pointer to the opencpn display canvas, to use as a parent for the POI Manager dialog
      m_parent_window = GetOCPNCanvasWindow();

      //    Get a pointer to the opencpn configuration object
      m_pconfig = GetOCPNConfigObject();

      //    And load the configuration items
      LoadConfig();

      //    This PlugIn needs a toolbar icon, so request its insertion
      m_leftclick_tool_id  = InsertPlugInTool(_T(""), _img_connector, _img_connector, wxITEM_NORMAL,
            _("Connector"), _T(""), NULL,
             CONNECTOR_TOOL_POSITION, 0, this);

      m_pConnectorDialog = NULL;

      return (WANTS_CURSOR_LATLON       |
              WANTS_TOOLBAR_CALLBACK    |
              INSTALLS_TOOLBAR_TOOL     |
              WANTS_PREFERENCES         |
              WANTS_CONFIG
           );
}

bool connector_pi::DeInit(void)
{
      //    Record the dialog position
      if (NULL != m_pConnectorDialog)
      {
            wxPoint p = m_pConnectorDialog->GetPosition();
            SetConnectorDialogX(p.x);
            SetConnectorDialogY(p.y);

            m_pConnectorDialog->Close();
            delete m_pConnectorDialog;
            m_pConnectorDialog = NULL;
      }
      SaveConfig();
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
      return _("Connects various datasources\n\
To the NMEA pipeline in OpenCPN.");
}


int connector_pi::GetToolbarToolCount(void)
{
      return 1;
}

void connector_pi::SetColorScheme(PI_ColorScheme cs)
{
      if (NULL == m_pConnectorDialog)
            return;

      //DimeDialog
}

void connector_pi::OnToolbarToolCallback(int id)
{
      if(NULL == m_pConnectorDialog)
      {
            m_pConnectorDialog = new ConnectorCfgDlg(m_parent_window);
            m_pConnectorDialog->Move(wxPoint(m_connector_dialog_x, m_connector_dialog_y));
      }

      m_pConnectorDialog->Show(!m_pConnectorDialog->IsShown());
}

bool connector_pi::LoadConfig(void)
{
      wxFileConfig *pConf = (wxFileConfig *)m_pconfig;

      if(pConf)
      {
            pConf->SetPath ( _T( "/Settings/Connector" ) );
            pConf->Read ( _T( "ViewType" ),  &m_iViewType, 1 );
            pConf->Read ( _T( "ShowAtCursor" ),  &m_bShowAtCursor, 1 );
            pConf->Read ( _T( "Opacity" ),  &m_iOpacity, 255 );

            m_connector_dialog_x =  pConf->Read ( _T ( "DialogPosX" ), 20L );
            m_connector_dialog_y =  pConf->Read ( _T ( "DialogPosY" ), 20L );

            if((m_connector_dialog_x < 0) || (m_connector_dialog_x > m_display_width))
                  m_connector_dialog_x = 5;
            if((m_connector_dialog_y < 0) || (m_connector_dialog_y > m_display_height))
                  m_connector_dialog_y = 5;
            pConf->SetPath ( _T ( "/Directories" ) );
            wxString def;
            def = ::wxGetCwd() + _T("/plugins");
            pConf->Read ( _T ( "ConnectorDataLocation" ), &m_connector_dir, def);
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
            pConf->Write ( _T ( "ViewType" ), m_iViewType );
            pConf->Write ( _T ( "ShowAtCursor" ), m_bShowAtCursor );
            pConf->Write ( _T ( "Opacity" ), m_iOpacity );

            pConf->Write ( _T ( "DialogPosX" ),   m_connector_dialog_x );
            pConf->Write ( _T ( "DialogPosY" ),   m_connector_dialog_y );
            pConf->SetPath ( _T ( "/Directories" ) );
            pConf->Write ( _T ( "ConnestorDataLocation" ), m_connector_dir );

            return true;
      }
      else
            return false;
}

void connector_pi::ShowPreferencesDialog( wxWindow* parent )
{
      //ConnectorCfgDlg *dialog = new ConnectorCfgDlg( parent, wxID_ANY, _("Connector Preferences"), wxPoint( m_connector_dialog_x, m_connector_dialog_y), wxDefaultSize, wxDEFAULT_DIALOG_STYLE );
      //dialog->Fit();
      wxColour cl;
      GetGlobalColor(_T("DILG1"), &cl);
      //dialog->SetBackgroundColour(cl);

      //if(dialog->ShowModal() == wxID_OK)
      //{

            SaveConfig();
      //}
}

