# This file was created automatically by SWIG.
# Don't modify this file, modify the SWIG interface instead.

import _wxctb

def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "this"):
        if isinstance(value, class_type):
            self.__dict__[name] = value.this
            if hasattr(value,"thisown"): self.__dict__["thisown"] = value.thisown
            del value.thisown
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name) or (name == "thisown"):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

import types
try:
    _object = types.ObjectType
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0
del types


def _swig_setattr_nondynamic_method(set):
    def set_attr(self,name,value):
        if hasattr(self,name) or (name in ("this", "thisown")):
            set(self,name,value)
        else:
            raise AttributeError("You cannot add attributes to %s" % self)
    return set_attr



new_intp = _wxctb.new_intp

copy_intp = _wxctb.copy_intp

delete_intp = _wxctb.delete_intp

intp_assign = _wxctb.intp_assign

intp_value = _wxctb.intp_value
class timer_control(object):
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ timer_control instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    msecs = property(_wxctb.timer_control_msecs_get, _wxctb.timer_control_msecs_set)
    exitflag = property(_wxctb.timer_control_exitflag_get, _wxctb.timer_control_exitflag_set)
    stop = property(_wxctb.timer_control_stop_get, _wxctb.timer_control_stop_set)
    exitfnc = property(_wxctb.timer_control_exitfnc_get, _wxctb.timer_control_exitfnc_set)

class timer_controlPtr(timer_control):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = timer_control
_wxctb.timer_control_swigregister(timer_controlPtr)

class timer(object):
    def __repr__(self):
        return "<%s.%s; proxy of C++ timer instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        newobj = _wxctb.new_timer(*args, **kwargs)
        self.this = newobj.this
        self.thisown = 1
        del newobj.thisown
    def __del__(self, destroy=_wxctb.delete_timer):
        try:
            if self.thisown: destroy(self)
        except: pass

    def start(*args, **kwargs): return _wxctb.timer_start(*args, **kwargs)
    def stop(*args, **kwargs): return _wxctb.timer_stop(*args, **kwargs)

class timerPtr(timer):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = timer
_wxctb.timer_swigregister(timerPtr)


sleepms = _wxctb.sleepms
CTB_RESET = _wxctb.CTB_RESET
class wxIOBase(object):
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxIOBase instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_wxctb.delete_wxIOBase):
        try:
            if self.thisown: destroy(self)
        except: pass

    def ClassName(*args, **kwargs): return _wxctb.wxIOBase_ClassName(*args, **kwargs)
    def Close(*args, **kwargs): return _wxctb.wxIOBase_Close(*args, **kwargs)
    def Ioctl(*args, **kwargs): return _wxctb.wxIOBase_Ioctl(*args, **kwargs)
    def IsOpen(*args, **kwargs): return _wxctb.wxIOBase_IsOpen(*args, **kwargs)
    def Open(*args, **kwargs): return _wxctb.wxIOBase_Open(*args, **kwargs)
    def PutBack(*args, **kwargs): return _wxctb.wxIOBase_PutBack(*args, **kwargs)
    def Read(*args, **kwargs): return _wxctb.wxIOBase_Read(*args, **kwargs)
    def ReadUntilEOS(*args, **kwargs): return _wxctb.wxIOBase_ReadUntilEOS(*args, **kwargs)
    def Readv(*args, **kwargs): return _wxctb.wxIOBase_Readv(*args, **kwargs)
    def Write(*args, **kwargs): return _wxctb.wxIOBase_Write(*args, **kwargs)
    def Writev(*args, **kwargs): return _wxctb.wxIOBase_Writev(*args, **kwargs)

class wxIOBasePtr(wxIOBase):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxIOBase
_wxctb.wxIOBase_swigregister(wxIOBasePtr)

wxBAUD_150 = _wxctb.wxBAUD_150
wxBAUD_300 = _wxctb.wxBAUD_300
wxBAUD_600 = _wxctb.wxBAUD_600
wxBAUD_1200 = _wxctb.wxBAUD_1200
wxBAUD_2400 = _wxctb.wxBAUD_2400
wxBAUD_4800 = _wxctb.wxBAUD_4800
wxBAUD_9600 = _wxctb.wxBAUD_9600
wxBAUD_19200 = _wxctb.wxBAUD_19200
wxBAUD_38400 = _wxctb.wxBAUD_38400
wxBAUD_57600 = _wxctb.wxBAUD_57600
wxBAUD_115200 = _wxctb.wxBAUD_115200
wxBAUD_230400 = _wxctb.wxBAUD_230400
wxBAUD_460800 = _wxctb.wxBAUD_460800
wxBAUD_921600 = _wxctb.wxBAUD_921600
wxPARITY_NONE = _wxctb.wxPARITY_NONE
wxPARITY_ODD = _wxctb.wxPARITY_ODD
wxPARITY_EVEN = _wxctb.wxPARITY_EVEN
wxPARITY_MARK = _wxctb.wxPARITY_MARK
wxPARITY_SPACE = _wxctb.wxPARITY_SPACE
wxSERIAL_LINESTATE_DCD = _wxctb.wxSERIAL_LINESTATE_DCD
wxSERIAL_LINESTATE_CTS = _wxctb.wxSERIAL_LINESTATE_CTS
wxSERIAL_LINESTATE_DSR = _wxctb.wxSERIAL_LINESTATE_DSR
wxSERIAL_LINESTATE_DTR = _wxctb.wxSERIAL_LINESTATE_DTR
wxSERIAL_LINESTATE_RING = _wxctb.wxSERIAL_LINESTATE_RING
wxSERIAL_LINESTATE_RTS = _wxctb.wxSERIAL_LINESTATE_RTS
wxSERIAL_LINESTATE_NULL = _wxctb.wxSERIAL_LINESTATE_NULL
class wxSerialPort_DCS(object):
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxSerialPort_DCS instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    baud = property(_wxctb.wxSerialPort_DCS_baud_get, _wxctb.wxSerialPort_DCS_baud_set)
    parity = property(_wxctb.wxSerialPort_DCS_parity_get, _wxctb.wxSerialPort_DCS_parity_set)
    wordlen = property(_wxctb.wxSerialPort_DCS_wordlen_get, _wxctb.wxSerialPort_DCS_wordlen_set)
    stopbits = property(_wxctb.wxSerialPort_DCS_stopbits_get, _wxctb.wxSerialPort_DCS_stopbits_set)
    rtscts = property(_wxctb.wxSerialPort_DCS_rtscts_get, _wxctb.wxSerialPort_DCS_rtscts_set)
    xonxoff = property(_wxctb.wxSerialPort_DCS_xonxoff_get, _wxctb.wxSerialPort_DCS_xonxoff_set)
    def __init__(self, *args, **kwargs):
        newobj = _wxctb.new_wxSerialPort_DCS(*args, **kwargs)
        self.this = newobj.this
        self.thisown = 1
        del newobj.thisown
    def __del__(self, destroy=_wxctb.delete_wxSerialPort_DCS):
        try:
            if self.thisown: destroy(self)
        except: pass

    def GetSettings(*args, **kwargs): return _wxctb.wxSerialPort_DCS_GetSettings(*args, **kwargs)

class wxSerialPort_DCSPtr(wxSerialPort_DCS):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxSerialPort_DCS
_wxctb.wxSerialPort_DCS_swigregister(wxSerialPort_DCSPtr)

class wxSerialPort_EINFO(object):
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxSerialPort_EINFO instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    brk = property(_wxctb.wxSerialPort_EINFO_brk_get, _wxctb.wxSerialPort_EINFO_brk_set)
    frame = property(_wxctb.wxSerialPort_EINFO_frame_get, _wxctb.wxSerialPort_EINFO_frame_set)
    overrun = property(_wxctb.wxSerialPort_EINFO_overrun_get, _wxctb.wxSerialPort_EINFO_overrun_set)
    parity = property(_wxctb.wxSerialPort_EINFO_parity_get, _wxctb.wxSerialPort_EINFO_parity_set)
    def __init__(self, *args, **kwargs):
        newobj = _wxctb.new_wxSerialPort_EINFO(*args, **kwargs)
        self.this = newobj.this
        self.thisown = 1
        del newobj.thisown

class wxSerialPort_EINFOPtr(wxSerialPort_EINFO):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxSerialPort_EINFO
_wxctb.wxSerialPort_EINFO_swigregister(wxSerialPort_EINFOPtr)

CTB_SER_GETEINFO = _wxctb.CTB_SER_GETEINFO
CTB_SER_GETBRK = _wxctb.CTB_SER_GETBRK
CTB_SER_GETFRM = _wxctb.CTB_SER_GETFRM
CTB_SER_GETOVR = _wxctb.CTB_SER_GETOVR
CTB_SER_GETPAR = _wxctb.CTB_SER_GETPAR
CTB_SER_GETINQUE = _wxctb.CTB_SER_GETINQUE
class wxSerialPort_x(wxIOBase):
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxSerialPort_x instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_wxctb.delete_wxSerialPort_x):
        try:
            if self.thisown: destroy(self)
        except: pass

    def ClassName(*args, **kwargs): return _wxctb.wxSerialPort_x_ClassName(*args, **kwargs)
    def ChangeLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_ChangeLineState(*args, **kwargs)
    def ClrLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_ClrLineState(*args, **kwargs)
    def GetLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_GetLineState(*args, **kwargs)
    def GetSettingsAsString(*args, **kwargs): return _wxctb.wxSerialPort_x_GetSettingsAsString(*args, **kwargs)
    def Ioctl(*args, **kwargs): return _wxctb.wxSerialPort_x_Ioctl(*args, **kwargs)
    def SendBreak(*args, **kwargs): return _wxctb.wxSerialPort_x_SendBreak(*args, **kwargs)
    def SetBaudRate(*args, **kwargs): return _wxctb.wxSerialPort_x_SetBaudRate(*args, **kwargs)
    def SetLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_SetLineState(*args, **kwargs)

class wxSerialPort_xPtr(wxSerialPort_x):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxSerialPort_x
_wxctb.wxSerialPort_x_swigregister(wxSerialPort_xPtr)

wxCOM1 = "com1"
wxCOM2 = "com2"
wxCOM3 = "com3"
wxCOM4 = "com4"
wxCOM5 = "com5"
wxCOM6 = "com6"
wxCOM7 = "com7"
wxCOM8 = "com8"
wxCOM9 = "com9"
wxCOM10 = "\\\\.\\com10"
wxCOM11 = "\\\\.\\com11"
wxCOM12 = "\\\\.\\com12"
wxCOM13 = "\\\\.\\com13"
wxCOM14 = "\\\\.\\com14"
wxCOM15 = "\\\\.\\com15"
wxCOM16 = "\\\\.\\com16"	

class wxSerialPort(wxSerialPort_x):
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxSerialPort instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        newobj = _wxctb.new_wxSerialPort(*args, **kwargs)
        self.this = newobj.this
        self.thisown = 1
        del newobj.thisown
    def __del__(self, destroy=_wxctb.delete_wxSerialPort):
        try:
            if self.thisown: destroy(self)
        except: pass

    def ChangeLineState(*args, **kwargs): return _wxctb.wxSerialPort_ChangeLineState(*args, **kwargs)
    def ClrLineState(*args, **kwargs): return _wxctb.wxSerialPort_ClrLineState(*args, **kwargs)
    def GetLineState(*args, **kwargs): return _wxctb.wxSerialPort_GetLineState(*args, **kwargs)
    def GetSettingsAsString(*args, **kwargs): return _wxctb.wxSerialPort_GetSettingsAsString(*args, **kwargs)
    def Ioctl(*args, **kwargs): return _wxctb.wxSerialPort_Ioctl(*args, **kwargs)
    def IsOpen(*args, **kwargs): return _wxctb.wxSerialPort_IsOpen(*args, **kwargs)
    def Read(*args, **kwargs): return _wxctb.wxSerialPort_Read(*args, **kwargs)
    def SendBreak(*args, **kwargs): return _wxctb.wxSerialPort_SendBreak(*args, **kwargs)
    def SetBaudRate(*args, **kwargs): return _wxctb.wxSerialPort_SetBaudRate(*args, **kwargs)
    def SetLineState(*args, **kwargs): return _wxctb.wxSerialPort_SetLineState(*args, **kwargs)
    def Write(*args, **kwargs): return _wxctb.wxSerialPort_Write(*args, **kwargs)

class wxSerialPortPtr(wxSerialPort):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxSerialPort
_wxctb.wxSerialPort_swigregister(wxSerialPortPtr)


GetKey = _wxctb.GetKey
wxGPIB_TO_NONE = _wxctb.wxGPIB_TO_NONE
wxGPIB_TO_10us = _wxctb.wxGPIB_TO_10us
wxGPIB_TO_30us = _wxctb.wxGPIB_TO_30us
wxGPIB_TO_100us = _wxctb.wxGPIB_TO_100us
wxGPIB_TO_300us = _wxctb.wxGPIB_TO_300us
wxGPIB_TO_1ms = _wxctb.wxGPIB_TO_1ms
wxGPIB_TO_3ms = _wxctb.wxGPIB_TO_3ms
wxGPIB_TO_10ms = _wxctb.wxGPIB_TO_10ms
wxGPIB_TO_30ms = _wxctb.wxGPIB_TO_30ms
wxGPIB_TO_100ms = _wxctb.wxGPIB_TO_100ms
wxGPIB_TO_300ms = _wxctb.wxGPIB_TO_300ms
wxGPIB_TO_1s = _wxctb.wxGPIB_TO_1s
wxGPIB_TO_3s = _wxctb.wxGPIB_TO_3s
wxGPIB_TO_10s = _wxctb.wxGPIB_TO_10s
wxGPIB_TO_30s = _wxctb.wxGPIB_TO_30s
wxGPIB_TO_100s = _wxctb.wxGPIB_TO_100s
wxGPIB_TO_300s = _wxctb.wxGPIB_TO_300s
wxGPIB_TO_1000s = _wxctb.wxGPIB_TO_1000s
class wxGPIB_DCS(object):
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxGPIB_DCS instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    m_address1 = property(_wxctb.wxGPIB_DCS_m_address1_get, _wxctb.wxGPIB_DCS_m_address1_set)
    m_address2 = property(_wxctb.wxGPIB_DCS_m_address2_get, _wxctb.wxGPIB_DCS_m_address2_set)
    m_timeout = property(_wxctb.wxGPIB_DCS_m_timeout_get, _wxctb.wxGPIB_DCS_m_timeout_set)
    m_eot = property(_wxctb.wxGPIB_DCS_m_eot_get, _wxctb.wxGPIB_DCS_m_eot_set)
    m_eosChar = property(_wxctb.wxGPIB_DCS_m_eosChar_get, _wxctb.wxGPIB_DCS_m_eosChar_set)
    m_eosMode = property(_wxctb.wxGPIB_DCS_m_eosMode_get, _wxctb.wxGPIB_DCS_m_eosMode_set)
    def __init__(self, *args, **kwargs):
        newobj = _wxctb.new_wxGPIB_DCS(*args, **kwargs)
        self.this = newobj.this
        self.thisown = 1
        del newobj.thisown
    def GetSettings(*args, **kwargs): return _wxctb.wxGPIB_DCS_GetSettings(*args, **kwargs)

class wxGPIB_DCSPtr(wxGPIB_DCS):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxGPIB_DCS
_wxctb.wxGPIB_DCS_swigregister(wxGPIB_DCSPtr)

CTB_GPIB_SETADR = _wxctb.CTB_GPIB_SETADR
CTB_GPIB_GETRSP = _wxctb.CTB_GPIB_GETRSP
CTB_GPIB_GETSTA = _wxctb.CTB_GPIB_GETSTA
CTB_GPIB_GETERR = _wxctb.CTB_GPIB_GETERR
CTB_GPIB_GETLINES = _wxctb.CTB_GPIB_GETLINES
CTB_GPIB_SETTIMEOUT = _wxctb.CTB_GPIB_SETTIMEOUT
CTB_GPIB_GTL = _wxctb.CTB_GPIB_GTL
CTB_GPIB_REN = _wxctb.CTB_GPIB_REN
CTB_GPIB_RESET_BUS = _wxctb.CTB_GPIB_RESET_BUS
CTB_GPIB_FIND_LISTENERS = _wxctb.CTB_GPIB_FIND_LISTENERS
class wxGPIB_x(wxIOBase):
    def __init__(self): raise RuntimeError, "No constructor defined"
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxGPIB_x instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __del__(self, destroy=_wxctb.delete_wxGPIB_x):
        try:
            if self.thisown: destroy(self)
        except: pass

    def ClassName(*args, **kwargs): return _wxctb.wxGPIB_x_ClassName(*args, **kwargs)
    def GetError(*args, **kwargs): return _wxctb.wxGPIB_x_GetError(*args, **kwargs)
    def Ibrd(*args, **kwargs): return _wxctb.wxGPIB_x_Ibrd(*args, **kwargs)
    def Ibwrt(*args, **kwargs): return _wxctb.wxGPIB_x_Ibwrt(*args, **kwargs)
    def Ioctl(*args, **kwargs): return _wxctb.wxGPIB_x_Ioctl(*args, **kwargs)
    def IsOpen(*args, **kwargs): return _wxctb.wxGPIB_x_IsOpen(*args, **kwargs)
    def Read(*args, **kwargs): return _wxctb.wxGPIB_x_Read(*args, **kwargs)
    def Write(*args, **kwargs): return _wxctb.wxGPIB_x_Write(*args, **kwargs)

class wxGPIB_xPtr(wxGPIB_x):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxGPIB_x
_wxctb.wxGPIB_x_swigregister(wxGPIB_xPtr)

class wxGPIB(wxGPIB_x):
    def __repr__(self):
        return "<%s.%s; proxy of C++ wxGPIB instance at %s>" % (self.__class__.__module__, self.__class__.__name__, self.this,)
    def __init__(self, *args, **kwargs):
        newobj = _wxctb.new_wxGPIB(*args, **kwargs)
        self.this = newobj.this
        self.thisown = 1
        del newobj.thisown
    def __del__(self, destroy=_wxctb.delete_wxGPIB):
        try:
            if self.thisown: destroy(self)
        except: pass


class wxGPIBPtr(wxGPIB):
    def __init__(self, this):
        self.this = this
        if not hasattr(self,"thisown"): self.thisown = 0
        self.__class__ = wxGPIB
_wxctb.wxGPIB_swigregister(wxGPIBPtr)


