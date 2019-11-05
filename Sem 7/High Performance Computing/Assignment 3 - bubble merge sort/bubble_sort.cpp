#include <bits/stdc++.h>
#include <omp.h>
#include <time.h>
using namespace std;

int vector1[10000];
int vector2[10000];
int number_of_elements;

void sequential_bubble_sort(){
  double start_time = omp_get_wtime();
  for(int i = 0; i < number_of_elements; i++){
    for(int j = i + 1; j < number_of_elements; j++){
      if(vector1[j] > vector1[i]){
        swap(vector1[j], vector1[i]);
      }
    }
  }
  double end_time = omp_get_wtime();

  cout<<"Time taken for Sequential bubble sort is "<<end_time - start_time<<endl;
}

void parallel_bubble_sort(int number_of_threads){
  double start_time = omp_get_wtime();
  for(int i = 0; i < number_of_elements; i++){
    int first = i % 2;
		#pragma omp parallel for shared(vector2, first) num_threads(number_of_threads)
    for(int j = i + 1; j < number_of_elements; j++){
      if(vector2[j] > vector2[i]){
        swap(vector2[j], vector2[i]);
      }
    }
  }
  double end_time = omp_get_wtime();

  cout<<"Time taken for Parallel bubble sort is "<<end_time - start_time<<endl;
}

void swap(int &a, int &b) {
	int test;
	test = a;
	a = b;
	b = test;
}


int main(int argc, char const *argv[]) {
  cout<<"Enter the number of elements you want to add"<<endl;
  cin>>number_of_elements;

  for(int i = 0; i < number_of_elements; i++){
      vector1[i] = rand() % number_of_elements;
      vector2[i] = vector1[i];
  }

  int choice;
  while(1){
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Sequential bubble sort"<<endl;
    cout<<"2. Parallel bubble sort"<<endl;
    cout<<"0. Exit"<<endl;
    cin>>choice;
    switch (choice) {
      case 1:
            sequential_bubble_sort();
            break;
      case 2:
            int number_of_threads;
            cout<<"Enter the number of threads you want (max 8)"<<endl;
            cin>>number_of_threads;
            parallel_bubble_sort(number_of_threads);
            break;
      case 0:
            return 0;
    }
  }
}
