#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string s1, s2;cin >> s1 >> s2;
    for (int i = 0; i < n; i++) {
        if (s1[i] == '0') s1[i] = 'O';
        else if (s1[i] == '1' || s1[i] == 'l') s1[i] = 'I';

        if (s2[i] == '0') s2[i] = 'O';
        else if (s2[i] == '1' || s2[i] == 'l') s2[i] = 'I';

        if (s1[i] != s2[i]) {
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
