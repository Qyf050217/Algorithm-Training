#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<pair<PII, PII>> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b, c, d;cin >> a >> b >> c >> d;
        arr[i] = {{a, b}, {c, d}};
    }

    int ans = 0;
    for (int len = 1; len <= n; len++) {
        int idx = 1;
        for (int i = 1; i <= n; i++) {
            int A = idx, B = len - idx + 1;
            if ((A >= arr[i].first.first && A <= arr[i].first.second) || (B >= arr[i].second.first && B <= arr[i].second.second)) continue;
            idx++;
            if (idx > n) break;
        }
        if (idx > len) ans = len;
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
