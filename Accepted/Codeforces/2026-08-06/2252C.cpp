#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> wd(n + 1);
    for (int i = 1; i <= n; i++) cin >> wd[i];
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = m;
    priority_queue<int, vector<int>, greater<int>> pq; // 当前的选择
    vector<int> choose(m + 1);
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            pq.push(arr[i][j]);
        }
        int idx = m;
        while (pq.size() > m) pq.pop();
        while (pq.size()) {
            choose[idx--] = pq.top();
            pq.pop();
        }
        // for (int i = 1; i <= m; i++) cout << choose[i] << " \n"[i == m];
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += choose[j];
            if (sum >= wd[i]) {
                ans = min(ans, j);
                break;
            }
        }
        for (int j = 1; j <= m; j++) {
            pq.push(choose[j]);
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
