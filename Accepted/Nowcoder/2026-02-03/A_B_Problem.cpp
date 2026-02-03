#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (ksm(x, MOD - 2))

const int MOD = 998244353;
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

vector<vector<int>> kkk = {
    {0, 1, 2, 4, 5, 6},    // 0
    {2, 5},                // 1
    {0, 2, 3, 4, 6},       // 2
    {0, 2, 3, 5, 6},       // 3
    {1, 2, 3, 5},          // 4
    {0, 1, 3, 5, 6},       // 5
    {0, 1, 3, 4, 5, 6},    // 6
    {0, 2, 5},             // 7
    {0, 1, 2, 3, 4, 5, 6}, // 8
    {0, 1, 2, 3, 5, 6}     // 9
};

void solve(){
    int C;cin >> C;
    vector<int> p(7); // 灯管 i 亮的概率
    for (auto &i : p) {
        cin >> i;
        i = (i * inv(100)) % MOD;
    }
    vector<int> arr(10); // 显示数字为 i 的概率
    for (int num = 0; num <= 9; num++) {
        set<int> st;
        int P = 1;
        for (auto i : kkk[num]) {
            st.insert(i);
        }
        for (int i = 0; i <= 6; i++) {
            if (st.count(i)) P = P * p[i] % MOD;
            else P = P * ((MOD + 1 - p[i]) % MOD) % MOD;
        }
        arr[num] = P;
    }


    vector<int> PC(C + 1); // 4个显示数字为i
    for (int i = 0; i <= C; i++) {
        int t = i;
        int d4 = t % 10; t /= 10;
        int d3 = t % 10; t /= 10;
        int d2 = t % 10; t /= 10;
        int d1 = t % 10;
        int res = arr[d1];
        res = (res * arr[d2]) % MOD;
        res = (res * arr[d3]) % MOD;
        res = (res * arr[d4]) % MOD;
        
        PC[i] = res;
    }

    int ans = 0;
    for (int A = 0; A <= C; A++) {
        int B = C - A;
        ans = ans + (PC[A] * PC[B] % MOD);
        ans %= MOD;
    }

    cout << ans % MOD << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
