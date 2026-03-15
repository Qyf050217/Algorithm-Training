#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int res = LNF;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i) continue;
        int a = i, b = n / i;
        if (a >= 3) res = min(res, a);
        if (b >= 3) res = min(res, b);
    }
    cout << max(n / res, 1LL) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
