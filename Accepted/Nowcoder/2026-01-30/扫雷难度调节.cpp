#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m,k;cin >> n >> m >> k;
    vector<vector<int>> ans(n+1, vector<int>(m + 1, 1));
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (cur == k) continue;
        if (i % 3 == 2 || (i == n && n % 3 == 1)) {
            for (int j = 1; j <= m; j++) {
                if (cur == k) continue;
                if (j % 3 == 2) continue;
                cur++;
                ans[i][j] = 0;
                if (j % 3 == 1 && j == m) {
                    cur--;
                    ans[i][j] = 1;
                }
            }
            continue;
        }
        for (int j = 1; j <= m; j++) {
            if (cur == k) continue;
            cur++;
            ans[i][j] = 0;
        }
    }
    if (cur < k) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cout << ans[i][j];
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
