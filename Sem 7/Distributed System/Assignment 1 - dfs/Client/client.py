import socket

PORT = 1234
MAIN_SERVER_IP = 'localhost'
# this path can be used to store files on client
FILEPATH = '/home/ria/1 LP2/DS/1.DFS/Client/'

# TODO
def main():
    '''
    This function contains main logic for client
    '''
    client_socket = socket.socket()

    client_socket.connect((MAIN_SERVER_IP, PORT))

    while True:
        data = client_socket.recv(1024).decode()
        print(data)
        choice = input('Enter choice: ')
        client_socket.send(choice.encode())
        filedata = client_socket.recv(1024).decode()
        list_of_files = filedata.split('**')
        print('Images stored on file server:')
        for file in list_of_files:
            print(file)
        filename = input('Enter the name of the file you want to download (Enter -1 to skip)\n')
        client_socket.send(filename.encode())
        if filename != '-1':
            file_pointer = open(filename, 'wb')
            filedata = client_socket.recv(1024)
            print('Getting', filename, 'from server...')
            while filedata:
                file_pointer.write(filedata)
                fileda = client_socket.recv(1024)
            print('Got', filename, 'from server.')
            file_pointer.close()
        else:
            print('Going back to menu...')
    client_socket.close()

if __name__ == '__main__':
    main()
