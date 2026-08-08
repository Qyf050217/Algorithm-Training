#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    string a, b;cin >> a >> b;
    a = "#" + a;
    b = "#" + b;

    int a_1_1 = 0, a_2_1 = 0, b_1_1 = 0, b_2_1 = 0;
    for (int i = 1; i <= n; i++) {
        if (i & 1) {
            if (a[i] == '1') a_1_1++;
            if (b[i] == '1') b_1_1++;
        } else {
            if (a[i] == '1') a_2_1++;
            if (b[i] == '1') b_2_1++;
        }
    }
    if (a_1_1 != b_1_1 || a_2_1 != b_2_1) {
        cout << -1 << endl;
        return;
    }

    vector<int> idx1, idx2;
    for (int i = 1; i <= n; i += 2) if (b[i] == '1') idx1.push_back(i);
    for (int i = 2; i <= n; i += 2) if (b[i] == '1') idx2.push_back(i);
    
    int ans = 0;
    int idx = 0;
    for (int i = 1; i <= n; i += 2) {
        if (a[i] == '1') {
            ans += abs(idx1[idx++] - i) / 2;
        }
    }
    idx = 0;
    for (int i = 2; i <= n; i += 2) {
        if (a[i] == '1') {
            ans += abs(idx2[idx++] - i) / 2;
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
