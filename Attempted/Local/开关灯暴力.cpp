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
int p[N], a[N], vis[N], fac[N], ifac[N], invv[N];
int A(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[n-m] % MOD;
}
int C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] % MOD * ifac[n-m] % MOD;
}

int ce[N], ce0[N], ce1[N], ce_1[N], ce01n[N];
int resi[N];

void solve(){
    int n; cin >> n;
    iota(p+1, p+1+n, 1LL);
    fill(ce, ce+1+n, 0);
    fill(ce0, ce0+1+n, 0);
    fill(ce01n, ce01n+1+n, 0);
    fill(ce1, ce1+1+n, 0);
    fill(ce_1, ce_1+1+n, 0);
    fill(resi, resi+1+n, 0);
    int res = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int c = 0;
    auto calc = [&]() -> int {
        c = 0;
        fill(vis, vis+2+n, 0);
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int u = p[i];
            vis[u] = 1;
            if (vis[u-1] && vis[u+1]) --c, ce_1[i] += c;
            else if (!vis[u-1] && !vis[u+1]) ++c, ce1[i] += c;
            else {
                ce0[i] += c;
                if (u == 1 || u == n) ce01n[i] += c;
            }
            ans += c * a[u];
            resi[i] += c * a[u];
            ce[i] += c;
        }
        return ans;
    };

    do { res += calc(); } while (next_permutation(p+1, p+1+n)) ;
cout << res << '\n';
    cout << res * ifac[n] % MOD << '\n';
for (int i = 1; i <= n; ++i) cout << ce[i] << " \n"[i==n];
for (int i = 1; i <= n; ++i) cout << resi[i] << " \n"[i==n];
cout << ce0[2] << ' ' << ce1[2] << ' ' << ce_1[2] << '\n';
cout << ce0[3] << ' ' << ce1[3] << ' ' << ce_1[3] << '\n';
// cout << ce01n[2] << '\n';
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