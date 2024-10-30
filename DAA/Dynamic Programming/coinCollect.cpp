#include<iostream>
using namespace std;
void display(int mat[5][6]){
	for (int i=0;i<5;i++){
		for(int j=0;j<6;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int coinCollect(int c[5][6]){
	int f[5][6];
	for (int i=0;i<5;i++){
		for (int j=0;j<6;j++){
			f[i][j]=c[i][j];
		}
	}
		for (int j=1;j<6;j++){
		f[0][j]=c[0][j]+f[0][j-1];
	}
	for (int i=1;i<5;i++){
		f[i][0]=c[i][0]+f[i-1][0];
	}
	for (int i=1;i<5;i++){
		for(int j=1;j<6;j++){
		    
			int temp=-1;
			if (f[i][j-1]>f[i-1][j]){
				temp=f[i][j-1];
			}
			else{
				temp=f[i-1][j];
			}
			f[i][j]=temp+c[i][j];
		}
	}

	return f[4][5];
}
int main(){
int inp[5][6]={{0, 0, 0, 0, 1, 0}, 
{0, 1, 0, 1, 0, 0}, 
{0, 0, 0, 1, 0, 1}, 
{0, 0, 1, 0, 0, 1}, 
{1, 0, 0, 0, 1, 0}};

	display(inp);
	cout<<endl;
	cout<<"Maximum number of coins collected is:"<<coinCollect(inp);
}
	
