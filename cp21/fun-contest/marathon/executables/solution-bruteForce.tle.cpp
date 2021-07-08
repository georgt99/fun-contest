#include <bits/stdc++.h>

#define endl        '\n'
using namespace std;
using ll = long long;
using Graph = vector<set<int>>;

void doWalk(int v, int steps, Graph& G, vector<int>& paths) {
    if (steps == 0) {
        paths[v]++;
        return;
    }
    for (int w : G[v]) {
        doWalk(w, steps-1, G, paths);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n, m, a, k; cin >> a >> k >> n >> m;

    //Read in graph
    Graph G(n);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        G[x].insert(y);
        G[y].insert(x);
    }

    vector<pair<int, int>> solutions;

    //For every town x, do all walks of length
    for (x = 0; x < n; x++) {
        vector<int> possiblePaths(n, 0); //possiblePaths[y] is number of x-y-paths (with repeating edges) of length a
        doWalk(x, a, G, possiblePaths);
        for (y = x+1; y < n; y++) {
            if (possiblePaths[y] >= k)
                solutions.push_back({x,y});
        }
    }
    sort(solutions.begin(), solutions.end());
    for (auto [x1,y1] : solutions) {
        cout << x1 << " " << y1 << endl;
    }
    cout << "0 0" << endl;
    return 0;
}