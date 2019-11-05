#include <bits/stdc++.h>
#include <omp.h>
#include <time.h>
using namespace std;

int vector1[100000];
int matrix1[1000][1000];
int number_of_elements;

void sequential_vector_matrix_multiplication(){
  int result[number_of_elements];
  memset(result, 0, number_of_elements);

  double start_time = omp_get_wtime();
  for(int i = 0; i < number_of_elements; i++){
    for(int j = 0; j < number_of_elements; j++){
      result[i] += vector1[i] * matrix1[i][j];
    }
  }
  double end_time = omp_get_wtime();

  cout<<"Sequential vector - matrix multiplication : "<<endl;
  cout<<"for "<<number_of_elements<<" elements time taken is"<<end_time - start_time<<endl;
}

void parallel_vector_matrix_multiplication(int number_of_threads){
  int result[number_of_elements];
  memset(result, 0, number_of_elements);

  double start_time = omp_get_wtime();
  #pragma omp parallel for collapse(2) num_threads(number_of_threads)
  for(int i = 0; i < number_of_elements; i++){
    for(int j = 0; j < number_of_elements; j++){
      result[i] += vector1[i] * matrix1[i][j];
    }
  }
  double end_time = omp_get_wtime();

  cout<<"Parallel vector - matrix multiplication : "<<endl;
  cout<<"for "<<number_of_elements<<" elements time taken is"<<end_time - start_time<<endl;
}

int main(int argc, char const *argv[]) {
  cout<<"Enter the number of elements you want to add"<<endl;
  cin>>number_of_elements;

  for(int i = 0; i < number_of_elements; i++){
    for(int j = 0; j < number_of_elements; j++){
      matrix1[i][j] = rand() % number_of_elements;
    }
    vector1[i] = rand() % number_of_elements;
  }

  int choice;
  while(1){
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Sequential vector - matrix multiplication"<<endl;
    cout<<"2. Parallel vector - matrix multiplication"<<endl;
    cout<<"0. Exit"<<endl;
    cin>>choice;
    switch (choice) {
      case 1:
            sequential_vector_matrix_multiplication();
            break;
      case 2:
            int number_of_threads;
            cout<<"Enter the number of threads you want (max 8)"<<endl;
            cin>>number_of_threads;
            parallel_vector_matrix_multiplication(number_of_threads);
            break;
      case 0:
            return 0;
    }
  }
}
