
/*

                        NAME-SHRIRANG MHALGI
                        DIV-B BATCH-B1
			 			ROLL NO.-222006
STATEMENT :
Write C++ program to maintain club members, sort on roll numbers in ascending order.
Write function  ̳Ternary_Search to search whether particular student is member of club.
Ternary search is modified binary search that divides array into 3 halves instead of two.
*/

#include<iostream>
#include<limits>
using namespace std;

		int a[20],key,n,ch,m1,m2,x,temp=0,i=0,j=0;

void getdata()
{
	cout<<"Enter the total members of club :"<<endl;
		for(;;)
			{
				if(cin>>n)
				{
					break;
				}

				else
				{
					cout<<"please enter a valid no !!!"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}

	cout<<"Enter the roll number : "<<endl;
	for(int i=0;i<n;i++)
	{
		for(;;)
			{
				if(cin>>a[i])
				{
					break;
				}

				else
				{
					cout<<"please enter a valid no !!!"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
	}
}

void sort(int a[])
{
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	cout<<"sort roll number are :"<<endl;
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<"\t";
	}
}

int ternarys(int a[],int n,int m1,int m2,int key)
{
	if(m1<0 ||m2>n-1 || m1>m2)
	{
		return -1;
	}
	if(key==a[m1])
	{
		return m1;
	}
	if(key==a[m2])
	{
		return m2;
	}
	if(key<a[m1])
	{
		return ternarys(a,n,m1-1,m2,key);
	}
	if(key>a[m1]&& key<a[m2])
	{
		return ternarys(a,n,m1+1,m2-1,key);
	}
	if(key>a[m2])
	{
		return ternarys(a,n,m1,m2+1,key);
	}
}

int main()
{
do
{
	cout<<"\n\t\t1]. Accept data"<<endl;
	cout<<"\n\t\t2]. sort the data"<<endl;
	cout<<"\n\t\t3]. searching by using ternary search."<<endl;
	cout<<"\n\t\t4]. Exit"<<endl;

	cout<<"Enter the choice"<<endl;
	cin>>ch;

	switch(ch)
	{
		case 1 :
			getdata();
			break;

		case 2 :
			sort(a);
			break;

		case 3 :
			m1=n/3;
			m2=(n/3)*2;
			cout<<"Enter the elements to be search : "<<endl;
			for(;;)
			{
				if(cin>>key)
				{
					break;
				}

				else
				{
					cout<<"please enter a valid no !!!"<<endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
				}
			}
			if(ternarys(a,n,m1,m2,key)==-1)
			{
				cout<<"Roll number is absent !!!"<<endl;
			}
			else
			{
				cout<<"Roll number is present"<<endl;
				x=ternarys(a,n,m1,m2,key);
				cout<<"& postion is : "<<x<<endl;
			}
			break;

		case 4 :
			//exit.
			break;

		default :
			cout<<"Enter valid choice !!!"<<endl;
			break;
	}
}while(ch!=4);
return 0;
}


/* output
1]. Accept data

		2]. sort the data

		3]. searching by using ternary search.

		4]. Exit
Enter the choice
1
Enter the total members of club :
4
Enter the roll number :
1
2
3
4

		1]. Accept data

		2]. sort the data

		3]. searching by using ternary search.

		4]. Exit
Enter the choice
2
sort roll number are :
1	2	3	4
		1]. Accept data

		2]. sort the data

		3]. searching by using ternary search.

		4]. Exit
Enter the choice
3
Enter the elements to be search :
2
Roll number is present
& postion is : 1

		1]. Accept data

		2]. sort the data

		3]. searching by using ternary search.

		4]. Exit
Enter the choice
4
*/
