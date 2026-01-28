#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m;cin >> m;
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) cin >> b[i];

    ranges::sort(a.begin()+1, a.end());
    ranges::sort(b.begin()+1, b.end());
    int i = 1, j = 1;
    int res = 0;
    while (i <= n && j <= m) {
        if (abs(a[i] - b[j]) > 1) {
            if (a[i] < b[j]) i++;
            else j++;
        } else {
            res++;
            i++;
            j++;
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
