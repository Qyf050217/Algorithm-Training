#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) cin >> arr[i];
    vector<int> dp(2 * n + 1, 0);
    vector<PII> pos(n + 1, {0, 0});
    for (int i = 1; i <= 2 * n; i++) {
        int x = arr[i];
        if (pos[x].first == 0) pos[x].first = i;
        else pos[x].second = i;
    }
    for (int i = 1; i <= 2 * n; i++) {
        int x = arr[i];
        if (i == pos[x].first) { // 第一次出现
            dp[i] = dp[i - 1] + 1;
        } else { // 第二次出现
            dp[i] = max(dp[i - 1] + 1, dp[pos[x].first - 1] + (pos[x].second - pos[x].first + 1) * (pos[x].second - pos[x].first + 1));
        }
    }

    cout << dp[2 * n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
