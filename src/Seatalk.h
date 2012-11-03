/******************************************************************************
* 
*
* Project:  OpenCPN
* Purpose:  Connector Plugin/Seatalk
* Author:   Gilles Audemard
*
***************************************************************************
*   Copyright (C) 2012 by Gilles Audemard   *
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

#ifndef _Seatalk_H_
#define _Seatalk_H_

#include "wx/wxprec.h"
#include "wx/ctb/serport.h"

#ifndef  WX_PRECOMP
#include "wx/wx.h"
#endif //precompiled headers

#include "connector_pi.h"



//Forward declarations

class SerialConnection;
class ConnectionHandler;

//Type definitions



//----------------------------------------------------------------------------------------------------------
//    Connection parameters class
//----------------------------------------------------------------------------------------------------------
class StkSerialConnection : public SerialConnection
{
public:

	StkSerialConnection(ConnectionHandler *handler) ;
	~StkSerialConnection();
	
    void PushBuffer(const char * b, unsigned int l);
	
private:

	void stk(unsigned char tre[255]);
	void seatalk(unsigned char d, bool cde) ;
	bool getParity(unsigned int n);
	void received(const char *data, unsigned int len);
	wxString m_sbuffer;
    unsigned long vent ;
	float HeadingMag;
	float Cog;
	float Sow;
};

#endif