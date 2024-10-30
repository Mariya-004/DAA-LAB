#include<iostream>
using namespace std;
int partition(int A[],int LB,int len){
	int j=LB-1;
	int pivot=A[len-1];
	int i=LB;
	while (i<len){
		if (A[i]<pivot){
			j=j+1;
			int t=A[i];
			A[i]=A[j];
			A[j]=t;
		}
		i=i+1;
	}
	int u=A[j+1];
	A[j+1]=A[len-1];
	A[len-1]=u;
	return j+1;
}
void quicksort(int LB,int len,int A[]){
	if(LB<len){
	int p=partition(A,LB,len);
	quicksort(LB,p,A);
	quicksort(p+1,len,A);
}
}
int main(){
	int A[5]={3,2,9,7,1};
	quicksort(0,5,A);
	for (int i=0;i<5;i++){
		cout<<A[i]<<" ";
	}
	
	cout<<endl;
}
