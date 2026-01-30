#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,a0,a1;cin >> n >> a0 >> a1;
    int cur0 = 0, cur1 = 0;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int t0 = abs((cur0 + 1) * a1 - cur1 * a0);
        int t1 = abs(cur0 * a1 - (cur1 + 1) * a0);
        if (t0 <= t1) {
            cur0++;
        } else {
            cur1++;
            ans[i] = 1;
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
