#include<iostream>
using namespace std;
int max(int a,int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}
int lcs(string s1,string s2){
	int rows=s1.length()+1;
	int cols=s2.length()+1;
	int mat[rows][cols];
	for (int i=0;i<rows;i++){
		mat[i][0]=0;
	}
	for (int i=0;i<cols;i++){
		mat[0][i]=0;
	}	
	for (int i=1;i<rows;i++){
		for (int j=1;j<cols;j++){
			if (s1[i-1]==s2[j-1]){
				mat[i][j]=mat[i-1][j-1]+1;
			}
			else{
				mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
			}
		}
	}
		for (int i=0;i<rows;i++){
		for (int j=0;j<cols;j++){
				cout<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
	int s=mat[rows-1][cols-1];
	char arr[s+1];
	int r=rows-1;
	int c=cols-1;
	int d=s-1;
	arr[s]='\0';
	while (r>0 and c>0){
			if (s1[r-1]==s2[c-1]){
				arr[d--]=s2[c-1];
				r--;
				c--;
			}
			else{
				if (mat[r-1][c]>mat[r][c-1]){
					r--;
				}
				else{
					c--;
				}
			}
	}
	cout<<"Path"<<endl;
	cout<<arr<<endl;
	cout<<endl;
	return mat[rows-1][cols-1];
	
}
int main(){
	cout<<"Enter the first string:";
	string s1;
	cin>>s1;
	cout<<"Enter the second string:";
	string s2;
	cin>>s2;
	lcs(s1,s2);
}
