#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, m;
bool isGood(int x, int y) {
    return x>=1 && x<=n && y>=1 && y<=m;
}

void solve(){
    int q;cin >> n >> m >> q;
    vector<vector<int>> arr(n + 7, vector<int>(m + 7));
    for (int i = 1; i <= n; i++) {
        for (int j= 1; j <= m; j++) cin >> arr[i][j];
    }

    vector<vector<int>> cnt(n + 1, vector<int>(m + 1));
    PII res = {1, 1};
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x = i, y = j;
            for (int xx = -2; xx <= 2; xx++) {
                for (int yy = -2; yy <= 2; yy++) {
                    if (abs(xx) + abs(yy) > 2) continue;
                    int nx = x + xx;
                    int ny = y + yy;
                    if (isGood(nx, ny)) cnt[x][y] += arr[nx][ny];
                }
            }
            if (cnt[x][y] > mx) {
                res = {i, j};
                mx = cnt[x][y];
            }
        }
    }

    while (q--) {
        int x, y, z;cin >> x >> y >> z;
        for (int xx = -2; xx <= 2; xx++) {
            for (int yy = -2; yy <= 2; yy++) {
                if (abs(xx) + abs(yy) > 2) continue;
                int nx = x + xx;
                int ny = y + yy;
                if (isGood(nx, ny)) {
                    cnt[nx][ny] += z;
                    if (cnt[nx][ny] > cnt[res.first][res.second]) res = {nx, ny};
                }
            }
        }

        cout << res.first << ' ' << res.second << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) cout << cnt[i][j] << " \n"[j == m];
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
