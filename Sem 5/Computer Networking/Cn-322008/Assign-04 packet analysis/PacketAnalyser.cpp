#include<iostream>
#include<fstream>
using namespace std;

class PacketAnalyser{
public:
	void analyse();
};

int main(){
	PacketAnalyser p;
	p.analyse();
	return 0;
}

void PacketAnalyser :: analyse(){
	int count = 0;
	ifstream fin;
	string srNo,time,source,destination,protocol,len,info;
	char choice;
	string protocolChoice;


	do{
		 cout<<"\nSelect which protocol packets you want to see "<<endl;
        	cout<<"1. TCP"<<endl;
        	cout<<"2. UDP"<<endl;
        	cout<<"3. ARP"<<endl;
        	cout<<"4. DNS"<<endl;
        	cout<<"5. HTTP"<<endl;
        	cout<<"q. Quit"<<endl;
        	cin>>choice;
        	count=0;       //reinitialize

        	switch(choice){

        	case '1':
        		protocolChoice = "TCP";
        		break;
        	case '2':
        		protocolChoice = "UDP";
        		break;
        	case '3':
        		protocolChoice = "ARP";
        		break;
        	case '4':
        		protocolChoice = "DNS";
        		break;
        	case '5':
        		protocolChoice = "HTTP";
        		break;
        	case 'q':
        		return;
        	}

        	fin.open("tp.csv"); // open csv file

        	while(fin.good()){

        		getline(fin,srNo,',');
        		getline(fin,time,',');
        		getline(fin,source,',');
        		getline(fin,destination,',');
        		getline(fin,protocol,',');
        		getline(fin,len,',');
        		getline(fin,info,'\n');

        		protocol = string(protocol,1,protocol.length()-2);

        		if(protocol == protocolChoice){
        		//if(count == 0){
        			cout<<endl;
        			cout<<"No. \tTime\tSOURCE\tDESTINATION\tPROTOCOL\tLENGTH \n";
        			cout<<string(srNo,1,srNo.length()-2)<<"\t";
        			cout<<string(time,1,time.length()-2)<<"\t";
        			cout<<string(source,1,source.length()-2)<<"\t";
        			cout<<string(destination,1,destination.length()-2)<<"\t";
        			cout<<protocol<<"\t";
        			cout<<string(len,1,len.length()-2)<<"\t";
        			cout<<endl;
        			count++;

        		//}
        		}
        	}
        	cout<<" Total packets of "<<protocol<<" are "<<count<<endl;
        	fin.close(); // reset file pointer

	}
	while(choice != 'q');
}
