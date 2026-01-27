#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,k;cin >> n >> k;
    if (k >= 32) {
        cout << __builtin_popcount(n) + k - 1 << endl;
        return;
    }
    vector<vector<vector<int>>> dp(64, vector<vector<int>>(64, vector<int>(2, LNF)));
    dp[0][0][0] = 0;
    for (int i = 0; i <= 40; i++) {
        for (int j = 0; j <= i; j++) {
            for (int c = 0; c <= 1; c++) {
                if (dp[i][j][c] == INF) continue;
                int a = (n >> i) & 1;
                int b = c;
                dp[i+1][j][(a + b) / 2] = min(dp[i+1][j][(a + b) / 2], dp[i][j][c] + (a + b) % 2);
                dp[i+1][j+1][(a+b+1)/2] = min(dp[i+1][j+1][(a+b+1)/2], dp[i][j][c] + (a + b + 1) % 2);
            }
        }
    }
    int ans = LNF;
    for (int j = 0; j <= k; j++) {
        for (int c = 0; c <= 1; c++) {
            ans = min(ans, dp[40][j][c] + c);
        }
    }
    cout << __builtin_popcount(n) + k - ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
