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
    s = "#" + s;
    vector<int> cnt(n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n && s[j] == s[i]) j++;
        int len = j - i;
        for (int k = i; k < j; k++) {
            cnt[k] = len;
        }
        i = j - 1;
        ans++;
    }

    int f = 0, kkk = 0;
    for (int i = 2; i < n; i++) {
        if (s[i - 1] == s[i + 1] && s[i] != s[i - 1]) {
            f = 1;
            break;
        }
        if (cnt[i] == 1) {
            kkk = 1;
        }
    }
    if (f == 1) ans -= 2;
    else if (kkk == 1) ans--;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
