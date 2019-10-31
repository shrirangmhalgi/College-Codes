/*Develop  an  object  oriented  program  in  C++  to  create  a  database  of  student information
system  containing the following information: Name, Roll number, Class, division,  Date of
Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the
database  with  suitable  member  functions  for  initializing  and  destroying  the  data  viz
constructor, default constructor, Copy constructor, destructor, static member functions, friend
class, this pointer, inline code and dynamic memory allocation operators-new and delete.*/
#include<iostream>
#include<string.h>
using namespace std;

class biodata
{
	char *name,*div,*dob,*bloodgroup,*address,*drivingLicence;
	char *mobile,*telephone,*rollno;
	int num;
	public: biodata()
		{
			name=NULL;
			div=NULL;
			dob=NULL;
			bloodgroup=NULL;
			address=NULL;
			telephone=NULL;
			drivingLicence=NULL;
			mobile=0;
		}

		inline int noOfRec(int num);
		inline int acceptname();
		inline int acceptRollno();
		inline int acceptDiv();
		inline int acceptdob();
		inline int acceptbloodgrp();
		inline int acceptaddress();
		inline int acceptLandline();
		inline int acceptMob();
		inline int acceptDrivingLic();
		inline int show();

		~biodata()
		{
			delete name;
			delete div;
			delete dob;
			delete bloodgroup;
			delete address;
			delete telephone;
			delete drivingLicence;
			delete mobile;
		}
};

 int main()
{
	static int num;
	cout<<"enter number of records you want to add"<<endl;
	cin>>num;
	biodata a[num],b;
	b.noOfRec(num);
	for(int i=0;i<num;i++)
	{
		a[i].acceptRollno();
		a[i].acceptDiv();
		a[i].acceptname();
		a[i].acceptaddress();
		a[i].acceptLandline();
		a[i].acceptMob();
		a[i].acceptdob();
		a[i].acceptbloodgrp();
		a[i].acceptDrivingLic();
	}
	for(int i=0;i<num;i++)
	{
		a[i].show();
	}

	return 0;
}

	int biodata :: acceptname()
		{
			cout<<"enter name"<<endl;
			name=new char[30];
      ws(cin);
			cin.getline(name,30);
			return 0;
		}
	int biodata :: acceptRollno()
		{
			cout<<"enter your roll number "<<endl;
			rollno =new char;
			cin>>rollno;
			return 0;
		}
	int biodata :: acceptDiv()
		{
			cout<<"enter your division"<<endl;
			div=new char;
			cin>>div;
			return 0;
		}


	int biodata :: noOfRec(int num)
	{
		this->num=num;
		cout<<"you have entered "<<num<<" records"<<endl;
	}

	int biodata :: acceptdob()
	{
		cout<<"enter dob "<<endl;
		dob=new char[11];
		cin>>dob;
	}

	int biodata :: acceptbloodgrp()
		{
			cout<<"enter bloodgroup"<<endl;
			bloodgroup=new char[10];
			cin>>bloodgroup;
		}
	int biodata :: acceptaddress()
		{
			cout<<"enter your address "<<endl;
			address=new char[50];
      ws(cin);
			cin.getline(address,50);
		}

	 int biodata :: acceptLandline()
	 	{
	 		cout<<"enter your landline number "<<endl;
	 		telephone=new char[12];
	 		cin>>telephone;
	 	}

	 int biodata :: acceptMob()
	 	{
	 		cout<<"enter your mobile number "<<endl;
	 		mobile=new char[15];
	 		cin>>mobile;
	 	}

	 int biodata :: acceptDrivingLic()
	 	{
	 		cout<<"enter your driving license number"<<endl;
	 		drivingLicence=new char[15];
	 		cin>>drivingLicence;
	 	}
		int biodata :: show()
				{
					cout<<endl;
					cout<<"\t\t\t\t**********your biodata is**********"<<endl;
					cout<<"\t\troll no : "<<rollno<<endl;
					cout<<"\t\tdivision : "<<div<<endl;;
					cout<<"\t\tname : "<<name<<endl;
					cout<<"\t\taddress : "<<address<<endl;
					cout<<"\t\ttelephone number : "<<telephone<<endl;
					cout<<"\t\tmobile number : "<<mobile<<endl;
					cout<<"\t\tdate of Birth : "<<dob<<endl;
					cout<<"\t\tbloodgroup : "<<bloodgroup<<endl;
					cout<<"\t\tdriving license number : "<<drivingLicence<<endl;
				}
