#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, x, y;cin >> n >> x >> y;
    y--;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> A, B;
    int mn1 = LNF, mn2 = LNF;
    for (int i = x; i <= y; i++) {A.push_back(arr[i]); mn1 = min(mn1, arr[i]);}
    for (int i = x; i <= y; i++) A.push_back(arr[i]);

    for (int i = 0; i < x; i++) B.push_back(arr[i]);
    for (int i = y+1; i < n; i++) B.push_back(arr[i]);
    // for (auto &i : B) cout << i << ' ';
    // cout << endl;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (A[i] == mn1) {
            // cout << 111;
            ans.push_back(A[i]);
            for (int j = i+1; A[j] != mn1; j++) ans.push_back(A[j]);
            break;
        }
    }
    // for (auto &i : ans) cout << i << ' ';
    // cout << endl;
    for (int i = 0; i < B.size(); i++) {
        if (B[i] > mn1) {
            for (int j = 0; j < i; j++) cout << B[j] << ' ';
            for (auto &j : ans) cout << j << ' ';
            for (int j = i; j < B.size(); j++) cout << B[j] << ' ';
            cout << endl;
            return;
        }
    }
    for (auto &i : B) cout << i << ' ';
    for (auto &j : ans) cout << j << ' ';
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
