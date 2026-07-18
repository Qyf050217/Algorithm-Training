#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    string s;cin >> s;
    s = "#" + s;
    if (2 * k > n) {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    for (int i = 1; i <= k; i++) {
        if (s[i] == 'L') res++;
    }
    for (int i = n; i > n - k; i--) {
        if (s[i] == 'R') res++;
    }
    
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
