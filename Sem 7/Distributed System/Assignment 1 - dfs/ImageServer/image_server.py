import socket
import os

MAIN_SERVER_PORT = 1234
MAIN_SERVER_IP = 'localhost'
IMAGE_SERVER_PORT = 1235
IMAGE_SERVER_IP = 'localhost'
IMAGEPATH = '../ImageData/'

# TODO
def main():
    # read filepath here to save load time
    files = os.listdir(IMAGEPATH)

    image_server_socket = socket.socket()
    image_server_socket.bind((IMAGE_SERVER_IP, IMAGE_SERVER_PORT))
    image_server_socket.listen(5)
    print('Waiting for main server to connect...')
    server, addr = image_server_socket.accept()
    print('Connected to main server.')
    # TODO: here comes the part which will send data

    while True:
        request = server.recv(1024).decode()
        request = request.split('**')

        # if request[0] is list, forward list of image names
        if request[0] == 'LIST':
            # TODO: send list of files in IMAGEPATH
            filedata = '**'.join(files)
            server.send(filedata.encode())

        # if request[0] is GET; main server needs the file request[1]
        elif request[0] == 'GET':
            file_pointer = open(IMAGEPATH + request[1], 'rb')
            print('Sending file to main server...')
            data = file_pointer.read(1024)
            while data:
                server.send(data)
                data = file_pointer.read(1024)
            print(request[1], 'sent to main server.')
            file_pointer.close()
            server.send(b'DONE')
            print('yes the file is sent from image server.')
        else:
            print('Invalid request from main server:', request)
            break
    image_server_socket.close()

if __name__ == '__main__':
    main()
