#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


int highbit(int x) {
    int cnt = 0;
    while (x) {
        cnt++;
        x /= 2;
    }
    return cnt;
}

void solve(){
    int a, b, c;cin >> a >> b >> c;
    vector<int> ans;
    if (a == 0 && b == 0) {
        if (c == 0) {
            cout << 0 << endl << endl;
        } else {
            cout << -1 << endl;
        }
        return;
    }

    if (highbit(a) > highbit(b)) {
        b ^= a;
        ans.push_back(4);
    } else if (highbit(a) < highbit(b)) {
        a ^= b;
        ans.push_back(3);
    }

    int ha = highbit(a) - 1;
    for (int bit = highbit(c) - 1; bit > ha; bit--) {
        if (((a >> (highbit(b) - 1)) & 1) != ((c >> bit) & 1)) {
            a ^= b;
            ans.push_back(3);
        }
        a *= 2;
        ans.push_back(1);
    }

    for (int bit = highbit(b) - 1; bit >= 0; bit--) {
        if (((c >> bit) & 1) != ((a >> bit) & 1)) {
            a ^= b;
            ans.push_back(3);
        }
        b /= 2;
        ans.push_back(2);
    }

    b ^= a;
    ans.push_back(4);

    cout << ans.size() << endl;
    for (auto &i : ans) cout << i << ' ';
    cout << endl;
    // cout << a << ' ' << b << ' ' << c << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
