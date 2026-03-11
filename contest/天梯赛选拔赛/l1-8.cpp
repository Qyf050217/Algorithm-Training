#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
void solve() {
    vector<PII> arr(4);
    for (int i = 0; i < 4; i++) cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());

    int X1 = arr[0].first - arr[1].first;
    int Y1 = arr[0].second - arr[1].second;
    int X2 = arr[2].first - arr[3].first;
    int Y2 = arr[2].second - arr[3].second;
    // 平行
    if (X1 * Y2 != X2 * Y1) {
        cout << "NO" << endl;
        return;
    }

    if (X1*X1 + Y1*Y1 != X2*X2 + Y2*Y2) {
        cout << "NO" << endl;
        return;
    }

    X1 = arr[0].first - arr[2].first;
    Y1 = arr[0].second - arr[2].second;
    X2 = arr[1].first - arr[3].first;
    Y2 = arr[1].second - arr[3].second;
    if (X1 * Y2 != X2 * Y1) {
        cout << "NO" << endl;
        return;
    }

    if (X1*X1 + Y1*Y1 != X2*X2 + Y2*Y2) {
        cout << "NO" << endl;
        return;
    }


    X1 = arr[0].first - arr[1].first;
    Y1 = arr[0].second - arr[1].second;
    X2 = arr[0].first - arr[2].first;
    Y2 = arr[0].second - arr[2].second;
    if (X1*X2 + Y1*Y2 != 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;cin >> T;
    while (T--) solve();
}