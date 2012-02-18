# This file was created automatically by SWIG 1.3.29.
# Don't modify this file, modify the SWIG interface instead.

import _wxctb
import new
new_instancemethod = new.instancemethod
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'PySwigObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static) or hasattr(self,name):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError,name

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

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
        if (name == "thisown"): return self.this.own(value)
        if hasattr(self,name) or (name == "this"):
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
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    usecs = property(_wxctb.timer_control_usecs_get, _wxctb.timer_control_usecs_set)
    exitflag = property(_wxctb.timer_control_exitflag_get, _wxctb.timer_control_exitflag_set)
    exitfnc = property(_wxctb.timer_control_exitfnc_get, _wxctb.timer_control_exitfnc_set)
timer_control_swigregister = _wxctb.timer_control_swigregister
timer_control_swigregister(timer_control)

class timer(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        this = _wxctb.new_timer(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _wxctb.delete_timer
    __del__ = lambda self : None;
    def start(*args, **kwargs): return _wxctb.timer_start(*args, **kwargs)
    def stop(*args, **kwargs): return _wxctb.timer_stop(*args, **kwargs)
timer_swigregister = _wxctb.timer_swigregister
timer_swigregister(timer)

sleepms = _wxctb.sleepms
CTB_RESET = _wxctb.CTB_RESET
class wxIOBase(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_destroy__ = _wxctb.delete_wxIOBase
    __del__ = lambda self : None;
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
wxIOBase_swigregister = _wxctb.wxIOBase_swigregister
wxIOBase_swigregister(wxIOBase)

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
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    baud = property(_wxctb.wxSerialPort_DCS_baud_get, _wxctb.wxSerialPort_DCS_baud_set)
    parity = property(_wxctb.wxSerialPort_DCS_parity_get, _wxctb.wxSerialPort_DCS_parity_set)
    wordlen = property(_wxctb.wxSerialPort_DCS_wordlen_get, _wxctb.wxSerialPort_DCS_wordlen_set)
    stopbits = property(_wxctb.wxSerialPort_DCS_stopbits_get, _wxctb.wxSerialPort_DCS_stopbits_set)
    rtscts = property(_wxctb.wxSerialPort_DCS_rtscts_get, _wxctb.wxSerialPort_DCS_rtscts_set)
    xonxoff = property(_wxctb.wxSerialPort_DCS_xonxoff_get, _wxctb.wxSerialPort_DCS_xonxoff_set)
    def __init__(self, *args, **kwargs): 
        this = _wxctb.new_wxSerialPort_DCS(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _wxctb.delete_wxSerialPort_DCS
    __del__ = lambda self : None;
    def GetSettings(*args, **kwargs): return _wxctb.wxSerialPort_DCS_GetSettings(*args, **kwargs)
wxSerialPort_DCS_swigregister = _wxctb.wxSerialPort_DCS_swigregister
wxSerialPort_DCS_swigregister(wxSerialPort_DCS)

class wxSerialPort_EINFO(object):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    brk = property(_wxctb.wxSerialPort_EINFO_brk_get, _wxctb.wxSerialPort_EINFO_brk_set)
    frame = property(_wxctb.wxSerialPort_EINFO_frame_get, _wxctb.wxSerialPort_EINFO_frame_set)
    overrun = property(_wxctb.wxSerialPort_EINFO_overrun_get, _wxctb.wxSerialPort_EINFO_overrun_set)
    parity = property(_wxctb.wxSerialPort_EINFO_parity_get, _wxctb.wxSerialPort_EINFO_parity_set)
    def __init__(self, *args, **kwargs): 
        this = _wxctb.new_wxSerialPort_EINFO(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
wxSerialPort_EINFO_swigregister = _wxctb.wxSerialPort_EINFO_swigregister
wxSerialPort_EINFO_swigregister(wxSerialPort_EINFO)

CTB_SER_GETEINFO = _wxctb.CTB_SER_GETEINFO
CTB_SER_GETBRK = _wxctb.CTB_SER_GETBRK
CTB_SER_GETFRM = _wxctb.CTB_SER_GETFRM
CTB_SER_GETOVR = _wxctb.CTB_SER_GETOVR
CTB_SER_GETPAR = _wxctb.CTB_SER_GETPAR
CTB_SER_GETINQUE = _wxctb.CTB_SER_GETINQUE
class wxSerialPort_x(wxIOBase):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_destroy__ = _wxctb.delete_wxSerialPort_x
    __del__ = lambda self : None;
    def ClassName(*args, **kwargs): return _wxctb.wxSerialPort_x_ClassName(*args, **kwargs)
    def ChangeLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_ChangeLineState(*args, **kwargs)
    def ClrLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_ClrLineState(*args, **kwargs)
    def GetLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_GetLineState(*args, **kwargs)
    def GetSettingsAsString(*args, **kwargs): return _wxctb.wxSerialPort_x_GetSettingsAsString(*args, **kwargs)
    def Ioctl(*args, **kwargs): return _wxctb.wxSerialPort_x_Ioctl(*args, **kwargs)
    def SendBreak(*args, **kwargs): return _wxctb.wxSerialPort_x_SendBreak(*args, **kwargs)
    def SetBaudRate(*args, **kwargs): return _wxctb.wxSerialPort_x_SetBaudRate(*args, **kwargs)
    def SetLineState(*args, **kwargs): return _wxctb.wxSerialPort_x_SetLineState(*args, **kwargs)
wxSerialPort_x_swigregister = _wxctb.wxSerialPort_x_swigregister
wxSerialPort_x_swigregister(wxSerialPort_x)

wxCOM1 = "/dev/ttyS0"
wxCOM2 = "/dev/ttyS1"
wxCOM3 = "/dev/ttyS2"
wxCOM4 = "/dev/ttyS3"
wxCOM5 = "/dev/ttyS4"
wxCOM6 = "/dev/ttyS5"
wxCOM7 = "/dev/ttyS6"
wxCOM8 = "/dev/ttyS7"
wxCOM9 = "/dev/ttyS8"

class wxSerialPort(wxSerialPort_x):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        this = _wxctb.new_wxSerialPort(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _wxctb.delete_wxSerialPort
    __del__ = lambda self : None;
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
wxSerialPort_swigregister = _wxctb.wxSerialPort_swigregister
wxSerialPort_swigregister(wxSerialPort)

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
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    m_address1 = property(_wxctb.wxGPIB_DCS_m_address1_get, _wxctb.wxGPIB_DCS_m_address1_set)
    m_address2 = property(_wxctb.wxGPIB_DCS_m_address2_get, _wxctb.wxGPIB_DCS_m_address2_set)
    m_timeout = property(_wxctb.wxGPIB_DCS_m_timeout_get, _wxctb.wxGPIB_DCS_m_timeout_set)
    m_eot = property(_wxctb.wxGPIB_DCS_m_eot_get, _wxctb.wxGPIB_DCS_m_eot_set)
    m_eosChar = property(_wxctb.wxGPIB_DCS_m_eosChar_get, _wxctb.wxGPIB_DCS_m_eosChar_set)
    m_eosMode = property(_wxctb.wxGPIB_DCS_m_eosMode_get, _wxctb.wxGPIB_DCS_m_eosMode_set)
    def __init__(self, *args, **kwargs): 
        this = _wxctb.new_wxGPIB_DCS(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    def GetSettings(*args, **kwargs): return _wxctb.wxGPIB_DCS_GetSettings(*args, **kwargs)
wxGPIB_DCS_swigregister = _wxctb.wxGPIB_DCS_swigregister
wxGPIB_DCS_swigregister(wxGPIB_DCS)

CTB_GPIB_SETADR = _wxctb.CTB_GPIB_SETADR
CTB_GPIB_GETRSP = _wxctb.CTB_GPIB_GETRSP
CTB_GPIB_GETSTA = _wxctb.CTB_GPIB_GETSTA
CTB_GPIB_GETERR = _wxctb.CTB_GPIB_GETERR
CTB_GPIB_GETLINES = _wxctb.CTB_GPIB_GETLINES
CTB_GPIB_SETTIMEOUT = _wxctb.CTB_GPIB_SETTIMEOUT
CTB_GPIB_GTL = _wxctb.CTB_GPIB_GTL
CTB_GPIB_REN = _wxctb.CTB_GPIB_REN
CTB_GPIB_RESET_BUS = _wxctb.CTB_GPIB_RESET_BUS
class wxGPIB_x(wxIOBase):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    def __init__(self): raise AttributeError, "No constructor defined"
    __repr__ = _swig_repr
    __swig_destroy__ = _wxctb.delete_wxGPIB_x
    __del__ = lambda self : None;
    def ClassName(*args, **kwargs): return _wxctb.wxGPIB_x_ClassName(*args, **kwargs)
    def GetError(*args, **kwargs): return _wxctb.wxGPIB_x_GetError(*args, **kwargs)
    def Ibrd(*args, **kwargs): return _wxctb.wxGPIB_x_Ibrd(*args, **kwargs)
    def Ibwrt(*args, **kwargs): return _wxctb.wxGPIB_x_Ibwrt(*args, **kwargs)
    def Ioctl(*args, **kwargs): return _wxctb.wxGPIB_x_Ioctl(*args, **kwargs)
    def IsOpen(*args, **kwargs): return _wxctb.wxGPIB_x_IsOpen(*args, **kwargs)
    def Read(*args, **kwargs): return _wxctb.wxGPIB_x_Read(*args, **kwargs)
    def Write(*args, **kwargs): return _wxctb.wxGPIB_x_Write(*args, **kwargs)
    FindListeners = staticmethod(_wxctb.wxGPIB_x_FindListeners)
wxGPIB_x_swigregister = _wxctb.wxGPIB_x_swigregister
wxGPIB_x_swigregister(wxGPIB_x)
wxGPIB_x_FindListeners = _wxctb.wxGPIB_x_FindListeners

class wxGPIB(wxGPIB_x):
    thisown = property(lambda x: x.this.own(), lambda x, v: x.this.own(v), doc='The membership flag')
    __repr__ = _swig_repr
    def __init__(self, *args, **kwargs): 
        this = _wxctb.new_wxGPIB(*args, **kwargs)
        try: self.this.append(this)
        except: self.this = this
    __swig_destroy__ = _wxctb.delete_wxGPIB
    __del__ = lambda self : None;
wxGPIB_swigregister = _wxctb.wxGPIB_swigregister
wxGPIB_swigregister(wxGPIB)



