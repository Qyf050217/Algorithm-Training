#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> z[maxN];
vector<int> f[maxN];
vector<int> a[maxN];
vector<int> vis(maxN);
vector<int> fa(maxN);
vector<int> ans(maxN);
map<int, vector<int>> flag;
int ok = 1;

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}


void dfs(int val) {
    auto &vec = flag[val];
    if (vec.size() == 0) return;
    for (auto &u : vec) {
        if (vis[u]) continue;
        vis[u] = 1;
        if (val > 0) { // 1
            int to = -val - 1;
            for (auto &son : f[u]) { // -2
                if (vis[son]) continue;
                ans[son] = to;
                flag[to].push_back(son);
            }
        } else { // -1
            int to = -val + 1;
            for (auto &son : z[u]) { // 2
                if (vis[son]) continue;
                ans[son] = to;
                flag[to].push_back(son);
            }
        }
    }
    if (val > 0) dfs(-val - 1);
    else dfs(val+1);
}


void solve(){
    int n, m;cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        vis[i] = 0;
        ans[i] = 0;
        z[i].clear();
        f[i].clear();
    }
    vector<vector<int>> dr(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= m; i++) {
        int o, u, v;cin >> o >> u >> v;

        int u_fa = find(u);
        int v_fa = find(v);
        if (u_fa != v_fa) fa[u_fa] = u_fa;

        if (o == 1) {
            z[u].push_back(v);
            z[v].push_back(u);
            dr[u][v] = dr[v][u] = 1;
        } else {
            f[u].push_back(v);
            f[v].push_back(u);
            dr[u][v] = dr[v][u] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dr[i][i] == 1) ans[i] = 1;
        else if (dr[i][i] == -1) ans[i] = -1;
    }

    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            if (dr[u][v] == 1) {
                for (int x = 1; x <= n; x++) {
                    if (x == u || x == v) continue;
                    if (dr[u][x] == -1 && dr[v][x] == -1) {
                        if (ans[x] == 1) {
                            cout << "NO" << endl;
                            return;
                        }
                        ans[x] = -1;
                    }
                }
            } else {
                for (int x = 1; x <= n; x++) {
                    if (x == u || x == v) continue;
                    if (dr[u][x] == 1 && dr[v][x] == 1) {
                        if (ans[x] == -1) {
                            cout << "NO" << endl;
                            return;
                        }
                        ans[x] = 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (ans[i] != 0 && ans[j] != 0 && dr[i][j] != 0) {
                if (dr[i][j] != )
            } 
        }
    }

    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) {
        mp[find(i)].push_back(i); 
    }
    for (auto &[root, vec] : mp) {
        int f = 1;
        for (auto &i : vec) {
            if (ans[i] != 0) {
                f = 0;
                break;
            }
        }
        if (f == 0) break;
        ans[root] = 1;
    }

    for (int i = 1; i <= n; i++) {
        if (ans[i] != 0) flag[ans[i]].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}