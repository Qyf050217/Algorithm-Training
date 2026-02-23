#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = '#' + s;
    int cntA = 0, cntB = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (s[i] == 'a') cntA++;
    //     else if (s[i] == 'b') cntB++;
    // }
    // if (cntA>(n+1)/2 || cntB>n/2) {
    //     cout << "NO" << endl;
    //     return;
    // }

    if (n & 1) {
        if (s[1] == 'b') {
            cout << "NO" << endl;
            return;
        }
        for (int i = 2; i <= n; i++) {
            if (i & 1) {
                if (s[i] != '?' && s[i] == s[i - 1]) {
                    cout << "NO" << endl;
                    return;
                }
            }
        }
    } else {
        for (int i = 1; i <= n; i++) {
            if ((i & 1) == 0) {
                if (s[i] != '?' && s[i] == s[i - 1]) {
                    cout << "NO" << endl;
                    return;
                }
            }
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
