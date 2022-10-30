# Programming in Python
# First of all import the socket library

import socket
import threading


HEADER = 60
FORMAT = 'utf-8'        ## UTF stands for "Unicode Transformation Format," and the number "8" indicates that the encoding uses 8-bit data. 
                        ## It is among the most effective and practical encoding formats available.A Unicode string is converted to bytes via utf-8.

# Reserving a port in the Computer
PORT = 5050         ## Port for Socket or Port to listen on. 

DISCONNECT_MESSAGE = 'Disconnected !!!'


SERVER = socket.gethostbyname(socket.gethostname())         ## The gethostbyname() function of socket module returns the IP address of a given host name. 
                                                            ## The returned address is an IPv4 address.
'''print(socket.gethostname())
print(SERVER)'''


Address = (SERVER,PORT)         ## Here is the Address for the Socket. 


'''Here we made a socket instance and passed it two parameters. The first parameter is AF_INET and the second one is SOCK_STREAM. 
AF_INET refers to the address-family ipv4. The SOCK_STREAM means connection-oriented TCP protocol.'''


server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

server.bind(Address)        ## Next bind to the port.

# Function for handling the client 
def handle_client(conn,addr):
    print(f"[NEW CONNECTION] {addr} is connected.")         ## Send the connected message. 
    connected = True
    while connected:
        msg_length = conn.recv(HEADER).decode(FORMAT)
        if msg_length:
          msg_length = int(msg_length)
          msg = conn.recv(msg_length).decode(FORMAT)

          if msg == DISCONNECT_MESSAGE:         ## Disconnecting ..........
               connected = False

        print(f"[{addr}] {msg}")
        conn.send("[MESSAGE] is recieved".encode(FORMAT))       ## Send a recieved message to the client. Encoding to send byte type.
    conn.close()        ## Close the connection with the client.


        
# Function to Start 
def start():
    server.listen()         ## Puttting the socket into listening mode.
    print(f"[SERVER] server is listening on {SERVER}")      ## Send the listening message. 
    
    # A forever loop until we interrupt it or
    # An error occurs
    while True:
        (conn,addr) =  server.accept()      ## Establish connection with client.
        thread = threading.Thread(target = handle_client, args = (conn,addr))
        thread.start()
        print(f"[ACTIVE CONNECTIONS] {threading.active_count() - 1}")       ## Tracking Active connections. 

    

print("[SERVER] server is starting !!!")
start()