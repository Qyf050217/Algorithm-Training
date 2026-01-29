#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> ans(n + 1);
    int idx = 1;
    for (int i = 1; i <= n; i += 2) {
        ans[i] = idx++;
    }
    idx = n;
    for (int i = 2; i <= n; i += 2) {
        ans[i] = idx--;
    }
    for (int i = n; i >= 1; i--) cout << ans[i] << " \n"[i == 1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
