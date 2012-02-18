#!/usr/bin/python

from wxctb import *
import sys

quit=new_intp()
intp_assign(quit, 0)
t=timer(2000,quit)
t.start()

while intp_value(quit)==0:
    print "."
    sleepms(100)
    
delete_intp(quit)
sys.exit(0)
