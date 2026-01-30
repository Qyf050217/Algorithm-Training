#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        b[i] = arr[i];
    }
    sort(b.begin() + 1, b.end());
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + b[i];
    int all = sum[n];

    for (int i = 1; i <= n; i++) {
        int val = arr[i];
        int aid = m - val;
        int idx = upper_bound(b.begin() + 1, b.end(), aid) - b.begin() - 1;
        int res = idx * val - (all - sum[idx]);
        if (val + val <= m) res -= val;
        else res += val;
        cout << res << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
