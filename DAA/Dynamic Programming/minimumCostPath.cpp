#include<iostream>
using namespace std;

void display(int mat[4][3]){
	for (int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}int min(int a,int b,int c){
	if (a<=b and a<=c){
		return a;
	}
	else if(b<=a and b<=c){
		return b;
	}
	else{
		return c;
	}
}
int mcp(int mat[4][3],int n,int c){
	int F[n][c];
	for (int i=0;i<n;i++){
		for (int j=0;j<c;j++){
			F[i][j]=mat[i][j];
		}
	}
	F[0][0]=mat[0][0];
	for (int i=0;i<n;i++){
		for (int j=0;j<c;j++){
			if (i==0 and j>0){
				F[i][j]=F[i][j-1]+mat[i][j];
			}
			if (j==0 and i>0){
				F[i][j]=F[i-1][j]+mat[i][j];
			}
			if (i>0 and j>0){
				F[i][j]=min(F[i-1][j],F[i][j-1],F[i-1][j-1])+mat[i][j];
			}
		}
	}
	// backtracking
	int i=n-1;
	int j=c-1;
	int B[100];
	int ind=0;
	B[ind++]=mat[i][j];
	while (i>0 or j>0){
		if (i>0 and j>0 and F[i][j]==F[i-1][j-1]+mat[i][j]){
			i--;
			j--;
			
		}
		else if ( i>0  and F[i][j]==F[i-1][j]+mat[i][j]){
			i--;
		}
		else{
			j--;
		}
		B[ind++]=mat[i][j];
	}
	cout<<"Path:";
	for (int k=ind-1;k>=0;k--){
		cout<<B[k]<<" ";
	}
	cout<<endl;
	return F[n-1][c-1];
}
int main(){
int inp[4][3]={{3, 2, 8}, 
{1, 9, 7}, 
{0, 5, 2}, 
{6, 4, 3}};

	display(inp);
	cout<<endl;
	cout<<mcp(inp,4,3);
}
	
