#include<iostream>
using namespace std;
int min(int a,int b,int c){
	if (a<c and a<b){
		return a;
	}
	if(b<a and b<c){
		return b;
	}
	if (c<a and c<b){
		return c;
	}
}
void display(int mat[4][3]){
	for (int i=0;i<4;i++){
		for(int j=0;j<3;j++){
			cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
int minimumCostPath(int c[4][3]){
	int f[4][3];
	for (int i=0;i<4;i++){                            //copying the matrix
		for (int j=0;j<3;j++){
			f[i][j]=c[i][j];
		}
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<3;j++){
			if (i==0 and j>0){
				f[i][j]=f[i][j-1]+c[i][j];
			}
		    if (j==0 and i>0){
				f[i][j]=f[i-1][j]+c[i][j];
			}
			if (i>0 and j>0){
				f[i][j]=min(f[i-1][j],f[i][j-1],f[i-1][j-1])+c[i][j];
			}
		}
	}
//	display(f);
	int A[100];
	int i=3;
	int j=2;
	int el=-1;
	int d=0;
	while (i>0 or j>0){
		if (i==0 and j>0){
				el=f[i][j]-f[i][j-1];
			}
		    if (j==0 and i>0){
				el=f[i][j]-f[i-1][j];
			}
			if (i>0 and j>0){
				el=f[i][j]-min(f[i-1][j],f[i][j-1],f[i-1][j-1]);
				
			}
			//cout<<el<<endl;
			
			if (f[i][j]-el==f[i-1][j]){
				i=i-1;
	
			}
			if (f[i][j]-el==f[i][j-1]){
				j=j-1;
				
			}
			if (f[i][j]-el==f[i-1][j-1]){
				i=i-1;
				j=j-1;
			}
			A[d]=el;
			d++;
			
			
		
	}
	A[d]=f[0][0];
	cout<<"Path:";
	for (int i=d;i>=0;i--){
		cout<<A[i]<<" ";
	}
	cout<<endl;
	return f[3][2];

}
int main(){
int inp[4][3]={{3, 2, 8}, 
{1, 9, 7}, 
{0, 5, 2}, 
{6, 4, 3}};

	display(inp);
	cout<<endl;
	cout<<minimumCostPath(inp);
}
	
		
	
		
	
			
				
	
		
	
		
	
			
				
