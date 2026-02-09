#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int calc(int x) {
    int res = x % 10;
    x /= 10;
    while (x) {
        res *= x % 10;
        x /= 10;
    }
    return res;
}

int cnt(int x) {
    int res = 0;
    while (x != calc(x)) {
        x = calc(x);
        res++;
    }
    return res;
}

void solve(){
    // 277777788888899          11      27777799999999998
    // 3778888999               10      937638166841712
    // 3788997988
    int x = 3788997988;
    vector<int> fac;
    // for (int i = 3778888999; i <= 4778888999; i++) {
    //     if (cnt(i) == 10) cout << i << endl;
    // }
    // for (int i = 2; i <= x; i++) {
    //     if (x % i == 0) {
    //         cout << i << endl;
    //         x /= i;
    //     }
    // }
    // cout << calc(27777799999999998) << endl;
    // cout << cnt(27777799999999998) << endl;
    cout << 27777799999999998 << ' ' << 277777788888899 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
