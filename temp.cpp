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


void solve(){
    int n, m;cin >> n >> m;
    vector<int> ans(n + 1);
    vector<vector<int>> dr(n + 1, vector<int>(n + 1));
    
    for (int i = 1; i <= m; i++) {
        int o, u, v;cin >> o >> u >> v;
        if (o == 1) {
            dr[u][v] = 1;
            dr[v][u] = 1;
        } else {
            dr[u][v] = -1;
            dr[v][u] = -1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dr[i][i] == 1) ans[i] = 1;
        else ans[i] = -1;
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


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}