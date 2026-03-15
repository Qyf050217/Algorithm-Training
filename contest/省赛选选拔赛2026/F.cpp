#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
int x, y;

bool calc(int num) {
    int a = 0, b = 0;
    while (num) {
        if (num % 10 == x) a++;
        if (num % 10 == y) b++;
        num /= 10;
    }
    return a > b;
}
void solve() {
    int l, r;cin >> l >> r;
    cin >> x >> y;
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (calc(i)) res++;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}