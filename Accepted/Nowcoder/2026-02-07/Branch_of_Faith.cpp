#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int highBit(int x) {
    int res = 0;
    while (x) {
        x >>= 1;
        res++;
    }
    return res - 1;
}

void solve(){
    int n, q;cin >> n >> q;
    // cout << highBit(4) << endl;
    while (q--) {
        int x;cin >> x;
        int l = (1LL << highBit(x));
        int r = min(n, (1LL << (highBit(x) + 1)) - 1);
        cout << (r - l + 1) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
