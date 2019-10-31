#include<iostream>

using namespace std;
int city_num,i,j;
char ans,t;

class node{
	string data;
	char time;
	node *next;
	friend class Graph;
};

class Graph{
	string city[10];
	node *arr[10];
	public:
		int create();
			char city_matrix[10][10];
			
		int matrix();
		void dis_m();
		int list();
		void dis_l();
		
};
	
int Graph :: create(){
		cout<<"Enter the number of cities : ";
		cin>>city_num;
		for(i=0;i<city_num;i++)
		{
			cout<<"City "<<i+1<<" : ";
			cin>>city[i];
		}
		return city_num;
	}

int Graph :: matrix(){
	for(i=0;i<city_num;i++)
	{	
		for(j=0;j<city_num;j++)
		{
			city_matrix[i][j]='-';
		}
	}

	for(i=0;i<city_num;i++)
	{
		for(j=0;j<city_num;j++)
		{
			if(i<=j)
				continue;
			else
			{
				cout<<"Is there flight between "<<city[i]<<" and "<< city[j]<<" (y/n)"<<endl;
				cin>>ans;
				if(ans=='y'||ans=='Y')
				{
					cout<<"Enter the time taken to fly : ";
					cin>>t;
					city_matrix[i][j]=t;
					city_matrix[j][i]=t;
				}
			}
		}
	}
}

void Graph :: dis_m(){
	cout<<"\n------------------ADJACENCY MATRIX-------------------\n\n";
	for(i=0;i<city_num;i++)
	{
		cout<<"\t"<<city[i];	
	}
	cout<<endl;
	for(i=0;i<city_num;i++)
	{	
		cout<<endl<<city[i]<<"\t";
		for(j=0;j<city_num;j++)
		{
			cout<<city_matrix[i][j]<<"\t";
		}
	}
}

int Graph :: list(){
	node *New,*temp1,*temp2,*t1,*t2;
	for(i=0;i<city_num;i++)
	{
		New = new node;
		New->next=NULL;
		New->time='-';
		New->data=city[i];
		arr[i]=New;
	}
	
	for(i=0;i<city_num;i++){
		for(j=i+1;j<city_num;j++){
			cout<<"Is there flight between "<<city[i]<<" and "<< city[j]<<" (y/n)"<<endl;
			cin>>ans;
			if(ans=='y'||ans=='Y')
			{
				temp1 = new node;
				temp1->next = NULL;
				temp2 = new node;
				temp2->next = NULL;
				temp1->data = city[j];
				temp2->data = city[i];
				cout<<"Enter the time taken to fly : ";
				cin>>t;
				temp1->time=t;
				temp2->time=t;
				
				t1 = arr[i];
				while(t1->next!=NULL)
					t1 = t1->next;
				t1->next = temp1;
				
				t2=arr[j];
				while(t2->next!=NULL)
					t2=t2->next;
				t2->next = temp2; 
			}
			else
				continue;
		}
	}
}

void Graph :: dis_l(){
	cout<<endl<<"----------------ADJACENCY LIST---------------\n";
	node *curr;
	i=0;
	while(i<city_num){
		curr = arr[i];
		cout<<curr->data;
		curr=curr->next;
		while(curr!=NULL)
		{
			cout<<" -> "<<curr->data<<","<<curr->time;
			curr=curr->next;
		}
		cout<<"\n";
		i++;
	}	
}

int main(){
	Graph ob;
	ob.create();
	int choice;
	do{
		cout<<"\n\n------------------ MENU -------------------";
		cout<<"\n1 : Adjacency matrix";
		cout<<"\n2 : Adjacency list";
		cout<<"\n3 : Exit";
		cout<<"\nEnter your choice : ";
		cin>>choice;
		switch(choice){
			case 1 : ob.matrix();
					 ob.dis_m();
					 break;
			case 2 : ob.list();
					 ob.dis_l();
					 break;
		}
	}while(choice!=3);
}
