from time import sleep
from ctb import *
import sys

s=wxSerialPort()
s.Open("com4",115200)
s.Reset()

cmd="*idn?;*opc?\n"
print "send %s" % cmd,
s.Write(cmd)
print s.ReadUntilEOS()

cmd = ":syst:err?\n"
s.Write(cmd)
print "send %s" % cmd,
sleep(1)
print s.Read(5)
print s.GetAvailableBytes()
s.Read(1000)

# test line state switching
s.SetLineState(wxSERIAL_LINESTATE_DTR)
s.ClrLineState(wxSERIAL_LINESTATE_RTS)

print "test line state switching (toggle RTS and DTR)..."
lines = wxSERIAL_LINESTATE_DTR | wxSERIAL_LINESTATE_RTS
for i in range(10):
    s.ChangeLineState(lines)
    sleep(0.2)

# test line state reading
print "test line state reading..."
while 1:
    lines = s.GetLineState()
    if(lines & wxSERIAL_LINESTATE_CTS):
        print "CTS is on"
    else:
        print "CTS is off"
    sleep(0.1)
