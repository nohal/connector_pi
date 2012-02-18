///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Dec  2 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CONNECTORGUI_H__
#define __CONNECTORGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/listctrl.h>
#include <wx/string.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/statbox.h>
#include <wx/dialog.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/choice.h>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ConnectorCfgDlg
///////////////////////////////////////////////////////////////////////////////
class ConnectorCfgDlg : public wxDialog
{
	private:
	
	protected:
		wxListCtrl* m_listCtrlDatasources;
		wxButton* m_button1;
		wxButton* m_button3;
		wxButton* m_button2;
		wxStdDialogButtonSizer* m_sdbSizer2;
		wxButton* m_sdbSizer2OK;
		wxButton* m_sdbSizer2Cancel;
	
	public:
		
		ConnectorCfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connector Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 464,359 ), long style = wxDEFAULT_DIALOG_STYLE ); 
            //ConnectorCfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Connector Configuration"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 464,359 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ConnectorCfgDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ConnectorSourceDlg
///////////////////////////////////////////////////////////////////////////////
class ConnectorSourceDlg : public wxDialog
{
	private:
	
	protected:
		wxRadioButton* m_radioBtn1;
		wxRadioButton* m_radioBtn2;
		wxStaticText* m_staticText1;
		wxComboBox* m_comboBox1;
		wxStaticText* m_staticText2;
		wxComboBox* m_comboBox2;
		wxStaticText* m_staticText3;
		wxChoice* m_choice2;
		wxStaticText* m_staticText4;
		wxTextCtrl* m_textCtrl1;
		wxStaticText* m_staticText5;
		wxTextCtrl* m_textCtrl2;
		wxStaticText* m_staticText6;
		wxChoice* m_choice1;
		wxStdDialogButtonSizer* m_sdbSizer1;
		wxButton* m_sdbSizer1OK;
		wxButton* m_sdbSizer1Cancel;
	
	public:
		
		ConnectorSourceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data source properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
            //ConnectorSourceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data source properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE ); 
		~ConnectorSourceDlg();
	
};

#endif //__CONNECTORGUI_H__
