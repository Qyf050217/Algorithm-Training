#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    map<int, PII> ops;
    for (int i = 1; i <= m; i++) {
        int p, l, r;cin >> p >> l >> r;
        if (ops.count(p)) {
            ops[p].first = max(ops[p].first, l);
            ops[p].second = min(ops[p].second, r);
        } else {
            ops[p] = {l, r};
        }
    }

    int res = 0;
    for (auto [p, II] : ops) {
        int l = II.first;
        int r = II.second;
        if (l > r) {
            cout << -1 << endl;
            return;
        }
        if (arr[p] < l) res += l - arr[p];
        else if (r < arr[p]) res += arr[p] - r;
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
// ac