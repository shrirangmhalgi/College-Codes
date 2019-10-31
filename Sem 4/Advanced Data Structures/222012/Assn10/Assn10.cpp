#include<iostream>
using namespace std;

int n,i;

class heap{
	public:
		int arr[50];
		
		int create();
		void display();
		void heapsort(int *,int );
		void heapify(int *,int ,int );
};

int heap :: create(){
	cout<<"Enter the number of elements : ";
	cin>>n;
	cout<<"Enter the elements \n";
	for(i=0;i<n;i++)
		cin>>arr[i];
}

void heap :: display(){
	cout<<"Entered elements are \n";
	for(i=0;i<n;i++)
		cout<<arr[i]<<"\t";
}

void heap :: heapsort(int arr[], int n){
	//build heap
	for(i=(n/2)-1;i>=0;i--)
		heapify(arr,n,i);
		
	//extract each element from root
	for(i=n-1;i>=0;i--)
	{
		swap(arr[0],arr[i]);
		heapify(arr,i,0);
	}
}

void heap :: heapify(int arr[] ,int n, int i ){
	int largest = i;
	int l = 2*i+1;
	int r = 2*i+2;
	
	if(l<n && arr[l]>arr[largest])
		largest=l;
	if(r<n && arr[r]>arr[largest])
		largest=r;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		heapify(arr,n,largest);
	}
}

int main(){
	heap o;
	o.create();
	o.heapsort(o.arr,n);
	o.display();
}
