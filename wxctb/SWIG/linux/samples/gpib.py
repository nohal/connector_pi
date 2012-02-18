from time import sleep
from ctb import *
import sys

g=wxGPIB()
g.Open("gpib1",1)
#g.Write("*idn?\n")
g.Write("calc:form?\n")
#sleep(1)
print g.ReadUntilEOS("\n",1000,"\"")
#print g.Read(100)

g.Write("*idn?\n")
print g.ReadUntilEOS("\n",1000)
