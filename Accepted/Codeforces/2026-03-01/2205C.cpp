#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<vector<int>> arr(n);
    for (int ii = 0; ii < n; ii++) {
        int l;cin >> l;
        vector<int> A;
        set<int> ttt;
        vector<int> t(l);
        for (int i = 0; i < l; i++) cin >> t[i];
        for (int i = l - 1; i >= 0; i--) {
            if (ttt.count(t[i])) continue;
            ttt.insert(t[i]);
            A.push_back(t[i]);
        }
        arr[ii] = A;
    }
    vector<int> res;
    unordered_set<int> st;
    int e = n - 1;
    for (int ii = 0; ii < n; ii++) {
        ranges::sort(arr, greater<vector<int>>());
        for (auto &c : arr[e]) {
            res .push_back(c);
            st.insert(c);
        }
        arr.pop_back();
        e--;
        for (int i = 0; i <= e; i++) {
            vector<int> t;
            for (auto &c : arr[i]) {
                if (st.count(c)) continue;
                t.push_back(c);
            }
            arr[i] = t;
        }
    }

    // cout << res << endl;
    for (auto &i : res) cout << i << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
