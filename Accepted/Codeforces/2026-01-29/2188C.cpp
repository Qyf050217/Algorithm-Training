#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    int mx = -LNF, mn = LNF;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        mx = max(mx, a[i]);
        mn = min(mn, a[i]);
    }
    ranges::sort(b.begin()+1, b.end());
    int f = 1;
    int res = LNF;
    for (int i = 1; i <= n; i++) {
        if (b[i] != a[i]) {
            f = 0;
            int t = max(a[i] - mn, mx - a[i]);
            res = min(res, t);
        }
    }

    cout << (res == LNF ? -1 : res) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
