// freopen("../../p257.t13.in", "r", stdin);

#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int w,h; cin>>w>>h;
    vector<string> mat(h);
    for(auto& s : mat) cin>>s;

    int ans_p = 0, ans_n = 0;
    rep(i,h) rep(j,w) {
        if(mat[i][j]=='0') continue;
        auto charge = mat[i][j];
        mat[i][j] = '0';
        queue<pair<int,int>> q;
        q.emplace(i,j);
        int comp_sz = 1;
        while(!empty(q)) {
            auto [x,y] = q.front(); q.pop();
            for(auto dx : {-1,0,1}) for(auto dy : {-1,0,1}) {
                auto [nx,ny] = pair(x+dx, y+dy);
                if(nx<0 || h<=nx || ny<0 || w<=ny) continue;
                if(mat[nx][ny]!=charge) continue;
                mat[nx][ny] = '0';
                q.emplace(nx,ny);
                comp_sz++;
            }
        }
        if(charge=='+') ans_p = max(ans_p, comp_sz);
        if(charge=='-') ans_n = max(ans_n, comp_sz);
    }

    cout << ans_p << ' ' << ans_n << endl;

    return 0;
}

