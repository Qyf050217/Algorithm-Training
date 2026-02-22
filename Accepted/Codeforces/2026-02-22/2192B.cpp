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
    int cnt0 = 0, cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') cnt1++;
        else cnt0++;
    }
    if (cnt1 == 0) {
        cout << 0 << endl;
        return;
    }
    if (cnt0 & 1) {
        cout << cnt0 << endl;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '0') cout << i << ' ';
        }
        cout << endl;
    } else if (cnt1 %2 == 0) {
        cout << cnt1 << endl;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '1') cout << i << ' ';
        }
        cout << endl;
    } else cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
