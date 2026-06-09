#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    string s;cin >> s;
    s = '#' + s;
    vector<int> ans;
    int mn = LNF;
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        vector<int> res(n + 1);
        int L = l, R = r;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '(' && L) {
                res[i] = 1;
                L--;
            }
        }
        for (int i = n; i >= 1; i--) {
            if (s[i] == ')' && R) {
                res[i] = 1;
                R--;
            }
        }
        int cnt = 0;
        int cur = 0;
        for (int i = 1; i <= n; i++) {
            if (res[i] == 1) continue;
            if (s[i] == '(') cur++;
            else {
                if (cur > 0) {
                    cur--;
                    cnt++;
                }
            }
        }
        if (cnt < mn) {
            ans = res;
            mn = cnt;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
