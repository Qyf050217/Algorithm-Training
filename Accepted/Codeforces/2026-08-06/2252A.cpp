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
    map<int, int> cnt;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cnt[arr[i]]++;
        sum += arr[i];
    }
    int mx = 0, v = 0;
    
    for (auto [val, c] : cnt) {
        if (c > mx) {
            mx = c;
            v = val;
        }
    }
    sum -= mx * v;
    int re = n - mx;
    mx = min(mx, re + 2);
    cout << mx * v + sum << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
