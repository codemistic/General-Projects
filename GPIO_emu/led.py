import FAKE_GPIO_LIB.GPIO as GPIO
import os
import sys
from tkinter import *
from tkinter.ttk import *


MODE = "DEVICE"
STATE = False
PIN = sys.argv[1]

DEVICE_NAME = sys.argv[2]



def listener():
    ret = ''
    if GPIO.isValidPin(PIN) and GPIO.canRecive(PIN, MODE):
        ret = GPIO.getSig(PIN)
        if ret == '1':
            lt.configure(image = ONSTATE)
        elif ret == '0':
            lt.configure(image = OFFSTATE)
    else:
        print("InValid PIN or Access Denied")
        dummy = input("Press any here or Close Window ")
        window.quit()
    
    window.after(100, listener)




#GUI
window = Tk()
window.title(DEVICE_NAME)
window.geometry('220x120')
window.configure(bg = '#0f0f0f')


ONSTATE = PhotoImage(file = './res/lightON.png')
OFFSTATE = PhotoImage(file = './res/lightOFF.png')

lt = Label(window, image = OFFSTATE)
lt.pack()

window.after(100, listener)
window.mainloop()



