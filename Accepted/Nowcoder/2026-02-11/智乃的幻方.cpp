#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    vector<vector<int>> arr(4, vector<int>(4));
    set<int> st;
    for (int i = 1; i <= 3; i++) for (int j = 1; j <= 3; j++) {
        cin >> arr[i][j];
        st.insert(arr[i][j]);
    }
    if (st.size() != 9) {
        cout << "No" << endl;
        return;
    }
    int a = 0;
    for (int i = 1; i <= 3; i++) a += arr[i][1];
    for (int i = 1; i <= 3; i++) {
        int t = 0;
        for (int j = 1; j <= 3; j++) {
            t += arr[i][j];
        }
        if (t != a) {
            cout << "No" << endl;
            return;
        }
    }
    for (int j = 1; j <= 3; j++) {
        int t = 0;
        for (int i = 1; i <= 3; i++) {
            t += arr[i][j];
        }
        if (t != a) {
            cout << "No" << endl;
            return;
        }
    }
    int t = arr[1][1] + arr[2][2] + arr[3][3];
    if (t != a) {
        // cout << t;
        cout << "No" << endl;
        return;
    }
    t = arr[1][3] + arr[2][2] + arr[3][1];
    if (t != a) {
        // cout << t;
        cout << "No" << endl;
        return;
    }
    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
