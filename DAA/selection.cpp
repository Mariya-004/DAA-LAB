#include<iostream>
using namespace std;
void selection(int A[],int len){
	for(int i=0;i<len;i++){
		int min=i;
		for(int j=i+1;j<len;j++){
			if (A[min]>A[j]){
				int t=A[min];
				A[min]=A[j];
				A[j]=t;
			}
		
		}
		if (min!=i){	
			int u=A[min];
			A[min]=A[i];
			A[i]=A[min];
		}
	}
}
int main(){
	int A[6]={1,2,0,5,4,3};
	selection(A,6);
	for (int i=0;i<6;i++){
		cout<<A[i]<<" ";
	}
	cout<<endl;
return 0;
}	
				
