///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CONNECTORGUI_H__
#define __CONNECTORGUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/combobox.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/statbox.h>
#include <wx/dialog.h>
#include <wx/listbox.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class ConnectorSourceDlg
///////////////////////////////////////////////////////////////////////////////
class ConnectorSourceDlg : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxComboBox* m_comboPort;
		wxStaticText* m_staticText2;
		wxChoice* m_choiceBaudRate;
		wxStaticText* m_staticText4;
		wxChoice* m_choiceDataBits;
		wxStaticText* m_staticText5;
		wxChoice* m_choiceParity;
		wxStaticText* m_staticText6;
		wxChoice* m_choiceStopBits;
		wxCheckBox* m_cbRtsCts;
		wxCheckBox* m_cbXonXoff;
		wxStaticText* m_staticText8;
		wxChoice* m_choiceEOS;
		wxStaticText* m_staticText3;
		wxChoice* m_choiceSerialProtocol;
		wxCheckBox* m_cbCheckCRC;
		wxRadioButton* m_rbIAccept;
		wxRadioButton* m_rbIIgnore;
		wxTextCtrl* m_tcInputStc;
		wxButton* m_btnInputStcList;
		wxCheckBox* m_cbOutput;
		wxRadioButton* m_rbOAccept;
		wxRadioButton* m_rbOIgnore;
		wxTextCtrl* m_tcOutputStc;
		wxButton* m_btnOutputStcList;
		wxStdDialogButtonSizer* m_sdbSizerDlgButtons;
		wxButton* m_sdbSizerDlgButtonsOK;
		wxButton* m_sdbSizerDlgButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnBaudrateChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProtocolChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCrcCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRbInput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnIStcs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCbOutput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRbOutput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnOStcs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConnectorSourceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data source properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 550,480 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ConnectorSourceDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class SentenceListDlg
///////////////////////////////////////////////////////////////////////////////
class SentenceListDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_lbSentences;
		wxButton* m_btnAdd;
		wxButton* m_btnDel;
		wxButton* m_btnDelAll;
		wxStdDialogButtonSizer* m_sdbSizer4;
		wxButton* m_sdbSizer4OK;
		wxButton* m_sdbSizer4Cancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnStcSelect( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnDeleteAllClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		SentenceListDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Sentences"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 284,361 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~SentenceListDlg();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class ConnectorCfgDlg
///////////////////////////////////////////////////////////////////////////////
class ConnectorCfgDlg : public wxDialog 
{
	private:
	
	protected:
		wxListBox* m_lbDatasources;
		wxButton* m_buttonAdd;
		wxButton* m_buttonEdit;
		wxButton* m_buttonRemove;
		wxStdDialogButtonSizer* m_sdbSizerDlgButtons;
		wxButton* m_sdbSizerDlgButtonsOK;
		wxButton* m_sdbSizerDlgButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectDatasource( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnAddClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnEditClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConnectorCfgDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data sources"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 300,400 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~ConnectorCfgDlg();
	
};

#endif //__CONNECTORGUI_H__
