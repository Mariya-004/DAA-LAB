#include<iostream>
using namespace std;
void display(int mat[4][3]){
	for (int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int coinCollect(int c[4][3]){
	int f[4][3];
	for (int i=0;i<4;i++){
		for (int j=0;j<3;j++){
			f[i][j]=c[i][j];
		}
	}
		for (int j=1;j<3;j++){
		f[0][j]=c[0][j]+f[0][j-1];
	}
	for (int i=1;i<4;i++){
		f[i][0]=c[i][0]+f[i-1][0];
	}
	for (int i=1;i<4;i++){
		for(int j=1;j<3;j++){
			int temp=1000;
			if (f[i][j-1]<f[i-1][j]){
				temp=f[i][j-1];
			}
			else{
				temp=f[i-1][j];
			}
			if (temp>f[i-1][j-1]){
			    temp=f[i-1][j-1];
			}
			f[i][j]=temp+c[i][j];
		}
	}
	display(f);

	return f[3][2];
}
int main(){
int inp[4][3]={{3, 2, 8}, 
{1, 9, 7}, 
{0, 5, 2}, 
{6, 4, 3}};

	display(inp);
	cout<<endl;
	cout<<"Maximum number of coins collected is:"<<coinCollect(inp);
}
	
		
	
		
	
			
				
