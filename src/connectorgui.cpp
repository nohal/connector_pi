///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Apr 10 2012)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "connectorgui.h"

///////////////////////////////////////////////////////////////////////////

ConnectorSourceDlg::ConnectorSourceDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	wxStaticBoxSizer* sbSizer2;
	sbSizer2 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Properties") ), wxVERTICAL );
	
	wxGridSizer* gSizer1;
	gSizer1 = new wxGridSizer( 0, 2, 0, 0 );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	gSizer1->Add( m_staticText1, 0, wxALL, 5 );
	
	m_comboPort = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	gSizer1->Add( m_comboPort, 0, wxEXPAND|wxTOP, 5 );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, _("Baudrate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	gSizer1->Add( m_staticText2, 0, wxALL, 5 );
	
	wxString m_choiceBaudRateChoices[] = { _("4800"), _("9600"), _("38400"), _("115200"), _("230400") };
	int m_choiceBaudRateNChoices = sizeof( m_choiceBaudRateChoices ) / sizeof( wxString );
	m_choiceBaudRate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBaudRateNChoices, m_choiceBaudRateChoices, 0 );
	m_choiceBaudRate->SetSelection( 0 );
	gSizer1->Add( m_choiceBaudRate, 1, wxEXPAND|wxTOP, 5 );
	
	m_staticText4 = new wxStaticText( this, wxID_ANY, _("Data bits"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText4->Wrap( -1 );
	gSizer1->Add( m_staticText4, 0, wxALL, 5 );
	
	wxString m_choiceDataBitsChoices[] = { _("8"), _("7"), _("6"), _("5") };
	int m_choiceDataBitsNChoices = sizeof( m_choiceDataBitsChoices ) / sizeof( wxString );
	m_choiceDataBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDataBitsNChoices, m_choiceDataBitsChoices, 0 );
	m_choiceDataBits->SetSelection( 0 );
	gSizer1->Add( m_choiceDataBits, 0, wxEXPAND|wxTOP, 5 );
	
	m_staticText5 = new wxStaticText( this, wxID_ANY, _("Parity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText5->Wrap( -1 );
	gSizer1->Add( m_staticText5, 0, wxALL, 5 );
	
	wxString m_choiceParityChoices[] = { _("None"), _("Odd"), _("Even"), _("Mark"), _("Space") };
	int m_choiceParityNChoices = sizeof( m_choiceParityChoices ) / sizeof( wxString );
	m_choiceParity = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceParityNChoices, m_choiceParityChoices, 0 );
	m_choiceParity->SetSelection( 0 );
	gSizer1->Add( m_choiceParity, 0, wxEXPAND|wxTOP, 5 );
	
	m_staticText6 = new wxStaticText( this, wxID_ANY, _("Stop bits"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	gSizer1->Add( m_staticText6, 0, wxALL, 5 );
	
	wxString m_choiceStopBitsChoices[] = { _("1"), _("2") };
	int m_choiceStopBitsNChoices = sizeof( m_choiceStopBitsChoices ) / sizeof( wxString );
	m_choiceStopBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceStopBitsNChoices, m_choiceStopBitsChoices, 0 );
	m_choiceStopBits->SetSelection( 0 );
	gSizer1->Add( m_choiceStopBits, 0, wxEXPAND|wxTOP, 5 );
	
	m_cbRtsCts = new wxCheckBox( this, wxID_ANY, _("RTS/CTS"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_cbRtsCts, 0, wxALL, 5 );
	
	m_cbXonXoff = new wxCheckBox( this, wxID_ANY, _("Xon/Xoff"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizer1->Add( m_cbXonXoff, 0, wxALL, 5 );
	
	m_staticText8 = new wxStaticText( this, wxID_ANY, _("EOS is"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText8->Wrap( -1 );
	gSizer1->Add( m_staticText8, 0, wxALL, 5 );
	
	wxString m_choiceEOSChoices[] = { _("<CR><LF>"), _("<LF>"), _("<CR>"), _("<LF><CR>"), _("None") };
	int m_choiceEOSNChoices = sizeof( m_choiceEOSChoices ) / sizeof( wxString );
	m_choiceEOS = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceEOSNChoices, m_choiceEOSChoices, 0 );
	m_choiceEOS->SetSelection( 0 );
	gSizer1->Add( m_choiceEOS, 0, wxEXPAND|wxTOP, 5 );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	gSizer1->Add( m_staticText3, 0, wxALL, 5 );
	
	wxString m_choiceSerialProtocolChoices[] = { _("NMEA 0183"), _("NMEA 2000"), _("Seatalk") };
	int m_choiceSerialProtocolNChoices = sizeof( m_choiceSerialProtocolChoices ) / sizeof( wxString );
	m_choiceSerialProtocol = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSerialProtocolNChoices, m_choiceSerialProtocolChoices, 0 );
	m_choiceSerialProtocol->SetSelection( 0 );
	m_choiceSerialProtocol->Enable( false );
	
	gSizer1->Add( m_choiceSerialProtocol, 1, wxEXPAND|wxTOP, 5 );
	
	
	sbSizer2->Add( gSizer1, 0, wxEXPAND, 5 );
	
	m_cbCheckCRC = new wxCheckBox( this, wxID_ANY, _("Control checksum"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbCheckCRC->SetValue(true); 
	m_cbCheckCRC->SetToolTip( _("If checked, only the sentences with a valid checksum are passed through") );
	
	sbSizer2->Add( m_cbCheckCRC, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbIAccept = new wxRadioButton( this, wxID_ANY, _("Accept sentences"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer9->Add( m_rbIAccept, 0, wxALL, 5 );
	
	m_rbIIgnore = new wxRadioButton( this, wxID_ANY, _("Ignore sentences"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_rbIIgnore, 0, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_tcInputStc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer11->Add( m_tcInputStc, 1, wxALL|wxEXPAND, 5 );
	
	m_btnInputStcList = new wxButton( this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer11->Add( m_btnInputStcList, 0, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_cbOutput = new wxCheckBox( this, wxID_ANY, _("Output on this port"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer2->Add( m_cbOutput, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbOAccept = new wxRadioButton( this, wxID_ANY, _("Output sentences"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer10->Add( m_rbOAccept, 0, wxALL, 5 );
	
	m_rbOIgnore = new wxRadioButton( this, wxID_ANY, _("Ignore sentences"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_rbOIgnore, 0, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_tcOutputStc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer12->Add( m_tcOutputStc, 1, wxALL|wxEXPAND, 5 );
	
	m_btnOutputStcList = new wxButton( this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer12->Add( m_btnOutputStcList, 0, wxALL, 5 );
	
	
	sbSizer2->Add( bSizer12, 0, wxEXPAND, 5 );
	
	
	bSizer7->Add( sbSizer2, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_sdbSizerDlgButtons = new wxStdDialogButtonSizer();
	m_sdbSizerDlgButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsOK );
	m_sdbSizerDlgButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsCancel );
	m_sdbSizerDlgButtons->Realize();
	
	bSizer4->Add( m_sdbSizerDlgButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_choiceBaudRate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnBaudrateChoice ), NULL, this );
	m_choiceSerialProtocol->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnProtocolChoice ), NULL, this );
	m_cbCheckCRC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCrcCheck ), NULL, this );
	m_rbIAccept->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_rbIIgnore->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_btnInputStcList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnIStcs ), NULL, this );
	m_cbOutput->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCbOutput ), NULL, this );
	m_rbOAccept->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbOutput ), NULL, this );
	m_btnOutputStcList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnOStcs ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnOkClick ), NULL, this );
}

ConnectorSourceDlg::~ConnectorSourceDlg()
{
	// Disconnect Events
	m_choiceBaudRate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnBaudrateChoice ), NULL, this );
	m_choiceSerialProtocol->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnProtocolChoice ), NULL, this );
	m_cbCheckCRC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCrcCheck ), NULL, this );
	m_rbIAccept->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_rbIIgnore->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_btnInputStcList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnIStcs ), NULL, this );
	m_cbOutput->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCbOutput ), NULL, this );
	m_rbOAccept->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbOutput ), NULL, this );
	m_btnOutputStcList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnOStcs ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnOkClick ), NULL, this );
	
}

SentenceListDlg::SentenceListDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lbSentences = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer17->Add( m_lbSentences, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_btnAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_btnAdd, 0, wxALL, 5 );
	
	m_btnDel = new wxButton( this, wxID_ANY, _("Delete"), wxDefaultPosition, wxDefaultSize, 0 );
	m_btnDel->Enable( false );
	
	bSizer18->Add( m_btnDel, 0, wxALL, 5 );
	
	m_btnDelAll = new wxButton( this, wxID_ANY, _("Delete All"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_btnDelAll, 0, wxALL, 5 );
	
	
	bSizer17->Add( bSizer18, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer16->Add( bSizer17, 1, wxEXPAND, 5 );
	
	m_sdbSizer4 = new wxStdDialogButtonSizer();
	m_sdbSizer4OK = new wxButton( this, wxID_OK );
	m_sdbSizer4->AddButton( m_sdbSizer4OK );
	m_sdbSizer4Cancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizer4->AddButton( m_sdbSizer4Cancel );
	m_sdbSizer4->Realize();
	
	bSizer16->Add( m_sdbSizer4, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer16 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_lbSentences->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( SentenceListDlg::OnStcSelect ), NULL, this );
	m_btnAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnAddClick ), NULL, this );
	m_btnDel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnDeleteClick ), NULL, this );
	m_btnDelAll->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnDeleteAllClick ), NULL, this );
	m_sdbSizer4Cancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnCancelClick ), NULL, this );
	m_sdbSizer4OK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnOkClick ), NULL, this );
}

SentenceListDlg::~SentenceListDlg()
{
	// Disconnect Events
	m_lbSentences->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( SentenceListDlg::OnStcSelect ), NULL, this );
	m_btnAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnAddClick ), NULL, this );
	m_btnDel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnDeleteClick ), NULL, this );
	m_btnDelAll->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnDeleteAllClick ), NULL, this );
	m_sdbSizer4Cancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnCancelClick ), NULL, this );
	m_sdbSizer4OK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( SentenceListDlg::OnOkClick ), NULL, this );
	
}

ConnectorCfgDlg::ConnectorCfgDlg( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Data Sources") ), wxVERTICAL );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lbDatasources = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	bSizer2->Add( m_lbDatasources, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3->Add( m_buttonAdd, 0, wxALL, 5 );
	
	m_buttonEdit = new wxButton( this, wxID_ANY, _("Properties"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonEdit->Enable( false );
	
	bSizer3->Add( m_buttonEdit, 0, wxALL, 5 );
	
	m_buttonRemove = new wxButton( this, wxID_ANY, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRemove->Enable( false );
	
	bSizer3->Add( m_buttonRemove, 0, wxALL, 5 );
	
	
	bSizer2->Add( bSizer3, 0, wxEXPAND, 5 );
	
	
	sbSizer1->Add( bSizer2, 1, wxEXPAND, 5 );
	
	
	bSizer1->Add( sbSizer1, 1, wxALL|wxEXPAND, 5 );
	
	m_sdbSizerDlgButtons = new wxStdDialogButtonSizer();
	m_sdbSizerDlgButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsOK );
	m_sdbSizerDlgButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsCancel );
	m_sdbSizerDlgButtons->Realize();
	
	bSizer1->Add( m_sdbSizerDlgButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_lbDatasources->Connect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ConnectorCfgDlg::OnSelectDatasource ), NULL, this );
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnAddClick ), NULL, this );
	m_buttonEdit->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnEditClick ), NULL, this );
	m_buttonRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnRemoveClick ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnOkClick ), NULL, this );
}

ConnectorCfgDlg::~ConnectorCfgDlg()
{
	// Disconnect Events
	m_lbDatasources->Disconnect( wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler( ConnectorCfgDlg::OnSelectDatasource ), NULL, this );
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnAddClick ), NULL, this );
	m_buttonEdit->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnEditClick ), NULL, this );
	m_buttonRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnRemoveClick ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorCfgDlg::OnOkClick ), NULL, this );
	
}
