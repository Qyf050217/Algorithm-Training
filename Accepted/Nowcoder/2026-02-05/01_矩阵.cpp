#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int a = 0, b = 1;
    if (n & 1) swap(a, b);
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, LNF));
    for (int i = 1; i <= n; i++) {
        if (i & 1) continue;
        for (int j = 1; j <= i; j++) ans[i][j] = a;
    }
    for (int j = 1; j <= n; j++) {
        if (j & 1) continue;
        for (int i = 1; i <= j; i++) ans[i][j] = a;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (ans[i][j] == LNF) ans[i][j] = b;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
