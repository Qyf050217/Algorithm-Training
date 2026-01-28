#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int stX, stY, edX, edY;cin >> stX >> stY >> edX >> edY;
    int k;cin >> k;
    int dx = abs(stX - edX);
    int dy = abs(stY - edY);
    int mx = max(dx, dy);
    int mn = min(dx, dy);
    if ((mx + k - 1) / k - 1 <= mn) {
        cout << dx + dy << endl;
    } else {
        int res = (mx + k - 1) / k - 1 - mn;
        if (res & 1) res += 1;
        res += dx + dy;
        cout << res << endl;
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
