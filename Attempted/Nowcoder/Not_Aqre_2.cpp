#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

map<int, vector<int>> adj;
vector<vector<int>> dp(1000, vector<int>(1000));
vector<int> valid;

int dijkstra(int aid) {
    for (auto &i : valid) dp[i][1] = 1;

    priority_queue<PII, vector<PII>, greater<PII>> pq; // {cnt, u}
    for (auto &i : valid) {
        pq.push({1, i});
    }

    set<int> st;
    int res = 0;
    while (pq.size()) {
        auto [cnt, u] = pq.top(); pq.pop();
        if (cnt == aid) {
            if (st.count(u)) continue;
            st.insert(u);
            // cout << u << ' ' << dp[u][cnt] << endl;
            res += dp[u][cnt];
            continue;
        }
        for (auto &son : adj[u]) {
            dp[son][cnt + 1] += dp[u][cnt];
            pq.push({cnt + 1, son});
        }
    }

    return res;
}



void solve(){
    int n, m;cin >> n >> m;

    for (int i = 0; i < pow(3, n); i++) {
        int f = 1;
        int x = i;
        for (int bit = 1; bit < n; bit++) {
            int cur = (int)(x / pow(3, bit)) % 3;
            int fr = (int)(x / pow(3, bit - 1)) % 3;
            if (cur == fr) {
                f = 0;
                break;
            }
        }
        if (f) valid.push_back(i);
    }
    // for (auto &i : valid) cout << i << ' ';
    // cout << endl;
    // cout << valid.size() << endl;

    for (int i = 0; i < valid.size(); i++) {
        for (int j = i + 1; j < valid.size(); j++) {
            int f = 1;
            for (int bit = 0; bit < n; bit++) {
                int a = (int)(valid[i] / pow(3, bit)) % 3;
                int b = (int)(valid[j] / pow(3, bit)) % 3;
                if (a == b) {
                    f = 0;
                    break;
                }
            }
            if (f) {
                adj[valid[i]].push_back(valid[j]);
                adj[valid[j]].push_back(valid[i]);
            }
        }
    }

    // for (auto &i : adj) {
    //     cout << i.first << ":" << endl;
    //     for (auto &j : i.second) cout << j << ' ';
    //     cout << endl;
    // }
    cout << dijkstra(m) << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
