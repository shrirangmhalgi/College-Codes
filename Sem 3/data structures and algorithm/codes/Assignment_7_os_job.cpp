
#include<iostream>
#include<stdlib.h>

using namespace std;
class queue
{
 private:
		int q[20],i,y;
 		int rear,front;
public:
 			queue()
 			{
 				rear=-1;
 				front=-1;
 			}
			void Insert(int n)
			{
				if(rear<n)
				{
					if(front==-1 && rear==-1)
					{
						front=rear=0;
					}
					cout<<"Enter The Job Id"<<endl;
       					cin>>y;
					q[rear++]=y;
					cout<<"Job Id inserted "<<y<<endl;
				}
				if(rear>=n)
				{
					cout<<"queue overflow"<<endl;
				}
			}



							void Delete()
							{
								if (front==rear)
								{
									cout<<"Job Id is empty"<<endl;
									return;
								}
								else
								{
										cout<<"Job "<<q[front++]<<" id deleted."<<endl;
								}
							}

							void Display()
							{
								if (front==rear)
								{

									cout<<"Job Id is empty"<<endl;
								}

								else
								{
									for(int i=front;i<rear;i++)
									{
											cout<<"The Job id Are :"<<endl;
											cout<<q[i] <<" "<<endl;
									}



								}

							}
};

int main()
{
	int ch,n;
	queue qu;
	cout<<"how many elemnts in queue/"<<endl;
	cin>>n;

		cout<<" Please Select One Of The Following Options !"<<endl;
			do
			{
			cout<<" 1.Insert\n 2.Delete\n 3.Display\n 4.Exit"<<endl;
			cin>>ch;

				switch(ch)
				{
					case 1:
       						 qu.Insert(n);
       						 break;
					case 2: qu.Delete();
       						 break;
					case 3: qu.Display();
       						 break;
					case 4: exit(0);
				}
				cout<<endl;
			}while(ch!=0);
						return 0;


}
/*
OUTPUT-:
Please Select One Of The Following Options !
 1.Insert
 2.Delete
 3.Display
 4.Exit
1
Enter The Job Id
1
Job Id inserted 1

 1.Insert
 2.Delete
 3.Display
 4.Exit
1
Enter The Job Id
2
Job Id inserted 2

 1.Insert
 2.Delete
 3.Display
 4.Exit
1
Enter The Job Id
3
Job Id inserted 3

 1.Insert
 2.Delete
 3.Display
 4.Exit
2
Job Id Deleted 1

 1.Insert
 2.Delete
 3.Display
 4.Exit
2
Job Id Deleted 2

 1.Insert
 2.Delete
 3.Display
 4.Exit
2
Job Id Deleted 3

 1.Insert
 2.Delete
 3.Display
 4.Exit
2
Job Id is empty

 1.Insert
 2.Delete
 3.Display
 4.Exit
1
Enter The Job Id
1
Job Id inserted 1

 1.Insert
 2.Delete
 3.Display
 4.Exit
1
Enter The Job Id
2
Job Id inserted 2

 1.Insert
 2.Delete
 3.Display
 4.Exit
3
The Job id Are :
1
The Job id Are :
2

 1.Insert
 2.Delete
 3.Display
 4.Exit
0
*/
