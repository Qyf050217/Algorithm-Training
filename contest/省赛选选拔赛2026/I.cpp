#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

void solve() {
    int a, b, m;cin >> a >> b >> m;
    for (int i = 1; i <= 100; i++) {
        // cout << a << ' ' << b << endl;
        if (min(a, b) < m / 2 && max(a, b) >= m / 2) {
            cout << "Yes" << endl;
            return;
        } 
        a = a * (m / 2 - 1) % m;
        b = b * (m / 2 - 1) % m;
    }
    cout << "No" << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}