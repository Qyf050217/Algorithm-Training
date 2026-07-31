#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

constexpr int N = 500005;
int a[N];

void solve(){
    int n, q; cin >> n >> q;
    int tot = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], tot += a[i];
    for (int i = 1; i < n; ++i) {
        int u; cin >> u >> u;
    }
    while (q--) {
        int r; cin >> r;
        cout << (a[r] ? 0 : tot + 1) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
