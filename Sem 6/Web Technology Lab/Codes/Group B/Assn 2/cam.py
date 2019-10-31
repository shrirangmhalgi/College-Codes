from picamera import PiCamera
from time import sleep

camera=PiCamera()

camera.start_preview()
camera.brightness=70
for i in range(20):
    sleep(1)
    camera.capture('/home/pi/Desktop/image%s.jpg' % i)
camera.stop_preview()






