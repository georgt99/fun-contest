//region template{{{
//https://github.com/schmidtjonas/CPT/blob/master/template.cpp
#include <bits/stdc++.h>

#define GET_MACRO(_1,_2,_3,NAME,...) NAME
#define rep(...)        GET_MACRO(__VA_ARGS__, repn, rep0)(__VA_ARGS__)
#define rep0(i, b)      for(int i = 0; i < (b); ++i)
#define repn(i, a, b)   for(int i = (a); i < (b); ++i)
#define trav(a, b)      for(auto& a : b)
#define all(a)          (a).begin(),(a).end()
#define endl            '\n'
#define sz(x)           ((int)(x).size())
#define tests           int ___;cin>>___;while(___--)

using namespace std;
using ll = int64_t;
using ld = long double;
using ul = uint64_t;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vpi = vector<pi>;

static constexpr int inf = (int)1e9 + 5;
static constexpr ll infl = (ll)1e18 + 5;
static mt19937 rng((uint32_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count());
//endregion}}}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(10);

  int n, m; cin >> n >> m;
  vector<int> deg(n);
  vector<vector<int>> adj(n);
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    adj[a].emplace_back(i);
    adj[b].emplace_back(i);
  }
  vector<int> imp(n);
  iota(all(imp), 0);
  // greedy: sort by degree
  sort(all(imp), [&](auto &&a, auto &&b){
    return adj[a].size() < adj[b].size();
  });
  vector<bool> cov(m, false);
  int covered = 0;
  while (covered != m) {
    int c = imp.back();
    imp.pop_back();
    for (auto e : adj[c]) {
      if (!cov[e]) {
        covered++;
        cov[e] = true;
      }
    }
  }

  cout << (n - imp.size()) << endl;

  return 0;
}

