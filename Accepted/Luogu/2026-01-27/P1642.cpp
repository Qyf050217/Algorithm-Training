#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, m, k;
const double eps = 0.001;
const int maxN = 107;
vector<int> adj[maxN];
vector<double> arr(maxN);
vector<vector<double>> dp(maxN, vector<double>(maxN, -LNF));
void dfs(int x, int fa) {
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
        for (int i = k; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                if (dp[x][i - j] != -LNF && dp[son][j] != -LNF) {
                    dp[x][i] = max(dp[x][i], dp[x][i - j] + dp[son][j]);
                }
            }
        }
    }
}

bool check() {
    for (int i = 1; i <= n; i++) for (int j = 2; j <= n; j++) dp[i][j] = -LNF;
    for (int i = 1; i <= n; i++) dp[i][1] = arr[i];
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        if (dp[i][k] >= 0.0) return true;
    }
    return false;
}

void solve(){
    cin >> n >> m;
    k = n - m;
    vector<int> w(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> w[i]; 
    for (int i = 1; i <= n; i++) cin >> c[i]; 
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    double l = 0.0, r = 10000.0;
    double ans = 0.0;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        for (int i = 1; i <= n; i++) arr[i] = w[i] - c[i] * mid;
        if (check()) {
            l = mid;
            ans = l;
        } else {
            r = mid;
        }
    }
    printf("%.1f", ans);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
