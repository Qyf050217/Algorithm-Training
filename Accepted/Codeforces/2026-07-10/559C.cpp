#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;

const int MOD = 1e9 + 7;
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
    int n, m;cin >> n >> m;
    int k;cin >> k;
    vector<PII> arr(k + 1);
    for (int i = 1; i <= k; i++) {
        int a, b;cin >> a >> b;
        arr[i] = {a, b};
    }

    ranges::sort(arr.begin() + 1, arr.end());
    vector<int> cnt(k + 1, 0);
    for (int i = 1; i <= k; i++) {
        int x = arr[i].first;
        int y = arr[i].second;
        cnt[i] = C(x-1 + y-1, x-1);
        for (int j = 1; j < i; j++) {
            int cx = arr[j].first;
            int cy = arr[j].second;
            if (cx > x || cy > y) continue;
            int dx = x - cx;
            int dy = y - cy;
            cnt[i] = (cnt[i] - cnt[j] * C(dx + dy, dx) % MOD + MOD) % MOD;
        }
    }

    int res = 0;
    for (int i = 1; i <= k; i++) {
        int x = arr[i].first;
        int y = arr[i].second;
        int dx = n - x;
        int dy = m - y;
        res = (res + cnt[i] * C(dx + dy, dx) % MOD) % MOD;
    }

    cout << ((C(n-1 + m-1, n-1) - res) % MOD + MOD) % MOD << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;//cin >> T;
    while (T--) solve();
}
