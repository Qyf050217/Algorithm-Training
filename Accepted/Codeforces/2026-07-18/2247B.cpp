#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, m;cin >> n >> k >> m;
    if (m < k) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << m - k + 1 << ' ';
    for (int i = 2; i <= n; i++) cout << 1 << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
