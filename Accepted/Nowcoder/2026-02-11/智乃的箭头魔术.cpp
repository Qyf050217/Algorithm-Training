#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string op = "0112233445142015320125410214530214510214102302142025101203201451451522302514203214510021454101002532";
    // op = "012345";
    int cur = 0;
    string ans;
    for (auto &c : op) {
        if (c == '0') {
            cur = 3 - cur;
        } else if (c == '1') {
            if (cur == 1) cur = 3;
            else if (cur == 3) cur = 1;
        } else if (c == '2') {
            if (cur == 0 || cur == 1) cur = 1 - cur;
            else if (cur == 2) cur = 3;
            else cur = 2;
        } else if (c == '3') {
            if (cur == 0 || cur == 2) {
                cur = 2 - cur;
            }
        } else if (c == '4') {
            cur = (cur + 1) % 4;
        } else cur = (cur - 1 + 4) % 4;
        ans += char(cur + '0');
        cout << cur;
    }
    // cout << endl;
    // cout << ans.size();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
