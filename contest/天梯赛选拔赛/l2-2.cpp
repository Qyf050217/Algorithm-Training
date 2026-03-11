#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

int n;
const int maxN = 1e5 + 7;
vector<int> adj[maxN];
vector<int> height(maxN);
vector<int> k(maxN);
vector<int> gra(maxN), f(maxN);
vector<int> s(maxN), e(maxN);
int odd = 0, even = 0;
vector<int> ans;
void pre(int x, int fa, int h) {
    height[x] = h;
    f[x] = fa;
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        pre(son, x, h + 1);
    }
}
/*
       1
    2     3
  4   5


*/
void dfs(int x, int fa, int h) {
    s[x] ^= k[f[fa]];
    if (s[x] != e[x]) {
        ans.push_back(x);
        k[x] = 1 - k[f[fa]];
    } else {
        k[x] = k[f[fa]];
    }

    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x, h+1);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> e[i];
    // for (int i = 1; i <= n; i++) cout << e[i] << ' ';
    // cout << endl;
    pre(1, 0, 1);
    dfs(1, 0, 1);
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i < ans.size() - 1) cout << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}