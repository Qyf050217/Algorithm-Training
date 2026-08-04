#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(int B){
    if (B & 1 || (B == 2)) {
        cout << -1 << endl;
        return;
    }
    vector<int> ans(B);
    for (int i = 0; i < B - 2; i++) {
        ans[i] = ans[i] + (B - i - 1) * 2;
        while (ans[i] >= B) {
            ans[i] -= B;
            ans[i + 1]++;
        }
    }
    ans[B - 2] = ans[B - 2] + 1;
    while (ans[B - 2] >= B) {
        ans[B - 2] -= B;
        ans[B]++;
    }
    ans[B - 1] = ans[B - 1] + 1;

    // cout << "1 0 ";
    // for (int i = 2; i < B; i++) cout << i << " \n"[i == B - 1];
    // for (int i = 0; i < B; i++) cout << i << " \n"[i == B - 1];
    // for (int i = B - 1; i >= 0; i--) cout << ans[i] << ' ';
    int f = 1;
    set<int> st;
    for (int i = 0; i < B; i++) st.insert(ans[i]);
    if (st.size() != B) cout << -1 << endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    cout << 1 << endl;
    for (int B = 4; B <= 1000; B += 2) {
        solve(B);
    }
}