#include <bits/stdc++.h>

#define rep(a, b) for (int a = 0; a < (b); ++a)
#define all(a) (a).begin(), (a).end()
#define endl '\n'

using namespace std;
using Graph = vector<vector<int>>; // init: Graph matrix(M, vector<int>(N));
using ll = long long;

int bfs(int h, int w, vector<vector<bool>> &visited)
{
    if (visited[h][w])
        return 0;
    int count = 0;
    queue<tuple<int, int>> q;
    q.push({h, w});

    while (!q.empty())
    {
        auto [h, w] = q.front();
        q.pop();
        if (h >= 0 && w >= 0 && h < visited.size() && w < visited[0].size() && !visited[h][w])
        {
            visited[h][w] = true;
            ++count;
            q.push({h, w + 1});
            q.push({h, w - 1});
            q.push({h + 1, w});
            q.push({h - 1, w});
            q.push({h + 1, w + 1});
            q.push({h - 1, w - 1});
            q.push({h + 1, w - 1});
            q.push({h - 1, w + 1});
        }
    }
    return count;
}

int maxArea(vector<vector<bool>> &visited)
{
    int h = visited.size(), w = visited[0].size(), maxarea = 0;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            int test = bfs(i, j, visited);
            maxarea = max(maxarea, test);
        }
    return maxarea;
}

void solve()
{
    int w, h;
    char tmp;
    cin >> w >> h;
    vector<vector<bool>> visitedPos(h, vector<bool>(w));
    vector<vector<bool>> visitedNeg(h, vector<bool>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            cin >> tmp;
            if (tmp == '+')
                visitedNeg[i][j] = true;
            else if (tmp == '-')
                visitedPos[i][j] = true;
            else
            {
                visitedNeg[i][j] = true;
                visitedPos[i][j] = true;
            }
        }

    cout << maxArea(visitedPos) << " " << maxArea(visitedNeg);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    solve();

    return 0;
}
