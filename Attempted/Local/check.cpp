#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;cin >> s;
    int n = s.size();
    s = "#" + s;
    int h = 0, d = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'h') h++;
        else if (s[i] == 'd') d += h;
        else res += d;
    }
    cout << res << endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}