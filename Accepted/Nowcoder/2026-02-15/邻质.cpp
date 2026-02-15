#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<vector<int>> dp(2, vector<int>(n + 1, LNF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 1) {
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
            continue;
        }
        if (gcd(arr[i], arr[i - 1]) == 1) {
            dp[0][i] = dp[1][i - 1];
            dp[1][i] = min(dp[0][i - 1], dp[1][i - 1]) + 1;
        } else {
            dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
            dp[1][i] = dp[0][i] + 1;
        }
    }
    cout << min(dp[0][n], dp[1][n]) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
