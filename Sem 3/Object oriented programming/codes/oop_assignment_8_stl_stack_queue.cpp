/* Write C++ program using STL for implementation of stack & queue using SLL */

#include <iostream>
#include<stdlib.h>
#include<list>
#include<vector>
using namespace std;

void add_list_element(list<int> *);
void delete_list_element(list<int> *);
void display_list_elements(list<int> );

void add_stack_element(vector<int> *);
void delete_stack_element(vector<int> *);
void display_stack_element(vector<int> );

int main()
{
  int condition, condition1, condition2;
  list <int> l1;
  vector<int> v1;

  do {
    cout<<"-----WELCOME-----"<<endl;
    cout<<"press 1 for queue"<<endl;
    cout<<"press 2 for stack"<<endl;
    cout<<"press 0 to exit"<<endl;
    cin>>condition;
    switch (condition) {
      case 1 :{
          do {
            cout<<endl;
            cout<<"implementation of queue using sll"<<endl;
            cout<<"press 1 to display size of queue"<<endl;
            cout<<"press 2 to insert element in the queue"<<endl;
            cout<<"press 3 to delete element queue"<<endl;
            cout<<"press 4 to display your queue"<<endl;
            cout<<"press 0 to go back "<<endl;
            cin>>condition1;
            cout<<endl;
            switch (condition1) {
            case 1 :{
              cout<<"size of the queue is " << l1.size()<<endl;
              break;
            }
            case 2 :{
              add_list_element(&l1);
              break;
            }
            case 3 :{
              delete_list_element(&l1);
              break;
            }
            case 4 :{
              display_list_elements(l1);
              break;
            }
            case 0 :{
              break;
            }
          }
        }while(condition1 != 0);
        break;
      }
      case 2 :{
        do {
          cout<<endl;
          cout<<"implementation of stack using vector"<<endl;
          cout<<"press 1 to display size of stack"<<endl;
          cout<<"press 2 to insert element in the stack"<<endl;
          cout<<"press 3 to delete element stack"<<endl;
          cout<<"press 4 to display your stack"<<endl;
          cout<<"press 0 to go back "<<endl;
          cin>>condition1;
          cout<<endl;
          switch (condition1) {
          case 1 :{
            cout<<"the size of stack is "<<v1.size()<<endl;
            break;
          }
          case 2 :{
            add_stack_element(&v1);
            break;
          }
          case 3 :{
            delete_stack_element(&v1);
            break;
          }
          case 4 :{
            display_stack_element(v1);
            break;
          }
          case 0 :{
            break;
          }
        }
        } while(condition1 != 0);
        break;
      }
      case 0 :{
        cout<<"exit successful..."<<endl;
        exit(0);
        break;
      }
      default : cout<<"wrong option... try again"<<endl;
    }
  } while(condition != 0);
}

void add_list_element(list<int> *l1){
  int element;
  char ch;

  do {
    cout<<"enter the element you want to push"<<endl;
    cin>>element;
    l1->push_back(element);
    cout<<"do you want to add another..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void delete_list_element(list<int> *l1){
  char ch;
  do {
    l1->pop_front();
    cout<<"successfully deleted"<<endl;
    cout<<"do you want to delete more..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void display_list_elements(list <int> l1)
{
  if(l1.size() == 0){
    cout<<"list is empty "<<endl;
  }
  else{
    cout<<"your elemets are"<<endl;
    list<int> :: iterator i;
    for(i = l1.begin(); i != l1.end(); i++){
      cout<<*i<<endl;
    }
  }
}

void add_stack_element(vector<int> *v1){
  int element;
  char ch;

  do {
    cout<<"enter the element you want to push"<<endl;
    cin>>element;
    v1->push_back(element);
    cout<<"successfully pushed "<<element<<" on the stack"<<endl;
    cout<<"do you want to push another element on the stack..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void display_stack_element(vector<int> v1){
  cout<<"your elements are"<<endl;
  for(int i = v1.size()-1; i >= 0; i--){
    cout<<v1[i]<<endl;
  }
}

void delete_stack_element(vector<int> *v1){
  char ch;
  do {
    v1->pop_back();
    cout<<"successfully deleted"<<endl;
    cout<<"do you want to delete more..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}
