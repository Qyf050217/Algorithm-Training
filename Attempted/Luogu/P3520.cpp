#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
int n, m;
vector<int> adj[maxN];

vector<int> EulerCircuit() {
    vector<int> deg(n + 1, 0);
    for (int u = 1; u <= n; ++u) {
        deg[u] = adj[u].size();
    }

    int start = -1;
    bool hasOdd = false;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] % 2 != 0) {
            hasOdd = true;
        }
        if (deg[i] > 0 && start == -1) {
            start = i;
        }
    }
    if (hasOdd || start == -1) {
        return {};
    }

    vector<int> path;
    auto dfs = [&](auto&& self, int u) -> void {
        while (!adj[u].empty()) {
            int v = adj[u].back();
            adj[u].pop_back();
            auto it = find(adj[v].begin(), adj[v].end(), u);
            if (it != adj[v].end()) {
                adj[v].erase(it);
            }
            self(self, v);
        }
        path.push_back(u);
    };
    
    dfs(dfs, start);
    reverse(path.begin(), path.end());
    return path;
}

void solve(){
    for (int i = 1; i <= n; i++) adj[i].clear();


    cin >> n >> m;

    map<PII, int> pos;
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        pos[{min(u, v), max(u, v)}] = i;
    }
    vector<int> odd;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() & 1) odd.push_back(i);
    }
    
    for (int i = 0; i < odd.size(); i += 2) {
        int u = odd[i], v = odd[i + 1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> cir = EulerCircuit();
    vector<int> res(m + 1, 0);

    int c = 1;
    for (int i = 0; i < cir.size(); i++) {
        int s = cir[i];
        c++;
        for (int j = i + 1; ; j++) {
            int u = cir[j - 1];
            int v = cir[j];
            int p = pos[{min(u, v), max(u, v)}];
            res[p] = c;
            if (v == s) {
                i = j;
                break;
            }
        }
    }

    for (int i = 1; i <= m; i++) cout << res[i] << " \n"[i == m];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}