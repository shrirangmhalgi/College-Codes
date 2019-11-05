#include<bits/stdc++.h>
#include<time.h>
#include<omp.h>
using namespace std;

int vector1[100000];
int vector2[100000];
int number_of_elements;

int sequential_binary_search(int vector[], int key, int low, int high){
  int mid = (low + high) / 2;
  if(vector[mid] == key){
    return mid;
  }

  if(low == high){
    return -1;
  }

  if(key < vector[mid]){
    sequential_binary_search(vector, key, low, mid);
  }
  else{
    sequential_binary_search(vector, key, mid + 1, high);
  }
}

int parallel_binary_search(int vector[], int key, int low, int high, int number_of_threads){
  int mid = (low + high) / 2;
  if(vector[mid] == key){
    return mid;
  }

  if(low == high){
    return -1;
  }

  #pragma omp parallel sections num_threads(number_of_threads)
  {
    #pragma omp section
    {
      parallel_binary_search(vector, key, low, mid, number_of_threads);
    }
    #pragma omp section
    {
      parallel_binary_search(vector, key, mid + 1, high, number_of_threads);
    }
  }
}

int main() {
  cout<<"Enter the number of elements you want to add"<<endl;
  cin>>number_of_elements;

  int vector1[number_of_elements], vector2[number_of_elements];

  for(int i = 0; i < number_of_elements; i++){
    vector1[i] = rand() % number_of_elements;
    vector2[i] = rand() % number_of_elements;
  }

  int choice;
  int key;
  double start_time, end_time;
  while(1){
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Sequential vector addition"<<endl;
    cout<<"2. Parallel vector addition"<<endl;
    cout<<"0. Exit"<<endl;
    cin>>choice;
    cout<<"Enter the key you want to search"<<endl;
    cin>>key;
    switch (choice) {
      case 1:
            start_time = omp_get_wtime();
            sequential_binary_search(vector1, key, 0, number_of_elements);
            end_time = omp_get_wtime();
            cout<<"Time taken for Sequential binary search is "<<end_time - start_time<<endl;
            break;
      case 2:
            int number_of_threads;
            cout<<"Enter the number of threads you want (max 8)"<<endl;
            cin>>number_of_threads;
            start_time = omp_get_wtime();
            parallel_binary_search(vector2, key, 0, number_of_elements, number_of_threads);
            end_time = omp_get_wtime();
            cout<<"Time taken for Sequential binary search is "<<end_time - start_time<<endl;
            break;
      case 0:
            return 0;
    }
  }
}
