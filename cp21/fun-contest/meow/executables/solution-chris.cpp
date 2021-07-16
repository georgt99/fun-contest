#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);

    int t; cin>>t;
    while(t--) {
        string s; cin>>s;
        int oes = count(all(s), 'e') + count(all(s), 'o');
        int res = oes%2;
        for(int d=2; d*d<=oes; d++) {
            if(oes%d!=0) continue;
            // found two diviors (d and oes/d)
            res += d%2;
            res += oes/d%2 && d*d!=oes;
        }
        cout << res << endl;
    }

    return 0;
}
