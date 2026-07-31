#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ranges::sort(arr.begin()+1, arr.end());
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];

    if (k & 1) {
        int res = 0;
        for (int i = k / 2 + 1; (i + k / 2) <= n; i++) {
            int r = i + k / 2;
            int l = i;
            // cout << l << ' ' << r << endl;
            res = max(res, sum[n] - sum[k / 2] - (sum[r] - sum[l - 1]) + k * arr[l]);
        }
        cout << res << endl;
    } else {
        int a, b;
        int res = 0;
        for (int i = k / 2; (i + k / 2) <= n; i++) {
            int l = i;
            int r = i + k / 2;
            // cout << l << ' ' << r << endl;
            res = max(res, sum[n] - sum[k / 2 - 1] - (sum[r] - sum[l - 1]) + k / 2 * (arr[l] + arr[l + 1]));
        }
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
