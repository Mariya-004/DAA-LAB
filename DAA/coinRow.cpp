#include<iostream>
using namespace std;
int coinRow(int A[],int n){
	int F[n+1];
	F[0]=0;
	F[1]=A[0];
	for (int i=2;i<n+1;i++){
		int c=A[i-1]+F[i-2];
		int m=F[i-1];
		if (m>c){
			F[i]=m;
		}
		else{
			F[i]=c;
		}
	}
	for (int i=0;i<n+1;i++){
		cout<<F[i]<<endl;
	}
	return F[n];
	
}
int main(){
	int A[6]={5,1,2,10,6,2};
	cout<<coinRow(A,6)<<endl;
}