#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

void solve() {
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    ranges::sort(arr.begin()+1, arr.end(), greater<int>());
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res += arr[i] * ((i + m - 1) / m);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}