#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


void solve(){
    int n, m;cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    }
    

    vector<PII> mp(n + m + 7, {0, 0});
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int dist = i + j - 2;
            mp[dist].first += arr[i][j];
            mp[dist].second++;
        }
    }
    int f = 1;
    int aid = mp[1].first - mp[0].first; // 目标大小
    int d = aid - mp[0].first;
    if (mp[1].second == mp[0].second) {
        aid = mp[0].first;
        d = 0;
    }

    if (d < 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 0; i <= n + m - 2; i++) {
        int t = aid * mp[i].second - mp[i].first;
        if (t != d) {
            f = 0;
            break;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] > aid) {
                f = 0;
                break;
            }

            int s = 0;
            int cnt = 0;
            if (i < n) {
                s += arr[i + 1][j];
                cnt++;
            }
            if (j < m) {
                s += arr[i][j + 1];
                cnt++;
            }
            if (cnt && aid - arr[i][j] > aid * cnt - s) {
                f = 0;
                break;
            }

            s = 0;cnt = 0;
            if (i > 1) {
                s += arr[i - 1][j];
                cnt++;
            }
            if (j > 1) {
                s += arr[i][j - 1];
                cnt++;
            }
            if (cnt && aid - arr[i][j] > aid * cnt - s) {
                f = 0;
                break;
            }
        }
        if (f == 0) break;
    }



    // for (int i = 1; i <= n; i++) {
    //     int xia = 0;
    //     if (i < n) xia += arr[i + 1][1];
    //     int shang = 0;
    //     if (i > 1) shang += arr[i - 1][1];
    //     for (int j = 1; j <= m; j++) {
    //         int x = i - j + 1;
    //         int y = j;
    //         if (y < m) xia += arr[x][y + 1];
    //         if (x > 1) shang += 
    //     }
    // }
    if (f) cout << d << endl;
    else cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
}