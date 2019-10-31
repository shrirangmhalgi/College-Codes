/*Write a C++ program that creates an output file,
 writes information to it, closes the file and open it again
 as an input file and read the information from the file.*/
#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream fp;
    ifstream fp1;
    char ch;
    char *info;
    info = new char[100];
    char num;
    fp.open("test.txt");
    do {
      cout<<"enter the information to ur file"<<endl;
      ws(cin);
      cin.getline(info, 100);
      fp<<info;
      fp<<" "<<endl;
      cout<<"add more info..? press annything if yes else press 0 to quit"<<endl;
      cin>>num;
    } while(num != '0');
    fp.close();

    cout<<"your data is"<<endl;
    fp1.open("test.txt");
    while(!fp1.eof()){
      fp1.get(ch);
      cout<<ch;
    }
    fp1.close();
}
