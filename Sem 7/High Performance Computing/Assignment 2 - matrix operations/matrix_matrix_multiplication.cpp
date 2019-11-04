#include <bits/stdc++.h>
#include <omp.h>
#include <time.h>
using namespace std;

int matrix1[1000][1000];
int matrix2[1000][1000];
int number_of_elements;

void sequential_matrix_matrix_multiplication(){
  int result[number_of_elements][number_of_elements];
  memset(result, 0, number_of_elements);

  double start_time = omp_get_wtime();
  for(int i = 0; i < number_of_elements; i++){
    for(int j = 0; j < number_of_elements; j++){
      for(int k = 0; k < number_of_elements; k++){
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  double end_time = omp_get_wtime();

  cout<<"Sequential matrix - matrix multiplication : "<<endl;
  cout<<"for "<<number_of_elements<<" elements time taken is"<<end_time - start_time<<endl;
}

void parallel_matrix_matrix_multiplication(int number_of_threads){
  int result[number_of_elements][number_of_elements];
  memset(result, 0, number_of_elements);

  double start_time = omp_get_wtime();
  #pragma omp parallel for collapse(1) num_threads(number_of_threads)
  for(int i = 0; i < number_of_elements; i++){
    for(int j = 0; j < number_of_elements; j++){
      for(int k = 0; k < number_of_elements; k++){
        result[i][j] += matrix1[i][k] * matrix2[k][j];
      }
    }
  }
  double end_time = omp_get_wtime();

  cout<<"Parallel matrix - matrix multiplication : "<<endl;
  cout<<"for "<<number_of_elements<<" elements time taken is"<<end_time - start_time<<endl;
}

int main(int argc, char const *argv[]) {
  cout<<"Enter the number of elements you want to add"<<endl;
  cin>>number_of_elements;

  for(int i = 0; i < number_of_elements; i++){
    for(int j = 0; j < number_of_elements; j++){
      matrix1[i][j] = rand() % number_of_elements;
      matrix2[i][j] = rand() % number_of_elements;
    }
  }

  int choice;
  while(1){
    cout<<"-----MENU-----"<<endl;
    cout<<"1. Sequential matrix - matrix multiplication"<<endl;
    cout<<"2. Parallel matrix - matrix multiplication"<<endl;
    cout<<"0. Exit"<<endl;
    cin>>choice;
    switch (choice) {
      case 1:
            sequential_matrix_matrix_multiplication();
            break;
      case 2:
            int number_of_threads;
            cout<<"Enter the number of threads you want (max 8)"<<endl;
            cin>>number_of_threads;
            parallel_matrix_matrix_multiplication(number_of_threads);
            break;
      case 0:
            return 0;
    }
  }
}
