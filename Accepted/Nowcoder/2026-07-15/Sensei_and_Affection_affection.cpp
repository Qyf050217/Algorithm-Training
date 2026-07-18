#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    
    int mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, arr[i]);


    if (m == 1) {
        vector<int> t(n + 1);
        for (int i = 1; i <= n; i++) {
            t[i] = mx - arr[i];
        }
        int res = 0;
        for (int i = 1; i <= n; i++) res += max(t[i] - t[i - 1], 0LL);
        cout << res << endl;
        return;
    }

    int ans = LNF;
    vector<vector<int>> dp(n + 1, vector<int>(2, LNF));
    for (int a = mx; a <= 200; a++) {
        for (int b = 0; b <= mx; b++) {
            for (int i = 1; i <= n; i++) {
                dp[i][0] = dp[i][1] = LNF;
            }
            if(arr[1] <= a) dp[1][0] = max( (a - arr[1]) - 0, 0LL);
            if(arr[1] <= b) dp[1][1] = max( (b - arr[1]) - 0, 0LL);
            for (int i = 2; i <= n; i++) {
                if (arr[i] <= a) {
                    int opt1 = dp[i - 1][0] + max((a - arr[i]) - (a - arr[i - 1]), 0LL);
                    int opt2 = dp[i - 1][1] + max((a - arr[i]) - (b - arr[i - 1]), 0LL);
                    dp[i][0] = min({dp[i][0], opt1, opt2});
                }

                if (arr[i] <= b) {
                    int opt1 = dp[i - 1][0] + max((b - arr[i]) - (a - arr[i - 1]), 0LL);
                    int opt2 = dp[i - 1][1] + max((b - arr[i]) - (b - arr[i - 1]), 0LL);
                    dp[i][1] = min({dp[i][1], opt1, opt2});
                }
            }
            ans = min(ans, min(dp[n][0], dp[n][1]));
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
