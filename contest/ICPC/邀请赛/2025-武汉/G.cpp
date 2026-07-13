#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5;
const int MOD = 998244353;
vector<int> f(maxN + 7);
vector<int> finv(maxN + 7);

int ksm(int a, int b) {
    int res = 1;
    a %= MOD;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void init() {
    f[0] = finv[0] = 1;
    f[0] = 1;
    for (int i = 1; i <= maxN; i++) f[i] = f[i-1] * i % MOD;
    finv[maxN] = ksm(f[maxN], MOD - 2);
    for (int i = maxN - 1; i >= 0; i--) finv[i] = finv[i+1] * (i+1) % MOD;
}

int C(int n, int m) {
    return f[n] * finv[m] % MOD * finv[n-m] % MOD;
}

int A(int n, int m) {
    return f[n] % MOD * finv[n-m] % MOD;
}


int n, m;
vector<vector<int>> arr;
unordered_map<int, vector<PII>> mp;


int dp(int x) {
    vector<vector<int>> res(n + 1, vector<int>(m + 1));
    if (arr[1][1] != x) res[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == x) continue;
            res[i][j] = max(res[i][j], res[i - 1][j] + res[i][j - 1]) % MOD;
        }
    }
    return C(n + m - 2, n - 1) - res[n][m];
}

int rc(vector<PII> &vec) {
    ranges::sort(vec);
    int k = vec.size();
    vector<int> cnt(k, 0);

    for (int i = 0; i < k; i++) {
        auto [x, y] = vec[i];
        cnt[i] = C(x + y - 2, x - 1);
        for (int j = 0; j < i; j++) {
            auto [cx, cy] = vec[j];
            if (cx > x || cy > y) continue;
            int dx = x - cx;
            int dy = y - cy;
            cnt[i] = (cnt[i] - cnt[j] * C(dx + dy, dx) % MOD + MOD) % MOD;
        }
    }

    int res = 0;
    for (int i = 0; i < k; i++) {
        auto [x, y] = vec[i];
        int dx = n - x;
        int dy = m - y;
        res = (res + cnt[i] * C(dx + dy, dx)) % MOD;
    }
    return res;
}

void solve(){
    cin >> n >> m;
    arr.resize(n + 1);
    mp.clear();
    for (int i = 1; i <= n; i++) {
        arr[i].resize(m + 1);
        for (int j = 1; j <= m; j++) {
            int x;cin >> x;
            mp[x].push_back({i, j});
            arr[i][j] = x;
        }
    }
    int aid = sqrt(n * m);
    int res = 0;
    for (auto &[x, vec] : mp) {
        if (vec.size() > aid) { // dp
            res = (res + dp(x)) % MOD;
        } else { // 容斥
            res = (res + rc(vec)) % MOD;
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    init();
    int T = 1;cin >> T;
    while (T--) solve();
}
// ac