#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) ksm(x, MOD - 2);

const int maxN = 2e6 + 7;
const int MOD = 998244353;
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
    f[0] = 1;
    for (int i = 1; i <= maxN; i++) f[i] = f[i-1] * i % MOD;
    finv[maxN] = ksm(f[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 0; i--) finv[i] = finv[i+1] * (i+1) % MOD;
}

int C(int n, int m) {
    return f[n] * finv[m] % MOD * finv[n-m] % MOD;
}

int A(int n, int m) {
    return f[n] % MOD * finv[n-m] % MOD;
}

void solve(){
    int n, m, c, a, b;cin >> n >> m >> c >> a >> b;

    if (m < n || (m - n) % c) {
        cout << 0 << endl;
        return;
    }
    if(n==m)
    {
        cout<<ksm(b-a,m)*ksm(ksm(b,m),MOD-2)%MOD<<'\n';
        return;
    }
    int cnt = (m - n) / c;
    int ans=0;
    ans=(C(m,cnt)+MOD) * n* ksm(a,cnt) % MOD * ksm(b-a,m-cnt) % MOD * ksm(ksm(b,m),MOD-2) % MOD;
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}