#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e5 + 7;
vector<double> aid(maxN);
int n, m;
bool check() {
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + aid[i];
    int ans = sum[m];
    int mn = 0;
    for (int i = m+1; i <= n; i++) {
        mn = min(mn, sum[i - m]);
        ans = max(ans, sum[i] - mn);
    }
    return ans >= 0;
}

void solve(){
    cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i] *= 1000;
    }
    int l = -10, r = 2000010;
    int ans = 0;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        for (int i = 1; i <= n; i++) {
            aid[i] = arr[i] - mid;
        }
        if (check()) {
            l = mid;
            ans = l;
        } else {
            r = mid;
        }
    }
    cout << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
