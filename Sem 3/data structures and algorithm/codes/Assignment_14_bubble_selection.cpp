
#include<iostream>
#include<stdlib.h>

using namespace std;

void Bubble(float * , int);
void Selection(float* ,int);

int main()
{
	int i,j,n,ch;
	float *arr;
	cout<<"Enter the number of the Students : ";
	cin>>n;

	arr=(float*)malloc(sizeof(float)*n);
	for(i=0;i<n;i++)
	{
	cout<<"Enter the Percent of the student with roll no  "<<i+1<<" : ";
	cin>>arr[i];
	}
	cout<<"\n";
	cout<<"\n\tList of Percentage of Students : "<<endl;
	for(i=0;i<n;i++)
	{
	cout<<"\t"<<arr[i];
	}
	cout<<endl;

	do{
		cout<<"\n\n\tENTER : ";
		cout<<"\n\t1.To Sort the Percentage using Bubble Sort : ";
		cout<<"\n\t2.To Sort the Percentage using Selection Sort : ";
		cout<<"\n\t0.Exit!!! \n";
		cin>>ch;

		switch(ch)
		{
			case 1:
			Bubble(arr,n);
			break;

			case 2:
			Selection(arr,n);
			break;


		}
	}while(ch!=0);
return 0;
}

void Bubble(float* arr1,int no)
{
	float temp;
	for(int i=0;i<no;i++)
	{
		for(int j=i+1;j<no;j++)
		{
			if(arr1[i]>arr1[j])
			{
				temp=arr1[i];
				arr1[i]=arr1[j];
				arr1[j]=temp;
			}
		}
	}

	cout<<"\n\tThe Percentage of Students in Sorted order : \n";
	for(int i=0;i<no;i++)
	{
		cout<<"\t"<<arr1[i];
	}
}

void Selection(float *arr1, int no)
{
	int smallest;
	float temp;
	for(int i=0;i<no-1;i++)
	{
		smallest = i;
		for(int j=i+1;j<no;j++)
		{
			if(arr1[smallest]>arr1[j])
			{
				smallest=j;
			}

		}
		if(i!=smallest)
		{
			temp=arr1[i];
			arr1[i]=arr1[smallest];
			arr1[smallest]=temp;
		}
	}

	cout<<"\n\tThe Percentage of Students in Sorrted order : \n";
	for(int i=0;i<no;i++)
	{
		cout<<"\t"<<arr1[i];
	}
}




/*
********************OUTPUT**************************

Enter the number of the Students : 5
Enter the Percent of the student with roll no  1 : 78
Enter the Percent of the student with roll no  2 : 58
Enter the Percent of the student with roll no  3 : 91
Enter the Percent of the student with roll no  4 : 88
Enter the Percent of the student with roll no  5 : 86


        List of Percentage of Students :
        78      58      91      88      86


        ENTER :
        1.To Sort the Percentage using Bubble Sort :
        2.To Sort the Percentage using Selection Sort :
        0.Exit!!!
1

        The Percentage of Students in Sorted order :
        58      78      86      88      91

        ENTER :
        1.To Sort the Percentage using Bubble Sort :
        2.To Sort the Percentage using Selection Sort :
        0.Exit!!!
2

        The Percentage of Students in Sorted order :
        58      78      86      88      91

        ENTER :
        1.To Sort the Percentage using Bubble Sort :
        2.To Sort the Percentage using Selection Sort :
        0.Exit!!!
0



*/
