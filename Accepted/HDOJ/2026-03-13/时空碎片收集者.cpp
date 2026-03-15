#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, m;cin >> n >> k >> m;
    vector<int> arr(n + 1);
    vector<int> sum(n + 2);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
    sum[n + 1] = sum[n];
    vector<vector<int>> dp(n + 2, vector<int>(k + 1, -LNF));
    dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            if (dp[i][j] == -LNF) continue;
            int val = arr[i];
            if (j) val /= 2;

            // op1
            dp[i + 1][max(0LL, j - 1)] = max(dp[i + 1][max(0LL, j - 1)], dp[i][j] + val);

            // op2
            if (j == 0) dp[i + 1][k] = max(dp[i + 1][k], dp[i][0] + val * 2);

            // op3
            int ni = min(n + 1, m+1+i);
            dp[ni][max(0ll, j - m - 1)] = max(dp[ni][max(0ll, j - m - 1)], dp[i][j] + sum[min(n, i+m)] - sum[i-1]);
            // if (i == 2 && j == 3) cout << dp[ni][max(0ll, j - m - 1)] << "@@@@";
        }
        // cout << endl;
    }

    int res = 0;
    for (int i = 0; i <= k; i++) {
        res = max(res, dp[n + 1][i]);
    }
    // cout << dp[2][3] << endl;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
