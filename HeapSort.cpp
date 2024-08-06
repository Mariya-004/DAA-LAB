#include<iostream>
using namespace std;
void swap(int A[],int i,int j){
	int temp=A[i];
	A[i]=A[j];
	A[j]=temp;
}
void heapify(int A[],int i,int n){
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if (A[l]>A[largest] and l<n){
		largest=l;
	}
	if (A[r]>A[largest] and r<n){
		largest=r;
	}
	if (largest!=i){
		swap(A,i,largest);
		heapify(A,largest,n);
	}
}
void heapSort(int A[],int n){
	for (int i=(n-2)/2;i>=0;i--){
		heapify(A,i,n);
	}
	for (int i=n-1;i>=0;i--){
		swap(A,0,i);
		heapify(A,0,i);
	}
}
int main(){
	int A[5]={4,1,5,3,2};
	heapSort(A,5);
	for (int i=0;i<5;i++){
		cout<<A[i]<<endl;
	}
}
		
