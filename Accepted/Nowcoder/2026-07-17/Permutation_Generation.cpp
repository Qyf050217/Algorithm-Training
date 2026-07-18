#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;

void solve(){
    int n, k, x; cin >> n >> k >> x;
    vi p(n), idx(n);
    for (int i = 0; i < n; i++) cin >> p[i], idx[p[i]] = i;

    int cur = (idx[x]-k+n)%n;
    for (int step = 0; step < n; ++step) {
        int i = (cur + step) % n;
        cout << p[i] << " \n"[step == n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
