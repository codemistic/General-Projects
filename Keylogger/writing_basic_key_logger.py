import pynput.keyboard as spy

def process_on_key_press(key):
    print(key)

keyboard_listener = spy.Listener(on_press = process_on_key_press)
keyboard_listener.join()
