#include <bits/stdc++.h>

#define rep(a, b)   for(int a = 0; a < (b); ++a)
#define all(a)      (a).begin(),(a).end()
#define endl        '\n'

using namespace std;
using Graph = vector<vector<int>>; // init: Graph matrix(M, vector<int>(N));
using ll = long long;

int dfs(int h, int w, vector<vector<bool>> &visited) {
    if (h < 0 || w < 0 || h >= visited.size() || w >= visited[0].size() || visited[h][w])
        return 0;
    visited[h][w] = true;
    return dfs(h + 1, w, visited) + dfs(h, w + 1, visited) + dfs(h + 1, w + 1, visited) +
           dfs(h - 1, w, visited) + dfs(h, w - 1, visited) + dfs(h - 1, w - 1, visited) +
           dfs(h + 1, w - 1, visited) + dfs(h - 1, w + 1, visited) + 1;
}

int maxArea(vector<vector<bool>> &visited) {
    int h = visited.size(), w = visited[0].size(), maxarea = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            int test = dfs(i, j, visited);
            maxarea = max(maxarea, test);
        }
    return maxarea;
}

void solve() {
    int w, h;
    char tmp;
    cin >> w >> h;
    vector<vector<bool>> visitedPos(h, vector<bool>(w));
    vector<vector<bool>> visitedNeg(h, vector<bool>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            cin >> tmp;
            if (tmp == '+')
                visitedNeg[i][j] = true;
            else if (tmp == '-')
                visitedPos[i][j] = true;
            else {
                visitedNeg[i][j] = true;
                visitedPos[i][j] = true;
            }
        }

    cout << maxArea(visitedPos) << " " << maxArea(visitedNeg);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    solve();

    return 0;
}

