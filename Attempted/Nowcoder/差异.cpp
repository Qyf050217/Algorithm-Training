#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m;cin >> n >> m;
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> sum(m);
    for (int j = 0; j < m; j++) {
        for (int i = 1; i <= n; i++) {
            sum[j] += arr[i][j] - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        string s = arr[i];
        vector<int> t(m);
        for (int j = 0; j < m; j++) {
            t = 
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}