import FAKE_GPIO_LIB.GPIO as GPIO
from time import sleep

GPIO.setmode(GPIO.BOARD)

GPIO.setup(0, GPIO.IN)
GPIO.setup(20, GPIO.IN)
GPIO.setup(26, GPIO.IN)

GPIO.setup(15, GPIO.OUT)

GPIO.setup(1, GPIO.OUT)
GPIO.setup(2, GPIO.OUT)

GPIO.initDevice(GPIO.Swtich('SW1', 0))
GPIO.initDevice(GPIO.Swtich('SW2', 20))
GPIO.initDevice(GPIO.Swtich('SW3', 26))

GPIO.initDevice(GPIO.Bulb('Bulb1', 1))
GPIO.initDevice(GPIO.Bulb('Bulb2', 2))
GPIO.initDevice(GPIO.Speaker('Speaker1', 15))

while True:
    ret = GPIO.input(0)
    ret2 = GPIO.input(20)
    ret3 = GPIO.input(26)

    if ret == '1' and ret2 == '1' and ret3 == '1':
        GPIO.output(1, '1')
        GPIO.output(2, '0')
        GPIO.output(15, '1')
    else:
        GPIO.output(1, '0')
        GPIO.output(2, '1')
        GPIO.output(15, '0')

    sleep(.5)

    

