#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m,l;cin >> n >> m >> l;
    vector<int> t(l + 1);
    for (int i = 1; i <= n; i++) {
        int x;cin >> x;
        t[x] = 1;
    }
    vector<int> cur(min(m, n+1) + 1);
    for (int i = 1; i <= l; i++) {
        ranges::sort(cur.begin()+1, cur.end());
        cur[1]++;
        if (t[i]) {
            n--;
            ranges::sort(cur.begin()+1, cur.end());
            if (min(m, n + 1) < cur.size() - 1) cur.pop_back();
            else cur.back() = 0;
        }
    }
    ranges::sort(cur.begin()+1, cur.end());
    cout << cur.back() << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
