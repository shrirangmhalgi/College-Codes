// client
#include<iostream>
// string header
#include<string.h>
// Headers for connection
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<arpa/inet.h>
// define port no
#define PORT 8080
#define SERVER_ADD "127.0.0.1"
using namespace std;

class Client{

public:
	void connectToServer();
};

int main(){
	Client c;
	c.connectToServer();
	return 0;
}

void Client :: connectToServer(){
	
	cout<<"Connecting to Server\n";
	
	int sockfd , n;
	struct sockaddr_in server_addr;
	struct hostent *server;
	
	char buffer[256];	//buffer to send and receive data
	char num1[20];
	char num2[20];
	char choice[2];
	char result[20];
	
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	
	if(sockfd < 0)
		cout<<"Error in opening Socket \n";
	
	server = gethostbyname(SERVER_ADD);
	
	if(server == NULL)
		cout<<"Error ! No such host exists \n";
	
	bzero((char*)&server_addr,sizeof(server_addr)); // clear
	
	server_addr.sin_family = AF_INET;
	//bcopy((char*)server->h_addr,(char*)&server_addr.sin_addr.s_addr,server->h_length);	// copy address of server
	server_addr.sin_addr.s_addr = inet_addr(SERVER_ADD);
	server_addr.sin_port = htons(PORT);
	

	if(connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0)
		cout<<" Error in connecting ";
	
	//bzero(buffer,256); // clear buffer
	

	do{
		cout<<"Enter 1.Add 2.Substract 3.Multiply 4.Division 5.Sin 6.Cos 7.Tan 0.exit\n";
		bzero(choice,2);
		cin>>choice;
		switch(choice[0]){
			case '0':
				n = send(sockfd,choice,2,0);
				if(n < 0)
					cout<<" Error in writing choice to socket \n";
				return;
			case '1':
			case '2':
			case '3':
			case '4':
				n = send(sockfd,choice,2,0);
				if(n < 0)
					cout<<" Error in writing choice to socket \n";
				cout<<" Enter first number \n";
				bzero(num1,20);
				cin>>num1;
				n = send(sockfd,num1,20,0);
				if(n < 0)
					cout<<" Error in writing number 1 to socket \n";
				cout<<" Enter Second number \n";
				bzero(num2,20);
				cin>>num2;
				n = send(sockfd,num2,20,0);
				if(n < 0)
					cout<<" Error in writing number 2 to socket \n";
				
				bzero(result,20);	
				n = recv(sockfd,result,20,0);
				if(n < 0)
					cout<<" Error in reading result from socket \n";	
				cout<<" Result of operation is : "<<result<<"\n";
				break;
			case '5':
			case '6':
			case '7':
				n = send(sockfd,choice,2,0);
				if(n < 0)
					cout<<" Error in writing choice to socket \n";
				cout<<" Enter number \n";
				bzero(num1,20);
				cin>>num1;
				n = send(sockfd,num1,20,0);
				if(n < 0)
					cout<<" Error in writing number to socket\n";		
				bzero(result,20);	
				n = recv(sockfd,result,20,0);
				if(n < 0)
					cout<<" Error in reading result from socket \n";	
				cout<<" Result of operation is : "<<result<<"\n";
				break;		
						
		}
			
	}
	while(1);
	
	cout<<"Disconnected !\n";
	
					
}
