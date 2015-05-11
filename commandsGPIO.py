import time
while True:
	f=open('/sys/class/gpio/gpio2/value','w')
	print f
	f.write('1')
	time.sleep(2)
	f.close()
	print "hi"
	f=open('/sys/class/gpio/gpio2/value','w')
	f.write('0')
	time.sleep(1)
	print "hi2"
	f.close()
