#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) arr[i] %= 5;
    int res = 0;
    vector<int> val(n + 1);
    for (int i = 2; i <= n; i++) {
        val[i] = ((arr[i] - arr[i - 1]) % 5 + 5) % 5; 
        res += val[i];
    }
    for (int i = 1; i <= m; i++) {
        int l, r;cin >> l >> r;
        if (l > 1) {
            res -= val[l];
            val[l] = (val[l] + 1) % 5;
            res += val[l];
        }
        if (r < n) {
            res -= val[r + 1];
            val[r + 1] = ((val[r + 1] - 1) % 5 + 5) % 5;
            res += val[r + 1];
        }
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
