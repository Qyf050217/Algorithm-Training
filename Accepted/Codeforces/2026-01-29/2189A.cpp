#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, h, l;cin >> n >> h >> l;
    int a = 0, b = 0;
    int mx = max(h, l);
    int mn = min(h, l);
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        if (x <= mn) a++;
        if (x <= mx) b++;
    }
    cout << min(a, b/2) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
