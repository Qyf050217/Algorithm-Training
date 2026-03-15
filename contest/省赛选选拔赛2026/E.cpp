#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> adj[maxN];
vector<int> d(maxN); // 以 i 为根子树的直径
vector<int> res(maxN);
vector<PII> lian(maxN);
// d[x] = max(d[son], mx + cx);
void dfs(int x, int fa) {
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
        d[x] = max(d[x], d[son]);
        int l = lian[son].first + 1;
        if (l >= lian[x].first) {
            lian[x].second = lian[x].first;
            lian[x].first = l;
        } else if (l > lian[x].second) {
            lian[x].second = l;
        }
        res[x] += d[son];
    }
    d[x] = max(d[x], lian[x].first + lian[x].second);
}

void solve() {
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        d[i] = 0;
        res[i] = 0;
        lian[i] = {0, 0};
    }
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << res[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}