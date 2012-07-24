#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1 //Use the Secure C Runtime in ATL
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN
#endif

#ifndef WINVER
#define WINVER 0x0500
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0500
#endif

#ifndef _WIN32_WINDOWS
#define _WIN32_WINDOWS 0x0500
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0500
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#define _AFX_ALL_WARNINGS // turns off MFC's hiding of some common and often safely ignored warning messages

#include <afxext.h> 
#include <afxtempl.h>

#include <setupapi.h>
#include <malloc.h>
#include <winspool.h>
#include <Wbemcli.h>
#include <comdef.h>
#include <stdio.h>

#include <atlbase.h>

//#define CENUMERATESERIAL_USE_STL //Uncomment this line if you want to test the STL support in CEnumerateSerial

#ifdef CENUMERATESERIAL_USE_STL
#include <vector>
#include <string>
#endif