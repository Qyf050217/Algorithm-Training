#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m, k;cin >> n >> m >> k;
    vector<int> adj[n + 1];
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<pair<PII, int>> q; // {[v, 0/1] - dis}
    vector<vector<int>> dis(n + 1, vector<int>(2, LNF));
    vector<vector<int>> vis(n + 1, vector<int>(2, 0));
    dis[1][0] = 0;
    // dis[1][1] = LNF;
    q.push({{1, 0}, 0});
    int cnt = 0;
    while (q.size()) {
        auto [pii, d] = q.front(); q.pop();
        int v = pii.first, st = pii.second;
        if (vis[v][st]) continue;
        vis[v][st] = 1;
        int nx = 1 - st;
        int D = d + 1;
        for (auto u : adj[v]) {
            if (D < dis[u][nx]) {
                dis[u][nx] = D;
                q.push({{u, nx}, D});
            }
        }
    }

    // for (int i = 1; i <= n; i++) cout << dis[i][0] << " \n"[i == n];
    // for (int i = 1; i <= n; i++) cout << dis[i][1] << " \n"[i == n];
    
    cout << 0 << ' ';
    for (int i = 2; i <= n; i++) {
        int ans = LNF;
        
        if (dis[i][0] != LNF) {
            int x = dis[i][0];
            int z = (x + k - 1) / k;
            
            if (z * k % 2 != x % 2) z++;
            if (z * k % 2 == x % 2) ans = min(ans, z * k);
        }
        if (dis[i][1] != LNF) {
            int x = dis[i][1];
            int z = (x + k - 1) / k;
            if (z * k % 2 != x % 2) z++;
            if (z * k % 2 == x % 2) ans = min(ans, z * k);
        }
        if (ans == LNF) cout << -1 << ' ';
        else cout << ans << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
