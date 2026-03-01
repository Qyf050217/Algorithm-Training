#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int ans = 1;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i) continue;
        ans *= i;
        while (n && n % i == 0) n /= i;
    }
    if (n > 1) ans *= n;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
