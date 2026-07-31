#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int x, y, n, m;cin >> x >> y >> n >> m;
    vector<int> a(n + 1), b (m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    int res = x * y;
    int mxA = 0, mnA = 0;
    int mxB = 0, mnB = 0;
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            mxA = -LNF;
            mnA = LNF;
        }
        mxA = max(mxA, a[i]);
        mnA = min(mnA, a[i]);
    }
    for (int i = 1; i <= m; i++) {
        if (i == 1) {
            mxB = -LNF;
            mnB = LNF;
        }
        mxB = max(mxB, b[i]);
        mnB = min(mnB, b[i]);
    }
    // cout << mxB << ' ' << mnB << endl;
    res = max(res, x * y);
    res = max(res, (x + mxA) * y);
    res = max(res, (x + mnA) * y);

    res = max(res, x * (y + mnB));
    res = max(res, (x + mxA) * (y + mnB));
    res = max(res, (x + mnA) * (y + mnB));

    res = max(res, x * (y + mxB));
    res = max(res, (x + mxA) * (y + mxB));
    res = max(res, (x + mnA) * (y + mxB));
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
