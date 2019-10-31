// write a c++ program to create a Calculator for an arithmatic operation (+ , - , * , / ) the program should take 2 inputs from the user and performs the operationgiven by the user depending upon the operator enteredby the user. use a switch statement to select an operation and finally display the result
#include<iostream>
using namespace std;
class Calculator
{
	public : float no1,no2,ans;
	public : char oper ;
	public : int operation()
       {
	do
	{

			cout<<"enter your equation "<<endl;
			cin>>no1>>oper>>no2;


			switch(oper)
			{
				case '+' : ans=no1+no2;
					   cout<<"your addition is "<<ans<<endl;
					   break;

				case '-' : ans=no1-no2;
					   cout<<"your subtraction is "<<ans<<endl;
					   break;

				case '*' : ans=no1*no2;
					   cout<<"your multiplication is "<<ans<<endl;
					   break;

				case '/' : ans=no1/no2;
					   cout<<"your division is "<<ans<<endl;
	                                   break;
				default : cout<<"you entered wrong choice.. plz try again"<<endl;
		}
	cout<<"do you want to continue???"<<endl;
	cout<<"press y to continue & n to exit "<<endl;;
	cin>>oper;
	}while(oper!='n');
      }
};

int main()
{
	Calculator calc;
	calc.operation();
}
