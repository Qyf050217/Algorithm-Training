// 0.011

#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
const ld e = 0.011L;

void solve(){
    int n; cin >> n;

    cout << 2 * n << '\n';

    cout << fixed << setprecision(15);

    for (int z = 0; z <= 1; ++z) {
        int c = n;
        for (int x = 0; x < 10 && c; ++x) {
            for (int y = 0; y < 10 && c; ++y) {
                cout << x * e << ' ' << y * e << ' ' << z * 1.0L << '\n';
                --c;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
