#include<iostream>
#include<cstring>
#include<limits>
using namespace std;
void display(int A[],int UB){
	cout<<"The array is:";
	for (int i=0;i<UB;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
}
void merge(int LB,int mid,int UB,int A[]){
	int n1=mid-LB+1;
	int n2=UB-mid;	
	int L[n1+1];
	int R[n2+1];
	memcpy(L,&A[LB],n1*sizeof(int));
  memcpy(R,&A[mid+1],n2*sizeof(int));
  L[n1]=R[n2]=numeric_limits<int>::max();
  int i=0;
  int j=0;
  int k=LB;
  for (k=LB;k<=UB;k++){
    if (L[i]<R[j]){
      A[k]=L[i];
      i=i+1;
  }
    else{
      A[k]=R[j];
      j=j+1;
    }
	}

}
void merge_sort(int LB,int UB,int A[]){
	if (LB<UB){
		int M=(LB+UB)/2;
		merge_sort(LB,M,A);
		merge_sort(M+1,UB,A);
		merge(LB,M,UB,A);
	}
}
int main(){
    cout<<"Enter the array size:";
    int n;
    cin>>n;
    int A[n];
    for (int i=0;i<n;i++){
        cout<<"Enter the array element:";
        int el;
        cin>>el;
        A[i]=el;
    }
    display(A,n);
    merge_sort(0,n,A);
	cout<<"Sorted Array"<<endl;
	display(A,n);
    return 0;
}	

	
