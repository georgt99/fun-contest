#include <bits/stdc++.h>

#define all(a) begin(a), end(a)
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define sz(x) (int)size(x)
#define endl '\n'

using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
using ld=long double;

const int MAXN = 1005;

int dp[MAXN][2][MAXN];
vi adj[MAXN];

int n,m,a,k;

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	cin >> a >> k >> n >> m;
	rep(i,0,m) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	rep(i,0,n) {
		sort(all(adj[i]));
		adj[i].erase(unique(all(adj[i])), end(adj[i]));
	}

	rep(s,0,n) {
		dp[s][0][s] = 1;
		rep(t, 1, a+1) {
			rep(v, 0, n) {
				dp[s][t&1][v] = 0;
				for (auto ne : adj[v]) dp[s][t&1][v] += dp[s][(t-1)&1][ne];
				dp[s][t&1][v] = min(dp[s][t&1][v], k);
			}
		}
	}

	rep(i,0,n) rep(j,i+1, n) {
		if (dp[i][a&1][j] == k) cout << i << " " << j << endl;
	}
	
	cout << "0 0";

	return 0;
}
