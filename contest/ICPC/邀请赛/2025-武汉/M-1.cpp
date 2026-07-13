#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

typedef long double ld;
typedef long long ll;
ld EPS = 1e-10;

struct Point {
    ld x, y, z;
    Point (ld x = 0, ld y = 0, ld z = 0) : x(x), y(y), z(z) {}
} o;

ld operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
ld len(const Point &a) {
    return sqrtl(a.x * a.x + a.y * a.y + a.z * a.z);
}
bool is0(ld x) {
    return -EPS < x && x < EPS;
}


void solve(){
    ld r; cin >> r;
    ld a, b, c, u, v, w, x, y, z; cin >> a >> b >> c >> u >> v >> w >> x >> y >> z;

    ld r1 = len(Point(a, b, c));
    a = r * a / r1;
    b = r * b / r1;
    c = r * c / r1;
    Point P = Point(a, b, c);

    ld r2 = len(Point(u, v, w));
    u = r * u / r2;
    v = r * v / r2;
    w = r * w / r2;
    Point A = Point(u, v, w);

    ld r3 = len(Point(x, y, z));
    x = r * x / r3;
    y = r * y / r3;
    z = r * z / r3;
    Point B = Point(x, y, z);

    Point m = Point(v * z - y * w, x * w - u * z, u * y - v * x);

    if (is0(P * m)) {
        ld aab = acosl(A * B / len(A) / len(B));
        ld aap = acosl(A * P / len(A) / len(P));
        ld abp = acosl(B * P / len(B) / len(P));

        if (is0(aab - aap - abp)) {
            cout << fixed << setprecision(30) << 0.0L << '\n';
        }
        else {
            cout << fixed << setprecision(30) << min(aap, abp) * r << '\n';
        }

        return;
    }

    ld h = P * m / len(m);

    ld angle = asinl(h / r);

    ld res = angle * r;

    cout << fixed << setprecision(30) << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}