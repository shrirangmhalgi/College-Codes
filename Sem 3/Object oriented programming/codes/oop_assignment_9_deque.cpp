/* Write a c++ program for implementation of dqueue (double ended queue)*/

#include<iostream>
#include<deque>
#include<stdlib.h>
using namespace std;

void push_at_front(deque<int> *);
void push_at_back(deque<int> *);
void pop_from_front(deque<int> *);
void pop_from_back(deque<int> *);
void display(deque<int> );

int main(){
  deque<int> d;
  int condition;
  
  do {
    cout<<endl;
    cout<<"-----WELCOME-----"<<endl;
    cout<<"press 1 to display size of deque"<<endl;
    cout<<"press 2 to push element from back"<<endl;
    cout<<"press 3 to push element from front"<<endl;
    cout<<"press 4 to pop element from back"<<endl;
    cout<<"press 5 to pop element from front"<<endl;
    cout<<"press 6 to display your deque"<<endl;
    cout<<"press 0 to exit"<<endl;
    cin>>condition;
    cout<<endl;
    switch (condition) {
      case 1 :{
        cout<<"the size of deque is "<<d.size()<<endl;
        break;
      }
      case 2 :{
        push_at_back(&d);
        break;
      }
      case 3 :{
        push_at_front(&d);
        break;
      }
      case 4 :{
        pop_from_back(&d);
        break;
      }
      case 5 :{
        pop_from_front(&d);
        break;
      }
      case 6 :{
        display(d);
        break;
      }
      case 0 :{
        cout<<"exit successful"<<endl;
        exit(0);
      }
    }
  } while(condition != 0);
}

void push_at_front(deque<int> *d){
  int element;
  char ch;
  do {
    cout<<"enter the element you want to push at front"<<endl;
    cin>>element;
    d->push_front(element);
    cout<<"successfully pushed "<<element<<" at front"<<endl;
    cout<<"do you want to push another element..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void push_at_back(deque<int> *d){
  int element;
  char ch;
  do {
    cout<<"enter the element you want to push at back"<<endl;
    cin>>element;
    d->push_back(element);
    cout<<"successfully added "<<element<<" at back"<<endl;
    cout<<"do you want to push another element..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void pop_from_front(deque<int> *d){
  char ch;
  do {
    d->pop_front();
    cout<<"successfully deleted from front"<<endl;
    cout<<"do you want to pop another element..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void pop_from_back(deque<int> *d){
  char ch;
  do {
    d->pop_back();
    cout<<"successfully deleted from back"<<endl;
    cout<<"do you want to pop another element..?(y/n)"<<endl;
    cin>>ch;
  } while(ch != 'n');
}

void display(deque<int> d){
  if(d.size() == 0)
    cout<<"queue is empty "<<endl;
  else{
    cout<<"your elements are"<<endl;
    for(int i = 0; i < d.size(); i++)
      cout<<d[i]<<endl;
  }
}
