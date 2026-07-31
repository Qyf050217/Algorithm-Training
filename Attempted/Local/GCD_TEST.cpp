#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int cnt(int x, vector<int> &pri) {
    int n = pri.size();
    vector<vector<int>> b(40);
    for (int st = 1; st < (1 << n); st++) {
        int cnt = 0;
        for (int bit = 0; bit <= 30; bit++) {
            if ((st >> bit) & 1) cnt++;
        }
        b[cnt].push_back(st);
    }
    // for (int i = 1; i <= 20; i++) {
    //     cout << i << endl;
    //     for (auto &st : b[i]) cout << st << ' ';
    //     cout << endl;
    // }
    int f = 1;
    int res = 0;
    for (int len = 1; len <= 30; len++) {
        
        for (auto &st : b[len]) {
            int aid = 1;
            for (int bit = 0; bit <= 30; bit++) {
                if ((st >> bit) & 1) aid *= pri[bit];
            }
            res += f * (x / aid);
        }
        
        f = 0 - f;
    }

    return res;
}


void solve(){
    int l, r, n;cin >> l >> r >> n;
    int res = 0;
    for (int i = l; i <= r; i++) {
        if (gcd(i, n) == 1) res++;
        else res += 2;
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}