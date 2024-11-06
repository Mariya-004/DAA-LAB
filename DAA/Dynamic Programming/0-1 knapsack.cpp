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

int knapsack(int n,int c,int w[],int v[]){
	int mat[n+1][c+1];
	 for (int i=0;i<=n;i++){
	 	mat[i][0]=0;
	 }
	 for (int i=0;i<=c;i++){
	 	mat[0][i]=0;
	 }
	 for (int i=1;i<=n;i++){
	 	for(int j=1;j<=c;j++){
	 		if (j-w[i-1]>=0){
	 			mat[i][j]=max(mat[i-1][j],v[i-1]+mat[i-1][j-w[i-1]]);
			 }
			 else{
			 	mat[i][j]=mat[i-1][j];
			 }
		 }
	 }
	 for (int i=0;i<=n;i++){
	 	for (int j=0;j<=c;j++){
	 		cout<<mat[i][j]<<"\t";
		 }
		 cout<<endl;
	 }
	 int val=mat[n][c];
	 int includeItems[n];// array to store included items
	 int index=0; 
	 int cap=c; // stores capacity
	 for (int i=n;i>0;i++){
	 	if (mat[i][cap]!=mat[i-1][cap]){
	 		includeItems[index++]=i-1;
	 		cap=cap-w[i-1];
		 }
	 }
	 cout<<"Included items:";
	 for (int i=index-1;i>=0;i--){
	 	cout<<includedItems[i]<<" ";
	 }
    cout << endl;

	return val;
	 

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
		cout<<"ENTER THE WEIGHT OF ITEM:";
		int w;
		cin>>w;
		W[i]=w;
		cout<<"ENTER THE VALUE OF ITEM:";
		int v;
		cin>>v;
		V[i]=v;
	}
	cout<<"Maximum value:"<<knapsack(n,cap,W,V);
}
