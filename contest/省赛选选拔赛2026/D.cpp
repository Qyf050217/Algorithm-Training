#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e18

int n;
const int maxN = 1e5 + 7;
int MOD;
vector<int> arr(20);
vector<int> vis(maxN, 0);
vector<int> dis(maxN, LNF);

void dijkstra() {
    dis[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> pq; // {w, p}
    pq.push({0, 0});
    while (pq.size()) {
        auto [w, p] = pq.top();pq.pop();
        if (vis[p]) continue;
        vis[p] = 1;
        for (int i = 1; i <= n; i++) {
            int np = (p + arr[i]) % MOD;
            int nw = w + arr[i];
            if (nw < dis[np]) {
                dis[np] = nw;
                pq.push({nw, np});
            }
        }
    }
}

int calc(int x) {
    int res = 0;
    for (int i = 0; i < MOD; i++) {
        res += (x - dis[i]) / MOD;
    }
    return res;
}

void solve() {
    int q;cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    MOD = *min_element(arr.begin()+1, arr.begin()+n);
    // cout << MOD << endl;
    dijkstra();
    // for (int i = 0; i < MOD; i++) cout << dis[i] << " \n"[i == MOD - 1];
    while (q--) {
        int l, r;cin >> l >> r;
        cout << calc(r) - calc(l - 1) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}