#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __int128 lll;
constexpr int N = 1e5+5;

struct Point {
    ll x, y;
    Point(ll x = 0, ll y = 0) : x(x), y(y) {}
} P[N];

// AB x AC
lll cross(Point a, Point b, Point c) {
    return (lll)(b.x-a.x) * (lll)(c.y-a.y) - (lll)(b.y-a.y) * (lll)(c.x-a.x);
}

void solve(){
    ll n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> P[i].x >> P[i].y;
    for (int i = 2; i <= n-1; ++i) {
        lll t = cross(P[i-1], P[i], P[i+1]);
        if (t > 0) cout << "LEFT";
        else if (t == 0) cout << "STRAIGHT";
        else cout << "RIGHT";
        cout << (i == n-1 ? "\n" : " ");
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
