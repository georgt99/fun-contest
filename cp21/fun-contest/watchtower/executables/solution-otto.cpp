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
  bitset<210> tgt = 0;
  vector<bitset<210>> vs(n);
  rep(i, m) {
    tgt.set(i, true);
    int a, b; cin >> a >> b;
    a--; b--;
    vs[a].set(i, true);
    vs[b].set(i, true);
  }
  vector<int> combs(1<<20);
  iota(all(combs), 0);
  sort(all(combs), [](auto &a, auto &b) { return __builtin_popcount(a) < __builtin_popcount(b); });
  for (auto comb : combs) {
    int cnt = __builtin_popcount(comb);
    bitset<210> hit = 0;

    while (comb > 0) {
      int v = __builtin_ctz(comb);
      hit |= vs[v];
      comb ^= (1 << v);
    }

    if (hit == tgt) {
      cout << cnt << endl;
      break;
    }
  }

  return 0;
}

