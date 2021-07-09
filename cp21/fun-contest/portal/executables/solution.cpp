#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
//#define endl        '\n'


using namespace std;
using Graph = vector<vector<int>>;
using ll = long long;


Graph G;

// pair<subtree_requires_portal, subtree_is_solvable>
pair<bool,bool> DFS_portal_check(int current, int caller){
    int number_of_subtrees_requiring_portal = 0;
    int number_of_children = 0;
    for (int adj : G[current]){
        if (adj == caller) continue;
        pair<bool, bool> result = DFS_portal_check(adj, current);
        if (!result.second) return pair<bool,bool>(false, false);
        if (result.first) number_of_subtrees_requiring_portal++;
        number_of_children++;
    }
    if (number_of_subtrees_requiring_portal >= 2){
        return pair<bool, bool>(false, false);
    }
    if (number_of_children > 1 || number_of_subtrees_requiring_portal == 1){
        return pair<bool, bool>(true, true);
    }
    return pair<bool, bool>(false, true);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);


    // content
    int n; cin >> n; n++;
    G = Graph(n, vector<int>());
    for (int i = 0; i < n-1; i++){
        int a; cin >> a;
        int b; cin >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    if (DFS_portal_check(0, -1).second){
        cout << "THERE WILL BE CAKE" << endl;
    } else {
        cout << "THE CAKE IS A LIE" << endl;
    }

    return 0;
}