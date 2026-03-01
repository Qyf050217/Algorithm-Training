#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int cnt = 0, mx = 0;
    int n;cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        if (x > mx) {
            mx = x;
            cnt = 1;
        } else if (x == mx) cnt++;
    }
    cout << cnt << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
