import time
import socket
import sys
import math
import serial 
#ser = serial.Serial('/dev/ttyAMA0', 57600)

if __name__ == "__main__":
## ---------- UDP Start ---------------
      UDP_IP = "192.168.1.137"
      UDP_PORT = 12346
#      MESSAGE = "Hello, World!"
      sock = socket.socket(socket.AF_INET, # Internet
                           socket.SOCK_DGRAM) # UDP
      sock.bind((UDP_IP, UDP_PORT))
## ---------- UDP End -----------------
x=00
y = 00
while(True):
	y, addr = sock.recvfrom(3) # buffer size is 1024 bytes 
	print "client received =",y
	x=int(y)
	print "client received =",x
	if x==97:
		print 'you entered Right --> ', x
		f=open('/sys/class/gpio/gpio2/value','w')
		print f
		f.write('1')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio3/value','w')
		print f
		f.write('0')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio4/value','w')
		print f
		f.write('0')
		time.sleep(.1)
		f.close()

	elif x==122:
		print 'you entered Up --> ', x
		f=open('/sys/class/gpio/gpio2/value','w')
		print f
		f.write('0')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio3/value','w')
		print f
		f.write('0')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio4/value','w')
		print f
		f.write('0')
		time.sleep(.1)
		f.close()

	elif x==119:
		print 'you entered Down --> ', x
		f=open('/sys/class/gpio/gpio2/value','w')
		print f
		f.write('0')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio3/value','w')
		print f
		f.write('1')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio4/value','w')
		print f
		f.write('0')
		time.sleep(.1)
		f.close()

	elif x==100:
		print 'you entered Left --> ', x
		f=open('/sys/class/gpio/gpio2/value','w')
		print f
		f.write('1')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio3/value','w')
		print f
		f.write('1')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio4/value','w')
		print f
		f.write('0')
		time.sleep(.1)
		f.close()
	elif x==115:
		print 'you entered STOP --> ', x
		f=open('/sys/class/gpio/gpio2/value','w')
		print f
		f.write('1')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio3/value','w')
		print f
		f.write('1')
		time.sleep(0)
		f.close()
		f=open('/sys/class/gpio/gpio4/value','w')
		print f
		f.write('1')
		time.sleep(.1)
		f.close()

	time.sleep(.2)	
	#	ser.write(str(x))





