#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m;cin >> n >> m;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        string s;cin >> s;
        s = '#' + s;
        arr[i] = s;
    }
    vector<int> sum(m + 1);
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            sum[j] += arr[i][j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        string s = arr[i];
        vector<int> t(m + 1);
        int res = 0;
        for (int j = 1; j <= m; j++) {
            int cnt1 = sum[j];
            int cnt0 = n - sum[j];
            if (s[j] == '0') {
                res += cnt1;
                t[j] = cnt1 - (cnt0 - 1);
            } else {
                res += cnt0;
                t[j] = cnt0 - (cnt1 - 1);
            }
        }
        // for (int i = 1; i <= m; i++) cout << t[i] << " \n"[i == m];
        int change = 0;
        int mx = 0;
        for (int i = 1; i <= m; i++) {
            change += t[i];
            if (change < 0) change = 0;
            mx = max(mx, change);
        }
        res -= mx;
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
