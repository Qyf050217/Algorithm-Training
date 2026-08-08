#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> pos;
    map<int, int> neg;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        sum += x;
        if (x > 0) pos.push_back(x);
        else neg[x]++;
    }

    if (sum <= 0) {
        cout << -1 << endl;
        return;
    }

    ranges::sort(pos);
    // for (auto &i : neg) cout << i << ' ';
    // cout << endl;

    sum = 0;
    vector<int> ans;
    int idx = 0;
    for (auto &i : pos) {
        ans.push_back(i);
        sum += i;

        // 在 neg 里面二分找到第一个大于 -sum 的值
        while (1) {
            auto it = neg.upper_bound(-sum);
            int val = -LNF;
            if (it != neg.end()) {
                val = it->first;
                it->second--;
                if (it->second == 0) neg.erase(it);
            } else break;
            if (val != -LNF) {
                ans.push_back(val);
                sum += val;
            }
        }
    }

    for (int i = neg.size() - 1; i >= idx; i--) {
        ans.push_back(neg[i]);
    }

    for (int i = 1; i < n; i++) ans[i] += ans[i - 1];
    for (int i = 0; i < n; i++) {
        if (ans[i] <= 0) {
            cout << -1 << endl;
            return;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
