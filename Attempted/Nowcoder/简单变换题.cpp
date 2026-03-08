#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s, t;cin >> s >> t;
    if (s == t) {
        cout << "YES" << endl;
        return;
    }
    int zero = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') zero++;
    }
    if (zero == n) {
        cout << "NO" << endl;
        return;
    }

    char fr = t[0];
    int f = 1;
    for (int i = 1; i < n; i++) {
        if (t[i] == fr) f = 0;
        fr = t[i];
    }

    if (f) cout << "NO" << endl;
    else cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}