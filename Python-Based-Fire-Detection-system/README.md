# Fire-detection-using-Python

This code setup is used in Raspberry Pi which has OpenCV installed in it. The aim of the project is to detect fire from any CCTV camera or any USB camera without using any sensor.

Working:
-------
The USB camera is connecetd with RPi, as soon as any flame is detected it prints message as "Fire Detected". This message is than fed to Node-red which is running on RPi and reply back with a audio message "Fire Detected". We can also use HTTP Post to send the message to external server.
