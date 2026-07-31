#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<vector<int>> res(n + 7, vector<int>(n + 7));

    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;cin >> x1 >> y1 >> x2 >> y2;
        res[x1][y1]++;
        res[x1][y2 + 1]--;
        res[x2 + 1][y1]--;
        res[x2 + 1][y2 + 1]++;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res[i][j] += res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << res[i][j] << " \n"[j == n];
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
