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
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_lcSources = new wxListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxLC_SINGLE_SEL );
	bSizer17->Add( m_lcSources, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );
	
	m_buttonAdd = new wxButton( this, wxID_ANY, _("Add"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer18->Add( m_buttonAdd, 0, wxALL, 5 );
	
	m_buttonRemove = new wxButton( this, wxID_ANY, _("Remove"), wxDefaultPosition, wxDefaultSize, 0 );
	m_buttonRemove->Enable( false );
	
	bSizer18->Add( m_buttonRemove, 0, wxALL, 5 );
	
	
	bSizer17->Add( bSizer18, 0, wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer17, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	sbSizerConnectionProps = new wxStaticBoxSizer( new wxStaticBox( this, wxID_ANY, _("Properties") ), wxVERTICAL );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbTypeSerial = new wxRadioButton( this, wxID_ANY, _("Serial"), wxDefaultPosition, wxDefaultSize, 0 );
	m_rbTypeSerial->SetValue( true ); 
	bSizer15->Add( m_rbTypeSerial, 0, wxALL, 5 );
	
	m_rbTypeNet = new wxRadioButton( this, wxID_ANY, _("Network"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer15->Add( m_rbTypeNet, 0, wxALL, 5 );
	
	
	sbSizerConnectionProps->Add( bSizer15, 0, wxEXPAND, 0 );
	
	gSizerNetProps = new wxGridSizer( 0, 2, 0, 0 );
	
	m_stNetProto = new wxStaticText( this, wxID_ANY, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stNetProto->Wrap( -1 );
	gSizerNetProps->Add( m_stNetProto, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbNetProtoTCP = new wxRadioButton( this, wxID_ANY, _("TCP"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer16->Add( m_rbNetProtoTCP, 0, wxALL, 5 );
	
	m_rbNetProtoUDP = new wxRadioButton( this, wxID_ANY, _("UDP"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_rbNetProtoUDP, 0, wxALL, 5 );
	
	m_rbNetProtoGPSD = new wxRadioButton( this, wxID_ANY, _("GPSD"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer16->Add( m_rbNetProtoGPSD, 0, wxALL, 5 );
	
	
	gSizerNetProps->Add( bSizer16, 1, wxEXPAND, 5 );
	
	m_stNetAddr = new wxStaticText( this, wxID_ANY, _("Address"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stNetAddr->Wrap( -1 );
	gSizerNetProps->Add( m_stNetAddr, 0, wxALL, 5 );
	
	m_tNetAddress = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizerNetProps->Add( m_tNetAddress, 0, wxEXPAND|wxTOP, 5 );
	
	m_stNetPort = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stNetPort->Wrap( -1 );
	gSizerNetProps->Add( m_stNetPort, 0, wxALL, 5 );
	
	m_tNetPort = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	gSizerNetProps->Add( m_tNetPort, 1, wxEXPAND|wxTOP, 5 );
	
	
	sbSizerConnectionProps->Add( gSizerNetProps, 0, wxEXPAND, 5 );
	
	gSizerSerProps = new wxGridSizer( 0, 4, 0, 0 );
	
	m_stSerPort = new wxStaticText( this, wxID_ANY, _("Port"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerPort->Wrap( -1 );
	gSizerSerProps->Add( m_stSerPort, 0, wxALL, 5 );
	
	m_comboPort = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 ); 
	gSizerSerProps->Add( m_comboPort, 0, wxEXPAND|wxTOP, 5 );
	
	m_stSerBaudrate = new wxStaticText( this, wxID_ANY, _("Baudrate"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerBaudrate->Wrap( -1 );
	gSizerSerProps->Add( m_stSerBaudrate, 0, wxALL, 5 );
	
	wxString m_choiceBaudRateChoices[] = { _("150"), _("300"), _("600"), _("1200"), _("2400"), _("4800"), _("9600"), _("19200"), _("38400"), _("57600"), _("115200"), _("230400"), _("460800"), _("921600") };
	int m_choiceBaudRateNChoices = sizeof( m_choiceBaudRateChoices ) / sizeof( wxString );
	m_choiceBaudRate = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceBaudRateNChoices, m_choiceBaudRateChoices, 0 );
	m_choiceBaudRate->SetSelection( 0 );
	gSizerSerProps->Add( m_choiceBaudRate, 1, wxEXPAND|wxTOP, 5 );
	
	m_stSerDatabits = new wxStaticText( this, wxID_ANY, _("Data bits"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerDatabits->Wrap( -1 );
	gSizerSerProps->Add( m_stSerDatabits, 0, wxALL, 5 );
	
	wxString m_choiceDataBitsChoices[] = { _("8"), _("7"), _("6"), _("5") };
	int m_choiceDataBitsNChoices = sizeof( m_choiceDataBitsChoices ) / sizeof( wxString );
	m_choiceDataBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceDataBitsNChoices, m_choiceDataBitsChoices, 0 );
	m_choiceDataBits->SetSelection( 0 );
	gSizerSerProps->Add( m_choiceDataBits, 0, wxEXPAND|wxTOP, 5 );
	
	m_stSerParity = new wxStaticText( this, wxID_ANY, _("Parity"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerParity->Wrap( -1 );
	gSizerSerProps->Add( m_stSerParity, 0, wxALL, 5 );
	
	wxString m_choiceParityChoices[] = { _("None"), _("Odd"), _("Even"), _("Mark"), _("Space") };
	int m_choiceParityNChoices = sizeof( m_choiceParityChoices ) / sizeof( wxString );
	m_choiceParity = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceParityNChoices, m_choiceParityChoices, 0 );
	m_choiceParity->SetSelection( 0 );
	gSizerSerProps->Add( m_choiceParity, 0, wxEXPAND|wxTOP, 5 );
	
	m_stSerStopbits = new wxStaticText( this, wxID_ANY, _("Stop bits"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerStopbits->Wrap( -1 );
	gSizerSerProps->Add( m_stSerStopbits, 0, wxALL, 5 );
	
	wxString m_choiceStopBitsChoices[] = { _("1"), _("2") };
	int m_choiceStopBitsNChoices = sizeof( m_choiceStopBitsChoices ) / sizeof( wxString );
	m_choiceStopBits = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceStopBitsNChoices, m_choiceStopBitsChoices, 0 );
	m_choiceStopBits->SetSelection( 0 );
	gSizerSerProps->Add( m_choiceStopBits, 0, wxEXPAND|wxTOP, 5 );
	
	m_cbRtsCts = new wxCheckBox( this, wxID_ANY, _("RTS/CTS"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerSerProps->Add( m_cbRtsCts, 0, wxALL, 5 );
	
	m_cbXonXoff = new wxCheckBox( this, wxID_ANY, _("Xon/Xoff"), wxDefaultPosition, wxDefaultSize, 0 );
	gSizerSerProps->Add( m_cbXonXoff, 0, wxALL, 5 );
	
	m_stSerEos = new wxStaticText( this, wxID_ANY, _("EOS is"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerEos->Wrap( -1 );
	gSizerSerProps->Add( m_stSerEos, 0, wxALL, 5 );
	
	wxString m_choiceEOSChoices[] = { _("<CR><LF>"), _("<LF>"), _("<CR>"), _("<LF><CR>"), _("None") };
	int m_choiceEOSNChoices = sizeof( m_choiceEOSChoices ) / sizeof( wxString );
	m_choiceEOS = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceEOSNChoices, m_choiceEOSChoices, 0 );
	m_choiceEOS->SetSelection( 0 );
	gSizerSerProps->Add( m_choiceEOS, 0, wxEXPAND|wxTOP, 5 );
	
	m_stSerProtocol = new wxStaticText( this, wxID_ANY, _("Protocol"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stSerProtocol->Wrap( -1 );
	gSizerSerProps->Add( m_stSerProtocol, 0, wxALL, 5 );
	
	wxString m_choiceSerialProtocolChoices[] = { _("NMEA 0183"), _("NMEA 2000"), _("Seatalk") };
	int m_choiceSerialProtocolNChoices = sizeof( m_choiceSerialProtocolChoices ) / sizeof( wxString );
	m_choiceSerialProtocol = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choiceSerialProtocolNChoices, m_choiceSerialProtocolChoices, 0 );
	m_choiceSerialProtocol->SetSelection( 0 );
	m_choiceSerialProtocol->Enable( false );
	
	gSizerSerProps->Add( m_choiceSerialProtocol, 1, wxEXPAND|wxTOP, 5 );
	
	m_cbCheckCRC = new wxCheckBox( this, wxID_ANY, _("Control checksum"), wxDefaultPosition, wxDefaultSize, 0 );
	m_cbCheckCRC->SetValue(true); 
	m_cbCheckCRC->SetToolTip( _("If checked, only the sentences with a valid checksum are passed through") );
	
	gSizerSerProps->Add( m_cbCheckCRC, 0, wxALL, 5 );
	
	m_staticText12 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText12->Wrap( -1 );
	gSizerSerProps->Add( m_staticText12, 0, wxALL, 5 );
	
	m_stPriority = new wxStaticText( this, wxID_ANY, _("Priority"), wxDefaultPosition, wxDefaultSize, 0 );
	m_stPriority->Wrap( -1 );
	gSizerSerProps->Add( m_stPriority, 0, wxALL, 5 );
	
	wxString m_choicePriorityChoices[] = { _("0"), _("1"), _("2"), _("3"), _("4"), _("5"), _("6"), _("7"), _("8"), _("9") };
	int m_choicePriorityNChoices = sizeof( m_choicePriorityChoices ) / sizeof( wxString );
	m_choicePriority = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, m_choicePriorityNChoices, m_choicePriorityChoices, 0 );
	m_choicePriority->SetSelection( 0 );
	gSizerSerProps->Add( m_choicePriority, 0, wxEXPAND|wxTOP, 5 );
	
	
	sbSizerConnectionProps->Add( gSizerSerProps, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbIAccept = new wxRadioButton( this, wxID_ANY, _("Accept sentences"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer9->Add( m_rbIAccept, 0, wxALL, 5 );
	
	m_rbIIgnore = new wxRadioButton( this, wxID_ANY, _("Ignore sentences"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer9->Add( m_rbIIgnore, 0, wxALL, 5 );
	
	
	sbSizerConnectionProps->Add( bSizer9, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	m_tcInputStc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer11->Add( m_tcInputStc, 1, wxALL|wxEXPAND, 5 );
	
	m_btnInputStcList = new wxButton( this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer11->Add( m_btnInputStcList, 0, wxALL, 5 );
	
	
	sbSizerConnectionProps->Add( bSizer11, 0, wxEXPAND, 5 );
	
	m_cbOutput = new wxCheckBox( this, wxID_ANY, _("Output on this port"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizerConnectionProps->Add( m_cbOutput, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );
	
	m_rbOAccept = new wxRadioButton( this, wxID_ANY, _("Output sentences"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer10->Add( m_rbOAccept, 0, wxALL, 5 );
	
	m_rbOIgnore = new wxRadioButton( this, wxID_ANY, _("Ignore sentences"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer10->Add( m_rbOIgnore, 0, wxALL, 5 );
	
	
	sbSizerConnectionProps->Add( bSizer10, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	m_tcOutputStc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
	bSizer12->Add( m_tcOutputStc, 1, wxALL|wxEXPAND, 5 );
	
	m_btnOutputStcList = new wxButton( this, wxID_ANY, _("..."), wxDefaultPosition, wxDefaultSize, wxBU_EXACTFIT );
	bSizer12->Add( m_btnOutputStcList, 0, wxALL, 5 );
	
	
	sbSizerConnectionProps->Add( bSizer12, 0, wxEXPAND, 5 );
	
	
	bSizer7->Add( sbSizerConnectionProps, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer5->Add( bSizer7, 1, wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer5, 1, wxEXPAND, 5 );
	
	m_sdbSizerDlgButtons = new wxStdDialogButtonSizer();
	m_sdbSizerDlgButtonsOK = new wxButton( this, wxID_OK );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsOK );
	m_sdbSizerDlgButtonsApply = new wxButton( this, wxID_APPLY );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsApply );
	m_sdbSizerDlgButtonsCancel = new wxButton( this, wxID_CANCEL );
	m_sdbSizerDlgButtons->AddButton( m_sdbSizerDlgButtonsCancel );
	m_sdbSizerDlgButtons->Realize();
	
	bSizer4->Add( m_sdbSizerDlgButtons, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer4 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_lcSources->Connect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( ConnectorSourceDlg::OnSelectDatasource ), NULL, this );
	m_buttonAdd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnAddClick ), NULL, this );
	m_buttonRemove->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnRemoveClick ), NULL, this );
	m_rbTypeSerial->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnTypeSerialSelected ), NULL, this );
	m_rbTypeNet->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnTypeNetSelected ), NULL, this );
	m_rbNetProtoTCP->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetProtocolSelected ), NULL, this );
	m_rbNetProtoUDP->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetProtocolSelected ), NULL, this );
	m_rbNetProtoGPSD->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetProtocolSelected ), NULL, this );
	m_choiceBaudRate->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnBaudrateChoice ), NULL, this );
	m_choiceSerialProtocol->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnProtocolChoice ), NULL, this );
	m_cbCheckCRC->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCrcCheck ), NULL, this );
	m_rbIAccept->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_rbIIgnore->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_btnInputStcList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnIStcs ), NULL, this );
	m_cbOutput->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCbOutput ), NULL, this );
	m_rbOAccept->Connect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbOutput ), NULL, this );
	m_btnOutputStcList->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnOStcs ), NULL, this );
	m_sdbSizerDlgButtonsApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnApplyClick ), NULL, this );
	m_sdbSizerDlgButtonsCancel->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCancelClick ), NULL, this );
	m_sdbSizerDlgButtonsOK->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnOkClick ), NULL, this );
}

ConnectorSourceDlg::~ConnectorSourceDlg()
{
	// Disconnect Events
	m_lcSources->Disconnect( wxEVT_COMMAND_LIST_ITEM_SELECTED, wxListEventHandler( ConnectorSourceDlg::OnSelectDatasource ), NULL, this );
	m_buttonAdd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnAddClick ), NULL, this );
	m_buttonRemove->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnRemoveClick ), NULL, this );
	m_rbTypeSerial->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnTypeSerialSelected ), NULL, this );
	m_rbTypeNet->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnTypeNetSelected ), NULL, this );
	m_rbNetProtoTCP->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetProtocolSelected ), NULL, this );
	m_rbNetProtoUDP->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetProtocolSelected ), NULL, this );
	m_rbNetProtoGPSD->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnNetProtocolSelected ), NULL, this );
	m_choiceBaudRate->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnBaudrateChoice ), NULL, this );
	m_choiceSerialProtocol->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnProtocolChoice ), NULL, this );
	m_cbCheckCRC->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCrcCheck ), NULL, this );
	m_rbIAccept->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_rbIIgnore->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbInput ), NULL, this );
	m_btnInputStcList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnIStcs ), NULL, this );
	m_cbOutput->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnCbOutput ), NULL, this );
	m_rbOAccept->Disconnect( wxEVT_COMMAND_RADIOBUTTON_SELECTED, wxCommandEventHandler( ConnectorSourceDlg::OnRbOutput ), NULL, this );
	m_btnOutputStcList->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnBtnOStcs ), NULL, this );
	m_sdbSizerDlgButtonsApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ConnectorSourceDlg::OnApplyClick ), NULL, this );
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
