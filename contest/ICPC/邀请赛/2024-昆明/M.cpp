#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef __int128 ll;

constexpr int N = 2e5+5;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
} o, C, p[N], s[N];
ll n, r, r2;

Point operator+(const Point &a, const Point &b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(const Point &a, const Point &b) { return Point(a.x - b.x, a.y - b.y); }
ll len2(Point a) { return a.x * a.x + a.y * a.y; }

ll cross(Point a, Point b, Point c) {
    return (b.x-a.x) * (c.y-a.y) - (b.y-a.y) * (c.x-a.x);
}

bool check(int i, int j) {
    ll s1 = cross(s[i], s[i+1], C);
    ll s2 = cross(s[i], s[j], C);
    if (s1 == 0 || s2 == 0) return 0;

    bool ok = 1;
    ll area2 = cross(s[i], s[j], C);
    area2 *= area2;

    ll l2 = len2(s[j] - s[i]);

    if (l2 * r2 > area2) return 0;
    
    area2 = cross(s[i], s[i+1], C);
    area2 *= area2;
    l2 = len2(s[i+1] - s[i]);

    if (l2 * r2 > area2) return 0;

    return (s1 > 0 && s2 > 0 || s1 < 0 && s2 < 0);
}

ll myin() {
    long long tin; cin >> tin;
    return tin;
}
const ll E18 = 1'000000'000000'000000;

void myout(ll x) {
    if (!x) return cout << "0", void();
    string s;
    while (x) s += char(x%10+'0'), x /= 10;
    reverse(s.begin(), s.end());
    cout << s;
}

void solve(){
    n = myin();
    C.x = myin();
    C.y = myin();
    r = myin();
    r2 = r * r;

    for (int i = 1; i <= n; ++i) {
        p[i].x = myin();
        p[i].y = myin();
        s[i] = p[i];
    }
    s[n+1] = p[n+1] = p[1];

    ll res = 0, cur = 0;
    for (int i = 1, j = 2; i <= n; ++i, cur -= cross(s[i-1], s[i], s[j])) {
        while (check(i, j % n + 1)) cur += cross(s[i], s[j], s[j % n + 1]), j = j % n + 1;
        res = max(res, cur);
    }

    myout(res);
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
}