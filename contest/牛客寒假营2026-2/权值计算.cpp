#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int res = 0;
    map<int, int> pos;

    int fr = 0;
    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        ans[i] += ans[i - 1];
        if (!pos.count(num)) ans[i] += i;
        else ans[i] += (i - pos[num]);
        pos[num] = i;
    }
    for (int i = 1; i <= n; i++) res += ans[i] * (n - i + 1);
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
