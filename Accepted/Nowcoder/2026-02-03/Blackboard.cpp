#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int MOD = 998244353;

void solve() {
    int n;cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = 0;
    vector<int> dp(n + 1);
    dp[0] = 1;

    vector<int> pos(40, 0);
    int l = 1;
    vector<int> sum(n + 1);
    sum[0] = dp[0];

    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit <= 30; bit++) {
            if ((a[i] >> bit) & 1) {
                l = max(l, pos[bit] + 1);
                pos[bit] = i;
            }
        }

        int res = sum[i - 1];
        if (l >= 2) res = (res - sum[l - 2] + MOD) % MOD;
        dp[i] = res;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }

    cout << dp[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
