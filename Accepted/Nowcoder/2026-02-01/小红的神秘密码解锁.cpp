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
    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    int res = 1;
    s = "#" + s;
    map<string, int> mp;
    map<string, vector<string>> op;
    op["01"].push_back("00");
    op["01"].push_back("11");

    op["00"].push_back("10");
    op["00"].push_back("01");

    op["10"].push_back("11");
    op["10"].push_back("00");

    op["11"].push_back("10");
    op["11"].push_back("01");


    int a = 0, b = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i + 1]) a++;
        else b++;
    }

    res += a * b;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
