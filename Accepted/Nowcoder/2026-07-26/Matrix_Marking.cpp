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
    map<int, vector<PII>> pos;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
            pos[arr[i][j]].push_back({i, j});
        }
    }


    vector<vector<int>> res(n + 7, vector<int>(m + 7));
    auto add = [&](int x1, int y1, int x2, int y2) {
        res[x1][y1]++;
        res[x1][y2 + 1]--;
        res[x2 + 1][y1]--;
        res[x2 + 1][y2 + 1]++;
    };

    for (auto &[val, vec] : pos) {
        map<int, PII> mp; // x - {mn, mx}
        for (auto &[x, y] : vec) {
            if (mp.find(x) == mp.end()) {
                mp[x] = {y, y};
            } else {
                mp[x].first = min(mp[x].first, y);
                mp[x].second = max(mp[x].second, y);
            }
        }
        int len = mp.size();
        if (len == 1) continue;
        vector<pair<int, PII>> t;
        for (auto &i : mp) t.push_back({i.first, i.second});
        vector<int> fr(len), ba(len);

        fr[0] = t[0].second.first;
        for (int i = 1; i < len; i++) {
            fr[i] = min(fr[i - 1], t[i].second.first);
        }
        ba[len - 1] = t[len - 1].second.second;
        for (int i = len - 2; i >= 0; i--) {
            ba[i] = max(ba[i + 1], t[i].second.second);
        }

        for (int i = 1; i < len; i++) {
            int x1 = t[i - 1].first;
            int y1 = fr[i - 1];
            int x2 = t[i].first;
            int y2 = ba[i];

            if (y1 < y2) add(x1, y1, x2, y2);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            res[i][j] += res[i - 1][j] + res[i][j - 1] - res[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << (res[i][j] == 0 ? 0 : 1);
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
