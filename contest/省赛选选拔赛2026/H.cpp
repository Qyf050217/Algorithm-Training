#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

const double eps = 1e-4;

void solve() {
    int n;cin >> n;
    vector<double> a(n + 1);
    vector<double> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) {
        if (abs(a[i] - b[i]) / max(1.0, abs(b[i])) > eps) {
            cout << "WA" << endl;
            return;
        }
    }
    cout << "AC" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}