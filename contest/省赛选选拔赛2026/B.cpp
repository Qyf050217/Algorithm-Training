#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define inv(x) ksm(x, MOD - 2);

vector<int> f(1e6 + 7);
vector<int> invf(1e6 + 7);
const int MOD = 998244353;

int ksm(int a, int n) {
    int ans = 1;
    a %= MOD;
    while (n) {
        if (n & 1) ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return ans;
}

void pre() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 1e6 + 5; i++) {
        f[i] = (f[i - 1] * i) % MOD;
    }
    invf[0] = inv(f[0]);
    for (int i = 1; i <= 1e6 + 5; i++) {
        invf[i] = inv(f[i]);
    }
}

int C(int a, int b) {
    if (b == 0) return 1;
    int res = f[a] * invf[b] % MOD * invf[a - b] % MOD;
    return res;
}


void solve() {
    int n;cin >> n;
    string s;cin >> s;
    if (s.size() % 4) {
        cout << 0 << endl;
        return;
    }
    map<char, int> cnt;
    for (auto &c : s) {
        cnt[c]++;
    }
    int remain = cnt['?'];
    int aid = n / 4;
    vector<int> zust(4, 0);
    zust[0] = cnt['z'];
    zust[1] = cnt['u'];
    zust[2] = cnt['s'];
    zust[3] = cnt['t'];
    int res = 1;
    for (int i = 0; i < 4; i++) {
        if (zust[i] > aid) {
            cout << 0 << endl;
            return;
        } else if (zust[i] == aid) continue;
        else if (aid - zust[i] > remain) {
            cout << 0 << endl;
            return;
        }
        res = res * C(remain, aid - zust[i]) % MOD;
        // if (res == 0) cout << remain << ' ' << aid - zust[i] << endl;
        remain -= (aid - zust[i]);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    pre();
    int T;cin >> T;
    while (T--) solve();
}