#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int highBit(int x) {
    for (int bit = 32; bit >= 0; bit--) {
        if ((x >> bit) & 1) return bit;
    }
    return -1;
}
void solve(){
    int l, r;cin >> l >> r;
    int lBit = highBit(l);
    int rBit = highBit(r);
    if (rBit > lBit) {
        cout << r + 1 << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}