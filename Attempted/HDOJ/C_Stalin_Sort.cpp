#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
struct SegmentTree {
private:
    int n;
    vector<int> tree_mx, tree_va;

    void pushup(int p, int l, int r) {
        int mid = l + r >> 1;
        tree_mx[p] = max(tree_mx[2 * p], tree_mx[2 * p + 1]);
        tree_va[p] = tree_va[2 * p] + calc(2 * p + 1, mid + 1, r, tree_mx[2 * p]);
    }
    
    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree_mx[p] = arr[l];
            tree_va[p] = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * p, l, mid, arr);
        build(2 * p + 1, mid + 1, r, arr);

        pushup(p, l, r);
    }


    void change(int p, int l, int r, int pos, int num) {
        if (l == r && l == pos) {
            tree_mx[p] = num;
            tree_va[p] = 1;
            return;
        }

        int mid = (l + r) >> 1;
        if (pos <= mid) change(2 * p, l, mid, pos, num);
        if (pos >= mid + 1) change(2 * p + 1, mid + 1, r, pos, num);

        pushup(p, l, r);
    }

    int calc(int p, int l, int r, int limit) {
        if (l == r) {
            if (tree_mx[p] > limit) return 0;
            else return 1;
        }
        int mid = (l + r) >> 1;

        if (tree_mx[2 * p] <= limit) {
            return calc(2 * p + 1, mid + 1, r, limit);
        } else {
            return calc(2 * p, l, mid, limit) + tree_va[p] - tree_va[2 * p];
        }
    }

    int query_mx(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree_mx[p];
        
        int res = -LNF; 
        int mid = (l + r) >> 1;
        
        if (x <= mid) res = max(res, query_mx(2 * p, l, mid, x, y));
        if (y >= mid + 1) res = max(res, query_mx(2 * p + 1, mid + 1, r, x, y));
        return res;
    }

    int query_first(int p, int l, int r, int x, int y, int val) {
        if (l > y || r < x || tree_mx[p] < val) return -1;
        if (l == r) return l;
        
        int mid = (l + r) >> 1;
        
        int res = query_first(2 * p, l, mid, x, y, val);
        if (res == -1) res = query_first(2 * p + 1, mid + 1, r, x, y, val);
        return res;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree_mx.assign(4 * n + 7, 0);
        tree_va.assign(4 * n + 7, 1);
    }

    void init(const vector<int>& arr) {
        build(1, 1, n, arr);
    }

    void update(int pos, int num) {
        if (pos > n || pos <= 0)  return;
        change(1, 1, n, pos, num);
    }

    int query(int p, int l, int r, int x, int y, int& mx) {
        if (x <= l && r <= y) {
            int res = calc(p, l, r, mx);
            mx = max(mx, tree_mx[p]);
            return res;
        }
        int mid = l + r >> 1;
        int res = 0;
        if (x <= mid) {
            res += calc(2 * p, l, mid, mx);
        }
        if (y >= mid + 1) {
            res += calc(2 * p + 1, mid + 1, r, mx);
        }
        return res;
    }
};


void solve(){
    int n, q;cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    SegmentTree st(n);
    st.init(arr);
    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            int pos, x;cin >> pos >> x;
            st.update(pos, x);
        } else {
            int l, r;cin >> l >> r;
            int mx = -LNF;
            cout << (r - l + 1 - (st.query(1, 1, n, l, r, mx))) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}