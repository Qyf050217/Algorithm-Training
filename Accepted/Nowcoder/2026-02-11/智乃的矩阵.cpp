#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    if (n == 1) {
        cout << "Yes" << endl;
        return;
    }
    vector<vector<int>> arr(n + 1, vector<int>(n + 1));
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            sum += arr[i][j];
        }
    }

    if (sum % (n * n)) {
        cout << "No" << endl;
        return;
    }

    int aid = sum / (n * n);
    for (int i = 1; i <= n - 2; i++) {
        for (int j = 1; j < n; j++) {
            int dis = aid - arr[i][j];
            arr[i][j] = aid;
            arr[i][j + 1] += dis;
            arr[i+1][j] -= dis;
            arr[i+1][j+1] -= dis;
        }
        int dis = aid - arr[i][n];
        if (dis & 1) {
            cout << "No" << endl;
            return;
        }
        arr[i][n] = aid;
        arr[i + 1][n - 1] -= dis;
    }
    
    vector<vector<int>> a(3, vector<int>(n + 1));
    for (int i = n-1; i <= n; i++) {
        for (int j = 1; j <= n; j++) a[i-n+2][j] = arr[i][j];
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << arr[i][j] << " \n"[j == n];
    //     }
    // }
    for (int j = 1; j < n; j++) {
        int dis1 = aid - a[1][j];
        int dis2 = aid - a[2][j];
        if ((dis1 & 1) != (dis2 & 1)) {
            cout << "No" << endl;
            return;
        }
        a[1][j] = a[2][j] = aid;
        a[1][j+1] -= dis2;
        a[2][j+1] -= dis1;
    }
    if (a[1][n] == aid && a[2][n] == aid) cout << "Yes";
    else cout << "No";
    // for (int i = 1; i <= 2; i++) {
    //     for (int j = 1; j <= n; j++) cout <<a[i][j] << " \n"[j == n];
    // }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
