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
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }
    int l = -LNF, r = LNF;
    for (int i = 1; i <= n; i += 2) {
        l = max(l, arr[i + 1] + 1);
        r = min(r, arr[i] - 1);
    }
    if (l > r) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
