/*Create User defined exception to check the following conditions and throw the exception if the
criterion does not meet.
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4 - wheeler
Accept age, Income, City, Vehicle from the user and check for the conditions mentioned
above. If any of the condition not met then throw the exception. */

#include<iostream>
#include<string.h>
using namespace std;
void try_catch();
int main()
{
	try_catch();
	return 0;
}

void try_catch()
{
	int age,income,vehicle;
	//char city[10];
	string city;
	//cout<<"enter age,income,vehicle,city"<<endl;
	//cin>>age>>income>>vehicle>>city;
	try
	{
		cout<<"enter age"<<endl;
		cin>>age;
		if(age>=18&&age<=55)
		cout<<"your age is valid"<<endl;
		else
		throw(age);

		cout<<"enter your income"<<endl;
		cin>>income;
		if(income>=50000 &&income<=100000)
		cout<<"valid salery"<<endl;
		else
		throw(income);

		cout<<"enter your vehicle type"<<endl;
		cin>>vehicle;
		if(vehicle==4)
		cout<<"valid vehicle"<<endl;
		else
		throw(vehicle);

		cout<<"enter your city "<<endl;
		cin>>city;
		if(city=="pune"||city=="mumbai"||city=="bangalore"||city=="chennai")
		cout<<"valid city"<<endl;
		else
		throw(city);

		//cout<<city<<endl;
		//if(strcmp(city,"pune")==1||strcmp(city,"mumbai")==1||strcmp(city,"bangalore")==1||strcmp(city,"chennai")==1)
		//cout<<"true"<<endl;
		//else
		//cout<<"false"<<endl;

		//if(strcmp(city,"pune")==1||strcmp(city,"mumbai")==1||strcmp(city,"bangalore")==1||strcmp(city,"chennai")==1)
		//cout<<"valid city"<<endl;
		//else
		//throw(city);
	}
	catch(...)
	{
		cout<<"error plz try again...."<<endl;
		try_catch();
	}
}
