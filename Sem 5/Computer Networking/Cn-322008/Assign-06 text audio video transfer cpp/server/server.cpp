// Server code for udp socket programming
#include<iostream>
#include<string.h>
// include header files for networking
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
// include header files for file handling
#include<fstream>

// define some constants
#define PORT 8080
#define NO_FILE "File Not Found"
using namespace std;

class Server{
	long long int filesize;
	char *filebuff;
public:
	void sendFile();
	//bool fileExists(string);
	void readFile(string);
};
int main(){
	Server s;
	s.sendFile();
	return 0;
}

/*bool Server :: fileExists(string filename){
	cout<<"test \n";
	ifstream ifile(filename.c_str());
  	return (bool)ifile;
}*/
void Server :: readFile(string filename){
	cout<<"Opening file : "<<filename<<endl;
	fstream fout;
	cout<<"File exists";
	fout.open(filename,ios::in|ios::out|ios::binary);
	fout.seekg(0,ios::end);
	filesize = fout.tellg();
	filebuff=new char[filesize];
	fout.seekg(0,ios::beg);
	fout.read(filebuff,filesize); // reading file content
	fout.close();
}
void Server :: sendFile(){
	// establish connection
	char filename[50];
	char *fileContents;
	cout<<"Server Started \n";
	int sockfd,n;
	struct sockaddr_in server_addr,client_addr;
	
	sockfd = socket(AF_INET,SOCK_DGRAM,0);
	
	if(sockfd < 0)
		cout<<"Socket Could Not Be Created";

	//bzero((char *)&server_addr,sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);
	
	if(bind(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0)
		cout<<"ERROR IN BINDING\n";

	
	socklen_t socklen = sizeof(client_addr);
	int client_len = sizeof(client_addr);
		
	// clear buffer
	bzero(filename,50);
	
	n = recvfrom(sockfd,filename,50,0,(struct sockaddr*)&client_addr,&socklen);
	
	if(n < 0)
		cout<<"Error \n";
	
	cout<<" Recieved Filename : "<<filename<<"\n";
	
	// read from file content and send it to  client
	string file = filename;
	cout<<"test : "<<file<<endl;
	readFile(filename);
	cout<<"Filesize : "<<filesize<<endl;
	// send file size
	n = sendto(sockfd,(void*)&filesize,sizeof(filesize),0,(struct sockaddr*)&client_addr,client_len); 
	if(n < 0)
 		cout<<" Error in sending filesize to client \n";
	
	bzero((char*)filebuff,sizeof(filebuff));
	n = sendto(sockfd,filebuff,filesize,0,(struct sockaddr*)&client_addr,client_len);
	
 	if(n < 0)
 		cout<<" Error in sending to client \n";
	
}
	

