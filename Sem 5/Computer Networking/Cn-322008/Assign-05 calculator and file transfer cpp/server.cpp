#include<iostream>
#include<string.h>
// Math Library
#include<cmath>
// header files for tcp connection
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
//#include<stdlib.h>

using namespace std;

// define port no;
#define PORT 8080

class Server{
		
public:
	// Arithmetic
	double add(double,double);
	double sub(double,double);
	double mul(double,double);
	double div(double,double);
	// Trignometry
	double sinOfAngle(double);
	double cosOfAngle(double);
	double tanOfAngle(double);
	// connection
	void establishConnection();
};

int main(){
	Server s;
	s.establishConnection();
	return 0;
}
double Server :: add(double a,double b){
	return a+b;
}
double Server :: sub(double a,double b){
	return a-b;
}
double Server :: mul(double a,double b){
	return a*b;
}
double Server :: div(double a,double b){
	return a/b;
}

double Server :: sinOfAngle(double a){
	return sin(a*(3.14159/180));
}
double Server :: cosOfAngle(double a){
	return cos(a*(3.14159/180));
}
double Server :: tanOfAngle(double a){
	return tan(a*(3.14159/180));
}

void Server :: establishConnection(){
	// Connect server to client
	char op[2];
	char num1[20];
	char num2[20];
	cout<<" Server is starting  \n";
	int sockfd , newSockFd ;
	char buffer[256];  // store values to be sent and received
	struct sockaddr_in server_addr , client_addr;
	int n;
	// create socket
	sockfd = socket(AF_INET,SOCK_STREAM,0);  // AF_INET : Internet address , SOCK_STREAM for TCP,0 for system to get appropriate socket
	if(sockfd < 0)
		cout<<" Error in opening Socket \n";
	bzero((char*)&server_addr, sizeof(server_addr));	// before storing clear server address with bzero method
	
	server_addr.sin_family = AF_INET; // IP address format
	server_addr.sin_addr.s_addr = INADDR_ANY; // take IP on your own i.e address of this pc
	server_addr.sin_port = htons(PORT); // htons() method to convert port no. from int to network format
	// bind socket and server address
	if(bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0 ){
		cout<<" Error in Binding \n";
	}
	
	// now listen for clients
	
	listen(sockfd,5);	// at a time handle 5 clients
	socklen_t clilen = sizeof(client_addr);
	
	// accept request of requesting client 
	newSockFd = accept(sockfd,(struct sockaddr*)&client_addr,&clilen); // new socket for client that will have address
	if(newSockFd < 0)
		cout<<" Error on accept \n";
	bzero(buffer,256);		//clear the buffer
	
	cout<<"Connection Established \n";
	
	
	// logic for calulator
	double a,b,ans;
	while(op[0] != '0'){
		
		bzero(op,2);
		n = recv(newSockFd,op,2,0);
		cout<<"Operator is : "<<op<<endl;
		
		
		
		
		switch(op[0]){
			case '1':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
		
				bzero(num2,20);
				n = recv(newSockFd,num2,20,0);
				b = (double)atof(num2);
				cout<<" Second Number : "<<b<<"\n";
				
				ans = 0;
				char ans1[20];		
				ans = add(a,b);
				bzero((char *)ans1,sizeof(ans1));
				sprintf(ans1,"%f",ans);
				send(newSockFd,ans1,sizeof(ans1),0);
				cout<<"Answer : "<<ans<<endl;
				break;
			case '2':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
		
				bzero(num2,20);
				n = recv(newSockFd,num2,20,0);
				b = (double)atof(num2);
				cout<<" Second Number : "<<b<<"\n";
						
				ans =0;
				char ans2[20];
				ans = sub(a,b);
				bzero((char *)ans2,sizeof(ans2));
				sprintf(ans2,"%f",ans);
				send(newSockFd,ans2,sizeof(ans2),0);
				cout<<"Answer : "<<ans<<endl;
				break;
			case '3':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
		
				bzero(num2,20);
				n = recv(newSockFd,num2,20,0);
				b = (double)atof(num2);
				cout<<" Second Number : "<<b<<"\n";
						
				ans  = 0;
				char ans3[20];
				ans = mul(a,b);
				bzero((char *)ans3,sizeof(ans3));
				sprintf(ans3,"%f",ans);
				send(newSockFd,ans3,sizeof(ans3),0);
				cout<<"Answer : "<<ans<<endl;
				break;
			case '4':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
		
				bzero(num2,20);
				n = recv(newSockFd,num2,20,0);
				b = (double)atof(num2);
				cout<<" Second Number : "<<b<<"\n";
						
				ans = 0;
				char ans4[20];
				ans = div(a,b);
				bzero((char *)ans4,sizeof(ans4));
				sprintf(ans4,"%f",ans);
				send(newSockFd,ans4,sizeof(ans4),0);
				cout<<"Answer : "<<ans<<endl;
				break;
			case '5':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
					
				ans = 0;
				char ans5[20];			
				ans = sinOfAngle(a);
				bzero((char *)ans5,sizeof(ans5));
				sprintf(ans5,"%f",ans);
				send(newSockFd,ans5,sizeof(ans5),0);
				cout<<"Answer : "<<ans<<endl;
				break;
			case '6':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
			
				ans = 0;
				char ans6[20];
				ans = cosOfAngle(a);
				bzero((char *)ans6,sizeof(ans6));
				sprintf(ans6,"%f",ans);
				send(newSockFd,ans6,sizeof(ans6),0);
				cout<<"Answer : "<<ans<<endl;
				break;
			case '7':
				bzero(num1,20);
				n = recv(newSockFd,num1,20,0);
				a = (double)atof(num1);
				cout<<" First number : "<<a<<"\n";
				
				ans = 0;
				char ans7[20];
				ans = tanOfAngle(a);
				bzero((char *)ans7,sizeof(ans7));
				sprintf(ans7,"%f",ans);
				send(newSockFd,ans7,sizeof(ans7),0);
				cout<<"Answer : "<<ans<<endl;
				break;						
		}
	}			
}	

