from tkinter import Tk, Menu, Menubutton, Frame, LEFT, W, X, RAISED, IntVar, StringVar, DISABLED  
import tkinter as tk  
from tkinter import *
from tkinter import font as tkfont  
from tkinter import filedialog  
from functools import partial
from cryptography.fernet import Fernet
import os

# Window Properties  
window = Tk()  
window.geometry('600x900')
window.title('Encryption & Decryption')
window.resizable(True, True)
bitmap = PhotoImage(file="icon.png")
window.iconphoto(False, bitmap)

# Defined Global Variables
key2 = b''  
encry_decry = ''  
filepath = ""  
data_list = []  
filename = ''  
filepath_key = ""  
filepath_decrypt = ''  
extracted_key = b''

# Use to prevent duplication of windows  
BUTTON_PRESSED_encrypt = False  
BUTTON_PRESSED_decrypt = False

#  Main  Encryption UDF
def encryption():
    global BUTTON_PRESSED_encrypt
    global frame1

    frame1.pack_forget()	# To hide the login dialogue box upon initiation of  encryption window

    if not BUTTON_PRESSED_encrypt:
        def browseFiles():  
            global filepath  
            global data_list

            # Opens Windows dialogue box to browse the desired file
            filename = filedialog.askopenfilename(initialdir="/",
            title="Select a File",  filetypes=(("Text files",
            "*.txt*"),
            ("all files",  "*.*")))

            # Change label contents
            label_file_explorer.configure(text="File Opened: " + filename)

            filepath =  str(filename)	# Changes the extracted filepath to string

        class page2:
            def write_key():
                global key2
                key1 =  Fernet.generate_key()	# Generating Key (binary)

                with  open("key.key",  "wb") as key_file:	# Writing the key into a file 'key.key'
                    key_file.write(key1)

                key2  =  open("key.key", "rb").read()	# Loads the key from the  current directory named `key.key`
                name = "key.key"
                label_keyname.configure(text="Generated  Keyname:   " +  name)	#Change label contents

            def encrypt(filename, key): #Given a filename (str) and key (bytes), it encrypts the file and write it
                global encry_decry
                f = Fernet(key)
                with open(filename, "rb") as file:
                    file_data =  file.read()	# Read all file data

                encrypted_data = f.encrypt(file_data)	# Encrypting data and Assigning the key generated  earlier to the encrypted file

                with open(filename, "wb") as file:  file.write(encrypted_data)	# Write the encrypted file

                encry_decry = 'Encryption'
                
                button_encrypt.configure(bg="green4")	# Changes button color to  green upon completion of encryption

        # Encryption frame
        encrypt = LabelFrame(window, text="Encryption", bd=10, bg='light cyan')  
        encrypt.pack(fill="both", expand="yes")

        label_file_explorer = Label(encrypt, text="Safely Transfer Your Data",  width=1000, height=4,  fg="white", bg="slategray4",  bd=3,  font='arial')
        label_file_explorer.pack()

        label_space1 = Label(encrypt, bg="light cyan", height="1")  
        label_space1.pack()

        button_explore = Button(encrypt,
        text="Browse Files",
        width=20, height=2, bg="lavender",  command=lambda: browseFiles())
        button_explore.pack()

        label_space1 = Label(encrypt, bg="light cyan")  
        label_space1.pack()

        label_keyname = Label(encrypt,
        text="Key Name:",  width=200, height=2,  fg="white",  bg="slategray4",  bd=3,
        font='arial')
        label_keyname.pack()

        label_space1 = Label(encrypt, bg="light cyan", height="1")  
        label_space1.pack()

        button_writekey = Button(encrypt,
        text='Generate Key',
        width=20, height=2, bg="lavender",  command=page2.write_key)
        button_writekey.pack()


        label_space2 = Label(encrypt, bg="light cyan", height="3")  
        label_space2.pack()

        button_encrypt = Button(encrypt,
        text='Encrypt',
        width=30, height=4, bg="orangered2",  command=lambda: page2.encrypt(filepath, key2))
        button_encrypt.pack()

        BUTTON_PRESSED_encrypt = True


# Main Decryption UDF
def decryption():
    global BUTTON_PRESSED_decrypt
    global frame1

    frame1.pack_forget()	# To hide the login dialogue box upon initiation of  decryption window

    if not BUTTON_PRESSED_decrypt:
        def decrypt(filename, key1):
            global encry_decry
            global data_list

            f =  Fernet(key1)
            with open(filename, "rb") as file:
                encrypted_data =  file.read()	# Read the encrypted data

            decrypted_data =  f.decrypt(encrypted_data)	# Decrypt data using the  assigned key

            with  open(filename,  "wb") as  file:	# Overwriting the original file
                file.write(decrypted_data)

            button_decrypt.configure(bg="green4")	# Changes button color to green upon completion of decryption

        def browsekey():
            global filepath_key
            # Opens Windows dialogue box to browse the desired file
            filename = filedialog.askopenfilename(initialdir="/",
            title="Select a File",  filetypes=(("Text files",
            "*.txt*"),
            ("all files",  "*.*")))

            label_file_explorer_key.configure(text="File  Opened:   " +  filename)	
            #Change  label contents

            filepath_key =  str(filename)	# Changes the extracted filepath to string

        def browse_encrypted_file():  
            global filepath_decrypt  
            global data_list

            # Opens Windows dialogue box to browse the desired file
            filename = filedialog.askopenfilename(initialdir="/",
            title="Select a File",  filetypes=(("Text files",
            "*.txt*"),
            ("all files",  "*.*")))
            label_file_explorer_decrypt.configure(text="Encrypted File Opened: " +  filename)	# Change label contents

            filepath_decrypt =  str(filename)	# Changes the extracted filepath to string


        def extract_key(filename):
            global extracted_key
            extracted_key  = open(filename, "rb").read()	# Reads the binary key  from the file

        # Decryption frame
        decrypt_ = LabelFrame(window, text="Decryption", bd=10, bg='light blue')  
        decrypt_.pack(fill="both", expand="yes")

        label_file_explorer_decrypt = Label(decrypt_,
        text="Decrypt Your Data",  width=1000, height=4,  fg="white",  bg="slategray4",
        bd=3,  font='arial')
        label_file_explorer_decrypt.pack()



        label_space1 = Label(decrypt_, bg="light blue")  
        label_space1.pack()

        button_explore_decrypt = Button(decrypt_,
        text="Browse Encrypted File",  width=20, height=2, bg="lavender",  command=browse_encrypted_file)
        button_explore_decrypt.pack()

        label_space1 = Label(decrypt_, bg="light blue")  
        label_space1.pack()

        label_file_explorer_key = Label(decrypt_,
        text="Browse Key",  width=200, height=2,  fg="white",  bg="slategray4",  bd=3,
        font='arial')
        label_file_explorer_key.pack()

        label_space1 = Label(decrypt_, bg="light blue")  
        label_space1.pack()

        button_explore_key = Button(decrypt_,
        text="Browse Key",
        width=20, height=2, bg="lavender",  command=browsekey)
        button_explore_key.pack()

        label_space1 = Label(decrypt_, bg="light blue")  
        label_space1.pack()

        button_loadkey = Button(decrypt_,
        text='Load Key',
        width=20, height=2, bg="lavender",  command=lambda: extract_key(filepath_key))
        button_loadkey.pack()

        label_space1 = Label(decrypt_, bg="light blue", height="3")  
        label_space1.pack()

        button_decrypt = Button(decrypt_,
        text='Decrypt',
        width=30, height=4, bg='OrangeRed2',  command=lambda: decrypt(filepath_decrypt,
        extracted_key))
        button_decrypt.pack()

        BUTTON_PRESSED_decrypt = True


def validateLogin(username):
    global data_list

    print("username entered :", username.get())  
    data_list.append(username.get())	# Gets the name of the user and appends the data into list which late is recorded in SQL table

    success_label = Label(frame1, text="Username recorded! \n Go to 'Action' dropdown list to Encrypt/Decrypt your file", bg="powderblue")	# Prints when username gets recorded successfully
    success_label.pack()
    


#  Menu  Bar
frame = Frame(window, relief=RAISED, borderwidth=1)  
frame.pack(fill=X)

# First Menu
first_menu = Menubutton(frame, text="Action")  
first_menu.pack(padx=3, pady=3, side=LEFT)  
first_menu.menu = Menu(first_menu, tearoff=False)
button1 = first_menu.menu.add_command(label="Encryption", command=encryption)
first_menu.menu.add_command(label="Decryption", command=decryption)  
first_menu['menu'] = first_menu.menu

# second Menu
second_menu = Menubutton(frame, text="Exit")  
second_menu.pack(padx=3, pady=3, side=LEFT)  
second_menu.menu = Menu(second_menu, tearoff=False)  
second_menu.menu.add_command(label="Confirm?", command=exit)  
second_menu['menu'] = second_menu.menu

# login block
frame1 = LabelFrame(window, padx=100, pady=100, bd=3, bg="powderblue")  
frame1.pack(fill="none", expand=True)

# username label and text entry box
usernameLabel = Label(frame1, text="Enter Username", bg="powderblue")  
usernameLabel.pack()
username = StringVar()
usernameEntry = Entry(frame1, textvariable=username)  
usernameEntry.pack()

validateLogin = partial(validateLogin, username)

label_space1 = Label(frame1, bg="powderblue", height="1")  
label_space1.pack()

# login button
loginButton = Button(frame1, text="Login", bg="lavender", command=validateLogin)  
loginButton.pack()



window.mainloop()
