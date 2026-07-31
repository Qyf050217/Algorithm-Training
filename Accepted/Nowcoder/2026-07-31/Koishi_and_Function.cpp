#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

typedef long long ll;
std::vector<int> minp, primes, phi;
 
const int MOD = 998244353;

void solve(){
    int n, c;cin >> n >> c;
    int res = 0;
    int mi = c % MOD;

    vector<int> dp(n + 7, 0);
    dp[1] = 1;

    minp.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
            dp[i] = 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                dp[i * p] = dp[i] + 1;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
            dp[i * p] = dp[i] + 1;
        }
    }
    // for (auto &i : primes) cout << i << ' ';
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        int idx = dp[i];
        if (idx >= 2) res = (res + primes[idx - 2] * mi % MOD) % MOD;
        else res = (res + 1 * mi) % MOD;
        mi = mi * c % MOD;
    }
    cout << res % MOD << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
