//Q2 implement a class complex which represents the complex number data type and implement the following functions:
//1. constructor which creates ther complex number 0+0i
//2. overload the operator + to add 2 complex numbers
//3. overload the * operator to multiply 2 complex numbers
//4. overload the << and >> operators to print and read complex numbers
#include<iostream>
using namespace std;
class complex
{
	public: float no1,no2;
	complex()
	{
		no1=no2=0;
	}
	complex(float a,float b)
	{
		no1=a;
		no2=b;
	}
	complex operator + (complex);
	complex operator - (complex);
	complex operator * (complex);
	complex operator / (complex);
	//complex operator << (complex);
	complex operator >> (complex);
};
complex complex :: operator + (complex obj)
{
	complex temp;
	temp.no1=no1+obj.no1;
	temp.no2=no2+obj.no2;
	return (temp);
}

complex complex :: operator - (complex obj1)
{
	complex temp;
	temp.no1=no1-obj1.no1;
	temp.no2=no2-obj1.no2;
	return temp;
}

complex complex :: operator * (complex obj)
{
	complex temp;
	temp.no1=(no1*obj.no1)-(no2*obj.no2);
	temp.no2=(no1*obj.no2)+(no2*obj.no1);
	return temp;
}

complex complex :: operator / (complex obj)
{
	complex temp;
	temp.no1=((no1*obj.no1)-(no2*(-obj.no2)))/((obj.no1*obj.no1)+(obj.no2*obj.no2));
	temp.no2=((no1*(-obj.no2))+(no2*obj.no1))/((obj.no1*obj.no1)+(obj.no2*obj.no2));
	return temp;
}

complex complex :: operator >> (complex obj)
{
	float re1,re2,im1,im2;
	complex c1,c2,c3,c4,c5,c6;
	cout<<"enter real part and imaginary part of the complex number1"<<endl;
	cin>>re1>>im1;
	cout<<"enter real part and imaginary part of the complex number2"<<endl;
	cin>>re2>>im2;
	c1=complex(re1,im1);
	c2=complex(re2,im2);
	c3=c1+c2;
	c4=c1-c2;
	c5=c1*c2;
	c6=c1/c2;
	cout<<"complex number 1 is"<<endl;
	cout<<re1<<"+"<<im1<<"j"<<endl;
	cout<<"complex number 2 is"<<endl;
	cout<<re2<<"+"<<im2<<"j"<<endl;
	cout<<"sum is "<<endl;
	cout<<c3.no1<<"+"<<c3.no2<<"j"<<endl;
	cout<<"sub is "<<endl;
	cout<<c4.no1<<"+"<<c4.no2<<"j"<<endl;
	cout<<"mul is "<<endl;
	cout<<c5.no1<<"+"<<c5.no2<<"j"<<endl;
	cout<<"div is "<<endl;
	cout<<c6.no1<<"+"<<c6.no2<<"j"<<endl;
}

int main()
{
	char ch;
	do
	{
		complex s1;
		s1>>(s1);
		cout<<"do you want to continue...??"<<endl;
		cout<<"press y to continue n to quit"<<endl;
		cin>>ch;
	} while(ch!='n');
	return 0;
}
