#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, a, b;

int calc1() {
    // 全是 td
    int res = n / 2 * b;
    return res;
}

int calc2() {
    // 全是kkt, 后补td
    int res = n / 7 * a;
    res += (n % 7 / 2) * b;
    return res;
}

int calc3() {
    // kkt 后插入 d
    int res = n / 8 * (a + b);
    res += (n % 8 / 2 * b);
    return res;
}

int calc4() {
    // kktd 删除几个d 凑kkt
    int res = n / 8 * (a + b);
    int rem = n % 8;
    if (rem >= 7) {
        res += a;
        rem -= 7;
    }
    res += (rem / 2 * b);
    return res;
}

int calc5() {
    // 删除一个kkt 凑td
    int cnt = n / 7;
    if (!cnt) return 0;
    cnt -= 1;
    int res = cnt * a;
    int rem = n % 7 + 7;
    res += rem / 2 * b;
    return res;
}

int calc111(int x) {
    // 三分calc
    int res = x * a;
    int rem = n - x * 7;
    if (rem <= x) {
        res += rem * b;
    } else {
        res += x * b;
        rem -= x;
        res += rem / 2 * b;
    }
    
    return res;
}

void solve(){
    cin >> n >> a >> b;
    int ans = max({calc1(), calc2(), calc3(), calc4(), calc5()});
    int l = 0, r = n / 7;
    while (r - l > 3) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (calc111(m1) < calc111(m2)) {
            l = m1;
        } else {
            r = m2;
        }
    }
    for (int i = l; i <= r; i++) ans = max(ans, calc111(i));
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
