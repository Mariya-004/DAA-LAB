#include <iostream>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();
int distanceArr[10];
int pred[10];

// Relax function to update the distance and predecessor if a shorter path is found
void relax(int u, int v, int w) {
    if (distanceArr[v] > distanceArr[u] + w) {
        distanceArr[v] = distanceArr[u] + w;
        pred[v] = u;
    }
}

// Initialize adjacency matrix for the graph
void initMat(int adj[10][10], int v) {
    for (int i = 0; i < v; ++i) {
        for (int j = 0; j < v; ++j) {
            adj[i][j] = 0;
        }
    }
}

// Add an edge to the adjacency matrix
void addEdge(int u, int v, int adj[10][10], int w) {
    adj[u][v] = w;
}
void printPath(int predecessor[], int v) {
    if (predecessor[v] == -1) { // Base case: Start of the path
        cout << v << " ";
        return;
    }
    printPath(predecessor, predecessor[v]);
    cout << v <<" "<<endl;
}

// Find the unvisited vertex with the smallest distance
int minVertex(int dist[], int vis[], int v) {
    int minIndex = 0;
    int minVal = INF;
    for (int i = 0; i < v; ++i) {
        if (!vis[i] && dist[i] < minVal) {
            minIndex = i;
            minVal = dist[i];
        }
    }
    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(int adj[10][10], int src, int v) {
    for (int i = 0; i < v; ++i) {
        distanceArr[i] = INF;
        pred[i] = -1;
    }
    distanceArr[src] = 0;

    int vis[10] = {0}; // Visited vertices array
    for (int i = 0; i < v; ++i) {
        int u = minVertex(distanceArr, vis, v);
        vis[u] = 1;
        
        for (int j = 0; j < v; ++j) {
            if (adj[u][j] != 0 && !vis[j]) {
                relax(u, j, adj[u][j]);
            }
        }
    }

    // Output the results
    cout << "Vertex\tDistance from Source\tPredecessor" << endl;
    for (int i = 0; i < v; ++i) {
        cout << i << "\t" << (distanceArr[i] == INF ? -1 : distanceArr[i]) << "\t\t";
        cout << pred[i] << endl;
    }
    cout<<"Path"<<endl;
    for (int i=0;i<v;i++){
    	printPath(pred,i);
	}
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;
    int adj[10][10];
    initMat(adj, v);
    cout << "Enter the edges in (u v w) form:" << endl;
    for (int i = 0; i < e; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, adj, w);
    }
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;
    dijkstra(adj, src, v);
    return 0;
}

