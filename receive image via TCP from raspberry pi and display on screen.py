import numpy as np
import cv2
import time
from cv2 import cv
import socket
import sys


if __name__ == "__main__":

      UDP_IP = "192.168.1.130"
      UDP_PORT = 50100

      sock = socket.socket(socket.AF_INET, # Internet
                           socket.SOCK_STREAM) # UDP
      sock.bind(('', UDP_PORT))
      sock.listen(10)
      packet_size = 57600
      c,q = sock.accept()

      while(True):
       d = c.recv(5)
       #print d
       if (d == "start"):
        data = ""
        while True:
           while len(data) < packet_size:
               d = c.recv(1024)
              # print len(d)
              
               data += d
           print len(data)
           print 'here'
           break
        img_str = data
        if len(img_str) == packet_size:       
         #img_str = c.recv(14400)
         #print len(img_str)
         nparr = np.fromstring(img_str, np.uint8).byteswap()
         #frame = cv2.imdecode(nparr, cv2.CV_LOAD_IMAGE_COLOR)
	 #print type(frame)
   #      print " shape = ", nparr.shape()
         #print " size = ", sys.getsizeof(nparr)
	 rm = np.reshape(nparr, (120,160,3),'C')
	 rrm = cv2.resize(rm, (640,480))
         cv2.imshow('frame',rrm)
         if cv2.waitKey(1) & 0xFF == ord('q'):
	   ipCam.close()
           break

