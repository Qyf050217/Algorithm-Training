#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<PII> arr(n);
    for (int i = 0; i < n; i++) {
        int x, y;cin >> x >> y;
        arr[i] = {x, y};
    }

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                int a = pow(arr[i].first - arr[j].first, 2) + pow(arr[i].second - arr[j].second, 2);
                int b = pow(arr[i].first - arr[k].first, 2) + pow(arr[i].second - arr[k].second, 2);
                int c = pow(arr[k].first - arr[j].first, 2) + pow(arr[k].second - arr[j].second, 2);
                if ((a == b || a == c || b == c) && !((arr[i].first == arr[j].first && arr[i].first == arr[k].first) || (arr[i].second == arr[j].second && arr[i].second == arr[k].second))) res++;
            }
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}