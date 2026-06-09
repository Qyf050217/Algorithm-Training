#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

std::vector<int> minp, primes, phi;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}

bool isprime(int n) {
    return minp[n] == n;
}


void solve(){
    int n;cin >> n;
    map<int, int> mp;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<PII> dp(n + 1);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        int x = arr[i];

        int fr = x;
        for (int fac = 1; fac <= sqrt(x); fac++) {
            if (x % fac) continue;
            if (isprime(fac)) {
                int y = x / fac;
                if (mp[y] > cnt) {
                    cnt = mp[y];
                    fr = y;
                }
            }
            if (isprime(x / fac)) {
                int y = fac;
                if (mp[y] > cnt) {
                    cnt = mp[y];
                    fr = y;
                }
            }
        }
        cnt++;
        mp[arr[i]] = max(mp[arr[i]], cnt);
        res = max(res, cnt);

        dp[i] = {fr, cnt};
    }
    
    // for (int i = 1; i <= n; i++) {
    //     cout << '[' << dp[i].first << ',' << dp[i].second << "]" << ' ';
    // }

    cout << res << endl;
    int e;
    int i = n;
    for (; i >= 1; i--) {
        if (dp[i].second == res) {
            e = arr[i];
            break;
        }
    }

    vector<int> ans;
    ans.push_back(e);

    int aid = dp[i].first;
    for (; i >= 1; i--) {
        if (arr[i] == aid) {
            ans.push_back(arr[i]);
            aid = dp[i].first;
            if (arr[i] == dp[i].first) {
                break;
            }
        }
    }
    for (int i = res - 1; i >= 0; i--) cout << ans[i] << ' ';
    // for (auto &i : ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    sieve(1e6 + 7);
    int T = 1;//cin >> T;
    while (T--) solve();
}
