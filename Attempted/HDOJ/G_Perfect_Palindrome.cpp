#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, d;
string s;


void solve(){
    cin >> n >> d;
    cin >> s;
    s = "#" + s;
    vector<int> f(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (f[i]) continue;
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (f[cur]) continue;
            f[cur] = i;
            if (n - cur + 1 <= n && n - cur + 1 >= 1) q.push(n - cur + 1);
            if (d == 0) continue;
            int nx = cur - cur % d;
            if (cur % d == 0) nx -= d;
            nx += 2 * d + 1;
            nx -= cur % d;
            if (cur % d == 0) nx -= d;
            if (nx >= 1 && nx <= n) q.push(nx);
        }
    }

    // for (int i = 1; i <= n; i++) cout << f[i] << " \n"[i == n];

    map<int, map<char, int>> mp;
    for (int i = 1; i <= n; i++) {
        mp[f[i]][s[i]]++;
    }


    int res = 0;
    for (auto &[_, mmp] : mp) {
        int mx = 0, cnt = 0;
        for (auto &[__, c] : mmp) {
            mx = max(mx, c);
            cnt += c;
        }
        res += cnt - mx;
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}