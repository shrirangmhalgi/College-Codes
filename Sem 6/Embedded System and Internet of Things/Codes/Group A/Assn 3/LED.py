import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(38,GPIO.OUT)
while True:
    print("LED on")
    GPIO.output(38,GPIO.HIGH)
    time.sleep(2)
    GPIO.output(38,GPIO.LOW)
    time.sleep(2)
    print("LED off")