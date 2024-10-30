#include<iostream>
using namespace std;
int max(int a,int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}
void display(int mat[5][11]){
	for (int i=0;i<5;i++){
		for (int j=0;j<11;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int knapsack(int w[],int v[],int n,int c){
	int mat[5][11];
	for (int i=0;i<=n;i++){
		mat[i][0]=0;
	}
	for (int i=0;i<=c;i++){
		mat[0][i]=0;
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=c;j++){
			if (j-w[i-1]>=0){
				mat[i][j]=max(mat[i-1][j],v[i-1]+mat[i-1][j-w[i-1]]);
			}
			else{
				mat[i][j]=mat[i-1][j];
			}
		}
	}
	return mat[4][10];
	
}
int main(){
	cout<<"ENTER THE CAPACITY OF THE KNAPSACK:";
	int cap;
	cin>>cap;
	cout<<"ENTER THE NUMBER OF ITEMS:";
	int n;
	cin>>n;
	int W[n];
	int V[n];
	for (int i=0;i<n;i++){
		cout<<"Enter the  weight of item:";
		int w;
		cin>>w;
		W[i]=w;
		cout<<"Enter the value of item:";
		int v;
		cin>>v;
		V[i]=v;
	}
	cout<<"Maximum value:"<<knapsack(W,V,n,cap);
}
