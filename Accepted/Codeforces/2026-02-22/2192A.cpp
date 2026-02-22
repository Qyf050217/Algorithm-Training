#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int res = 0;
    int n;cin >> n;
    string s;cin >> s;
    s = '#' + s;
    int f = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n && s[j] == s[i]) j++;
        res++;
        if (j - i >= 2) f = 1;
        i = j - 1;
    }
    if (s[1] == s[n]) {
        cout << res << endl;
        return;
    }
    // cout << res << ' ';
    if (f) res++;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
