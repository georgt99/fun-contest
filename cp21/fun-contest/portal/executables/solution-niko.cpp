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

const int MAXN = 200005;

vi adj[MAXN];

int dfs(int c, int p) {
	int child = 0;
	int child_portal = 0;
	for (auto ne : adj[c]) {
		if (ne != p) {
			child++;
			int r = dfs(ne, c);
			if (!r) return 0;
			child_portal += r == 1;
		}
	}
	if (child_portal > 1) return 0;
	return 2 - (child_portal || child > 1);
}

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	int n; cin >> n, n++;
	int a, b; 
	while (cin >> a >> b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}


	cout << (dfs(0, -1) ? "THERE WILL BE CAKE" : "THE CAKE IS A LIE") << endl;

	return 0;
}
