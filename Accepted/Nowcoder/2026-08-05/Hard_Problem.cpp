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
    if (!isprime(n - 1)) {
        for (int i = 1; i <= n; i++) cout << i << " \n"[i == n];
    } else {
        if (n <= 6) cout << -1 << endl;
        else {
            for (int i = 1; i < n - 3; i++) cout << i << ' ';
            for (int i = n; i >= n - 3; i--) cout << i << ' ';
            cout << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    sieve(2e5 + 7);
    while (T--) solve();
}
