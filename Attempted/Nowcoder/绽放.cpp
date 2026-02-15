#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<PII> adj[maxN]; // {u, w}
int res = 0;
void dfs(int x, int fa) {
    for (auto &[son, w] : adj[x]) {
        if (son == fa) continue;

    }
}

void solve(){
    int n, st;cin >> n >> st;
    for (int i = 1; i < n; i++) {
        int u, v, w;cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    int res = 0;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}