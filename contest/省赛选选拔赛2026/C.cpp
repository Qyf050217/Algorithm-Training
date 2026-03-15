#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>


const int maxN = 1e6 + 7;
vector<int> arr(maxN);
vector<int> sum(maxN);
vector<int> isum(maxN);

int n;
int calc(int l, int k) {
    int r = l;
    int low = l-1, high = n+1;
    while (low + 1 < high) {
        int mid = low + high >> 1;
        int s = (isum[mid] - isum[l - 1]) - (sum[mid] - sum[l - 1]) * (l - 1);
        // cout << s << ' ';
        if (s <= k) {
            r = mid;
            low = mid;
        } else high = mid;
    }
    return r;
}


void solve() {
    int q;cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sum[0] = 0;
    isum[0] = 0;
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + arr[i];
    for (int i = 1; i <= n; i++) isum[i] = isum[i - 1] + i * arr[i];
    // for (int i = 1; i <= n; i++) cout << isum[i] << " \n"[i == n];
    while (q--) {
        int l, k;cin >> l >> k;
        if (arr[l] > k) {
            cout << -1 << endl;
            continue;
        }
        cout << calc(l, k) << endl;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}