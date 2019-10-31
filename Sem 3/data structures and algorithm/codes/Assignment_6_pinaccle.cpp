#include<iostream>
using namespace std;
struct node
{
    long prn;
    char name[10];
    node *next;
}*temp,*head,*New;

void create()
{
    int flag;
    char con;
    temp=NULL;
    flag=1;
    do
    {
        New=new node;
        cout<<"Enter the PRN no. ";
        cin>>New->prn;
        cout<<"Enter the name ";
        cin>>New->name;
        New->next=NULL;
        if(flag==1)
        {
            head=New;
            temp=head;
            flag=0;
        }
        else
        {
            temp->next=New;
            temp=New;
        }
        cout<<"Do you wanna add more nodes?(y/n) ";
        cin>>con;
    }while(con=='y');
}

void atfirst()
{
    New=new node;
    cout<<"Enter the PRN no. of President ";
    cin>>New->prn;
    cout<<"Enter the name of President ";
    cin>>New->name;
    New->next=NULL;
    if(head==NULL)
        head=New;
    else
    {
        temp=head;
        head=New;
        New->next=temp;
    }
}

void atlast()
{
    New=new node;
    cout<<"Enter the PRN no. of secretary ";
    cin>>New->prn;
    cout<<"Enter the name of secretary ";
    cin>>New->name;
    New->next=NULL;
    if(head==NULL)
        head=New;
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=New;
    }
}

void atmid()
{
    long data;
    New=new node;
    cout<<"Enter the PRN no. ";
    cin>>New->prn;
    cout<<"Enter the name ";
    cin>>New->name;
    New->next=NULL;
    cout<<"Enter the prn after which you wanna enter new node: ";
    cin>>data;
    if(head==NULL)
        head=New;
    else
    {
        temp=head;
        while(temp->prn!=data)
        {
            temp=temp->next;
        }
        New->next=temp->next;
        temp->next=New;
    }
}

void srch()
{
    int flag=1;
    long data;
    cout<<"Enter the prn you wanna search ";
    cin>>data;
    temp=head;
    while(temp!=NULL)
    {
        if(temp->prn==data)
        {
            flag=0;
            break;
        }
        temp=temp->next;
    }
    if(flag==0)
        cout<<"The prn is present";
    else
        cout<<"Not present";
}

void del()
{
    node *p,*q;
    p=head;
    long data;
    cout<<"Enter the prn you want to delete : ";
    cin>>data;
    if(head->prn==data)
    {
        p=head;
        head=head->next;
        delete p;
    }
    else
    {
     while((p->next)->prn!=data && p->next!=NULL)
        p=p->next;
     if((p->next)->prn==data)
      {
        q=p->next;
        p->next=(p->next)->next;
        delete q;
      }
    }
}

void count()
{
    int cnt=0;
    temp=head;
    while(temp!=NULL)
    {
        temp=temp->next;
        cnt++;
    }
    cout<<"The count of the members is "<<cnt;
}

void rev(node *head)
{
    if(head==NULL)
        return;
    rev(head->next);
    cout<<head->prn<<" "<<head->name<<"\n";
}

void concat()
{
    node *temp1,*head1,*New1;
    int flag;
    char con;
    temp1=NULL;
    flag=1;
    cout<<"Enter the second linked list: \n";
    do
    {
        New1=new node;
        cout<<"Enter the PRN no. ";
        cin>>New1->prn;
        cout<<"Enter the name ";
        cin>>New1->name;
        New1->next=NULL;
        if(flag==1)
        {
            head1=New1;
            temp1=head1;
            flag=0;
        }
        else
        {
            temp1->next=New1;
            temp1=New1;
        }
        cout<<"Do you wanna add more nodes?(y/n) ";
        cin>>con;
    }while(con=='y');
    temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=head1;
        temp1=head;
}

void disp()
{
     temp=head;
    while(temp!=NULL)
    {
        cout<<temp->prn<<" ";
        cout<<temp->name<<"\n";
        temp=temp->next;
    }
}


int main()
{
    int ch;
    char con;
    do
    {
        cout<<"Choice Menu\n";
        cout<<"1.Create\n";
        cout<<"2.Insert president\n";
        cout<<"3.Insert Secretary\n";
        cout<<"4.Insert Member\n";
        cout<<"5.Search\n";
        cout<<"6.Delete\n";
        cout<<"7.Count\n";
        cout<<"8.Reverse\n";
        cout<<"9.Display\n";
        cout<<"10.Concat\n";
        cout<<"Enter your choice ";
        cin>>ch;
        switch(ch)
        {
        case 1:create();
        break;
        case 2:atfirst();
        break;
        case 3:atlast();
        break;
        case 4:atmid();
        break;
        case 5:srch();
        break;
        case 6:del();
        break;
        case 7:count();
        break;
        case 8:rev(head);
        break;
        case 9:disp();
        break;
        case 10:concat();
        break;
        default:cout<<"Enter correct choice....";
        }
        cout<<"\n\nDo you wanna continue?(y/n) ";
        cin>>con;
    }while(con=='y');
}

/* -----OUTPUT------

Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 1
Enter the PRN no. 1
Enter the name a
Do you wanna add more nodes?(y/n) y
Enter the PRN no. 2
Enter the name b
Do you wanna add more nodes?(y/n) n


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 2
Enter the PRN no. of President 111
Enter the name of President aaa


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 3
Enter the PRN no. of secretary 222
Enter the name of secretary rrr


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 4
Enter the PRN no. 3
Enter the name ee
Enter the prn after which you wanna enter new node: 2


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 9
111 aaa
1 a
2 b
3 ee
222 rrr


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 5
Enter the prn you wanna search 2
The prn is present

Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 6
Enter the prn you want to delete : 2


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 9
111 aaa
1 a
3 ee
222 rrr


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 7
The count of the members is 4

Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 8
222 rrr
3 ee
1 a
111 aaa


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 10
Enter the second linked list:
Enter the PRN no. 1111
Enter the name rr
Do you wanna add more nodes?(y/n) n


Do you wanna continue?(y/n) y
Choice Menu
1.Create
2.Insert president
3.Insert Secretary
4.Insert Member
5.Search
6.Delete
7.Count
8.Reverse
9.Display
10.Concat
Enter your choice 9
111 aaa
1 a
3 ee
222 rrr
1111 rr


Do you wanna continue?(y/n) n

Press any key to continue . . .

*/
