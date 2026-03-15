#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    int res = 0;
    while (n || m) {
        if (n == 1 || m == 1) {
            int mx = max(n, m);
            if (mx & 1) res += (mx + 1) / 2;
            else res += mx / 2 + 1;
            break;
        }
        int mn = min(n, m);
        res += mn;
        m -= mn;
        n -= mn;
        if (!m) {
            m = mn;
        } else n = mn;
        cout << "#" << mn << endl;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}