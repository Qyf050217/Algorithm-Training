#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    int cnt0 = 0, cnt1 = 0;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;cin >> c;
            if (c == '0') cnt0++;
            else cnt1++;
            arr[i][j] = c - '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] && cnt1 == 1) cout << "N";
            else if (!arr[i][j] && cnt0 == 1) cout << "N";
            else cout << "Y";
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
