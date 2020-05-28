# Prototype pour transmission de donnée en RS485 depuis la RPi

import time
import serial
import os

os.system("dmesg | grep FTDI")

send = serial.Serial(
        port='/dev/ttyUSB0',
        baudrate = 9600,
        parity=serial.PARITY_NONE,
        stopbits=serial.STOPBITS_ONE,
        bytesize=serial.EIGHTBITS,
        timeout=1
)

while True:
        msg = raw_input("Veuillez entrer un message : ")
        send.write(str(msg))
        print("Message envoye")
        time.sleep(1.5)
