#include<iostream>
using namespace std;
void insertion(int A[],int len){
	int i=1;
	while(i<len){
		int j=i-1;
		while (j<len){
			if (A[j] >A[i]){
				int t=A[j];
				A[j]=A[i];
				A[i]=t;
			}
			j++;
		}
		i++;
	}
}
int main(){
	int A[4]={5,2,1,9};
	insertion(A,4);
	for (int i=0;i<4;i++){
		cout<<A[i]<<" ";
	
	}
	cout<<endl;
}
		
