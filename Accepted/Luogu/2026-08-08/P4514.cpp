#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 2050;

class RangeAddRangeSum {
private:
    int n, m;
    long long t1[MAXN][MAXN]; // 维护 d[i][j]
    long long t2[MAXN][MAXN]; // 维护 d[i][j] * i
    long long t3[MAXN][MAXN]; // 维护 d[i][j] * j
    long long t4[MAXN][MAXN]; // 维护 d[i][j] * i * j


    inline int lowbit(int x) { return x & -x; }

    // 单点更新 4 个树状数组
    void _add(int x, int y, long long val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                t1[i][j] += val;
                t2[i][j] += val * x;
                t3[i][j] += val * y;
                t4[i][j] += val * x * y;
            }
        }
    }

    // 求原矩阵 (1,1) 到 (x,y) 的推导前缀和
    long long _query_prefix(int x, int y) {
        long long res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                res += (x + 1LL) * (y + 1LL) * t1[i][j]
                     - (y + 1LL) * t2[i][j]
                     - (x + 1LL) * t3[i][j]
                     + t4[i][j];
            }
        }
        return res;
    }

public:
    // 多测加上循环清空矩阵
    void init(int _n, int _m) {
        n = _n; m = _m;
    }

    // 左上角 (x1, y1) 到右下角 (x2, y2) 加上 val
    void range_add(int x1, int y1, int x2, int y2, long long val) {
        _add(x1, y1, val);
        _add(x1, y2 + 1, -val);
        _add(x2 + 1, y1, -val);
        _add(x2 + 1, y2 + 1, val);
    }

    // 左上角 (x1, y1) 到右下角 (x2, y2) 的元素总和
    long long range_query(int x1, int y1, int x2, int y2) {
        return _query_prefix(x2, y2)
             - _query_prefix(x1 - 1, y2)
             - _query_prefix(x2, y1 - 1)
             + _query_prefix(x1 - 1, y1 - 1);
    }
};

RangeAddRangeSum mat;

void solve(){
    char op;cin >> op;
    int n, m;cin >> n >> m;
    mat.init(n, m);
    while (cin >> op) {
        if (op == 'L') {
            int a, b, c, d, val;cin >> a >> b >> c >> d >> val;
            mat.range_add(a, b, c, d, val);
        } else {
            int a, b, c, d;cin >> a >> b >> c >> d;
            cout << mat.range_query(a, b, c, d) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
