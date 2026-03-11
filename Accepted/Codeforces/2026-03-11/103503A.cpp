#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, s;cin >> n >> s;
    vector<int> arr(n + 1);
    vector<int> pre(n + 2);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr.begin()+1, arr.end());
    for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + arr[i];
    pre[n + 1] = pre[n];
    if (sum >= s) {
        cout << n << endl;
        return;
    }
    int l = 0, r = 3e9;
    int x = 0;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        int t = (1 + mid) * mid / 2;
        int pos = lower_bound(arr.begin()+1, arr.end(), mid) - arr.begin();
        t = t + sum - pre[pos - 1];
        if (t >= s) {
            x = mid;
            r = mid;
        } else l = mid;
    }
    int res = n - (lower_bound(arr.begin() + 1, arr.end(), x) - arr.begin()) + x + 1;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
