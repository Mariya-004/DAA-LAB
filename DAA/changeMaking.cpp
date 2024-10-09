#include<iostream>
#include<limits>
using namespace std;
int min(int a,int b){
	if (a<b){
		return a;
	}
	else {
		return b;
	}
	
}
int coinChange(int D[],int n,int m){
	int F[n+1];
	int B[n+1];
	F[0]=0;
	for (int i=1;i<=n;i++){
		int temp=numeric_limits<int>::max();
		int j=0;
		while (j<=m and i>=D[j]){
			temp=min(F[i-D[j]],temp);
			j=j+1;
			
		}
		F[i]=temp+1;
	}
	for (int i=0;i<=n;i++){
		cout<<F[i]<<" ";
	}
	cout<<endl;
	return F[n];
}
int main(){
	cout<<"Enter the number of denominations you have:";
	int num;
	cin>>num;
	int D[num];
	cout<<"Enter the denominations one by one"<<endl;
	for (int i=0;i<num;i++){
		int den;
		cin>>den;
		D[i]=den;
	}
	cout<<"Enter the amount to make change for:";
	int amt;
	cin>>amt;
	coinChange(D,amt,num);
}
