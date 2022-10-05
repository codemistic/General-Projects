import FAKE_GPIO_LIB.GPIO as GPIO
from tkinter import *
from tkinter.ttk import *
import winsound
import sys
import os

MODE = "DEVICE"
STATE = False
PIN = sys.argv[1]

DEVICE_NAME = sys.argv[2]




def listener():
    ret = ''
    if GPIO.isValidPin(PIN) and GPIO.canRecive(PIN, MODE):
        ret = GPIO.getSig(PIN)
        if ret == '1':
            winsound.Beep(800, 300)
            lt.configure(text = 'Beeeeping!')
        else:
            lt.configure(text = 'Slient')
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


lt = Label(window, text = 'Slient')
lt.pack()

window.after(100, listener)
window.mainloop()