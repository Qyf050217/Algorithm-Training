#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int x, y, z, a, b, c;cin >> x >> y >> z >> a >> b >> c;
    int res = LNF;
    for (int yy = 0; yy <= 6075; yy++) {
        int X = x, Y = y, Z = z;
        int re = max((yy - X), 0LL) + max((yy - Y), 0LL);
        int la = (max(X - yy, 0LL) + 1) / 2;
        int bl = (max(Y - yy, 0LL) + 1) / 2;
        if ((X-yy)%2 == 1) Z--;
        if ((Y-yy)%2 == 1) Z--;
        int t = la * a + yy * b + bl * c;
        t += min({a, b, c}) * ((max(Z - re, 0LL) + 1) / 2);
        res = min(res, t);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}