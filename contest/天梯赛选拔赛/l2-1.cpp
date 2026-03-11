#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int maxN = 1e4 + 7;
vector<int> adj[maxN];
vector<int> arr(maxN);
vector<int> res(maxN, -1);
vector<char> vis(maxN);
void dijkstra() {
    priority_queue<PII> pq;
    pq.push({arr[1], 1});
    res[1] = arr[1];
    while (pq.size()) {
        auto [w, u] = pq.top();
        pq.pop();
        for (auto v : adj[u]) {
            int nw = res[u] + arr[v];
            if (nw > res[v]) {
                res[v] = nw;
                pq.push({nw, v});
            }
        }
    }
}

void solve() {
    
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
    }
    dijkstra();
    if (res[n] == -1) cout << "Impossible";
    else cout << res[n] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}