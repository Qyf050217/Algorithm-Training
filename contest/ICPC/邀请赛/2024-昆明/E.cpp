#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> fr(n + 2), ba(n + 2);
    fr[1] = arr[1]; ba[n] = arr[n];
    for (int i = 2; i <= n; i++) {
        fr[i] = gcd(fr[i - 1], arr[i]);
    }
    for (int i = n - 1; i >= 1; i--) {
        ba[i] = gcd(ba[i + 1], arr[i]);
    }
    int ans = fr[n];
    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            int l = i;
            int mid = 0;
            for (int r = i; r <= n; r++) {
                mid = gcd(mid, arr[r] + k);
                ans = max(ans, gcd(gcd(mid, ba[r + 1]), fr[i - 1]));
            }
        } else {
            if (fr[i] < fr[i - 1]) {
                int l = i;
                int mid = 0;
                for (int r = i; r <= n; r++) {
                    mid = gcd(mid, arr[r] + k);
                    ans = max(ans, gcd(gcd(mid, ba[r + 1]), fr[i - 1]));
                }
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}