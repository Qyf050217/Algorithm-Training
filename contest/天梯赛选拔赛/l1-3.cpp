#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
void solve() {
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int cnt = 0, mx = 0;
    arr[0] = 1e18;
    for (int i = 1; i <= n; i++) {
        if (arr[i] > arr[i - 1]) {
            cnt++;
            mx = max(mx, arr[i]);
        }
    }

    cout << cnt << ' ' << mx << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;//cin >> T;
    while (T--) solve();
}