#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 4e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


int dis(PII a, PII b) {
    if (a.first & a.second) return LNF;
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve(){
    int x, y;cin >> x >> y;
    if ((x & y) == 0) {
        cout << x << ' ' << y << endl;
        return;
    }
    PII xa, xb, ya, yb;
    int mxBit;
    for (int bit = 30; bit >= 0; bit--) {
        if (((x >> bit) & 1) && ((y >> bit) & 1)) {
            mxBit = bit;
            break;
        }
    }
    // 同x小于y
    xa.first = x ^ (1 << mxBit);
    xa.second = y;
    for (int bit = mxBit - 1; bit >= 0; bit--) {
        if (((x >> bit) & 1) == ((y >> bit) & 1)) {
            xa.first ^= (1 << bit);
        }
    }

    // 同x大于y
    xb.first = (1 << (mxBit+1));
    xb.second = y;


    ya.first = x;
    ya.second = y ^ (1 << mxBit);
    for (int bit = mxBit - 1; bit >= 0; bit--) {
        if (((x >> bit) & 1) == ((y >> bit) & 1)) {
            ya.second ^= (1 << bit);
        }
    }


    yb.first = (1 << (mxBit + 1));
    yb.second = ya.second;
    for (int bit = mxBit+1; bit <= 30; bit++) {
        if (!((x >> bit) & 1) && !((y >> bit) & 1)) {
            yb.second ^= (1 << bit);
            break;
        }
    }
    
    PII fr = {x, y};
    PII res = xa;
    if (dis(res, fr) > dis(xb, fr)) res = xb;
    if (dis(res, fr) > dis(ya, fr)) res = ya;
    if (dis(res, fr) > dis(yb, fr)) res = yb;
    // cout << res.first << ' ' << res.second << endl;
    for (int bit = mxBit + 1; bit <= 31; bit++) {
        if (!((x >> bit) & 1) && !((y >> bit) & 1)) {
            PII c1 = { ((x >> bit) | 1LL) << bit, y & ~((1LL << bit) - 1) };
            if (dis(c1, fr) < dis(res, fr)) res = c1;
            PII c2 = { x & ~((1LL << bit) - 1), ((y >> bit) | 1LL) << bit };
            if (dis(c2, fr) < dis(res, fr)) res = c2;
            break;
        }
    }
    // cout << xa.first << ' ' << xa.second << endl;
    // cout << xb.first << ' ' << xb.second << endl;
    // cout << (xb.first & xb.second) << endl;
    cout << res.first << ' ' << res.second << endl;
    // while (x) {
    //     cout << (x & 1) << ' ';
    //     x >>= 1;
    // }
    // cout << endl;
    // while (y) {
    //     cout << (y & 1) << ' ';
    //     y >>= 1;
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}