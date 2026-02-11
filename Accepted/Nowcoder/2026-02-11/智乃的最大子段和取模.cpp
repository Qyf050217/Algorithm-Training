#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, p;cin >> n >> p;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) sum[i] = (sum[i - 1] + arr[i]) % p;

    set<int> st; // val
    map<int, int> mp; // val - pos
    st.insert(0);
    mp[0] = 0;
    int mx = arr[1] % p;
    int resL = 1, resR = 1;
    mp[mx] = 1;
    st.insert(mx);
    for (int i = 2; i <= n; i++) {
        int mn = *st.begin();
        int cur = sum[i];
        if (cur - mn > mx) {
            mx = cur - mn;
            resR = i;
            resL = mp[mn] + 1;
        }
        auto it = st.upper_bound(cur);
        if (it != st.end()) 
        {int val = *it;
        if ((cur - val + p) % p > mx) {
            mx = (cur - val + p) % p;
            resR = i;
            resL = mp[val] + 1;
        }}
        st.insert(cur);
        mp[cur] = i;
    }

    cout << resL - 1 << ' ' << resR - 1 << ' ' << mx << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
