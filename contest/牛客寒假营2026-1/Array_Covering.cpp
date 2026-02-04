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
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    int res = mx * (n - 2) + arr[1] + arr[n];
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
