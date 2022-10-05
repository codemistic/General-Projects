from pathlib import Path
import os


IN      = 'INPUT'
OUT     = 'OUTPUT'
HIGH    = '1'
LOW     = '0'

MAIN = 'MAIN'
DEVICE = 'DEVICE'

BOARD = "F"

def setmode(x):
    return


def setup(PIN, MODE):
    if isValidPin(PIN):
        P = Path(f'./GPIO_DATA/GPIO_MODE.{PIN}')
        P.write_text(MODE)
        return True
    else:
        return False



def canSend(PIN, MODE):
    P = Path(f'./GPIO_DATA/GPIO_MODE.{PIN}')
    ret = P.read_text()

    if MODE == DEVICE:
        if ret == IN:
            return True
        elif ret == OUT:
            return False

    elif MODE == MAIN:
        if ret == IN:
            return False
        elif ret == OUT:
            return True
        
    return False



def canRecive(PIN, MODE):
    P = Path(f'./GPIO_DATA/GPIO_MODE.{PIN}')
    ret = P.read_text()

    if MODE == DEVICE:
        if ret == IN:
            return False
        elif ret == OUT:
            return True

    elif MODE == MAIN:
        if ret == IN:
            return True
        elif ret == OUT:
            return False
        
    return False






def isValidPin(pinNo):
    p = int(pinNo)
    if p > -1 and p < 28:
        return True
    else:
        return False





def sendSig(pinNo, val):
    if isValidPin(pinNo):
        if val == '-1':
            return clearGPIO(pinNo)
        else:
            PIN = Path(f'./GPIO_DATA/GPIO.{pinNo}')
            PIN.write_text(val)
            return f'{val} SuccessFully Sent'
    else:
        return f'BAD Request GPIO {pinNo} not Valid'


def getSig(pinNo):
    if isValidPin(pinNo):
        PIN = Path(f'./GPIO_DATA/GPIO.{pinNo}')
        return PIN.read_text()
            
    else:
        return None



def input(pin):
    if canRecive(pin, "MAIN"):
        return getSig(pin)
    else:
        return None


def output(pin, val = "0"):
    if canSend(pin, "MAIN"):
        sendSig(pin, val)
    else:
        return None



def clearGPIO(pinNo):
    if isValidPin(pinNo):
        PIN = Path(f'./GPIO_DATA/GPIO.{pinNo}')
        PIN.write_text('')
        return f'GPIO {pinNo} cleared'
    else:
        return f'BAD Request GPIO {pinNo} not Valid'



def initDevice(Device):
    os.system(f'start cmd.exe /c python {Device.ID}.py {Device.PIN} "{Device.NAME}"')


class Swtich:
    PIN     = None
    MODE    = 'DEVICE'
    NAME    = ''
    ID      = 'switch'

    def __init__(self,Name,Pin):
        self.NAME = Name
        self.PIN = Pin


class Bulb:
    PIN     = None
    MODE    = 'DEVICE'
    NAME    = ''
    ID      = 'led'

    def __init__(self,Name,Pin):
        self.NAME = Name
        self.PIN = Pin



class Speaker:
    PIN     = None
    MODE    = 'DEVICE'
    NAME    = ''
    ID      = 'speaker'

    def __init__(self,Name,Pin):
        self.NAME = Name
        self.PIN = Pin