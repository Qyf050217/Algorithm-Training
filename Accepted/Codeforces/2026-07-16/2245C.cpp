#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    k ^= n;
    set<int> need;
    for (int bit = 0; (1 << bit) <= k; bit++) {
        if ((k >> bit) & 1) need.insert((1 << bit));
    }

    for (auto &i : need) {
        if (i >= n) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;

    for (int i = 1; i < n; i++) {
        if (!need.count(i)) cout << i << ' ';
    }
    cout << 0 << ' ';
    for (auto &i : need) {
        if (i < n) cout << i << ' ';
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
