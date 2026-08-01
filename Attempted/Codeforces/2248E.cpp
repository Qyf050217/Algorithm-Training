#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<PII> pr(m);
    vector<int> p(m), pre(m);
    int S = 0;
    for (int i = 0; i < m; i++) {
        cin >> pr[i].first >> pr[i].second;
        p[i] = pr[i].first;
        S += pr[i].second;
    }

    pre[0] = pr[0].second;
    for (int i = 1; i < m; i++) {
        pre[i] = pre[i - 1] + pr[i].second;
    }

    bool ok = false;
    for (int i = 0; i < m; i++) {
        int r = pr[i].first;
        int sumr = pre[i];
        if (n * sumr > r * S) {
            ok = true;
            break;
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}