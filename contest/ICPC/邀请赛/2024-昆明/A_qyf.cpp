#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m, k;cin >> n >> m >> k;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    vector<int> s(n + 1);
    vector<pair<PII, int>> c(n + 1);
    for (int i = 1; i <= n; i++) cin >> s[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> arr[i][j];
    }

    vector<int> mx(n + 1);
    for (int i = 1; i <= n; i++) {
        int t = 0;
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] != -1) t += arr[i][j];
            else t += k;
        }
        mx[i] = t;
    }
    for (int i = 1; i <= n; i++) {
        c[i] = {{s[i], mx[i]}, i};
    }
    ranges::sort(c.begin()+1, c.end());

    int frSum = 0;
    int frIdx = 0;
    for (int i = 1; i <= n; i++) {
        int cur = c[i].second; // 当前下标

        int cnt = 0; // -1 数量
        int sum = 0; // 非 -1 和
        for (int j = 1; j <= m; j++) {
            if (arr[cur][j] != -1) sum += arr[cur][j];
            else cnt++;
        }
        int dis = sum - frSum;
        if ()
        if (s[cur] > s[frIdx]) dis++;
        if (dis < 0) {
            for (int j = 1; j <= m; j++) {
                if (arr[cur][j] == -1) arr[cur][j] = 0;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}