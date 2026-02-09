#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int c1 = 0, c2 = 0;

int exGcd (int a, int b, int &x, int &y) {
    if (a==0 && b==0) return -1; // 无gcd
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = exGcd(b, a%b, y, x);
    y -= a / b * x;
    return d;
}

void solve(){
    int n, a, b;cin >> n >> a >> b;
    if (n % gcd(a, b)) {
        cout << "No" << endl;
        return;
    }
    int x, y;
    exGcd(a, b, x, y);
    // cout << x << ' ' << y << endl;
    x *= n / gcd(a, b);
    y *= n / gcd(a, b);

    int k1 = b / gcd(a, b);
    int k2 = a / gcd(a, b);
    PII res = {x, y};
    // cout << "++++" << x << ' ' << y << endl;
    if (x < y) {
        // while (x < y) {
        //     // cout << "+++" << x << ' ' << y << endl;
        //     x += k1;
        //     y -= k2;
        //     if (max(x, y) < max(res.first, res.second)) res = {x, y};
        // }
        int i = 0, j = 1e18 / max(x, y);
        int ans = 0;
        while (i + 1 < j) {
            int mid = i + j >> 1;
            if (x + mid * k1 < 0) i = mid;
            else if (y-mid*k2 < x+mid*k1) {
                j = mid;
            } else {
                i = mid;
                ans = i;
            }
        }
        x += ans * k1;
        y -= ans * k2;
        int nx = x + k1;
        int ny = y - k2;
        if (min(nx, ny) >= 0 && (max(nx, ny)) < max(x, y)) {
            x = nx;
            y = ny;
        }
    } else {
        // while (x > y) {
        //     // cout << "+++" << x << ' ' << y << endl;
        //     x -= k1;
        //     y += k2;
        //     if (max(x, y) < max(res.first, res.second)) res = {x, y};
        // }
        int i = 0, j = 1e18 / max(x, y);
        int ans = 0;
        while (i + 1 < j) {
            int mid = i + j >> 1;
            if (y + mid * k2) i = mid;
            else if (x-mid*k1 < y+mid*k2) {
                j = mid;
            } else {
                i = mid;
                ans = i;
            }
        }
        x -= ans * k1;
        y += ans * k2;
        // cout << "下";
        int nx = x - k1;
        int ny = y + k2;
        if (min(nx, ny) >= 0 && (max(nx, ny)) < max(x, y)) {
            x = nx;
            y = ny;
        }
    }
    if (min(x, y) < 0) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << x << ' ' << y << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}