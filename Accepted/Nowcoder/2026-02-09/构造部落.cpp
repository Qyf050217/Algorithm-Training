#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, q, s;cin >> n >> q >> s;
    vector<int> ans(n + 7);
    ans[1] = s;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        ans[i + 1] = ans[i] + x;
    }
    while (q--) {
        int x, y;cin >> x >> y;
        cout << ans[x] + y - 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
