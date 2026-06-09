#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, x, y, z;cin >> n >> x >> y >> z;
    int res = (n + x + y - 1) / (x + y);
    int c = max((n - z * x + x + 10 * y - 1) / (x + 10 * y), 0LL) + z;
    res = min(res, c);
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
