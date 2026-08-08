#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
constexpr int N = 200005;
int a[N], vis[N];

struct node {
    int fa, l, r;
};

void solve() {
    // int n, res = 0; cin >> n;
    // for (int i = 1; i <= n; ++i) cin >> a[i];
    // fill(vis, vis+1+n, 0);

    // int avai = 0;
    // for (int j = 29; j >= 0; --j) {
    //     int c10 = 0;
    //     for (int i = 2; i <= n; ++i) {
    //         if (vis[i]) continue;
    //         if (a[i-1] >> j & 1 && !(a[i] >> j & 1)) ++c10;
    //     }
    //     if (c10 > avai) { res |= 1 << j; avai = avai << 1 | 1; }
    //     else {
    //         avai -= c10;
    //         for (int i = 2; i <= n; ++i) {
    //             if (vis[i]) continue;
    //             if (a[i-1] >> j & 1 ^ a[i] >> j & 1) vis[i] = 1;
    //         }
    //     }
    // }
    // cout << res << '\n';


}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
    return 0;
}