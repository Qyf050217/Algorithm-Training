#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, h, k;cin >> n >> h >> k;
    vector<int> arr(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    int res = (h - 1) / sum * (n + k);
    h = h % sum;
    if (h == 0) h = sum;
    int pos = 0;
    int cur = 0;
    vector<int> preMn(n + 1, LNF);
    vector<int> bacMx(n + 2, 0);
    for (int i = 1; i <= n; i++) {
        preMn[i] = min(preMn[i - 1], arr[i]);
    }
    bacMx[n] = arr[n];
    for (int i = n-1; i >= 1; i--) bacMx[i] = max(bacMx[i+1], arr[i]);

    for (int i = 1; i <= n; i++) {
        cur += arr[i];
        int mx = max(cur, cur - preMn[i] + bacMx[i + 1]);
        if (mx >= h) {
            res += i;
            cout << res << endl;
            return;
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
