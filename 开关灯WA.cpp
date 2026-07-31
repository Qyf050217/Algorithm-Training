#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (qpw(x, MOD - 2))
const int MOD = 998244353;
int qpw(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

constexpr int N = 2e5+5;
int a[N], fac[N], ifac[N], invv[N];
int A(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[n-m] % MOD;
}
int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}


void solve(){
    int n; cin >> n;
    int tot = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], tot += a[i];
    if (n == 1) return cout << a[1] << '\n', void();
    int mid = tot - a[1] - a[n];
    tot %= MOD; mid %= MOD;

    int res = fac[n-1] * tot % MOD * 2LL % MOD;
    (res *= ifac[n]) %= MOD;
    int e = 1;
    for (int i = 2; i < n; ++i) {
        int ne = fac[n-2] * e  % MOD * ((a[1] + a[n]) % MOD) % MOD * (i-1) % MOD;
        ((ne %= MOD) += MOD) %= MOD;

        ne += fac[n-2] * (e+1) % MOD * ((a[1] + a[n]) % MOD) % MOD * (n-i) % MOD;
        ((ne %= MOD) += MOD) %= MOD;
        
        ne += fac[n-3] *  e    % MOD * mid % MOD * (i-1) % MOD * (n-i) % MOD * 2LL % MOD;
        ((ne %= MOD) += MOD) %= MOD;

        ne += fac[n-3] * (e-1) % MOD * mid % MOD * A(i-1, 2) % MOD;
        ((ne %= MOD) += MOD) %= MOD;

        ne += fac[n-3] * (e+1) % MOD * mid % MOD * A(n-i, 2) % MOD;
        ((ne %= MOD) += MOD) %= MOD;

        (ne *= ifac[n]) %= MOD;
        (res += ne) %= MOD;
        e = ne;
    }

    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    
    invv[1] = fac[0] = ifac[0] = 1;
    for (int i = 2; i < N; ++i) invv[i] = (MOD - MOD / i) * invv[MOD % i] % MOD;
    for (int i = 1; i < N; ++i) {
        fac[i] = fac[i-1] * i % MOD;
        ifac[i] = ifac[i-1] * invv[i] % MOD;
    }
    
    cin >> T;
    while (T--) solve();
}