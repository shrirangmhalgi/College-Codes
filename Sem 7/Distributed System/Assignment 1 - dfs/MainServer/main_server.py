import socket

MAIN_SERVER_PORT = 1234
MAIN_SERVER_IP = 'localhost'
IMAGE_SERVER_PORT = 1235
IMAGE_SERVER_IP = 'localhost'
FILE_SERVER_PORT = 1236
FILE_SERVER_IP = 'localhost'

# DONE
def connect_to_server(ip_addr, port):
    '''
    This function takes input server ip and port number, and returns the socket after establishing a sconnection
    '''
    server_as_client = socket.socket()
    server_as_client.connect((ip_addr, port))
    return server_as_client

# DONE
def send_to_client(socket, filename):
    '''
    Sends the file to client, takes input filename and socket to which client is connected, returns nothing.
    '''
    file_pointer = open(filename, 'rb')
    data = file_pointer.read(1024)
    print('Sending', filename, 'to client...')
    while data != None and data != '' and data != 0 and data:
        socket.send(data)
        data = file_pointer.read(1024)
    file_pointer.close()
    print(filename, 'sent to client.')
    return

# DONE
def recv_from_server(socket, filename):
    '''
    Receives file from image or video server, takes input the socket and filename; returns nothing.
    '''
    file_pointer = open(filename, 'wb')
    data = socket.recv(1024)
    print('Receiving', filename, 'from server...')
    while data != None and data != '' and data != 0 and data:
        file_pointer.write(data)
        data = socket.recv(1024)
        if data[-4:] == b'DONE':
            data = None
            break
        # else: print(str(data[-4:]) + 'apple')

    print(filename, 'received from server.')
    file_pointer.close()
    return

# TODO
def main():
    '''
    This function contains main logic for main server
    '''
    server_socket = socket.socket()
    server_socket.bind((MAIN_SERVER_IP, MAIN_SERVER_PORT))

    print('Waiting for client to connect...')

    server_socket.listen(5)
    server, addr = server_socket.accept()
    print('Connected to client.')
    menu = '\nBrowse data:\n1.Images\n2.Files'

    while True:
        server.send(menu.encode())
        choice = int(server.recv(1024).decode())
        if choice == 1:
            print('Client wants images.')
            print('Connecting to image server...')
            server_as_client = connect_to_server(IMAGE_SERVER_IP, IMAGE_SERVER_PORT)
            # after making connection loop until client wants to exit
            while True:
                # get the content list from image server
                server_as_client.send('LIST'.encode())
                filedata = server_as_client.recv(1024).decode()
                # IMAGE_SERVER sends filedata as a string concatenated with '**'
                files = filedata.split('**')
                print('Files present on image server:')
                print(files)
                for file in files:
                    print(file)
                print('Forwarding information to client.')
                server.send(filedata.encode())
                client_response = server.recv(1024).decode()
                # if client wants to exit
                if client_response == '-1':
                    print('Client wants to go to back main menu.')
                    break
                    # else client wants the file
                else:
                    filedata = 'GET' + '**' +  client_response
                    server_as_client.send(filedata.encode())
                    # this function receives the file from server
                    recv_from_server(server_as_client, client_response)
                    # now send the file to client
                    send_to_client(server, client_response)
                    print('this is perfect.')

        elif choice == 2:
            server_as_client = connect_to_server(FILE_SERVER_IP, FILE_SERVER_PORT)
            print('Client wants files.')
            print('Connecting to file server...')
            server_as_client = connect_to_server(FILE_SERVER_IP, FILE_SERVER_PORT)

            while True:
                server_as_client.send('LIST'.encode())
                filedata = server_as_client.recv(1024).decode()
                # FILE_SERVER_IP sends filedata as a string concatenated with '**'
                files = filedata.split('**')
                print('Files present on file server:')
                print(files)
                for file in files:
                    print(file)
                print('Forwarding information to client.')
                server.send(filedata.encode())
                client_response = server.recv(1024).decode()
                # if client wants to exit
                if client_response == '-1':
                    print('Client wants to go to back main menu.')
                    break
                    # else client wants the file
                else:
                    filedata = 'GET' + '**' +  client_response
                    server_as_client.send(filedata.encode())
                    # this function receives the file from server
                    recv_from_server(server_as_client, client_response)
                    # now send the file to client
                    send_to_client(server, client_response)
                    print('this is perfect.')


        else:
            print('Invalid choice by client:', choice)
            break

    server_socket.close()

if __name__ == '__main__':
    main()
