#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
class data
{
    public:
    char name[20];
    long int tele_no;
    void accept();
    void display();
};
void data::accept()
{
    cout<<"Enter name: "<<endl;
    ws(cin);
    cin.getline(name,20);
    cout<<"Enter telephone no:"<<endl;
    cin>>tele_no;
}
void data::display()
{
    cout<<name<<"\t"<<tele_no<<endl;
}
int main()
{
    int num,i,ch;
    int long temp_tele;
    char temp[20],op;
    data d[10];
    fstream file;
    file.open("sample.DAT",ios::out|ios::in|ios::binary);
    cout<<"Enter the total no of data"<<endl;
    cin>>num;
    for(i=0;i<num;i++)
        {
            cout<<"Enter data for "<<i<<" person";
            d[i].accept();
            file.write((char*)&d[i],sizeof(d[i]));
        }
    do
        {
            cout<<"Enter your choice of operation:\n1.Search by name\n2.Search by telephone no\n3.Update telephone no";
            cin>>ch;
            switch(ch)
                {
                case 1:
                    cout<<"Enter the name which you want to search:"<<endl;
                    cin>>temp;
                    for(i=0;i<num;i++)
                        {
                            file.read((char*)&d[i],sizeof(d[i]));
                            if(strcmp(temp,d[i].name)==0)
                                cout<<"Search result:\n<<Telephone no:"<<d[i].tele_no;
                        }
                    break;
                case 2:
                    cout<<"Enter the telephone no:-";
                    cin>>temp_tele;
                    for(i=0;i<num;i++)
                        {
                            file.read((char*)&d[i],sizeof(d[i]));
                            if(d[i].tele_no==temp_tele)
                                cout<<"Search result:\n<<Name:"<<d[i].name;
                        }
                    break;
                case 3:
                    cout<<"Enter the name:"<<endl;
                    cin>>temp;
                    for(i=0;i<num;i++)
                        {
                            file.read((char*)&d[i],sizeof(d[i]));
                            if(strcmp(temp,d[i].name)==0)
                                {
                                    cout<<"Enter telephone no:"<<endl;
                                    cin>>d[i].tele_no;
                                }
                        }
                    break;
                }
            cout<<"Do you want to continue"<<endl;
            cin>>op;
        }while(op=='y');
    for(i=0;i<num;i++)
        {
            d[i].display();
        }
    file.close();
    return 0;
}
