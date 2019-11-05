#include <bits/stdc++.h>
#include <omp.h>
#include <time.h>
using namespace std;

void merge_arrays(int vector[], int low, int mid, int high){
  int temp[100000];
  int i = low;
  int j = mid + 1;
  int k = 0;
  while(i <= mid && j <= high){
    if(vector[i] < vector[j]){
      temp[k++] = vector[i++];
    }
    else{
      temp[k++] = vector[j++];
    }
  }

  while(i < mid){
    temp[k++] = vector[i++];
  }

  while(j <= high){
    temp[k++] = vector[j++];
  }

  for (int y = low, z = 0; y < high; y++, z++) {
    vector[y] = temp[z];
  }
}

void sequential_merge_sort(int vector1[], int low, int high){
  if (low < high) {
    int mid = (low + high) / 2;
    sequential_merge_sort(vector1, low, mid);
    sequential_merge_sort(vector1, mid + 1, high);
    merge_arrays(vector1, low, mid, high);
  }
}

void parallel_merge_sort(int vector2[], int low, int high, int number_of_threads){
  if (low < high) {
    int mid = (low + high) / 2;
    #pragma omp parallel sections num_threads(number_of_threads)
    {
      #pragma omp section
      {
        parallel_merge_sort(vector2, low, mid, number_of_threads);
      }

      #pragma omp section
      {
        parallel_merge_sort(vector2, mid + 1, high, number_of_threads);
      }
    }
    merge_arrays(vector2, low, mid, high);
  }
}


int main(int argc, char const *argv[]) {
  int number_of_elements;
  cout<<"Enter the number of elements you want to add"<<endl;
  cin>>number_of_elements;

  int vector1[number_of_elements];
  int vector2[number_of_elements];

  for(int i = 0; i < number_of_elements; i++){
      vector1[i] = rand() % number_of_elements;
      vector2[i] = vector1[i];
  }

  int choice;
  while(1){
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Sequential merge sort"<<endl;
    cout<<"2. Parallel merge sort"<<endl;
    cout<<"0. Exit"<<endl;
    cin>>choice;
    double start_time, end_time;
    switch (choice) {
      case 1:
            start_time = omp_get_wtime();
            sequential_merge_sort(vector1, 0, number_of_elements - 1);
            end_time = omp_get_wtime();
            cout<<"Time required for serial merge sort is "<<end_time - start_time<<endl;
            break;
      case 2:
            int number_of_threads;
            cout<<"Enter the number of threads you want (max 8)"<<endl;
            cin>>number_of_threads;
            start_time = omp_get_wtime();
            // parallel_merge_sort(vector2, 0, number_of_elements - 1, number_of_threads);
            end_time = omp_get_wtime();
            cout<<"Time required for parallel merge sort is "<<end_time - start_time<<endl;
            break;
      case 0:
            return 0;
    }
  }
}
