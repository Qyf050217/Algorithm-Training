#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


const int MOD = 998244353;

void solve(){
    int n;cin >> n;
    vector<int> arr(n);
    for (int i = 1; i < n; i++) cin >> arr[i];

    vector<int> res(n + 1);

    int f = 1; // 1 升  0 降
    for (int i = 2; i < n; i++) {
        if (arr[i] > arr[i - 1]) {
            if (!f) {
                cout << 0 << endl;
                return;
            }
        } else if (arr[i] < arr[i - 1]) {
            f = 0;
        }
    }
    int mx = 0;
    for (int i = 1; i < n; i++) mx = max(mx, arr[i]);
    if (mx != n - 1) {
        cout << 0 << endl;
        return;
    }  
    set<int> st;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            int x = arr[i];
            if (st.count(x)) {
                cout << 0 << endl;
                return;
            }
            st.insert(x);
        }
    }
    


    map<int, int> mp;
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j < n && arr[j] == arr[i]) j++;
        mp[arr[i]] = j - i;
        i = j - 1;
    }


    int ans = 1;
    int use = 0;
    for (auto &[val, cnt] : mp) {
        // cout << val << ' ' << cnt << endl;
        int keyong = val - 1 - use;
        if (cnt > 1 && keyong <= 0) {
            cout << 0 << endl;
            return;
        }
        use += cnt;
        cnt--;
        int t = 1;
        for (int i = keyong; cnt >= 1; i--, cnt--) t = t * i % MOD;
        ans = ans * t % MOD;
    }
    
    
    ans = ans * 2 % MOD;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
