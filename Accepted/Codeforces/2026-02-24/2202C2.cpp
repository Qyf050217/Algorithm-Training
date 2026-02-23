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
    vector<int> dp(n + 2);
    vector<int> next(n + 1);
    int pos = n + 1;
    for (int i = n; i >= 1; i--) {
        next[i] = pos;
        if (arr[i] > arr[i - 1] + 1) {
            pos = i;
        }
    }
    stack<int> st;
    for (int i = n; i >= 1; i--) {
        while (!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if (st.size()) {
            next[i] = min(next[i], st.top());
        }
        st.push(i);
    }

    for (int i = n; i >= 1; i--) {
        dp[i] = (n - i + 1) + dp[next[i]];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += dp[i];
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
