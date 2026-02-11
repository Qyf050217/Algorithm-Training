#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 1e9 + 7;

void solve(){
    int n;cin >> n;
    map<int, int> mp; // w - cnt
    for (int i = 1; i <= n; i++) {
        int c, w;cin >> c >> w;
        mp[w] += c;
    }
    int ans = 0;
    while (mp.size()) {
        auto [w, cnt] = *mp.begin();
        int nw = w * 2;
        int nc = cnt / 2;
        ans = (ans + nw % MOD * nc) % MOD;
        if (nc) mp[nw] += nc;
        mp.erase(mp.begin());
        if (cnt & 1) {
            if (mp.empty()) break;
            auto &[ww, cc] = *mp.begin();
            int nww = w + ww;
            cc--;
            if (!cc) mp.erase(mp.begin());
            mp[nww] += 1;
            ans = (ans + nww) % MOD;
        }
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
