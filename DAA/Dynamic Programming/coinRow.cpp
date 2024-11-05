#include<iostream>
using namespace std;
int max(int a,int b){
	if (a>=b){
		return a;
	}
	else{
		return b;
	}
}
int coinRow(int A[],int n){
	int F[n+1];
	F[0]=0;
	F[1]=A[0];
	for (int i=2;i<=n;i++){
		F[i]=max(A[i-1]+F[i-2],F[i-1]);
		
	}
	cout<<"Maximum amount made using the sum of alternate coins:"<<F[n]<<endl;	
	cout<<"Backtracking array:";
	for (int i=0;i<=n;i++){
		cout<<F[i]<<" ";
	}
	cout<<endl;
	cout<<"coins used:";
	int i=n;
	while(i>0){
		if (i==1 or F[i]!=F[i-1]){
			cout<<A[i-1]<<endl;
			i=i-2;
		}
		else{
			i=i-1;
		}
	}
}
int main(){
	cout<<"Enter the number of coins:";
	int n;
	cin>>n;
	int a[n];
	cout<<"Enter the denominations"<<endl;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	coinRow(a,n);
}
