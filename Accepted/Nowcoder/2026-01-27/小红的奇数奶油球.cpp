#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> adj[maxN];
vector<int> dp(maxN);
vector<int> siz(maxN);
int n, res = 0;

void dfs(int x, int fa) {
    siz[x] = 1;
    int f = 1;
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
        siz[x] += siz[son]; 
        if ((siz[son] & 1) == 0) f = 0;
    }
    if (f && ((n - siz[x] & 1) || n == siz[x])) res++;
}

void init(int n) {
    res = 0;
    for (int i = 1; i <= n; i++) adj[i].clear();
    for (int i = 1; i <= n; i++) dp[i] = 0;
    for (int i = 1; i <= n; i++) siz[i] = 0;
}

void solve(){
    cin >> n;
    init(n);
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
