#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    if (k < n || k >= 2*n) {
        cout << "NO" << endl;
        return;
    }
    if (n == k) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) {
            cout << i << ' ' << i << " \n"[i == n];
        }
        return;
    }
    int cnt = k - n;
    cout << "YES" << endl;
    cout << "1 2 ";
    for (int i = 3; i <= cnt+1; i++) {
        cout << i << ' ' << i - 1 << ' ';
    }
    cout << cnt + 1 << ' ' << 1 << ' ';
    for (int i = cnt+2; i <= n; i++) {
        cout << i << ' ' << i << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
