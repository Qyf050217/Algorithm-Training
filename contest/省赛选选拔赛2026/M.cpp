#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

void solve() {
    int a, b, c;cin >> a >> b >> c;
    int res = 0;
    for (int x = 0; x <= min(min({a, b, c}), 3LL); x++) {
        int t = x + (a - x) / 3 + (b - x) / 3 + (c - x) / 3;
        res = max(res, t);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}