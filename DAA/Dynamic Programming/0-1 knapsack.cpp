#include<iostream>
using namespace std;

int max(int a, int b) {
    if (a>b){
        return a;
    }
    else{
        return b;
    }
}

int knapsack(int n, int c, int w[], int v[]) {
    int mat[n + 1][c + 1];
    
    // Initialize base cases
    for (int i = 0; i <= n; i++) {
        mat[i][0] = 0;
    }
    for (int i = 0; i <= c; i++) {
        mat[0][i] = 0;
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (j - w[i - 1] >= 0) {
                mat[i][j] = max(mat[i - 1][j], v[i - 1] + mat[i - 1][j - w[i - 1]]);
            } else {
                mat[i][j] = mat[i - 1][j];
            }
        }
    }

    // Print DP table (optional)
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= c; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }

    int val = mat[n][c];

    // Traceback to find included items
    int includeItems[n]; // array to store included items
    int index = 0;
    int cap = c; // capacity tracker
    for (int i = n; i > 0; i--) {
        if (mat[i][cap] != mat[i - 1][cap]) {
            includeItems[index++] = i - 1;
            cap -= w[i - 1];
        }
    }

    // Print included items
    cout << "Included items: ";
    for (int i = index - 1; i >= 0; i--) {
        cout << includeItems[i] << " ";
    }
    cout << endl;
    cout<<"Maximum value:"<<mat[n][c]<<endl;
    return val;
}

int main() {
    cout << "ENTER THE CAPACITY OF THE KNAPSACK: ";
    int cap;
    cin >> cap;
    
    cout << "ENTER THE NUMBER OF ITEMS: ";
    int n;
    cin >> n;
    
    int W[n], V[n];
    for (int i = 0; i < n; i++) {
        cout << "ENTER THE WEIGHT OF ITEM " << i + 1 << ": ";
        cin >> W[i];
        cout << "ENTER THE VALUE OF ITEM " << i + 1 << ": ";
        cin >> V[i];
    }

     knapsack(n, cap, W, V) ;
}
