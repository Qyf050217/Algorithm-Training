#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int mx = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mx < arr[i]) {
            mx = arr[i];
            cnt = 1;
        } else if (mx == arr[i]) cnt++;
    }
    // cout << mx << endl;
    if (cnt & 1) {
        for (int i = 1; i <= n; i++) {
            if (arr[i] == mx) cout << 1;
            else cout << 0;
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if (arr[i] != mx) cout << 1;
            else cout << 0;
        }
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
