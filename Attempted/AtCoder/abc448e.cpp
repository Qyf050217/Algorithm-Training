#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int ksm(int a, int b, int MOD) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int calc(int x, int len, int MOD) {
    int res = x * (ksm(10, len - 1, MOD) - 1 + MOD) % MOD * ksm(9, MOD - 2, MOD) % MOD;
    //int res = x * (ksm(10, len, MOD) - 1 + MOD) % MOD * ksm(9, MOD - 2, MOD) % MOD;
    return res;
}

void solve(){
    int k, m;cin >> k >> m;
    const int MOD = 10007;
    vector<PII> arr(k);
    for (auto &i : arr) cin >> i.first >> i.second;
    vector<int> sum(k);
    sum[k - 1] = arr[k - 1].second;
    for (int i = k-2; i >= 0; i--) sum[i] = sum[i + 1] + arr[i].second;
    cout << calc(5, 5, m * MOD) << endl;
    int res = 0;
    for (int i = 0; i < k; i++) {
        res = (res * ksm(10, arr[i].second, m*MOD) + calc(arr[i].first, arr[i].second, m*MOD)) % (m * MOD);
    }
    cout << res / m << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}