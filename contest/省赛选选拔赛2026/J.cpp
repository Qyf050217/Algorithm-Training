#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define inv(x) ksm(x, MOD - 2);


const int MOD = 998244353;
int ksm(int a, int n) {
    int ans = 1;
    a %= MOD;
    while (n) {
        if (n & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}


void solve() {
    int n;cin >> n;
    int res = (ksm(3, n) + 1) * inv(2);
    res %= MOD;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}