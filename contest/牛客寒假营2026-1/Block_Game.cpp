#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve() {
    int n, k;cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int ans = -LNF;
    ans = max(ans, a[1] + k);
    ans = max(ans, a[n] + k);
    for (int i = 1; i <= n - 1; i++) {
        ans = max(ans, a[i] + a[i + 1]);
    }
    cout << ans << endl;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
