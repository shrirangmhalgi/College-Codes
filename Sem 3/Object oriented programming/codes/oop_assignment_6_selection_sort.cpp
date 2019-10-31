//Write a function template selection Sort. Write a program that inputs, sorts and outputs an
//integer array and a float array.
#include<iostream>
using namespace std;
int size;
template<class t>
class Selection_sort
{
public:
      //t *array; //temporary soln is this but i want to accept the number of elements from the user //does not name a type error
      //array=new t(sizeof(size));
      t array[100];// i want to allocate the size dynamically
      t input(int );
      t sort(int );
      t output(int );
};

template<typename t>
t Selection_sort <t>:: input(int size)
{
  cout<<"enter your array elements"<<endl;
  for(int i=0;i<size; i++)
  {
    cin>>array[i];
  }
}

template <class t>
t Selection_sort <t>:: sort(int size)
{
  t temp;
  for(int i=0;i<size;i++)
  {
    for(int j=0;j<size;j++)
    {
      if(array[i]<array[j])
      {
        temp=array[i];
        array[i]=array[j];
        array[j]=temp;
      }
    }
  }
}


template<class t>
t Selection_sort <t>:: output(int size)
{
  cout<<"your array elements are "<<endl;
  for(int i=0;i<size;i++)
  {
    cout<<"\t"<<array[i];
  }
}

int main()
{
  char ans;
  do
  {
  int choice;
  cout<<"-----welcome-----"<<endl;
  cout<<"press 1 to choose integer array "<<endl;
  cout<<"press 2 to choose float array "<<endl;
  cin>>choice;
  switch (choice)
  {
    case 1 : {
              cout<<"enter the size of elements you want to add"<<endl;
              cin>>size;
              Selection_sort <int> list1;
              list1.input(size);
              cout<<"before sorting ";
              list1.output(size);
              cout<<endl<<"after sorting ";
              list1.sort(size);
              list1.output(size);
              break;
            }
    case 2 : {
              cout<<"enter the size of elements you want to add"<<endl;
              cin>>size;
              Selection_sort <float> list2;
              list2.input(size);
              cout<<"before sorting ";
              list2.output(size);
              cout<<endl<<"after sorting ";
              list2.sort(size);
              list2.output(size);
              break;
             }
    default :{
              cout<<"wrong input try again "<<endl;
              break;
            }
    }
    cout<<endl<<"do you want to continue..?(y/n)"<<endl;
    cin>>ans;
}while (ans!='n');
}
