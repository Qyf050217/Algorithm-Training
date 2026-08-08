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
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
