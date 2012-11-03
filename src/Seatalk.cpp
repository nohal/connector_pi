

#include "Seatalk.h"

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <wx/string.h>
#include <vector>



#include "cnmea0183/nmea0183.h"

using namespace std;




StkSerialConnection::StkSerialConnection(ConnectionHandler *handler):SerialConnection(handler) 
{
	
}

StkSerialConnection::~StkSerialConnection()
{ 
}
void StkSerialConnection::stk(unsigned char tre[255])
{
	CNMEA0183 cm_nmea ;
	float t;
	int r;
	SENTENCE snt ;
	wxString unit;
	wxString tk;
	
	tk = wxT("EC");
	cm_nmea.TalkerID= tk ;
	
switch (tre[0])
{
	
		case 0x27 :  //Water temp
		t =  (float)((tre[3]*256 + tre[2])-100)/10 ;
			cm_nmea.Mtw.Empty();
			cm_nmea.Mtw.Temperature= t;
			unit = wxT("C");
			cm_nmea.Mtw.UnitOfMeasurement = unit;
			cm_nmea.Mtw.Write(snt);
			m_buffer.Append(snt.Sentence);
			break;
			
		case 0x10 : // ApW direction
			vent =  ((unsigned long)(tre[2]*256 +(unsigned long) tre[3]))/2 ;
		break;
		case 0x11 : // ApW direction
		//(XX & 0x7F) + Y/10 Knots
			t =  ((float)(tre[2]& 0x7F) +( (float) tre[3]/10)) ;
			cm_nmea.Mwv.Empty();
			cm_nmea.Mwv.WindAngle= vent;
			unit = wxT("R");
			cm_nmea.Mwv.Reference = unit;
			cm_nmea.Mwv.WindSpeed= t;
			if ((tre[2]& 0x80) ==0)cm_nmea.Mwv.WindSpeedUnits= wxT("K");
			cm_nmea.Mwv.IsDataValid = NTrue;
			cm_nmea.Mwv.Write(snt);
			m_buffer.Append(snt.Sentence);
		break;
		
		case 0x00 : // depth
			t =  ((float)tre[4]*256 +(float) tre[3])/10 ;
			cm_nmea.Dpt.Empty();
			cm_nmea.Dpt.DepthMeters = t * 0.3 ;
			cm_nmea.Dpt.OffsetFromTransducerMeters = 0;
			cm_nmea.Dpt.Write(snt);
			m_buffer.Append(snt.Sentence);
		break;
		
		case 0x84 :
		HeadingMag =   ((tre[1]>>4) & 0x3)* 90 + (tre[2] & 0x3F)* 2 ;
		
		break;
		
		case 0x53 :
		Cog =   ((tre[1]>>4) & 0x3)* 90 + (tre[2] & 0x3F)* 2 + (float)((tre[1])>>4 & 0xc)/ 2;
		break;
		case 0x20 :
		Sow =  ((float)tre[3]*256 +(float) tre[2])/10 ;
		cm_nmea.Vhw.DegreesTrue       = Cog;
        cm_nmea.Vhw.DegreesMagnetic   = HeadingMag;
        cm_nmea.Vhw.Knots             = Sow;
        cm_nmea.Vhw.KilometersPerHour = Sow *1.852;
		cm_nmea.Vhw.Write(snt);
		m_buffer.Append(snt.Sentence);
		break;
		
		
		case 0x99 : // hdg
		r= (int)(signed char)tre[2];
		cm_nmea.Hdg.Empty();
		if (r>0)
		{
				cm_nmea.Hdg.MagneticVariationDegrees = abs(r)  ;
				cm_nmea.Hdg.MagneticVariationDirection = West  ;
			}
		else
			{
				cm_nmea.Hdg.MagneticVariationDegrees = abs(r)  ;
				cm_nmea.Hdg.MagneticVariationDirection = East  ;
			}
		break;
		case 0x9c : // hdg
		HeadingMag =   ((tre[1]>>4) & 0x3)* 90 + (tre[2] & 0x3F)* 2 ;
		cm_nmea.Hdg.MagneticSensorHeadingDegrees = HeadingMag  ;
		cm_nmea.Hdg.MagneticDeviationDegrees  = 0  ;
		cm_nmea.Hdg.MagneticDeviationDirection = East  ;
		cm_nmea.Hdg.Write(snt);
		m_buffer.Append(snt.Sentence);
		break;
		
		default:
		break;
			
		
} // end switch
}
void StkSerialConnection::seatalk(unsigned char d, bool cde)   
{
	static unsigned int cpt;
	static int len ;
	static unsigned char tr[255];
	int i;
	wxString recu ;
	static bool b=false ;
	//char hex[]="0123456789ABCDEF";
	
	if (cde)
	{ 
		cpt = 255;
		tr[0]= d;
		b= true ;
		
	}else
	{
	if (b){
		if (cpt == 254)	{
			len = (d & 0x0f)+2;
			cpt = len;
			}
		tr[(len -cpt)+1]= d ;
		}	
	}
	if ( !--cpt and b ){
		recu.Clear();
		recu += wxT("** Con_ga ** " );
		for (i=0;i<=len;i++)
			{
				recu += wxString::Format(_T("%2x"),tr[i]);
				recu += wxString::FromAscii( ' ');
			}
		stk(tr);
		wxLogMessage(recu);
		b=false; //debug
	} ; // commande complete
}
	
	/* Function to get parity of number n. It returns 1
   if n has odd parity, and returns 0 if n has even
   parity */
	
bool StkSerialConnection::getParity(unsigned int n)
{
    bool parity = 0;
    while (n)
    {
        parity = !parity;
        n      = n & (n - 1);
    }
    return !parity;
}
void StkSerialConnection::PushBuffer( const char *b, unsigned int l )
{
	// Stealk to NMEA0183 conversion
    
	received( b,l );
	
	//
    int boundary = SentenceBoundary();
    while( boundary > -1 )
    {
        wxString msg = m_buffer.Left( boundary );
        m_buffer.Remove( 0, boundary + m_EOS.Length() );
        //TODO: honor the CRC if we should
        if ( FilterInput( msg, m_portName ) )
            m_pHandler->DistributeNMEAMessage( msg, m_portName );
        boundary = SentenceBoundary();
    }
}

// 


void StkSerialConnection::received(const char *data, unsigned int len)
{
	vector< unsigned char > v(data,data+len);
	
    for(unsigned int i=0;i<v.size();i++)
    {
      if ((v[i]== 0xff) & (v[i+1]== 0x00) ) /*  erreur parity impaire */
	  { 
		  if ( getParity(v[i+2]) )
		  { // even cde
				seatalk(v[i+2],1);
			  }else 
				  { //odd data
				seatalk(v[i+2],0);
					  }
		  i++;
		  i++;
		  }else //pas d'erreur parity paire
		{
		if ( getParity(v[i])) 
		  { // even data
				seatalk(v[i],0);
			  }else 
				  { //odd cde
					seatalk(v[i],1);
					  }
		}
    }
}


