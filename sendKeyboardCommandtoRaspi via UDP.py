#/usr/bin/python

import sys
import time
import socket
import cv2.cv as cv
import cv2
import numpy as np
import pickle
import curses
import serial

#initialize UDP socket
UDP_IP = "192.168.1.137"
UDP_PORT_send = 12346

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

x=0
x=00
y = 00
stdscr = curses.initscr()
#curses.noecho()
#curses.cbreak()
stdscr.keypad(1)
while(True):
	c = stdscr.getch()
	if c==curses.KEY_RIGHT:
		print 'you entered Right --> ', c
		sock.sendto(str(23), (UDP_IP, UDP_PORT_send))		
	elif c==curses.KEY_UP:
		print 'you entered Up --> ', c
		sock.sendto(str(24), (UDP_IP, UDP_PORT_send))		

	else:
		print 'you entered', c
		sock.sendto(str(c), (UDP_IP, UDP_PORT_send))


while True:

    send.sendto(str(x), (IP, PORT))
    print "i sent",x
    x=x+1
    time.sleep(1)
