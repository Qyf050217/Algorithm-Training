#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

int query(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
    cout.flush();
    int res;cin >> res;
    return res;
}

void solve() {
    int n;cin >> n;
    if (n == 1) {
        cout << "! 1" << endl;
        cout.flush();
        return;
    }
    vector<PII> ans;
    query(1, 2);
    int cur = query(1, 2);
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int t = query(i, j);
            if (t > cur) {
                ans.push_back({i, j});
                cur = t;
            } else query(i, j);
        }
    }
    vector<int> res(n + 1);
    for (int i = 1; i <= n; i++) res[i] = i;
    for (int k = ans.size() - 1; k >= 0; k--) {
        auto [i, j] = ans[k];
        swap(res[i], res[j]);
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " \n"[i == n];
    }
    cout.flush();
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) {
        solve();
        int t;cin >> t;
    }
}