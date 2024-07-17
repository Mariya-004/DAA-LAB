#include<iostream>
using namespace std;
class Mat{
	public:
		int ** adj;
		Mat(int row,int col){
			adj=new int*[row+1];
			for (int i=0;i<row+1;i++){
				adj[i]=new int[col+1];
			}
			for (int i=1;i<col+1;i++){
				adj[0][i]=i;
			}
			for (int i=1;i<row+1;i++){
				adj[i][0]=i;
			}
			for	(int i=1;i<row+1;i++){
				for (int j=1;j<col+1;j++){
					adj[i][j]=0;
				}
			}
		}
		void setMat(int n){
			for (int i=1;i<n+1;i++){
				for (int j=1;j<n+1;j++){
					cout<<"IS "<<j<<" CONNECTED TO "<<i<<" (y/n): ";
					char ch;
					cin>>ch;
					if (ch=='y'){
						adj[i][j]=1;
					}
					else{
						adj[i][j]=0;
					}
				}
				cout<<endl;
			}
		}
		void displayMat(int n){
			for (int i=0;i<n+1;i++){
				for (int j=0;j<n+1;j++){
					if (i==0 and j==0){
						cout<<"  ";
					}
					else{
					cout<<adj[i][j]<<" ";
					}
				}
				cout<<endl;
			}
		}
		
		
};
int main(){
	cout<<"ENTER THE NUMBER OF VERTICES:";
	int v;
	cin>>v;
	Mat m(v,v);
	m.displayMat(v);
	m.setMat(v);
	m.displayMat(v);
}
