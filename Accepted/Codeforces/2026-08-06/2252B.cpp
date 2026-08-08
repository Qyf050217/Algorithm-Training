#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;

    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') cnt0++;
        else cnt1++;
    }

    vector<vector<int>> cnt(2, vector<int>(2, 0));

    int aid = -1, len = 0;
    for (int i = 1; i <= n; i++) { // 0 开头
        if (aid == -1) {
            if (s[i] == '0') {
                aid = 1;
                len = 1;
            }
        } else {
            if (s[i] - '0' == aid) {
                aid ^= 1;
                len++;
            }
        }
    }
    if (aid == -1) {
        cnt[0][1] = 0, cnt[0][0] = 0;
    } else {
        cnt[0][aid ^ 1] = len;
        cnt[0][aid] = len - 1;
    }

    aid = -1, len = 0;
    for (int i = 1; i <= n; i++) { // 1 开头
        if (aid == -1) {
            if (s[i] == '1') {
                aid = 0;
                len = 1;
            }
        } else {
            if (s[i] - '0' == aid) {
                aid ^= 1;
                len++;
            }
        }
    }
    if (aid == -1) {
        cnt[1][1] = 0, cnt[1][0] = 0;
    } else {
        cnt[1][aid ^ 1] = len;
        cnt[1][aid] = len - 1;
    }



    
    int t0, t1;

    int ans = LNF;
    // 0 0
    t0 = (cnt[0][0] + 1) / 2;
    t1 = cnt[0][0] - t0;
    if (abs((cnt0 - t0) - (cnt1 - t1)) <= 1) ans = min(ans, n - cnt[0][0]);
    // 0 1
    t0 = cnt[0][1] / 2;
    t1 = cnt[0][1] - t0;
    if (abs((cnt0 - t0) - (cnt1 - t1)) <= 1) ans = min(ans, n - cnt[0][1]);
    // 1 1
    t1 = (cnt[1][1] + 1) / 2;
    t0 = cnt[1][1] - t1;
    if (abs((cnt0 - t0) - (cnt1 - t1)) <= 1) ans = min(ans, n - cnt[1][1]);
    // 1 0
    t0 = cnt[1][0] / 2;
    t1 = cnt[1][0] - t0;
    if (abs((cnt0 - t0) - (cnt1 - t1)) <= 1) ans = min(ans, n - cnt[1][0]);

    if (ans == LNF) cout << -1 << endl;
    else cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
