#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m, x, y;cin >> n >> m >> x >> y;
    vector<int> a(x + 1), b (y + 1);
    for (int i = 1; i <= x; i++) cin >> a[i];
    for (int i = 1; i <= y; i++) cin >> b[i];

    priority_queue<PII> pq;
    for (int i = 1; i <= x; i++) pq.push({a[i], 0});
    for (int i = 1; i <= y; i++) pq.push({b[i], 1});
    
    int choose = 0;
    int A = 0, B = 0;
    int ans = 0;
    set<int> st;
    while (pq.size()) {
        if (choose + A + B == n + m - 1) break;
        auto [val, pos] = pq.top(); pq.pop();
        if (st.count(val)) continue;
        if (pq.size()) {
            if (val == pq.top().first) { // 双方都有 -公共名额
                pq.pop();
                choose++;
                ans += val;
                st.insert(val);
                // cout << val << ' ';
            } else {
                if (pos == 0 && A < n) {
                    A++;
                    ans += val;
                    st.insert(val);
                    // cout << val << ' ';
                } else if (pos == 1 && B < m) {
                    B++;
                    ans += val;
                    st.insert(val);
                    // cout << val << ' ';
                }
            }
        } else {
            if (pos == 0 && A < n) {
                A++;
                ans += val;
                st.insert(val);
                // cout << val << ' ';
            } else if (pos == 1 && B < m) {
                B++;
                ans += val;
                st.insert(val);
                // cout << val << ' ';
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
