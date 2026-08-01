#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) cin >> b[i];
    if (n < m * 2) {
        cout << "NO" << endl;
        return;
    }
    ranges::sort(a.begin() + 1, a.end());
    ranges::sort(b.begin() + 1, b.end());

    vector<int> need;
    for (int i = 1; i <= m; i++) {
        if (a[i] > b[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = n, j = m; i >= 1 && j >= 1; i--, j--) {
        if (a[i] < b[j]) {
            cout << "NO" << endl;
            return;
        }
    }
    
    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
