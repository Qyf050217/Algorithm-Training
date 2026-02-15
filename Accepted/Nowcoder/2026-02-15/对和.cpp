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
    int odd = 0, even = 0;
    int res = 0;
    for (int i = n; i >= 1; i--) {
        if (arr[i] & 1) {
            res += (arr[i] + 1) / 2 * odd;
            res += arr[i] / 2 * even;
            odd++;
        } else {
            res += arr[i] / 2 * (odd + even);
            even++;
        }
        res += arr[i] / 2 * (i - 1);
    }   
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
