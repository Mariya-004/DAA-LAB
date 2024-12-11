#include <iostream>
#include <climits>
using namespace std;
void primMST(int graph[100][100], int nodes) {
    int parent[100], key[100];
    bool inMST[100] = {false};
    // Initialize keys to infinity and parents to -1
    fill(key, key + nodes, INT_MAX);
    parent[0] = -1; // Starting node
    key[0] = 0;     // Include first vertex
    for (int count = 0; count < nodes ; count++) {
        int u = -1;
        // Find the vertex with the minimum key value
        for (int i = 0; i < nodes; i++)
            if (!inMST[i] && (u == -1 || key[i] < key[u]))
                u = i;
        inMST[u] = true;
        // Update keys of adjacent vertices
        for (int v = 0; v < nodes; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    // Print the MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < nodes; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << "\n";
}
int main() {
    int nodes, edges;
    int graph[100][100] = {0}; // Initialize graph with 0s
    cout << "Enter number of nodes: ";
    cin >> nodes;
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges in (u v w) format:\n";
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w; // Assuming undirected graph
    }
    primMST(graph, nodes);
    return 0;
}

