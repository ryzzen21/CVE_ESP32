# Prototype de reception de donnée en RS485 depuis la RPi

import serial
import os
import time

print 'Lancement du programme de lecture ...'

os.system("dmesg | grep FTDI")

print 'Ecoute de la RS485 :'

read = serial.Serial(
        port='/dev/ttyUSB0',
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)
read.flushInput()

while True:
        s = read.read()
        s = s.strip()
        print (s.decode("utf-8"))
        print s
        time.sleep(1.5)
