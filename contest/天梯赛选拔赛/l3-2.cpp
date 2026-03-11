#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e18

const int maxN = 1e3 + 7;
vector<PII> adj[maxN];
vector<int> arr(maxN);
vector<vector<int>> dis(maxN, vector<int>(1LL << 12, LNF));
vector<vector<int>> vis(maxN, vector<int>(1LL << 12));

void dijkstra() {
    priority_queue<pair<int, PII>, vector<pair<int, PII>>, greater<pair<int, PII>>> pq; // w - u - st
    pq.push({0, {1, arr[1]}});
    dis[1][arr[1]] = 0;
    while (pq.size()) {
        int w = pq.top().first;
        int u = pq.top().second.first;
        int st = pq.top().second.second;
        pq.pop();
        if (vis[u][st]) continue;
        vis[u][st] = 1;
        for (auto &[v, nw] : adj[u]) {
            int nst = st | arr[v];
            if (dis[v][nst] < nw + w) {
                dis[v][nst] = nw + w;
                pq.push({dis[v][nst], {v, nst}});
            }
        }
    }
}

void solve() {
    int n, m, k;cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        int cnt;cin >> cnt;
        int t;
        for (int j = 1; j <= cnt; j++) {
            int kk;cin >> kk;
            t |= (1LL << kk);
        }
        arr[i] = t;
        // cout << t << endl;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dijkstra();
    cout << dis[n][(1<<(k + 1)) - 1] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}