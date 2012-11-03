///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Sep  5 2012)
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
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/radiobut.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
#include <wx/choice.h>
#include <wx/checkbox.h>
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
		wxListCtrl* m_lcSources;
		wxButton* m_buttonAdd;
		wxButton* m_buttonRemove;
		wxStaticBoxSizer* sbSizerConnectionProps;
		wxRadioButton* m_rbTypeSerial;
		wxRadioButton* m_rbTypeNet;
		wxGridSizer* gSizerNetProps;
		wxStaticText* m_stNetProto;
		wxRadioButton* m_rbNetProtoTCP;
		wxRadioButton* m_rbNetProtoUDP;
		wxRadioButton* m_rbNetProtoGPSD;
		wxStaticText* m_stNetAddr;
		wxTextCtrl* m_tNetAddress;
		wxStaticText* m_stNetPort;
		wxTextCtrl* m_tNetPort;
		wxGridSizer* gSizerSerProps;
		wxStaticText* m_stSerPort;
		wxComboBox* m_comboPort;
		wxStaticText* m_stSerBaudrate;
		wxChoice* m_choiceBaudRate;
		wxStaticText* m_stSerDatabits;
		wxChoice* m_choiceDataBits;
		wxStaticText* m_stSerParity;
		wxChoice* m_choiceParity;
		wxStaticText* m_stSerStopbits;
		wxChoice* m_choiceStopBits;
		wxCheckBox* m_cbRtsCts;
		wxCheckBox* m_cbXonXoff;
		wxStaticText* m_stSerEos;
		wxChoice* m_choiceEOS;
		wxStaticText* m_stSerProtocol;
		wxChoice* m_choiceSerialProtocol;
		wxCheckBox* m_cbCheckCRC;
		wxStaticText* m_staticText12;
		wxStaticText* m_stPriority;
		wxChoice* m_choicePriority;
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
		wxButton* m_sdbSizerDlgButtonsApply;
		wxButton* m_sdbSizerDlgButtonsCancel;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnSelectDatasource( wxListEvent& event ) { event.Skip(); }
		virtual void OnAddClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRemoveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTypeSerialSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnTypeNetSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnNetProtocolSelected( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBaudrateChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnProtocolChoice( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCrcCheck( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRbInput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnIStcs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCbOutput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnRbOutput( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnOStcs( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnApplyClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnCancelClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnOkClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		ConnectorSourceDlg( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Data source properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,655 ), long style = wxDEFAULT_DIALOG_STYLE ); 
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

#endif //__CONNECTORGUI_H__
