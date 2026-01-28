#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,q;cin >> n >> q;
    map<char, set<string>> op;
    vector<set<string>> ans(n + 1);
    for (int i = 1; i <= q; i++) {
        string to;
        char from;
        cin >> to >> from;
        if (from > 'f' || to[0] > 'f' || to[1] > 'f') continue;
        op[from].insert(to);
    }

    if (!op.count('a')) {
        cout << "0" << endl;
        return;
    }

    ans[1].insert("a");
    for (int j = 2; j <= n; j++) {
        for (auto &s : ans[j - 1]) {
            
            if (!op.count(s[0])) continue;
            for (auto mid : op[s[0]]) {
                string ns = mid + s.substr(1, n - 1);
                ans[j].insert(ns);
                // cout << ns << endl;
            }
            
        }
    }

    cout << ans[n].size() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
