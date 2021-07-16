#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    constexpr auto M = 15*14/2;

    int n,m; cin>>n>>m;
    vector<bitset<M>> e(n);
    rep(i,m) {
        int x,y; cin>>x>>y;
        e[x-1].set(i);
        e[y-1].set(i);
    }

    int res = n;
    rep(mask,2<<n) {
        bitset<M> hit;
        rep(v,n) if((mask>>v)&1) hit |= e[v];
        if(hit.count()==m) res = min(res, __builtin_popcount(mask));
    }
    cout << res << endl;

    return 0;
}
