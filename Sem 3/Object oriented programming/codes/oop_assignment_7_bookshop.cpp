/*A book shop maintains the inventory of books that are being sold at the shop. The list includes
details such as author, title, price, publisher and stock position. Whenever a customer wants a
book, the sales person inputs the title and author and the system searches the list and
displays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the
system displays the book details and requests for the number of copies required. If the
requested copies book details and requests for the number of copies required. If the requested
copies are available, the total cost of the requested copies is displayed; otherwise the message
―Required copies not in stock ‖ is displayed. Design a system using a class called books with
suitable member functions and Constructors. Use new operator in constructors to allocate
memory space required. Implement C++ program for the system. */


#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
static int count , flag_search;
int no_of_records;
class books
{
	char *author , *title, *publisher ;
	char *price , *stock;
	public:   books()
		{
			author=new char[50];
      //author=NULL;
			title=new char[50];
      //title=NULL;
			publisher=new char[50];
      //publisher=NULL;
			price=new char[10];
      //price=0;
			stock=new char[10];
      //stock=0;
		}

		int insert();
		int display();
		int search(string,string);
		int buy();
		int calcualate_cost();
    char get_title();
		//int stock();
		//int price();
};

char books :: get_title()
{
  return *title;
}

int books :: insert()
{
	int price_disp , stock_disp;
	cout<<"enter the title of the book"<<endl;
	ws(cin);
	cin.getline(title,50);
	cout<<"enter the author of the book"<<endl;
	cin.getline(author,50);
	cout<<"enter the publisher of the book"<<endl;
	cin.getline(publisher,50);
	cout<<"enter the price of 1 book"<<endl;
	ws(cin);
	cin.getline(price , 10);
	//price_disp=atoi(get_price());
	cout<<"enter the number of copies available"<<endl;
	cin.getline(stock,10);
	//stock_disp=atoi(get_stock());
	system("cls");
	cout<<"information added successfully"<<endl;
}

int books :: display()
{
	cout<<"title :- "<<title<<endl;
	cout<<"author :- "<<author<<endl;
	cout<<"publisher :- "<<publisher<<endl;
	cout<<"price :- "<<price<<endl;
	cout<<"stock :- "<<stock<<endl;
	cout<<endl;
}

int books :: search(string book_ip,string author_ip)
{
	if((title==book_ip) && (author==author_ip))
	flag_search=1;
}

int main()
{
  int CONDITION;
	books b[100];
  do
  {
    cout<<"\t\t------WELCOME-----\n"<<endl;
    cout<<"Press 1 to insert information for your reccords"<<endl;
    cout<<"Press 2 to display your entered reccords"<<endl;
    cout<<"Press 3 to search your existing reccords"<<endl;
    cout<<"Press 0 to exit"<<endl;
    cin>>CONDITION;
     switch (CONDITION)
     {
       case 1 :
       {
         system("cls");
				 cout<<"enter the number of records u want to insert"<<endl;
			   cin>>no_of_records;
			   //books b[no_of_records];
         for(int i=0;i<no_of_records;i++)
         {
           count++;
           cout<<"enter the information for your "<<i+1<<"th book"<<endl;
           b[i].insert();
         }
         break;
       }
       case 2 :
        {
            if(count==0)
            {
              cout<<"repository is empty"<<endl;
              break;
            }
            else
            {
              cout<<"your records are"<<endl;
              for(int i=0;i<no_of_records;i++)
              {
                cout<<"\tbook "<<i+1<<endl;
                b[i].display();
              }
            }
          break;
        }
       case 3 :
        {
          char *book_ip , *author_ip;
        	cout<<"enter the name of the book you want to search "<<endl;
          book_ip=new char[50];
          ws(cin);
        	cin.getline(book_ip,50);
        	cout<<"enter the name of author you want to search "<<endl;
          author_ip=new char[50];
          ws(cin);
        	cin.getline(author_ip,50);

        	int i;
        	for(i=0;i<no_of_records;i++)
        	{
        		if(flag_search==0)
        		b[i].search(book_ip,author_ip);
        		else
        		break;
        	}

        	if(flag_search==1)
        	{
        		cout<<"book record found"<<endl;
        		b[i].display();
        	}
        	else
        	{
        		cout<<"book record not found"<<endl;
        	}
          flag_search=0;
          break;
        }
      case 0 :
        {
          exit(0);
          break;
        }
      default : cout<<"wrong input try again"<<endl;
        }
    }while(CONDITION!=0);
  }
