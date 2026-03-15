#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define LNF 1e18
int cnt;
const int MOD = 998244353;
struct matrix {
    int m[9][9] = {0};
    int len;
};

matrix operator * (const matrix a, const matrix b) {
        matrix c;
        memset(c.m, 0, sizeof(c.m));
        c.len = a.len;
        for (int i = 0; i < cnt; i++) {
            for (int j = 0; j < cnt; j++) {
                for (int k = 0; k < cnt; k++) {
                    c.m[i][j] = (c.m[i][j] + a.m[i][k] * b.m[k][j]) % MOD;
                }
            }
        }
        return c;
    }


matrix mt_ksm(matrix a, int n) {
    matrix ans;
    for (int i = 0; i < cnt; i++) ans.m[i][i] = 1;
    while (n) {
        if (n & 1) ans = ans * a;
        a = a * a;
        n >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;cin >> n >> k;
    matrix mt;
    cnt = k;
    for (int i = 0; i < k; i++) mt.m[0][i] = 1;
    for (int i = 1; i < k; i++) mt.m[i][i - 1] = 1;
    vector<int> f(10);
    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    f[4] = 8;
    f[5] = 16;
    f[6] = 32;
    f[7] = 64;
    f[8] = 128;
    mt = mt_ksm(mt, n);
    // for (int i = 0; i < k; i++) {
    //     for (int j = 0; j < k; j++) {
    //         cout << mt.m[i][j] << " \n"[j == k-1];
    //     }
    // }
    // int res = 0;
    // for (int i = 0; i < k; i++) {
    //     cout << f[i] << "*" << mt.m[0][k - i - 1] << endl;
    //     res = (res + f[i] * mt.m[1][k - i - 1]) % MOD;
    // }
    cout << mt.m[0][0] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}