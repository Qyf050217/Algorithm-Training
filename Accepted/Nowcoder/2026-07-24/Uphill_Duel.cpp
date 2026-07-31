#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

PII d[4] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};

void solve(){
    int n, m;cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<vector<int>> res(n + 1, vector<int>(m + 1));
    // vector<vector<char>> vis(n + 1, vector<char>(m + 1));

    priority_queue<pair<int, PII>> pq;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            pq.push({arr[i][j], {i, j}});
        }
    }

    
    while (pq.size()) {
        auto [val, pos] = pq.top(); pq.pop();
        int x = pos.first, y = pos.second;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i].first, ny = y + d[i].second;
            if (nx > 0 && nx <= n && ny > 0 && ny <= m && arr[nx][ny] < val) {
                if (res[x][y] == 0) res[nx][ny] = 1;
            }
        }
    }


    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= m; j++) {
    //         cout << res[i][j] << " \n"[j == m];
    //     }
    // }


    int q;cin >> q;
    while (q--) {
        int x, y;cin >> x >> y;
        if (res[x][y]) cout << "First" << endl;
        else cout << "Second" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
