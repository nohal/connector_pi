from time import sleep
from ctb import *
import sys

s=wxSerialPort()
s.Open("/dev/ttyS0",115200)
s.Reset()

print "test line state switching (toggle RTS and DTR)..."
s.SetLineState(wxSERIAL_LINESTATE_DTR)
s.ClrLineState(wxSERIAL_LINESTATE_RTS)

lines = wxSERIAL_LINESTATE_DTR | wxSERIAL_LINESTATE_RTS

print "%04x" % lines
for i in range(10):
    s.ChangeLineState(lines)
    sleep(0.2)
    
sys.exit(9)


cmd="*idn?;*opc?\n"
print "send %s" % cmd,
s.Write(cmd)
#sleep(1)
print s.ReadUntilEOS()
#print s.Read(100)

cmd = ":syst:err?\n"
s.Write(cmd)
print "send %s" % cmd,
#print s.ReadUntilEOS()
print s.Read(5)
print s.GetAvailableBytes()
s.Read(1000)

# test line state switching
print "test line state switching (toggle RTS and DTR)..."
lines = wxSERIAL_LINESTATE_DTR
for i in range(10):
    s.ChangeLineState(lines)
    sleep(0.2)

sys.exit(0)
# test line state reading
print "test line state reading..."
for i in range(100):
    print s.GetLineState()
    sleep(0.1)
