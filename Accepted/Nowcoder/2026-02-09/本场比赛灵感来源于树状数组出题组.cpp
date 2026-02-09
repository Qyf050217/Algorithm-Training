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
    ranges::sort(arr.begin() + 1, arr.end(), greater<int>());
    int aid = arr[(n + 4) / 5];
    // cout << aid << endl;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (arr[i] >= aid) sum += arr[i];
    }
    cout << sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
