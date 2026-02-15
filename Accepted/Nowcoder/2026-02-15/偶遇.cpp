#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    map<int, int> mp;
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        mp[x]++;
    }
    for (auto &[x, c] : mp) {
        if (c & 1) {
            cout << "NO";
            return;
        }
    }
    cout << "YES" << endl;
    for (auto &[x, c] : mp) {
        for (int i = 1; i <= c; i++) cout << x << ' ';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
