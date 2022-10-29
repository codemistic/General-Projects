
# Programming in Python
# Import the socket library

import socket

PORT = 5050         ## The port used by the server.
HEADER = 60

'''UTF stands for "Unicode Transformation Format," and the number "8" indicates that the encoding uses 8-bit data. 
It is among the most effective and practical encoding formats available.A Unicode string is converted to bytes via utf-8.'''

FORMAT = 'utf-8'
DISCONNECT_MESSAGE = 'Disconnected !!!'
SERVER = socket.gethostbyname(socket.gethostname())         ## The gethostbyname() function of socket module returns the IP address of a given host name. 
                                                            ## The returned address is an IPv4 address.
Address = (SERVER,PORT)


'''Here we made a socket instance and passed it two parameters. The first parameter is AF_INET and the second one is SOCK_STREAM. 
AF_INET refers to the address-family ipv4. The SOCK_STREAM means connection-oriented TCP protocol.'''

client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
client.connect(Address)         ## connect to the server on local computer.


# Function to send messages
def send(msg):
    message = msg.encode(FORMAT)
    msg_length = len(message)
    send_length = str(msg_length).encode(FORMAT)
    send_length += b' '*(HEADER - len(send_length))
    client.send(send_length)
    client.send(message)
    print(client.recv(2048).decode(FORMAT))         ## receive data from the server and decoding to get the string.
    
    
# Sending messages 
send("Hello server socket. Client socket here.")
input()
send("Let's make a connection by applying the fundamentals of networking and socket.")
input()
send("Bye!!!")
input()
send(DISCONNECT_MESSAGE)