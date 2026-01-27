#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    vector<pair<PII, int>> arr(3);
    for (int i = 0; i < 3; i++) {
        int x, y;cin >> x >> y;
        arr[i] = {{x, y}, i+1};
    }
    ranges::sort(arr);
    cout << arr[1].second << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
