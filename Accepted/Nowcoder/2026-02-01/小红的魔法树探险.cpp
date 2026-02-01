#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (ksm(x, MOD - 2))

const int maxN = 1e5 + 7;
const int MOD = 1e9 + 7;
vector<int> adj[maxN];
vector<int> dp(maxN);

int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void dfs(int x, int fa) {
    int sum = 0;
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
        sum = (sum + dp[son]) % MOD;
    }
    int res = (1 + sum * inv(adj[x].size())) % MOD;
    dp[x] = res;
}

void solve(){
    int n;cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << dp[1] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
