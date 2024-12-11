#include <iostream>
#include <algorithm>
using namespace std;
// Structure to represent an edge in the graph
struct Edge {
    int u, v, weight;
};
// Function to find the parent of a vertex (with path compression)
int findSet(int parent[], int v) {
    if (parent[v] == v)
        return v;
    return parent[v] = findSet(parent, parent[v]);
}
// Function to perform union of two sets (union by rank)
void unionSet(int parent[], int rank[], int u, int v) {
    int rootU = findSet(parent, u);
    int rootV = findSet(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}
// Comparison function to sort edges by weight
bool compareEdges(Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}
// Kruskal's Algorithm
void kruskal(Edge edges[], int V, int E) {
    int parent[V];
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    // Sort edges by weight
    sort(edges, edges + E, compareEdges);
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    int mstWeight = 0;
    int edgeCount = 0; // Count of edges in the MST
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;
        // Check if including this edge creates a cycle
        if (findSet(parent, u) != findSet(parent, v)) {
            cout << u << " -- " << v << " == " << weight << endl;
            mstWeight += weight;
            unionSet(parent, rank, u, v);
            edgeCount++;
        }
    }
    cout << "Total weight of Minimum Spanning Tree: " << mstWeight << endl;
}
int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    Edge edges[E];
    cout << "Enter the edges (u v weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }
    kruskal(edges, V, E);
    return 0;
}

