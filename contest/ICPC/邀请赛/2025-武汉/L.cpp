/* 
4
7
3 5 9 8 2 11 5
7
7 9 2 4 17 10 15
1
100
2
100 100


*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

constexpr int N = 3123;
int a[N];

void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+1+n);
    a[0] = a[n+1] = -1;
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == a[i-1]) continue;
        for (int j = i; j <= n; ++j) {
            if (a[j] == a[j+1]) continue;
            if ((a[i] + a[j]) & 1) continue;

            int m = a[i] + a[j] >> 1;
            int l = lower_bound(a+i, a+j+1, m) - a; // = m
            if (l == j+1 || a[l] != m) continue;
            int r = upper_bound(a+i, a+j+1, m) - a; // > m
            
            int c1 = l - i;
            int c2 = r - l;
            int c3 = j + 1 - r;

            int t = c2 + 2 * min(c1, c3);
            
            if (c1 > c3) {
                t += min(c2-1, c1 - min(c1, c3));
            }
            else if (c1 < c3) {
                t += min(c2,   c3 - min(c1, c3));
            }

            res = max(res, t);
        }
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--) solve();
}
// ac