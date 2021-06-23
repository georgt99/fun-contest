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

    int n, m, k, d; cin >> n >> m >> k >> d;
    
    //Read in graph into adjacency matrix (and a copy)
    vector<vector<int>> map(n, vector<int>(n,0));
    vector<vector<int>> paths(n, vector<int>(n,0));
    int a,b;
    for (int i = 0; i < m; i++) {  
        cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
        paths[a][b] = 1;
        paths[b][a] = 1;
    }

    for (int i = 0; i < d-1; i++) { // d-1 times set paths = map * paths
        vector<vector<int>> next(n, vector<int>(n));
        multiplyMatrices(paths, map, next);
        paths = next;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (paths[i][j] >= k) {
                cout << i << " " << j << endl;
            }
        } 
    } 
    cout << -1 << endl;
    return 0;
}