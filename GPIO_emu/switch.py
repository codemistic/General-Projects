import FAKE_GPIO_LIB.GPIO as GPIO
import os
import sys
from tkinter import *


MODE = "DEVICE"
STATE = False
PIN = sys.argv[1]
TMP = GPIO.getSig(PIN)
if TMP == '0':
    STATE = False
else:
    STATE = True

DEVICE_NAME = sys.argv[2]

#def loop():
#    window.after(200, loop)

def clicked():
    global STATE
    ret = ''
    STATE = not STATE
    if STATE:
        if GPIO.isValidPin(PIN) and GPIO.canSend(PIN, MODE):
            GPIO.sendSig(PIN, '1')
            btn.configure(text="Turn OFF")
        

    else:
        if GPIO.isValidPin(PIN) and GPIO.canSend(PIN, MODE):
            GPIO.sendSig(PIN, '0')
            btn.configure(text="Turn ON")

    

#GUI
window = Tk()
window.title(DEVICE_NAME)
window.configure(bg = "#0f0f0f")
window.geometry('200x200')
btn = Button(window, text='ON', command = clicked)
btn.configure(height = 10, width = 20, bg = "#0f0f0f", fg = "white")
btn.pack()

if STATE:
    btn.configure(text = 'Turn OFF')
else:
    btn.configure(text = 'Turn ON')

#window.after(200, loop)
window.mainloop()



    
            

