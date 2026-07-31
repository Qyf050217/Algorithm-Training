#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;

    int a = k / 2;
    int b = k - a;
    if (a + 1 + b + 1 > n) {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= a + 1; i++) cout << 1;
    for (int i = 1; i <= b + 1; i++) cout << 0;

    int x = 1;
    for (int i = a + b + 3; i <= n; i++) {
        cout << x;
        x ^= 1;
    }
    
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
