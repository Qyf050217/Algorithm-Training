#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, x;cin >> n >> x;
    vector<int> p(n + 1), q(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++) cin >> q[i];

    int a = -1, b = -1;    
    for (int i = 1; i <= n; i++) {
        if (p[i] == x) a = i;
        if (q[i] == x) b = i;
    }
    set<int> st;
    for (int i = a + 1; i <= n; i++) st.insert(p[i]);
    for (int i = b + 1; i <= n; i++) {
        if (st.count(q[i])) {
            cout << "NO" << endl;
            return;
        }
    }

    set<int> fail;
    vector<int> posP(n + 1), posQ(n + 1);
    for (int i = 1; i <= n; i++) {
        posP[p[i]] = i;
        posQ[q[i]] = i;
    }

    int i = 1, j = 1;
    vector<int> ans;
    while (1) {
        while (i <= n && fail.count(p[i])) i++;
        while (j <= n && fail.count(q[j])) j++;
        if (p[i] == x) {
            if (q[j] == x) break;
            ans.push_back(q[j]);
            fail.insert(q[j]);
            j++;
            continue;
        }
        if (q[j] == x) {
            if (p[i] == x) break;
            ans.push_back(p[i]);
            fail.insert(p[i]);
            i++;
            continue;
        }
        if (p[i] == q[j]) {
            cout << "NO" << endl;
            return;
        }
        if (posQ[p[i]] < posP[q[j]]) {
            ans.push_back(p[i]);
            fail.insert(p[i]);
            i++;
        } else {
            ans.push_back(q[j]);
            fail.insert(q[j]);
            j++;
        }
    }

    cout << "YES" << endl;
    for (auto &i : ans) cout << i << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
