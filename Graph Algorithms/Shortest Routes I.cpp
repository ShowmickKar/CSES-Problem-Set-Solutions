// Problem Link: https://cses.fi/problemset/task/1671/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mxN = 1e5+7; 
const ll inf = 1e18+7;

vector<vector<pair<int, ll>>> edge(mxN);
vector<ll> dist(mxN);
vector<bool> visited(mxN);

int n, m;

void dijkstra(int x) {
    for (int i = 1; i <= n; i++) dist[i] = inf;
    dist[x] = 0;
    priority_queue<pair<ll, int>> q;
    q.push({0, x});
    while(!q.empty()) {
        int p = q.top().second;
        q.pop();
        if (visited[p]) continue;
        visited[p] = true;
        for (auto &u : edge[p]) {            
            int b = u.first;
            ll w = u.second;          
            if (dist[p] + w < dist[b]) {
                dist[b] = dist[p] + w;
                q.push({-dist[b], b});
            }
        } 
    }
}

void solve(){  
    cin >> n >> m; 
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; 
        ll w; cin >> w;
        edge[x].push_back({y, w});
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
}  

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}  
