#include<iostream>
using namespace std;
void bubbleSort(int A[],int len){
	for (int i=0;i<len-1;i++){
		for (int j=0;j<len-i-1;j++){
			if (A[j+1]<A[j]){
				int t=A[j];
				A[j]=A[j+1];
				A[j+1]=t;
			}
		}
	}

}
int main(){
	int A[6]={1,2,0,5,4,3};
	bubbleSort(A,6);
	for (int i=0;i<6;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
return 0;
}	
				
