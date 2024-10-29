#include<iostream>
#include<cstring>
using namespace std;
int max(int a,int b){
	if (a>b){
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
	for (int i=0;i<=rows;i++){
		mat[i][0]=0;
	}
	for (int i=0;i<=cols;i++){
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
			cout<<mat[i][j]<<"\t";
		}
		cout<<endl;
	}
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
	cout<<lcs(s1,s2);
}
