#include<iostream>
using namespace std;
void display(int adj[2][2],int v){
	for (int i=0;i<v;i++){
		for (int j=0;j<v;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<endl;
	}
}	
int main(){
	
	int adj[2][2]={{1,2},{3,4}};
	display(adj,2);
}