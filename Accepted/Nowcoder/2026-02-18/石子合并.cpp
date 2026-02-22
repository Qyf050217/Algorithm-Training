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
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    vector<int> sum(2 * n + 1);
    for (int i = 1; i <= 2 * n; i++) sum[i] = sum[i - 1] + arr[i];
    vector<vector<int>> dp1(2 * n + 1, vector<int>(2 * n + 1, LNF));
    vector<vector<int>> dp2(2 * n + 1, vector<int>(2 * n + 1));
    for (int i = 1; i <= 2 * n; i++) dp1[i][i] = dp2[i][i] = 0;

    for (int len = 2; len <= n; len++) {
        for (int l = 1, r = l + len - 1; r <= 2 * n; l++, r++) {
            for (int j = l; j < r; j++) {
                dp1[l][r] = min(dp1[l][r], dp1[l][j] + dp1[j+1][r] + sum[r] - sum[l - 1]);
                dp2[l][r] = max(dp2[l][r], dp2[l][j] + dp2[j+1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    int mn = LNF, mx = 0;
    for (int i = 1; i+n-1 <= 2*n; i++) {
        mn = min(mn, dp1[i][i + n - 1]);
        mx = max(mx, dp2[i][i + n - 1]);
    }
    cout << mn << endl << mx << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
