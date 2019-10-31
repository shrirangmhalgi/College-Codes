
#include<iostream>
#include<limits>
using namespace std;

class shell
{

private:

	int size,i,j,cn,step;
	float temp,small;
	float *arr;

public:
	void getdata();
	void shelsort();
	void insertion();
	void top();
};


void shell::getdata()
{

	cout<<"enter the no. of students"<<endl;
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


	arr=new float[size];

	cout<<"enter the percentage of students"<<endl;

	for(i=0;i<size;i++)
	{
		for(;;)
		{
			if(cin>>arr[i])
			{

				if(arr[i]>100)
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



	cout<<"enetred marks are"<<endl;
		for(i=0;i<size;i++)
		{
			cout<<arr[i]<<endl;
		}
}

void shell::shelsort()
{


	cout<<"shell sort"<<endl;
	for(step=size/2;step>0;step=step/2)
	{

		for(i=step;i<size;i++)
		{

			temp=arr[i];
			for(j=i;j>=step;j=j-step)


				if(temp<arr[j-step])
				arr[j]=arr[j-step];

				else
				break;

				arr[j]=temp;

		}
	}


	cout<<" after sorting"<<endl;
	for(i=0;i<size;i++)
	{

		cout<<arr[i]<<endl;
	}
}



void shell::insertion()
{
	cout<<"insertion sort"<<endl;

		for(i=1;i<size;i++)
		{

			small=arr[i];
			for(j=i-1;j>=0 && small<arr[j];j--)
				arr[j+1]=arr[j];

				arr[j+1]=small;
		}

			cout<<"after sorting"<<endl;
				for(i=0;i<size;i++)
				{
					cout<<arr[i]<<endl;
				}
}



void shell::top()
{

	cout<<"displaying top  scores"<<endl;
	i=size-1;
	if(size<5)
	{
		cout<<"Top "<<size<<" students are :"<<endl;
		do
		{
			cout<<arr[i]<<endl;
			i--;
		}while(i>=0);
	}
	else
	{
		cn=0;
		while(cn!=5)
		{
			cout<<arr[i]<<endl;
			i--;
			cn++;
		}
	}
}





int main()
{

	shell s;

	int ch;


		do
		{

			cout<<"1.enetr marks"<<endl<<"2.sort( by shell ) marks"<<endl<<" 3.by insertion sort"<<endl<<"4.top five scores"<<endl<<"0.exit"<<endl;
			cin>>ch;

			switch(ch)
			{

				case 1:

					s.getdata();
					break;
				case 2:

					s.shelsort();
					break;

				case 3:
					s.insertion();
					break;

				case 4:

					s.top();
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
1.enetr marks
2.sort( by shell ) marks
 3.by insertion sort
4.top five scores
0.exit
1
enter the no. of students
4
enter the percentage of students
12.4
78.4
67.3
r
please enter a valid no
34.2
enetred marks are
12.4
78.4
67.3
34.2

1.enetr marks
2.sort( by shell ) marks
 3.by insertion sort
4.top five scores
0.exit
3
insertion sort
after sorting
12.4
34.2
67.3
78.4

1.enetr marks
2.sort( by shell ) marks
 3.by insertion sort
4.top five scores
0.exit
4
displaying top  scores
Top 4 students are :
78.4
67.3
34.2
12.4

1.enetr marks
2.sort( by shell ) marks
 3.by insertion sort
4.top five scores
0.exit
*/
