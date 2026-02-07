#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int xa, ya, xb, yb;cin >> xa >> ya >> xb >> yb;
    if (ya == yb) {
        if (abs(xa - xb) * abs(ya) == 4) cout << 0 << endl;
        else cout << "no answer" << endl;
        return;
    }
    // 2 * s = (xa - res) * yb - (xb - res) * ya = 4
    double res = (4 - (xa*yb - xb*ya)) * 1.0 / (ya - yb);
    printf("%.20f", res);
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
