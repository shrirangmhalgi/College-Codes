import socket
HOST = '10.31.1.16'
PORT = 12346

s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
s.connect((HOST,PORT))

while True:
    request = raw_input("Enter the message: ")
    s.send(request)
    response = s.recv(4096)
    if response == 'Bye':
       break
    print ('Message from server' + response)
s.close()

