/* Problem Link: https://cses.fi/problemset/task/1668/ */

#include <bits/stdc++.h>
using namespace std;

const int mxN = 100007;
vector<vector<int>> edges(mxN);
bool visited[mxN];
int color[mxN];

void dfs(int x) {
    visited[x] = true;
    for (auto &u : edges[x]) {
        if (visited[u]) continue;
        if (color[x] == 1) color[u] = 2;
        else color[u] = 1;
        dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> connections;
    for (int i = 0; i < m; i++) {
        int x, y;        
        cin >> x >> y;
        connections.push_back({x, y});
        edges[x].push_back(y);
        edges[y].push_back(x);
    }    
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        color[i] = 1;
        dfs(i);
    }
    for (auto &u : connections) {
        if (color[u.first] == color[u.second]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}
