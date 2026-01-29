#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    s = '#' + s;
    vector<vector<int>> dp(n + 1, vector<int>(3, LNF));
    if (s[1] == '1') {
        dp[1][0] = 1;
    } else {
        dp[1][0] = 1;
        dp[1][2] = 0;
    }

    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + 1;
        if (s[i] == '1') continue;
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1];
    }

    int ans = min(dp[n][0], dp[n][1]);
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T;cin >> T;
    while (T--) solve();
}
