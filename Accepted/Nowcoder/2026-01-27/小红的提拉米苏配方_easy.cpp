#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;cin >> s;
    int cntOne = 0;
    for (auto &c : s) {
        if (c == '1') cntOne++;
    }

    int c = cntOne / 2;
    for (int i = s.size()-1; i >= 0; i--) {
        if (c && s[i] == '1') {
            s[i] = '2';
            c--;
        }
    }
    
    int idx = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') idx = i;
        if (s[i] == '1' && s[i+1] == '2') {idx = i; break;}
    }

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if ((cntOne & 1) && i == idx) cout << '1';
        } else cout << s[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
