import socket
HOST = '10.11.6.45' #Enter IP
PORT = 12346
s = socket.socket(socket.AF_INET , socket.SOCK_STREAM)
print ('Socket Created')

try:
    s.bind((HOST , PORT))
except socket.error:
    print ('Bind Failed')

s.listen()
print ('Socket awaiting messages!!')
(conn , addr) = s.accept()
print (' Connected ')

while True:
    data = conn.recv(4096)
    if (data == 'Bye'):
       break
    print ('Message from client')
    print (data)
    response = raw_input('Enter the message!')
    conn.send(response)
conn.close()

