#include<iostream>
#include<limits>
using namespace std;
int l;
int u;

class quick
{

private:
		int i,j,cn,size;

		float *a,temp,pivot;

public:
		void display();
		void getdata();
		void sort(int,int);
		void top();

};


void quick:: getdata()
{


	cout<<"enetr the strength of the class"<<endl;
	for(;;)
			{
				if(cin>>size)
				{
					break;
				}

				else
				{
					cout<<"please enter a valid no"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

	a = new float[size];

	 l = 0;
	 u= size -1;

	cout<<"enter the percentage of studemts"<<endl;
	for(i=0;i<size;i++)
	{
		for(;;)
			{
				if(cin>>a[i])
				{
					if(a[i]>100)
				{

					cout<<"it is not valid"<<endl;
				}
					else
					{
						break;
					}
				}

				else
				{
					cout<<"please enter a valid no"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

	}

		cout<<"displaying the marks of students"<<endl;
		for(i=0;i<size;i++)
		{
			cout<<a[i]<<endl;
		}
}

void quick::sort(int l, int u)
{



   if(l<u)
   {
   	pivot=a[l];
   	i=l;
   	j=u;

    while(i<j)
   	{
     	 while(a[i] <= pivot && i<j )
	 		i++;
    	  while(a[j]>pivot && i<=j )
	  	 j--;
      		if(i<=j)
      		{
     			temp=a[i];
      			a[i]=a[j];
      			a[j]=temp;
      		}
  	}

  	temp=a[j];
  	a[j]=a[l];
  	a[l]=temp;
  	cout <<"\n";


  		sort(l,j-1);
  		sort(j+1,u);
   }

}

void quick :: display()
{
	for(int i = 0; i <size; i++)
		cout<<a[i]<<endl;
}

void quick::top()
{
	int c;
	c=size-1;
	if(size<5)
	{
		cout<<"Top "<<size<<" students are :"<<endl;
		do
		{
			cout<<a[c]<<endl;
			c--;
		}while(c>=0);
	}
	else
	{
		cout<<"top 5 students are"<<endl;
		cn=0;
		while(cn!=5)
		{
			cout<<a[c]<<endl;
			c--;
			cn++;
		}
	}


}




int main()
{
	int ch;
	quick o;
	do
	{

		cout<<"enter your  choice"<<endl;
		cout<<"1.getdata"<<endl<<"2.sort"<<endl<<"3.display"<<endl<<"4.top scores"<<endl<<"0 exit"<<endl;
		for(;;)
			{
				if(cin>>ch)
				{
					break;
				}

				else
				{
					cout<<"please enter a valid no"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

		switch(ch)
		{

		case 1:
				o.getdata();
				break;
		case 2:
				o.sort(l,u);
				break;
		case 3:
				o.display();
				break;
		case 4:
				o.top();
				break;
		default:
				if(ch!=0)
					cout<<"INVALID!!!!!!!!"<<endl;
					break;
		}

		cout<<endl;
	}while(ch!=0);

	return 0;

}
/*
OUTPUT
entr yur choice
1.getdata
2.sort
3.display
4.top scores
0 exit
1
enetr the strength of the class
6
enter the percentage of studemts
23.4
45.2
67.2
12.3
89.2
45.1
displaying the marks of students
23.4
45.2
67.2
12.3
89.2
45.1

enter your  choice
1.getdata
2.sort
3.display
4.top scores
0 exit
2






enter your  choice
1.getdata
2.sort
3.display
4.top scores
0 exit
3
12.3
23.4
45.1
45.2
67.2
89.2

enter your  choice
1.getdata
2.sort
3.display
4.top scores
0 exit
4
top 5 students are
89.2
67.2
45.2
45.1
23.4

entr yur choice
1.getdata
2.sort
3.display
4.top scores
0 exit
*/
