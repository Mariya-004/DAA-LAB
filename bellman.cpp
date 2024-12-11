#include<iostream>
#include<limits>
using namespace std;
int distanceArr[10];
int pred[10];
int inf=numeric_limits<int>::max();
void relax(int u,int v,int w){
    if (distanceArr[v]>=distanceArr[u]+w){
        distanceArr[v]=distanceArr[u]+w;
        pred[v]=u;
    }
}
bool BellmanFord(int v,int e,int edgeList[][3],int src){
    //initialize single source
    for (int i=0;i<v;i++){
        distanceArr[i]=inf;
        pred[i]=-1;
    }
    distanceArr[src]=0;
    //algorithm
    for (int i=0;i<v-1;i++){
        for (int j=0;j<e;j++){
            int u=edgeList[j][0];
            int v=edgeList[j][1];
            int w=edgeList[j][2];
            relax(u,v,w);
        }
    }
    //checking negative weight cycles
    for (int j=0;j<e;j++){
            int u=edgeList[j][0];
            int v=edgeList[j][1];
            int w=edgeList[j][2];
            if(distanceArr[v]>distanceArr[u]+w and distanceArr[u]!=inf){
                cout<<"Graph Contains A negative Cycle"<<endl;
                return false;
            }
    }
    cout<<"vertex"<<"\t"<<"Distance from Source"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"\t"<<distanceArr[i]<<endl;
        
    }
    return true;
}
int main(){
    cout<<"Enter the number of vertices:";
    int v;
    cin>>v;
    cout<<"Enter the number of edges:";
    int e;
    cin>>e;
    int edgeList[e][3];
    cout<<"Enter the edge in (u v w) form:";
    for (int i=0;i<e;i++){
        cin>>edgeList[i][0]>>edgeList[i][1]>>edgeList[i][2];
    }
    cout<<"Enter the source vertex:";
    int src;
    cin>>src;
    if (BellmanFord(v, e, edgeList, src)) {
        cout << "No negative cycle found." << endl;
    }

    return 0;
    
}
