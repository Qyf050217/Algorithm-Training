#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    if (n == 2) {
        cout << "2 1 1 2 1 2 2 1" << endl;
        return;
    }
    cout << n << " 1 1 ";
    for (int i = 2; i <= n; i++) {
        cout << i << ' ' << i << ' ' << i - 1 << ' ' << i << ' ';
    }
    cout << 1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
