#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
constexpr int N = 1e5+100;
ll a[N], dp[N][2];

void solve(){
    ll n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    a[0] = a[n+1] = 0;
    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = min(dp[i-1][0] + a[i-1], dp[i-1][1]);
        dp[i][1] = min(dp[i-1][1] + a[i+1], dp[i-1][0] + max(a[i-1], a[i+1]));
    }
    cout << dp[n][1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
}
