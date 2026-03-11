#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e12
void solve() {
    int n;cin >> n;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (!arr[i][j]) arr[i][j] = -LNF;
        }
    }
    
    int res = -LNF;
    // vector<vector<int>> SSS(n + 1, vector<int>(n + 1));
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         SSS[i][j] = -SSS[i-1][j-1] + SSS[i-1][j] + SSS[i][j-1] + arr[i][j];
    //         if (arr[i][j] == 0) SSS[i][j] -= LNF;
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << SSS[i][j] << " \n"[j == n];
    //     }
    // }
    vector<vector<int>> sum(n + 1, vector<int>(n + 1)); // 列前缀和
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) {
            sum[i][j] = sum[i-1][j] + arr[i][j];
        }
    }

    for (int u = 1; u <= n; u++) {
        for (int d = u; d <= n; d++) {
            int cur = 0;
            int l = 1;
            for (int r = 1; r <= n; r++) {
                cur += sum[d][r] - sum[u-1][r];
                cur = max(0LL, cur);
                res = max(res, cur);
            }
        }
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;// cin >> T;
    while (T--) solve();
}