#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 998'244'353;
const ll i2 = MOD + 1 >> 1;

constexpr int N = 500005;
ll a[N], cnt[N], r[N], dp[N][2], top = 0;

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    fill(cnt, cnt+1+n, 0);
    fill(r, r+1+n, -1);
    
    int cnok = 0;
    top = 0;
    dp[0][0] = 1; dp[0][1] = 0;
    ll lastdameid = -1;
    vector<int> curval; curval.reserve(n);
    for (int i = 1; i <= n; ++i) {
        ++cnt[a[i]];
        curval.emplace_back(a[i]);
        if (cnt[a[i]] == 1) ++cnok;
        else if (cnt[a[i]] == 4) {
            --cnok;
            if (cnok == 0) {
                ll j = -1;
                for (int v : curval) j = max(r[v], j);
                if (top == 0) ;
                else if (j == top) {
                    dp[top][0] = 0;
                    dp[top][1] = (dp[top-1][0] + dp[top-1][1]) % MOD;
                }
                else if (j == -1) {
                    dp[top][0] = (dp[top-1][0] + dp[top-1][1]) % MOD;
                    dp[top][1] = (dp[top-1][0] + dp[top-1][1]) % MOD;
                }
                else if (j == top - 1) {
                    dp[top][0] = dp[top-1][1];
                    dp[top][1] = (dp[top-1][0] + dp[top-1][1]) % MOD;
                }
                else {
                    ll t = (dp[top-1][0] + dp[top-1][1]) % MOD;
                    dp[top][0] = t;
                    dp[top][1] = t;
                    if (lastdameid < j) (dp[top][0] *= i2) %= MOD;
                }
                
                ++top;
                for (int v : curval) { r[v] = top; cnt[v] = 0; }
                lastdameid = max(lastdameid, j);
                curval.clear();
            }
        }
        else if (cnt[a[i]] > 4) return cout << "0\n", void();
    }

    if (cnok) cout << "0\n";
    else cout << (dp[top-1][0] + dp[top-1][1]) % MOD << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
}