#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<int> p10(20);
int len(int x) {
    int res = 0;
    while (x) {
        x /= 10;
        res++;
    }
    return res;
}

int reserve(int x) {
    int res = 0;
    while (x && x % 10 == 0) {
        x /= 10;
    }
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

void solve(){
    int l, r;cin >> l >> r;
    int ans = 0;
    if (len(r) > len(l)) {
        int t = 0;
        for (int i = 1; i < len(r); i++) ans = ans * 10 + 9;
    }

    for (int LEN = len(r); LEN >= len(l); LEN--) {
        int res = l;
        if (LEN > len(l)) res = p10[LEN];
        for (int bit = 1; bit <= LEN; bit++) {
            int num = res / p10[bit] % 10;
            res -= num * p10[bit];
            for (int d = 9; d >= num; d--) {
                int ttt = res / p10[bit] % 10;
                res -= ttt * p10[bit];
                res += d * p10[bit];
                if (res >= l && res <= r) {
                    ans = max(ans, reserve(res));
                    break;
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    p10[0] = 1;
    p10[1] = 1;
    for (int i = 2; i <= 17; i++) p10[i] = (p10[i - 1] * 10);
    int T = 1;cin >> T;
    while (T--) solve();
}
