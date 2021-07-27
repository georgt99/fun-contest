#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

Graph adj;
bool dfs(int v, int p) {
    int req = 0;
    for(auto nei : adj[v])
        if(nei!=p)
            req += dfs(nei,v);
    if(req > 1) cout << "THE CAKE IS A LIE" << endl, exit(0);
    return req || size(adj[v])>2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int n; cin>>n;
    adj.resize(n+1);
    rep(i,n) {
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,-1);
    cout << "THERE WILL BE CAKE" << endl;

    return 0;
}

