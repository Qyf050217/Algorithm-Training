#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 1e9 + 7;
const int maxN = 2e5 + 7;
vector<int> f(maxN + 7);
vector<int> finv(maxN + 7);

int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    f[0] = finv[0] = 1;
    for (int i = 1; i <= maxN; i++) {
        f[i] = i * f[i-1] % MOD;
    }
    finv[maxN] = ksm(f[maxN], MOD-2);
    for (int i = maxN-1; i >= 1; i--) {
        finv[i] = finv[i+1] * (i+1) % MOD;
    }
}

int C(int n, int m) {
    return f[n] * finv[m] % MOD * finv[n-m] % MOD;
}

int A(int n, int m) {
    return f[n] * finv[n - m] % MOD;
}
void solve(){
    int n;cin >> n;
    int p = ksm(2, n-1);
    for (int i = 1; i <= n; i++) {
        cout << p * C(n, i) % MOD << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;//cin >> T;
    while (T--) solve();
}
