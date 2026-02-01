#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    map<int, int> mp;
    int n,m,k;cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;cin >> x;
            if (x) mp[x]++;
        }
    }
    int res = 0;
    int C = 0;
    for (auto &[x, cnt] : mp) {
        if (cnt < 2) continue;
        C += cnt / 2;
        mp[x + 1] += cnt / 2;
        if (x + 1 >= k) res += (cnt / 2);
    }
    cout << C << ' ' << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
