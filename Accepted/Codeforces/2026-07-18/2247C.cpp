#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b (n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    int zero = 0, one = 0;
    int w_zero = 0, w_one = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) {
            if (a[i] == 0) zero++;
            else one++;
        } else {
            if (a[i] == 0) w_zero++;
            else w_one++;
        }
    }

    if (one == 0 && zero == 0) {
        cout << 0 << endl;
        return;
    }

    if (one == 0) {
        if (w_zero && w_one) {
            cout << 2 << endl;
        } else cout << -1 << endl;
        return;
    }

    if (one & 1) {
        cout << 1 << endl;
    } else cout << 2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
