
#include<iostream>
#include<limits>
using namespace std;
class searching
{

private:
	unsigned int i;

public:

	void senti();
	void lin();
	void bin();
	int min(int ,int);
	void fibb();

};


void searching::senti()
{
	unsigned int Size;
	int *Arr,Search;

			cout << "\n how many students attended ? : "<<endl;
			cin >> Size;

			Arr = new int[Size+1];


			cout << "\n Enter roll no which attended : "<<endl;

 			for(i=0;i<Size;i++)
			{
				cin >> Arr[i];
			}

				cout << "\n Which roll no do you want to search? : "<<endl;
				cin >> Search;

				Arr[Size+1]=Search;


						i=0;
						while(Arr[i]!=Search)
						{
							i++;
						}

								if(i==Size+1)
								{
								cout << "\n Sentinel reached. roll no not found \n";
								}

								else

								cout << "\n roll no found at " << i+1 << " position \n";

}


void searching::lin()
{
	unsigned int size,search,flag;
	int *arr;

	cout<<"how many students attended the programme?:"<<endl;
	cin>>size;

	arr=new int[size];

	cout<<"enter the roll no which attended the programmes"<<endl;

	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}

		cout<<"enter the roll no which you want to search";
		cin>>search;


			for(i=0;i<size;i++)
			{

				if(arr[i]==search)
				{

				flag=1;
				break;

				}

				else
				{
				flag=0;
				}
			}

					if(flag==1)
					{
					cout<<"roll no found at  "  <<i+1<< "  position"<<endl;
					}

						else if(flag==0)
						{
							cout<<"roll no not found"<<endl;
						}

}

void searching::bin()
{

	unsigned int size,search,first,last,middle;
	int *arr;

	cout<<"how many students attended the programme?:"<<endl;
	cin>>size;

	arr=new int[size];

	cout<<"enter the roll no which attended the programmes"<<endl;

	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}

		cout<<"enter the roll no which you want to search";
		cin>>search;

		first=0;
		last=size-1;
		middle=(first+last)/2;

			while(first<=last)
			{
				if(arr[middle]<search)
				{

					first=middle+1;
				}
					else if(arr[middle]=search)
					{
						cout<<"roll no found at position no  "<<middle+1<<endl;
						break;
					}

						else
						{
							last=middle-1;
						}

							middle=(first+last)/2;

				}


	if(first>last)
	{

	cout<<"roll no not found"<<endl;

	}

}

int searching::min(int x,int y)
{

return ((x<=y)?x:y);
}


void searching::fibb()
{
	unsigned int size,search,flag=0;
	int *arr,j;

	cout<<"how many students attended the programme?:"<<endl;
	cin>>size;

	arr=new int[size];

	cout<<"enter the roll no which attended the programmes"<<endl;

		for(i=0;i<size;i++)
		{
			cin>>arr[i];
		}

	cout<<"enetr the roll no which you want to search"<<endl;
	cin>>search;

			int fibm1=0;
			int fibm2=1;
			int fibm=fibm1+fibm2;


				while(fibm<size)
				{
					fibm2=fibm1;
					fibm1=fibm;
					fibm=fibm2+fibm1;
				}
			int offset=-1;



					while(fibm>1)
					{

						 j=min(offset+fibm2,size-1);

						if(arr[j]<search)
						{
							fibm=fibm1;
							fibm1=fibm2;
							fibm2=fibm-fibm1;
							offset=j;
						}

						else if(arr[j]>search)
						{
							fibm=fibm2;
							fibm1=fibm1-fibm2;
							fibm2=fibm-fibm1;

						}

						else
						flag=1;
						break;


					}


	if(flag=1)
	{

	cout<<"roll no at"<<j<<endl;

	}



	else if(fibm1 && arr[offset+1]==search)
	{

		cout<<"roll no at "<<offset +1<<endl;

	}

	else

	{

	cout<<"roll no not found"<<endl;
	}

}










int main()
{

	searching o;

	unsigned int ch;
	int c;

	do
	{
	cout<<"1.sentinental"<<endl<<"2.linear"<<endl<<"3.binary"<<endl<<"4.fibbo"<<endl<<"0.exit"<<endl;

	cout<<"eneter your choice"<<endl;
	cin>>ch;

		switch(ch)

		{

			case 1:
				o.senti();
				break;

			case 2:
				o.lin();
				break;

			case 3:
				o.bin();
				break;

			case 4:
				o.fibb();
				break;



			case 0:
				break;

			default:
				cout<<"Invalid choce"<<endl;
				break;
		}

		cout<<endl;
	}while(ch!=0);






	return 0;
}

/*

OUTPUT-:

1.sentinental
2.linear
3.binary
4.fibbo
0.exit
eneter your choice
1

 how many students attended ? :
3

 Enter roll no which attended :
2
1
4

 Which roll no do you want to search? :
4

 roll no found at 3 position

1.sentinental
2.linear
3.binary
4.fibbo
0.exit
eneter your choice
2
how many students attended the programme?:
3
enter the roll no which attended the programmes
2
5
3
enter the roll no which you want to search1
roll no not found

1.sentinental
2.linear
3.binary
4.fibbo
0.exit
eneter your choice
3
how many students attended the programme?:
2
enter the roll no which attended the programmes
1
2
enter the roll no which you want to search2
roll no found at position no  2

1.sentinental
2.linear
3.binary
4.fibbo
0.exit
eneter your choice
4
how many students attended the programme?:
4
enter the roll no which attended the programmes
1
2
3
4
enetr the roll no which you want to search
1
roll no at1

1.sentinental
2.linear
3.binary
4.fibbo
0.exit

*/
