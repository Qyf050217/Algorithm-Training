#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,x;cin >> n >> x;
    vector<array<int, 3>> arr(n + 1);
    int cur = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int a, b, c;cin >> a >> b >> c;
        arr[i] = {a, b, c};
        cur += a * (b - 1);
        mx = max(mx, a * b - c);
    }

    if (cur >= x) {
        cout << 0 << endl;
        return;
    }
    if (mx <= 0) {
        cout << -1 << endl;
        return;
    }
    cout << (x - cur + mx - 1) / mx << endl;

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
