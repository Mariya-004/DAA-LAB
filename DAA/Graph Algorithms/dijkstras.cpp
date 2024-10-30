#include<iostream>
#include<limits>
using namespace std;
class graph{
	public:
		int* pred;
		int* d;
		int * vertices;
		int v;
		graph(int v){
			this->v=v;
			pred=new int[v];
			d=new int[v];
			vertices=new int[v];
		}
		void vertexArray(int adj[][]){
			for (int i=1;i<=v;i++){
				vertices[i-1]=adj[i][0];
			}
		}
		int findvertIndex(int vertex){
			for (int i=0;i<v;i++){
				if (vertices[i]==v){
					return i;
				}
			}
		}
		int findWeight(int mat[][],int u,int z){
			int w=0;
			for (int i=1;i<v+1;i++){
				for (int j=1;j<v+1;j++){
					if (mat[i][0]==u and mat[0][j]==z){
						w=mat[i][j];
					}
				}
			}
			return w;
		}
		void initializeSingleSource(int s){
			for (int i=0;i<v;i++){
				d[i]=numeric_limits<int>::max();
				pred[i]=-1;
			}
			int indSource=findvertIndex(s);
			d[indSource]=0;
		}
		void relax(int adj[3][3],int u,int s){
			int indU=findvertIndex(u); 
			int indS=findvertIndex(s);
			if (d[indU]>d[indS]+findWeight(adj,s,u)){
				d[indU]=d[indS]+findWeight(adj,s,u);
			}
			pred[indU]=s;
			
		}
		int extractMin(int adj[][],int s,int Q[]){
			int minIndex=-1;
			int minVertex=-1;
			int min=numeric_limits<int>::max();
			for (int i=0;i<v;i++){
				if(Q[i]!=-1){
				int w=findWeight(adj,s,Q[i]);
				if (w<min){
					min=w;
					minIndex=i;
				}
			}
		    minVertex=Q[minIndex];
			Q[minIndex]=-1;
			return minVertex;
				}

			 
		}
		int* findAdjVertices(int adj[][],int u){
			int indU=-1;
			for (int i=1;i<=v;i++){
				if (adj[i][0]==u){
					indU=i;
					break;
				}
			}
			int c=0;
			for (int i=1;i<=v;i++){
				if (adj[indU][i]!=0){
					c++;
				}
			}
			int* arr=new int[c];
			int a=0;
			for (int i=1;i<=v;i++){
				if (adj[indU][i]!=0){
					arr[a]=adj[0][i];
					a++;
				}
			}
			return arr;
		}
		void dijkstras(int adj[3][3],int s){
			initializeSingleSource(s);
			int S[v];
			int Q[v];
			for (int i=0;i<v;i++){
				Q[i]=vertices[i];
			}
			int i=0;
			while(i<v){
				int u=extractMin(adj,s,Q);
				S[i]=u;
				for 
			}
			
		}
		void display(int adj[3][3],int v){
			for (int i=0;i<v;i++){
				for (int j=0;j<v;j++){
					cout<<adj[i][j]<<" ";
				}
			cout<<endl;
		}
		}
};	
int main(){
	
	int adj[2][2]={{1,2},{3,4}};
	display(adj,2);
}