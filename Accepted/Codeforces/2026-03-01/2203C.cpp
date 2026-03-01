#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define lowbit(x) (x & -x)

void solve(){
    int s, m;cin >> s >> m;
    if (s % lowbit(m)) {
        cout << -1 << endl;
        return;
    }
    int l = 0, r = s;

    int ans = s;
    while (l + 1 < r) {
        int n = l + r >> 1LL;
        int t = s;
        for (int bit = 63; bit >= 0; bit--) {
            if (((m >> bit) & 1LL) == 0) continue;
            int cnt = t / (1LL << bit);
            t -= min(n, cnt) * (1LL << bit);
        }
        if (t == 0) {
            r = n;
            ans = n;
        } else {
            l = n;
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
