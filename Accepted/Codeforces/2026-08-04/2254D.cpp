#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];

    priority_queue<PII, vector<PII>, greater<PII>> pq;

    vector<int> ans(n + 1);
    vector<int> fr; // 上一级
    vector<int> cur; // 当前级
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) fr.push_back(i);
        else {
            pq.push({b[i], i});
        }
    }

    int sum = 0;
    int frVal = 0;
    while (pq.size()) {
        auto [val, idx] = pq.top();pq.pop();
        cur.push_back(idx);
        while (pq.size() &&  val == pq.top().first) {
            cur.push_back(pq.top().second);
            pq.pop();
        }
        if (fr.size() == 0 || (val - sum) % fr.size() != 0 || val < sum) {
            cout << -1 << endl;
            return;
        }

        int k = (val - sum) / fr.size();
        if (k <= frVal) {
            cout << -1 << endl;
            return;
        }
        for (auto &i : fr) ans[i] = k;

        fr = cur;
        sum = val;
        frVal = k;
        cur.clear();
    }
    for (auto &i : fr) ans[i] = frVal + 1;
    for (int i = 1; i <= 0; i++) {
        if (ans[i] == 0) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
