#include<iostream>
#include <string.h> 
// networking
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
// file 
#include<fstream>
using namespace std;

#define SERVER_ADDRESS "127.0.0.1"
#define PORT 8080

class Client{
public:
	void sendFilename();
};

int main(){
	Client c;
	c.sendFilename();
	return 0;
}

void Client :: sendFilename(){

	char filename[50];
	char *filebuff;
	int filesize;
	cout<<"Connecting to Server\n";
	
	cout<<"Enter Filename \n";
	bzero(filename,50);
	cin>>filename;
	
	int sock , n;
	struct sockaddr_in server_addr;
	
	sock = socket(AF_INET,SOCK_DGRAM,0);
	
	if(sock<0)
		cout<<"Socket Could Not Be Created";
		
	bzero((char*)&server_addr,sizeof(server_addr)); // clear
		
	server_addr.sin_family = AF_INET;	
	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);
	server_addr.sin_port = htons(PORT);

	socklen_t cli = sizeof(server_addr);
	
	int slen = sizeof(server_addr); // server_len slen
		
	cout<<"Sending filename \n";
	
	n = sendto(sock,filename,strlen(filename),0,(struct sockaddr*)& server_addr,slen);
	
	if(n < 0)
		cout<<" Error in sending file name \n";
	

	// recieve filesize
	n = recvfrom(sock,(void *)&filesize,sizeof(filesize),0,(struct sockaddr*)&server_addr,&cli);
	if(n < 0)
		cout<<" Error in recieving filesize \n";
	
	cout<<"filesize : "<<filesize<<endl;
	
	filebuff = new char[filesize];
	bzero((char *)filebuff,sizeof(filebuff));
	n = recvfrom(sock,filebuff,filesize,0,(struct sockaddr*)& server_addr,&cli);
	
	
	if(n < 0)
		cout<<" Error in recieving file \n";
	

	ofstream fout;
	fout.open(filename,ios::out|ios::binary);
	if(!fout)
		cout<<"CANNOT CREATE FILE\n";
	else
	{
		fout.write(filebuff,filesize);
		fout.close();
		cout<<" File recieved Successfully \n";
	}
}

