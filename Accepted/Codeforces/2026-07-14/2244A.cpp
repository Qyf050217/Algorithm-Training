#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int mx = 0;
    int cur = 0;
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '#') cur++;
        else cur = 0;
        mx = max(mx, cur);
    }
    cout << (mx + 1) / 2 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
