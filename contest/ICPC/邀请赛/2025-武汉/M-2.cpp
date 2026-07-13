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
const ld PI = acosl(-1);

struct Point {
    ld x, y, z;
    Point (ld x = 0, ld y = 0, ld z = 0) : x(x), y(y), z(z) {}
} o;

Point operator+(const Point &a, const Point &b) {
    return Point(a.x + b.x, a.y + b.y, a.z + b.z);
}
Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y, a.z - b.z);
}
Point operator*(const Point &a, const ld x) {
    return Point(a.x * x, a.y * x, a.z * x);
}
Point operator/(const Point &a, const ld x) {
    return Point(a.x / x, a.y / x, a.z / x);
}

ld operator*(const Point &a, const Point &b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
ld len(const Point &a) {
    return sqrtl(a.x * a.x + a.y * a.y + a.z * a.z);
}
bool is0(ld x) {
    return -EPS < x && x < EPS;
}
bool isPara(Point &a, Point &b) {
    return is0(a.x * b.y - a.y * b.x) && is0(a.x * b.z - a.z * b.x);
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

    ld h = abs(P * m / len(m));

    ld angle = asinl(h / r);
    // if (angle < 0) angle += PI;

    ld res = angle * r;

    if (isPara(P, m)) {
        cout << fixed << setprecision(30) << res << '\n';
        return;
    }

    ld aab = acosl(A * B / len(A) / len(B));
    ld aap = acosl(A * P / len(A) / len(P));
    ld abp = acosl(B * P / len(B) / len(P));
    // if (aab < 0) aab += PI * 2;
    // if (aap < 0) aap += PI * 2;
    // if (abp < 0) abp += PI * 2;
                                                                                                                                           
    Point MH = m / len(m) * h;
    Point PH = P + MH;
    if (!is0(PH * m)) {
        PH = P - MH;
    }

    ld aaph = acosl(A * PH / len(A) / len(PH));
    // if (aaph < 0) aaph += PI * 2;
    ld abph = acosl(B * PH / len(B) / len(PH));
    // if (abph < 0) abph += PI * 2;

    if (is0(aab - aaph - abph)) {
        cout << fixed << setprecision(30) << res << '\n';
    }
    else {
        cout << fixed << setprecision(30) << min(aap, abp) * r << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}