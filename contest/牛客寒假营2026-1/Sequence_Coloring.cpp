#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, k;
const int maxN = 5e5 + 7;
vector<int> arr(maxN);
vector<int> preMx(maxN);

bool check(int x) {
    int cur = 1;
    while (cur <= n && !arr[cur]) cur++;
    int res = 1;
    while (cur <= n) {
        int t = x;
        if (res != 1) t--;
        while (cur < n && t) {
            cur = preMx[cur];
            t--;
        }
        if (cur > n) break;
        int nex = cur + 1;
        while (nex <= n && !arr[nex]) nex++;
        if (nex > n) break;
        cur = preMx[nex];
        res++;
    }
    // cout << "+++++" << res << endl;
    return res <= k;
}

void solve(){
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int c = 0;
    for (int i = 1; i <= n; i++) {
        preMx[i] = 0;
        if (arr[i]) {
            arr[i] += i;
            c++;
        }
    }
    if (c <= k) {
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++) preMx[i] = max(preMx[i - 1], arr[i]);

    int l = 0, r = n;
    int ans = LNF;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }

    cout << (ans == LNF ? -1 : ans) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}