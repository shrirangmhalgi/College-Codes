// create an employee biodata using following classes
//1. personal record
//2. professional record
//3. academic record
// assume appropriate data and member functions to accept and print biodata using multiple inheritance in c++
#include<iostream>
#include <limits.h>
using namespace std;
class Personal
{
  public : char name[50],address[100];
  long long int mobile;
  char dob[15],nationality[20],sex[10];
  int personal()
 {
    cin.clear();
    cout<<"enter your personal record"<<endl;
    cout<<"enter name"<<endl;
    cin.getline(name,50);
    cout<<"enter your date of birth"<<endl;
    cin.getline(dob,15);
    cout<<"enter  your address"<<endl;
    cin.getline(address,100);
    cout<<"enter your nationality "<<endl;
    cin>>nationality;
    cout<<"enter your sex"<<endl;
    cin>>sex;
    cout<<"enter your mobile number"<<endl;
    cin>>mobile;
    cin.ignore(INT_MAX,'\n');
    return 0;
 }
};
class Qualifications
{
  public : char schoolName[50],collegeName[50],institute[50];
  int sPass,cPass,iPass;
  int qualifications()
  {
    cout<<"enter your qualifications "<<endl;
    cout<<"enter your school name "<<endl;
    cin.getline(schoolName,50);
    cout<<"enter your college name "<<endl;
    cin.getline(collegeName,50);
    cout<<"enter your institute name "<<endl;
    cin.getline(institute,50);
    cout<<"enter your year of passing school "<<endl;
    cin>>sPass;
    cout<<"enter your year of passing college "<<endl;
    cin>>cPass;
    cout<<"enter your year of passing institute "<<endl;
    cin>>iPass;
    return 0;
  }
};
class Academics
{
  public : float fe,se,te,be,avg;
  int academics()
  {
    cout<<"enter your academnic details"<<endl;
    cout<<"enter your first year pointer "<<endl;
    cin>>fe;
    cout<<"enter your second year pointer "<<endl;
    cin>>se;
    cout<<"enter your te pointer "<<endl;
    cin>>te;
    cout<<"enter your be pointer "<<endl;
    cin>>be;
    avg = (fe+se+te+be)/4;
    return 0;
  }
};
class Display : public Personal, public Academics,public Qualifications
{
  public : int display()
  {
    cout<<"\n\n\n\n\t\t\t***** YOUR BIODATA IS *****"<<endl;
    cout<<"1. Personal record :"<<endl;
    cout<<"\t\tName :"<<name<<endl;
    cout<<"\t\tDate of birth :"<<dob<<endl;
    cout<<"\t\tAddress :"<<address<<endl;
    cout<<"\t\tSex :"<<sex<<endl;
    cout<<"\t\tMobile :"<<mobile<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<"2. Qualifications :"<<endl;
    cout<<"\t\tSchool name  :"<<schoolName<<endl;
    cout<<"\t\tYear of passing :"<<sPass<<endl;
    cout<<"\t\tCollege name :"<<collegeName<<endl;
    cout<<"\t\tYear of passing  :"<<cPass<<endl;
    cout<<"\t\tInstitute name :"<<institute<<endl;
    cout<<"\t\tYear of passing :"<<iPass<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    cout<<"3. Academics"<<endl;
    cout<<"\tResult:"<<endl;
    cout<<"\t\tFirst year :"<<fe<<endl;
    cout<<"\t\tSecond year :"<<se<<endl;
    cout<<"\t\tThird year :"<<te<<endl;
    cout<<"\t\tFourth year :"<<be<<endl;
    cout<<"\t\tAverage :"<<avg<<endl;
    cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    return 0;
  }
};
int main()
{
  Display p1;
  p1.personal();
  p1.qualifications();
  p1.academics();
  p1.display();
  return 0;
}
