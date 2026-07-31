#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct SegmentTree {
private:
    int n;
    vector<int> tree;
    vector<int> lazy;
    const int LNF = 1e18;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree[p] = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * p, l, mid, arr);
        build(2 * p + 1, mid + 1, r, arr);
        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }

    void pushdown(int p, int l, int r) {
        if (lazy[p] == 0) return;
        
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
        tree[2 * p] += lazy[p];
        tree[2 * p + 1] += lazy[p];
        lazy[p] = 0;
    }

    void change(int p, int l, int r, int x, int y, int num) {
        if (x <= l && r <= y) {
            tree[p] += num;
            lazy[p] += num;
            return;
        }
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        if (x <= mid) change(2 * p, l, mid, x, y, num);
        if (y >= mid + 1) change(2 * p + 1, mid + 1, r, x, y, num);
        
        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }

    int calc(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        pushdown(p, l, r);
        
        int res = -LNF; 
        int mid = (l + r) >> 1;
        
        if (x <= mid) res = max(res, calc(2 * p, l, mid, x, y));
        if (y >= mid + 1) res = max(res, calc(2 * p + 1, mid + 1, r, x, y));
        return res;
    }

    int query_first(int p, int l, int r, int x, int y, int val) {
        if (l > y || r < x || tree[p] < val) return -1;
        if (l == r) return l;
        
        pushdown(p, l, r);
        int mid = (l + r) >> 1;
        
        int res = query_first(2 * p, l, mid, x, y, val);
        if (res == -1) res = query_first(2 * p + 1, mid + 1, r, x, y, val);
        return res;
    }

public:
    // 构造函数
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    // 初始化建树（1-indexed）
    void init(const vector<int>& arr) {
        build(1, 1, n, arr);
    }

    // 区间加：将 [x, y] 区间内的所有值加上 num
    void update(int x, int y, int num) {
        if (x > y) return;
        change(1, 1, n, x, y, num);
    }

    // 区间最大值查询：查询 [x, y] 区间内的最大值
    int query_max(int x, int y) {
        if (x > y) return -LNF;
        return calc(1, 1, n, x, y);
    }

    // 线段树上二分：在 [x, y] 区间内找到第一个 >= val 的下标
    int find_first(int x, int y, int val) {
        if (x > y) return -1;
        return query_first(1, 1, n, x, y, val);
    }
};

void solve(){
    int n;cin >> n;
    vector<int> arr(2 * n + 1);
    SegmentTree seg(2 * n + 7);

    vector<int> pos(n + 1); // i - pos
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        arr[i + n] = arr[i];
        pos[arr[i]] = i;
    }

    for (int i = 1; i <= 2 * n; i++) seg.update(i, i, i);
    for (int x = 1; x < n; x++) {
        seg.update(max(pos[x], pos[x + 1]), 2 * n, -1);
    }

    int ans = (seg.query_max(1, n) <= 2);
    for (int s = 1; s < n; s++) {
        int x = arr[s];
        if (x < n) seg.update(pos[x + 1], s + n - 1, 1);
        if (x > 1) seg.update(pos[x - 1], s + n - 1, 1);
        pos[x] = s + n;
        ans += (seg.query_max(s + 1, s + n) <= s + 2);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
