#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<PII> adj[maxN];
vector<vector<int>> dp(maxN);
vector<int> ans(maxN, 0);
int M;

void dfs(int x, int fa) {
    for (auto &[v, w] : adj[x]) {
        if (v == fa) continue;
        dfs(v, x);
        for (int i = 0; i <= M; i++) { // 向下偏移量
            int op1 = LNF, op2 = LNF;
            if (i >= w) op1 = dp[v][i - w] - w;
            if (i + w <= M) op2 = dp[v][i + w] + w;
            dp[x][i] = max(dp[x][i], min(op1, op2));
        }
    }

    int res = LNF;
    for (int i = 0; i <= M; i++) {
        res = min(res, i + dp[x][i]);
    }
    ans[x] = res;
}



void solve(){
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i].clear();
    }

    int W = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        W = max(W, w);
    }
    M = 2 * W;
    for (int i = 1; i <= n; i++) {
        dp[i].resize(2 * W + 1, 0);
    }

    dfs(1, 0);

    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
