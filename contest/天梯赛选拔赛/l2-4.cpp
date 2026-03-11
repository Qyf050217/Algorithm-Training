#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e18
int n;
const int maxN = 1e5 + 7;
vector<vector<int>> adj(maxN, vector<int>(maxN));
vector<vector<int>> dis1(maxN, vector<int>(2, LNF)), dis2(maxN, vector<int>(2, LNF));

void dijkstra1(int s) {
    queue<PII> q; // w - (odd, even)
    q.push({s, 0});
    dis1[s][0] = 0;
    while (q.size()) {
        auto [u, p] = q.front();
        for (int v = 1; v <= n; v++) {
            if (adj[u][v]) {
                int np = p;
                if (u == v) np = 1 - p;
                if (dis1[v][np] == LNF) {
                    dis1[v][np] = dis1[u][p] + 1;
                }
            }
        }
    }

}


void solve() {
    int m, s1, s2;cin >> n >> m >> s1 >> s2;
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    dijkstra1(s1);
    for (int i = 1; i <= n; i++) cout << dis1[i][0] << ' ';
    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;cin >> T;
    while (T--) solve();
}