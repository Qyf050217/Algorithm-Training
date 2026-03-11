#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e18

const int maxN = 1e4 + 7;
vector<pair<pair<int, int>, int>>  arr(maxN); // {e - s}, w

int find (int l, int r, int pos) {
    int s = arr[pos].first.second;
    int res = 0;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (arr[mid].first.first <= s) {
            res = mid;
            l = mid;
        } else r = mid;
    }
    return res;
}

void solve() {
    int n, k;cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int s, e, w;cin >> s >> e >> w;
        arr[i] = {{e, s}, w};
    }

    sort(arr.begin() + 1, arr.begin()+n);
    // for (int i = 1; i <= n; i++) cout << arr[i].first.first << ' ' << arr[i].first.second << ' ' << arr[i].second << endl;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    // dp[i][j] = max(dp[i][j], dp[tttttt][j - 1] + arr[i].w)
    for (int i = 1; i <= n; i++) {
        int s = arr[i].first.second;
        int e = arr[i].first.first;
        int w = arr[i].second;
        dp[i][1] = w;
        int tt = find(0, i, i);
        // if (i == 2) cout << tt << endl;
        for (int j = 1; j <= k; j++) {
            dp[i][j] = max({dp[i][j], dp[tt][j - 1] + w, dp[i-1][j]});
        }
    }
    int res = 0;
    // cout << dp[2][2] << endl;
    for (int i = 1; i <= n; i++) {
        res = max(res, dp[n][k]);
    }
    cout << res << endl;
}  

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;//cin >> T;
    while (T--) solve();
}