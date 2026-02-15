#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MOD = 998244353;
int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = '#' + s;
    vector<int> dp(n + 1);
    int cnt = 0;
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '(') cur++;
        else cur--;
        if (!cur) cnt++;
    }
    cout << ksm(2, cnt) << endl;
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}