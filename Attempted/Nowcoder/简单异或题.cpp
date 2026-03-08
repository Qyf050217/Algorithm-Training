#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> b(n + 1);
    for (int i = 1; i <= n; i++) cin >> b[i];
    int q;cin >> q;
    while (q--) {
        int k, l, r;cin >> k >> l >> r;
        r = r + k;
        r = min(r, n*m);
        int res = 0;
        for (int i = 0; i < min(k, r-l+1); i++) {
            int idx1 = l + i;
            int idx2 = r - i;
            if (k & 1) {
                idx1++;
                idx2++;
            }
            int A = b[idx1 % n] + idx1 / n;
            int B = b[idx2 % n] + idx2 / n;
            res ^= A ^ B;
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