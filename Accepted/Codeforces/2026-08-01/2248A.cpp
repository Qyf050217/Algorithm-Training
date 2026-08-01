#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;cin >> s;
    int a = -1, b = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') {
            a = i;
            break;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            b = i;
            break;
        }
    }

    for (int i = 0; i < s.size(); i++) {
        if (i == a || i == b) continue;
        cout << s[i];
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
