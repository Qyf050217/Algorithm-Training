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
    vector<char> a;
    for (int i = 1; i <= n; i++) {
        if (s[i] == (char)('0' + (i & 1))) {
            a.push_back(s[i]);
        }
    }

    int c0 = 0, c1 = 0;
    for (int i = 0; i < a.size(); i++) {
        char c = a[i];
        if (c == '0') {
            if (c1 > 0) {
                c1--;
                c0++;
            } else {
                c0++;
            }
        } else {
            if (c0 > 0) {
                c0--;
                c1++;
            } else {
                c1++;
            }
        }
    }
    cnt0 = c0 + c1;

    a.clear();
    for (int i = 1; i <= n; i++) {
        if (s[i] == (char)('0' + (i & 1 ^ 1))) {
            a.push_back(s[i]);
        }
    }

    c0 = 0, c1 = 0;
    for (int i = 0; i < a.size(); i++) {
        char c = a[i];
        if (c == '0') {
            if (c1 > 0) {
                c1--;
                c0++;
            } else {
                c0++;
            }
        } else {
            if (c0 > 0) {
                c0--;
                c1++;
            } else {
                c1++;
            }
        }
    }
    cnt1 = c0 + c1;
    cout << min(cnt0, cnt1) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
