/* Problem Link: https://cses.fi/problemset/task/1193/ */

#include <bits/stdc++.h>

using namespace std;

const int mxN = 1007;
vector<vector<int>> previous(mxN, vector<int>(mxN, 4));
bool visited[mxN][mxN];

int dn[] = {0, 0, 1, -1};
int dm[] = {1, -1, 0, 0};

char moves[] = {'R', 'L', 'D', 'U'};

void bfs(vector<string> grid, int n, int m, pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    while(!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();
        for (int x = 0; x < 4; x++) {
            int i = current.first + dn[x], j = current.second + dm[x];
            if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == '#') {
                continue;
            }
            visited[i][j] = true;
            previous[i][j] = x;
            q.push(make_pair(i, j));
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto &u : grid) cin >> u;
    pair<int, int> start, end;
    bool flag1 = false, flag2 = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                start = {i, j};
                flag1 = true;
            }
            if (grid[i][j] == 'B') {
                end = {i, j};
                flag2 == true;
            }
        }
        if (flag1 && flag2) break;
    }
    visited[start.first][start.second] = true;
    bfs(grid, n, m, start);
    if (previous[end.first][end.second] < 4) {
        cout << "YES\n";
        vector<char> result;
        while (end != start) {
            int p = previous[end.first][end.second];
            result.push_back(moves[p]);
            end.first -= dn[p];
            end.second -= dm[p];
        }
        cout << result.size() << endl;
        reverse(result.begin(), result.end());
        for (auto &u : result) cout << u; cout << endl;

    } else {
        cout << "NO\n";
    }
}
