#include <bits/stdc++.h>

#define endl        '\n'
using namespace std;
using ll = long long;

//Multiplies A and B and stores the result in C.
void multiplyMatrices(int n, vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C) {
    int sum;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum = 0;
            for (int k = 0; k < n; k++) {
                sum += A[k][j] * B[i][k];
            }
            C[i][j] = sum;
        }        
    }
    
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, a, k; cin >> a >> k >> n >> m;
    
    //Read in graph into adjacency matrix (and a copy)
    vector<vector<int>> map(n, vector<int>(n,0));
    vector<vector<int>> paths(n, vector<int>(n,0));
    int x, y;
    for (int i = 0; i < m; i++) {  
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
        paths[x][y] = 1;
        paths[y][x] = 1;
    }

    for (int i = 0; i < d-1; i++) { // d-1 times set paths = map * paths
        vector<vector<int>> next(n, vector<int>(n));
        multiplyMatrices(n, paths, map, next);
        paths = next;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (paths[i][j] >= k) {
                cout << i << " " << j << endl;
            }
        } 
    } 
    cout << "0 0" << endl;
    return 0;
}