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
    vector<int> k = {4, 8, 15, 16, 23, 42};
    vector<int> cnt(6);
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        int idx = lower_bound(k.begin(), k.end(), num) - k.begin();
        if (idx == 0) cnt[idx]++;
        else {
            if (cnt[idx - 1]) {
                cnt[idx - 1]--;
                cnt[idx]++;
            } else res++;
        }
    }
    for (int i = 0; i < 5; i++) res += cnt[i] * (i + 1);
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
