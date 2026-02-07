#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> adj[maxN];
vector<int> ans(maxN, LNF);
vector<int> deg(maxN, 0);


void solve(){
    int n, m;cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        deg[u]++; deg[v]++;
    }

    map<int, vector<int>> st;
    set<int> kkk;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        st[deg[i]].push_back(i);
        mx = max(mx, deg[i]);
        kkk.insert(deg[i]);
    }
    
    vector<int> k;
    for (auto &i : kkk) k.push_back(i);

    priority_queue<PII, vector<PII>, greater<PII>> pq; // w - u
    for (auto &u : st[mx]) pq.push({0, u});

    while (pq.size()) {

    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}