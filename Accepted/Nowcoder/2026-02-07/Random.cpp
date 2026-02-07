#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> res;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (arr[i] % 2 == 0) res.push_back(arr[i]);
    }
    if (res.size() >= 2) {
        cout << res[0] << ' ' << res[1] << endl;
        return;
    }

    n = min(n, 200LL);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (gcd(arr[i], arr[j]) > 1) {
                cout << arr[i] << ' ' << arr[j] << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
