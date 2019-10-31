#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
int n,i;

class emp{
	public:
	int roll_no;
	char div;
	char address[100],name[50];
	
		void insert(int );
		void display();
		void getname(int);
		char* getaddress(int);
		
}o[30];

void emp :: insert(int i){
	cout<<"\nRoll No. : ";
	cin>>o[i].roll_no;
	cout<<"Division : ";
	cin>>o[i].div;
	cout<<"Name : ";
	ws(cin);
	cin.getline(o[i].name,50);
	cout<<"Address : ";
	cin.getline(o[i].address,100);
}

void emp :: display(){
	
	cout<<"\nRoll no. : "<<o[i].roll_no<<endl;
	cout<<"Division : "<<o[i].div<<endl;
	cout<<"Name : "<<o[i].name<<endl;
	cout<<"Address : "<<o[i].address<<endl;
}

void emp :: getname(int j){
	int f=0;
	int h = max(strlen(o[j].name),strlen(o[j+1].name));
	while(f<h)
	{
		o[j].name[f]=o[j+1].name[f];
		f++;
	}
}

char* emp :: getaddress(int j){
	int f=0;
	int h = max(strlen(o[j].address),strlen(o[j+1].address));
	while(f<h)
	{
		o[j].address[f]=o[j+1].address[f];
		f++;
	}
}

int main(){
	emp obj;
	fstream f;
	
	int ch,v,id,flag=0;
	char divi;
	do{
	cout<<"\n1:Create\n2:Display\n3:Insert\n4:Update\n5:Delete\nEnter your choice : ";
	cin>>ch;
	switch(ch){
		case 1 :cout<<"Enter number of records : ";
				cin>>n;
				f.open("abc.txt",ios::app);
				for(i=0;i<n;i++)
				{
					obj.insert(i);
					f.write((char *)&o[i],sizeof(o[i]));
				}
			    v=i;
				break;
		case 2 : cout<<"\nDetails of file are \n ";
				f.seekg(0);
				for(i=0;i<n;i++)
				{
					f.read((char *)&o[i],sizeof(o[i]));
					obj.display();
				}	
				break;
		case 3 : obj.insert(v);
				f.write((char *)&o[v],sizeof(o[v]));
				v++; n++;
				break;
		case 4 :cout<<"Enter the roll no whose info is to be updated : ";
				cin>>id;
				cout<<"Enter the divisoin : ";
				cin>>divi;
				
				for(i=0;i<n;i++)
				{
					f.read((char *)&o[i],sizeof(o[i]));
					if(o[i].roll_no==id && o[i].div==divi)
					{
						cout<<"Enter the updated details \n ";
						cout<<"Division : ";
						cin>>o[i].div;
						cout<<"\nName : ";
						ws(cin);
						cin.getline(o[i].name,50);
						cout<<"\nAddress : ";
						cin.getline(o[i].address,100);
						f.write((char *)&o[i],sizeof(o[i]));
						flag=1;
						break;
					}
					else{
						continue;
					}
				}
				if(flag==0)
					cout<<"\nData not found\n";
			//	f.close();
				break;
		case 5 : cout<<"Enter the roll_no which is to be deleted : ";
				 cin>>id;
				 cout<<"Enter the division : ";
				 cin>>divi;
				 for(i=0;i<n;i++)
				{
					f.read((char *)&o[i],sizeof(o[i]));
					if(o[i].roll_no==id && o[i].div==divi)
					{
						for(int j=i;j<n;j++)
						{
							o[j].roll_no=o[j+1].roll_no;
							o[j].div=o[j+1].div;
							obj.getname(j);
							obj.getaddress(j);
							break;
						}
					}
				}
				n--;
				break;
		}
	}while(ch!=0);
}
