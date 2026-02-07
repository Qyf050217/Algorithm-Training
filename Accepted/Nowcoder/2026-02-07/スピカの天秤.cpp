#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m;cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int j = 1; j <= m; j++) cin >> b[j];
    int A = 0, B = 0;
    for (int i = 1; i <= n; i++) A += a[i];
    for (int j = 1; j <= m; j++) B += b[j];

    if (A == B) {
        cout << 1 << endl;
        return;
    }
    sort(a.begin()+1, a.end());
    sort(b.begin()+1, b.end());
    int ans = LNF;
    if (A < B) {
        int res = 0;
        while (A < B) {
            B -= b.back();
            b.pop_back();
            res++;
        }
        ans = min(ans, res);
    } else {
        int res = 0;
        while (A > B) {
            A -= a.back();
            a.pop_back();
            res++;
        }
        ans = min(ans, res);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
