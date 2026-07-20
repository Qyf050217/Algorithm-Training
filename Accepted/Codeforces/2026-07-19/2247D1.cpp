#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,q;cin >> n >> q;
    vector<int> arr(n);
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s[i] = arr[i];
    }
    ranges::sort(s);
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] != arr[i]) {
            index = i;
            break;
        }
    }
    if (index == -1) {
        cout << 0 << endl;
        return;
    }
    // for (int i = 0; i < n; i++) cout << arr[i] << " \n"[i == n - 1];
    // cout << "++++" << endl;
    for (int len = 2; len <= 2 * n; len *= 2) {
        // cout << len << "+++++++" << endl;
        for (int st = 0; st < n; st += len) {
            int ed = min(st + len, n);
            // cout << st << ' ' << ed << endl;
            sort(arr.begin()+st, arr.begin()+ed);
            int f = 1;
            for (int i = index; i < n; i++) {
                // cout << arr[i] << " \n"[i == n - 1];
                if (s[i] != arr[i]) {
                    index = i;
                    f = 0;
                    break;
                }
            }
            // cout << endl;
            if (f) {
                cout << len / 2 << endl;
                return;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
