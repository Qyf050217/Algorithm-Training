#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct PointAddRangeSum {
    int n, m; // 矩阵的实际长宽
    long long tree[107][307][307];

    void init(int _n, int _m) {
        n = _n; m = _m;
    }

    inline int lowbit(int x) { return x & -x; }

    // 单点修改：在位置 (x, y) 加上 val
    void add(int x, int y, long long color, int val) {
        for (int i = x; i <= n; i += lowbit(i)) {
            for (int j = y; j <= m; j += lowbit(j)) {
                tree[color][i][j] += val;
            }
        }
    }

    // 求二维前缀和：(1,1) 到 (x,y) 的矩阵和
    long long query_prefix(int x, int y, int color) {
        long long res = 0;
        for (int i = x; i > 0; i -= lowbit(i)) {
            for (int j = y; j > 0; j -= lowbit(j)) {
                res += tree[color][i][j];
            }
        }
        return res;
    }

    // 矩阵求和：左上角 (x1, y1) 到右下角 (x2, y2)
    long long range_query(int x1, int y1, int x2, int y2, int color) {
        return query_prefix(x2, y2, color) 
             - query_prefix(x1 - 1, y2, color) 
             - query_prefix(x2, y1 - 1, color) 
             + query_prefix(x1 - 1, y1 - 1, color);
    }
}mat;

void solve(){
    int n, m;cin >> n >> m;
    
    mat.init(n, m);
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int val;cin >> val;
            mat.add(i, j, val, 1);
            arr[i][j] = val;
        }
    }

    int q;cin >> q;

    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            int x, y, col;cin >> x >> y >> col;
            mat.add(x, y, arr[x][y], -1);
            arr[x][y] = col;
            mat.add(x, y, col, 1);
        } else {
            int a, b, c, d, val;cin >> a >> b >> c >> d >> val;
            cout << mat.range_query(a, c, b, d, val) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
    return 0;
}
