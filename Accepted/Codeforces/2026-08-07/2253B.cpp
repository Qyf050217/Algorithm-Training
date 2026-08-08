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
    vector<PII> res;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (j <= n && arr[j] == arr[i]) j++;
        int cnt = j - i;
        res.push_back({arr[i], cnt});
        i = j - 1;
    }

    int ans = res.size();
    int add = 0;
    for (int i = 0; i < res.size(); i++) {
        if (res[i].second == 1) continue;
        if (i + 1 < res.size() && res[i + 1].second >= 2) {
            add = max(add, 2LL);
        }
        if ((i + 2 < res.size() && res[i].first != res[i + 2].first) || (i + 1 == res.size() - 1)) add = max(add, 1LL);
        if ((i - 2 >= 0 && res[i].first != res[i - 2].first) || i - 1 == 0) add = max(add, 1LL);
    }

    cout << ans + add << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
