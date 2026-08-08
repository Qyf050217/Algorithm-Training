#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int ans = 0;
    vector<int> arr(3);
    for (int i = 0; i < 3; i++) cin >> arr[i];
    while (1) {
        ranges::sort(arr);
        if (arr[0] == arr[1] || arr[1] == arr[2]) {
            cout << ans << endl;
            break;
        }
        arr[0]++; arr[2]--;
        ans++;
    } 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
