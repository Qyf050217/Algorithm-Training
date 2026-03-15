#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int MOD = 1e9 + 7;

vector<vector<int>> dp(20, vector<int>(10));

void pre() {
    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= 9; j++) dp[i][0] = (dp[i][0] + dp[i - 1][j]) % MOD;
        for (int j = 1; j <= 9; j++) dp[i][j] = (dp[i][j - 1] + 1) % MOD;
    }
}

void solve(){
    cout << dp[2][9];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    pre();
    int T = 1;//cin >> T;
    while (T--) solve();
}