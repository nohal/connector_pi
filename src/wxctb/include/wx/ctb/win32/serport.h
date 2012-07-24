/////////////////////////////////////////////////////////////////////////////
// Name:        win32/serport.h
// Purpose:
// Author:      Joachim Buermann
// Id:          $Id: serport.h,v 1.1.1.1 2004/11/24 10:30:11 jb Exp $
// Copyright:   (c) 2001 Joachim Buermann
// Licence:     wxWindows licence
/////////////////////////////////////////////////////////////////////////////

#ifndef _WX_SERIALPORT_WIN32_H
#define _WX_SERIALPORT_WIN32_H

#include "../serportx.h"
#include <windows.h>

#define wxCOM1 "com1"
#define wxCOM2 "com2"
#define wxCOM3 "com3"
#define wxCOM4 "com4"
#define wxCOM5 "com5"
#define wxCOM6 "com6"
#define wxCOM7 "com7"
#define wxCOM8 "com8"
#define wxCOM9 "com9"
#define wxCOM10 "\\\\.\\com10"
#define wxCOM11 "\\\\.\\com11"
#define wxCOM12 "\\\\.\\com12"
#define wxCOM13 "\\\\.\\com13"
#define wxCOM14 "\\\\.\\com14"
#define wxCOM15 "\\\\.\\com15"
#define wxCOM16 "\\\\.\\com16"
#define wxCOM17 "\\\\.\\com17"
#define wxCOM18 "\\\\.\\com18"
#define wxCOM19 "\\\\.\\com19"
#define wxCOM20 "\\\\.\\com20"
#define wxCOM21 "\\\\.\\com21"
#define wxCOM22 "\\\\.\\com22"
#define wxCOM23 "\\\\.\\com23"
#define wxCOM24 "\\\\.\\com24"
#define wxCOM25 "\\\\.\\com25"
#define wxCOM26 "\\\\.\\com26"
#define wxCOM27 "\\\\.\\com27"
#define wxCOM28 "\\\\.\\com28"
#define wxCOM29 "\\\\.\\com29"
#define wxCOM30 "\\\\.\\com30"
#define wxCOM31 "\\\\.\\com31"
#define wxCOM32 "\\\\.\\com32"
#define wxCOM33 "\\\\.\\com33"
#define wxCOM34 "\\\\.\\com34"
#define wxCOM35 "\\\\.\\com35"
#define wxCOM36 "\\\\.\\com36"
#define wxCOM37 "\\\\.\\com37"
#define wxCOM38 "\\\\.\\com38"
#define wxCOM39 "\\\\.\\com39"
#define wxCOM40 "\\\\.\\com40"
#define wxCOM41 "\\\\.\\com41"
#define wxCOM42 "\\\\.\\com42"
#define wxCOM43 "\\\\.\\com43"
#define wxCOM44 "\\\\.\\com44"
#define wxCOM45 "\\\\.\\com45"
#define wxCOM46 "\\\\.\\com46"
#define wxCOM47 "\\\\.\\com47"
#define wxCOM48 "\\\\.\\com48"
#define wxCOM49 "\\\\.\\com49"
#define wxCOM50 "\\\\.\\com50"
#define wxCOM51 "\\\\.\\com51"
#define wxCOM52 "\\\\.\\com52"
#define wxCOM53 "\\\\.\\com53"
#define wxCOM54 "\\\\.\\com54"
#define wxCOM55 "\\\\.\\com55"
#define wxCOM56 "\\\\.\\com56"
#define wxCOM57 "\\\\.\\com57"
#define wxCOM58 "\\\\.\\com58"
#define wxCOM59 "\\\\.\\com59"
#define wxCOM60 "\\\\.\\com60"
#define wxCOM61 "\\\\.\\com61"
#define wxCOM62 "\\\\.\\com62"
#define wxCOM63 "\\\\.\\com63"
#define wxCOM64 "\\\\.\\com64"
#define wxCOM65 "\\\\.\\com65"
#define wxCOM66 "\\\\.\\com66"
#define wxCOM67 "\\\\.\\com67"
#define wxCOM68 "\\\\.\\com68"
#define wxCOM69 "\\\\.\\com69"

/*!
   \class wxSerialPort
   
   \brief the win32 version
*/
class wxSerialPort : public wxSerialPort_x
{
protected:
    /*!
      \brief the win32 api equivalent for the Linux
      file descriptor
    */
    HANDLE fd;
    /*!
      \brief a very special struct in the win32 api for controling
      an asynchronous serial communication through the com ports.
    */
    OVERLAPPED ov;

    /*!
      \brief The win32 API only allows to test for an existing
      break, framing, overrun or parity, not for the occured numbers.
      So every error event decrement this internal error struct and
      can request by an Ioctl call.
    */
    wxSerialPort_EINFO einfo;
    
    /*!
	 \brief The win32 API doesn't have any function to detect the
	 current state of the output lines RST and DTR (if someone knows
	 some function, please contact me).
	 So we save the state always after changing one or both lines
	 (for example, on Open, SetLineState and ChangeLineState)
    */
    int m_rtsdtr_state;

    int CloseDevice();
    int OpenDevice(const char* devname, void* dcs);
public:
    wxSerialPort();
    ~wxSerialPort();

    int ChangeLineState(wxSerialLineState flags);
    int ClrLineState(wxSerialLineState flags);
    int GetLineState();
    int GetSettingsAsString(char* str, size_t size);
    int Ioctl(int cmd,void* args);
    int IsOpen();
    int Read(char* buf,size_t len);
    int SendBreak(int duration);
    int SetBaudRate(wxBaud baudrate);
    int SetLineState(wxSerialLineState flags);
    int Write(char* buf,size_t len);
};

#endif
