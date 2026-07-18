#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, c;cin >> n >> c;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int res = 0;

    ranges::sort(arr.begin()+1, arr.end());
    int i = 1, j = n;
    while (i <= j) {
        if (i == j) {
            res += arr[i] - c;
            break;
        } else {
            res += arr[j] - c;
            if (arr[i] <= c) {
                i++;
                j--;
            } else j--;
        }
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
