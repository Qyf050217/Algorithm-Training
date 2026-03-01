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
    if (n & 1) {
        cout << "NO" << endl;
        return;
    }

    vector<char> st;
    for (int i = 1; i <= n; i++) {
        if (st.empty() || st.back() != s[i]) st.push_back(s[i]);
        else st.pop_back();
    }
    if (st.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
