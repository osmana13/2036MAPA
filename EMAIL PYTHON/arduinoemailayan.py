import serial 
import time
import os

import smtplib
print("server")
server = smtplib.SMTP('smtp.gmail.com', 587)

server.starttls()

print("logging in")
#Next, log in to the server
server.login("ayanosmanphotog@gmail.com", "Jamilo64.")

print("connecting arduino")
ser=serial.Serial(port = '/dev/tty.usbmodem1421', baudrate=9600)

state='0'

while True:
        print("listening for data")
        time.sleep(1)
        
        while state =='0':
            ser.flushInput()
            state = str(ser.read())
            print(state)
            
        while state =='1':
            #Send the mail
            print("sending email")
            msg = "SOMEONE IS ACCESSING YOUR INFORMATION" # The /n separates the message from the headers
            server.sendmail("ayanosmanphotog@gmail.com", "ayanosmanphotog@gmail.com", msg)
            state = 0
        
ser.close()