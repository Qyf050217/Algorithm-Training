#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<int> pri;
void pre() {
    for (int i = 2; i <= 113; i++) {
        int f = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                f = 0;
                break;
            }
        }
        if (f) pri.push_back(i);
    }
}

void solve(){
    vector<int> dis0(140, 0);
    vector<int> dis1(140, 0);
    int n;cin >> n;
    vector<int> arr(2 * n + 1);
    vector<int> b(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
        b[n - i + 1] = arr[i];
        b[2*n - i + 1] = arr[i];
    }
    int res = 0;
    // for (int i = 1; i <= 2*n; i++) cout << arr[i] << ' ';
    for (int i = 1; i <= 2 * n; i++) {
        // cout << i << ": ";
        vector<int> t(140, 0);
        if (arr[i] == 1) {
            dis0[0] = i;
            if (i - dis0[2] < n) dis0[3] = max(dis0[3], dis0[2]);
            continue;
        }
        for (auto p : pri) {
            if (dis0[p] == 0 || i - dis0[p] >= n) continue;
            // cout << p << ' ';
            int np = p + arr[i];
            np = *(upper_bound(pri.begin(), pri.end(), np) - 1);
            t[np] = max(t[np], dis0[p]);
        }
        for (auto p : pri) {
            dis0[p] = max(dis0[p], t[p]);
            // if (dis[p]) cout << p << ' ';
        }
        dis0[0] = i;
        int np = *(upper_bound(pri.begin(), pri.end(), arr[i]) - 1);
        dis0[np] = i;
    }

    for (int i = 1; i <= 2 * n; i++) {
        // cout << i << ": ";
        vector<int> t(140, 0);
        if (b[i] == 1) {
            dis1[0] = i;
            if (i - dis1[2] < n) dis1[3] = max(dis1[3], dis1[2]);
            continue;
        }
        for (auto p : pri) {
            if (dis1[p] == 0 || i - dis1[p] >= n) continue;
            // cout << p << ' ';
            int np = p + b[i];
            np = *(upper_bound(pri.begin(), pri.end(), np) - 1);
            t[np] = max(t[np], dis1[p]);
        }
        for (auto p : pri) {
            dis1[p] = max(dis1[p], t[p]);
            // if (dis1[p]) cout << p << ' ';
        }
        dis1[0] = i;
        int np = *(upper_bound(pri.begin(), pri.end(), b[i]) - 1);
        dis1[np] = i;
    }
    for (auto &p : pri) {
        if (dis1[p] || dis0[p]) res = max(res, p);
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    pre();
    int T = 1;cin >> T;
    while (T--) solve();
}
