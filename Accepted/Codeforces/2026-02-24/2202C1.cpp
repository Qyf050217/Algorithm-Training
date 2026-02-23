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
    vector<int> dp(n + 1);
    int l = -LNF, r = -LNF;
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        int aid = num - 1;
        if (aid>=l && aid<=r) {
            dp[i] = dp[i - 1];
            r = num;
        } else {
            dp[i] = dp[i - 1] + 1;
            l = num;
            r = num;
        }
    }

    cout << dp[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
