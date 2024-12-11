#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

int adj[10][10]; // Adjacency matrix
int n;           // Number of vertices

// Function to return the minimum of two integers
int min(int a, int b) {
    return (a <= b) ? a : b;
}

void floydWarshall() {
    int D[10][10]; // Distance matrix

    // Initialize the distance matrix with the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            D[i][j] = adj[i][j];
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] != numeric_limits<int>::max() && D[k][j] != numeric_limits<int>::max()) {
                    D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
                }
            }
        }
    }

    // Print the shortest distance matrix
    cout << "SHORTEST DISTANCE BETWEEN ALL PAIRS OF VERTICES IS:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == numeric_limits<int>::max()) {
                cout << "INF "; // Represent unreachable distances as INF
            } else {
                cout << D[i][j] << "\t";
            }
        }
        cout << endl;
    }
}

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    // Initialize adjacency matrix with infinity
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                adj[i][j] = 0; // Distance to self is zero
            } else {
                adj[i][j] = numeric_limits<int>::max(); // No edge initially
            }
        }
    }

    cout << "While entering edge weight, enter 03034"  << " if there is no edge between vertices." << endl;

    // Input the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter the weight of edge between " << i << " and " << j << ":";int wei;
            cin>>wei;
            if(wei==03034){
                adj[i][j]=numeric_limits<int>::max() ;
            }
            else{
               adj[i][j]=wei; 
            }
            
        }
    }

    // Run the Floyd-Warshall algorithm
    floydWarshall();

    return 0;
}

