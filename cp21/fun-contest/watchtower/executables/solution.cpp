
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

    int n, m;
    int first, second;

    cin >> n >> m;
    vector<array<int,2>> edges;
    edges.reserve(m);
    rep(i,m) {
        cin >> first >> second;
        edges.emplace_back(array{first -1,second -1});
    }

    if (m == 0) {
        cout << 0 << endl;
        return 0;
    }

    int minimum_vertex_cover = n;
    int number_of_subsets = (int) pow(2, n);

    for (int i = 0; i < number_of_subsets; i++) {
        vector<int> subset;

        for (int j = 0; j < n; j++) {

            if ((i & (1 << j)) != 0)
                subset.emplace_back(j);
        }

        bool covered_all_edges = true;

        for(auto edge: edges) {
            if(std::find_first_of(subset.begin(), subset.end(), edge.begin(), edge.end()) == subset.end()) {
                covered_all_edges = false;
                break;
            }
        }
        if (covered_all_edges) {
            minimum_vertex_cover = min(minimum_vertex_cover, (int) subset.size());
        }
    }

    cout << minimum_vertex_cover << endl;

    return 0;
}
