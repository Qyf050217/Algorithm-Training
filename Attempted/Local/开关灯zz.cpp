#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inv(x) (qpw(x, MOD - 2))
const int MOD = 998'244'353;
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
    int e = 1;
    for (int i = 2; i < n; ++i) {
        int ne = 0, t = 0;

int ce0 = 0, ce1 = 0, ce_1 = 0;

        // ...2.   1
        // ...n-1. n
        t = fac[n-2] * e    % MOD * (i-1) % MOD;
        ((t %= MOD) += MOD) %= MOD;
        (ne += t * 2LL % MOD) %= MOD;
        res += t * ((a[1] + a[n]) % MOD) % MOD;
        res %= MOD;

ce0 += t * 2;

        // 1 .2...
        // n .n-1...
        t = fac[n-2] * (e+1) % MOD * (n-i) % MOD;
        ((t %= MOD) += MOD) %= MOD;
        (ne += t * 2LL % MOD) %= MOD;
        res += t * ((a[1] + a[n]) % MOD) % MOD;
        res %= MOD;
        
ce1 += t * 2;

        // x-1  x  x+1
        // x+1  x  x-1
        t = fac[n-3] *  e    % MOD * (i-1) % MOD * (n-i) % MOD * 2LL % MOD;
        ((t %= MOD) += MOD) %= MOD;
        (ne += t * (n-2) % MOD) %= MOD;
        res += t * mid % MOD;
        res %= MOD;

ce0 += t * (n-2);

        // x-1 x+1 x
        // x+1 x-1 x
        t = fac[n-3] * (e-1) % MOD * A(i-1, 2) % MOD;
        ((t %= MOD) += MOD) %= MOD;
        (ne += t * (n-2) % MOD) %= MOD;
        res += t * mid % MOD;
        res %= MOD;

ce_1 += t * (n-2);

        // x x-1 x+1
        // x x+1 x-1
        t = fac[n-3] * (e+1) % MOD * A(n-i, 2) % MOD;
        ((t %= MOD) += MOD) %= MOD;
        (ne += t * (n-2) % MOD) %= MOD;
        res += t * mid % MOD;
        res %= MOD;

ce1 += t * (n-2);

cout << ce0 << '?' << ce1 << ' ' << ce_1 << '\n';

        (ne *= ifac[n]) %= MOD;

        if (i == 3) cout << ne * fac[n] % MOD << "??? \n";

        e = ne;
    }

    (res *= ifac[n]) %= MOD;
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1;
    
    invv[1] = fac[0] = ifac[0] = 1;
    for (int i = 2; i < N; ++i) invv[i] = (MOD - MOD / i) * invv[MOD % i] % MOD;
    for (int i = 1; i < N; ++i) {
         fac[i] =  fac[i-1] *      i  % MOD;
        ifac[i] = ifac[i-1] * invv[i] % MOD;
    }
    
    cin >> T_;
    while (T_--) solve();
}