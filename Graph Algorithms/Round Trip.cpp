/* Problem Link: https://cses.fi/problemset/task/1669/ */

#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+7; 
vector<vector<int>> adj(mxN);
int previous[mxN];
bool visited[mxN];
int start_cycle = 0, end_cycle = 0;

bool dfs(int x, int p) {
    visited[x] = true;
    for (auto &u : adj[x]) {
        if (u == p) continue;
        if (visited[u]) {
            start_cycle = u;
            end_cycle = x;
            return true;
        }
        previous[u] = x;
        if(dfs(u, x)) return true;
    }
    return false;
}

void find_cycle() {
    vector<int> ans;
    ans.push_back(start_cycle);
    for (int current = end_cycle; current != start_cycle; current = previous[current]) {
        ans.push_back(current);
    }
    ans.push_back(start_cycle);
    cout << ans.size() << endl;
    for (auto &u : ans) cout << u << " "; cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;        
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (visited[i]) continue;
        if (dfs(i, i)) break;
    }
    if (start_cycle) {
        find_cycle();
    } else {
        cout << "IMPOSSIBLE\n";
    }
}
