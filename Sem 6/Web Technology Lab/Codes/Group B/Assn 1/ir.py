import RPi.GPIO as pi
import time
#pi.setwarnings(False)
pi.setmode(pi.BOARD)
pi.setup(11,pi.OUT)
pi.setup(7,pi.IN)
pi.output(11,False)
while 1:
    time.sleep(1)
    print(pi.input(7))
    if(pi.input(7)==0):
        pi.output(11,True)
    if(pi.input(7)==1):
        pi.output(11,False)
            


