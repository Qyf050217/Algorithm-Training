#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1000006;
int a[N], b[2][N];

inline int mex(int a, int b, int c) {
    for (int i = 0; i <= 3; ++i) {
        if (a != i && b != i && c != i) return i;
    }
    return -1;
}

void solve(){
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        b[1][i] = mex(a[i], a[(i+1)%n], a[(i+n-1)%n]);
    }
    for (int i = 0; i < n; ++i) {
        b[0][i] = mex(b[1][i], b[1][(i+1)%n], b[1][(i+n-1)%n]);
    }

    if (k & 1) {
        for (int i = 0; i < n; ++i) cout << b[1][i] << " \n"[i==n-1];
    } else {
        for (int i = 0; i < n; ++i) cout << b[0][i] << " \n"[i==n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T_ = 1;
    // cin >> T_;
    while (T_--) solve();
}