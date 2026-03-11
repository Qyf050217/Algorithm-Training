#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>


bool check(int x) {
    int t = x;
    int sum = 0;
    while (t) {
        sum += t % 10;
        t /= 10;
    }
    return x % sum == 0;
}
void solve() {
    int l, r;cin >> l >> r;
    int res = 0;
    int mx = l;
    for (int i = l; i <= r; i++) {
        if (check(i)) {res++;mx = max(mx, i);}
    }
    if (res == 0) {
        cout << 0 << endl;
        cout << "None";
        return;
    }
    cout << res << endl << mx;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;//cin >> T;
    while (T--) solve();
}