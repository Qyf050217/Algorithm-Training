#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    arr[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i][1] = (arr[i - 1][1] ^ 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            arr[i][j] = (arr[i][j - 1] ^ 1);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j]) cout << '/';
            else cout << '\\';
        }
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
