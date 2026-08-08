#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

class SegmentTree {
private:
    int n;
    vector<int> tree_sum;
    vector<int> tree_max;

    void build(int p, int l, int r, const vector<int>& arr) {
        if (l == r) {
            tree_sum[p] = arr[l];
            tree_max[p] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * p, l, mid, arr);
        build(2 * p + 1, mid + 1, r, arr);
        
        tree_sum[p] = (tree_sum[2 * p] + tree_sum[2 * p + 1]);
        tree_max[p] = max(tree_max[2 * p], tree_max[2 * p + 1]);
    }

    void change(int p, int l, int r, int x, int y) {
        if (tree_max[p] <= 1) return;
        if (x <= l && r <= y) {
            if (l == r) {
                tree_max[p] = sqrt(tree_max[p]);
                tree_sum[p] = tree_max[p];
                return;
            }
        }

        int mid = (l + r) >> 1;
        if (x <= mid) change(2 * p, l, mid, x, y);
        if (y >= mid + 1) change(2 * p + 1, mid + 1, r, x, y);
        
        tree_max[p] = max(tree_max[2 * p], tree_max[2 * p + 1]);
        tree_sum[p] = (tree_sum[2 * p] + tree_sum[2 * p + 1]);
    }

    int calc_sum(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree_sum[p];
        
        int res = 0;
        int mid = (l + r) >> 1;
        if (x <= mid) res += calc_sum(2 * p, l, mid, x, y);
        if (y >= mid + 1) res += calc_sum(2 * p + 1, mid + 1, r, x, y);
        return res;
    }

public:
    SegmentTree(int size) {
        n = size;
        tree_sum.assign(4 * n + 7, 0);
        tree_max.assign(4 * n + 7, 0);
    }

    void init(const vector<int>& arr) {
        build(1, 1, n, arr);
    }

    void update(int x, int y) {
        if (x > y) return;
        change(1, 1, n, x, y);
    }

    int query_sum(int x, int y) {
        if (x > y) return 0;
        return calc_sum(1, 1, n, x, y);
    }
};

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    SegmentTree st(n);
    st.init(arr);

    int q;cin >> q;
    while (q--) {
        int op, l, r;cin >> op >> l >> r;
        if (l > r) swap(l, r);
        if (op == 0) {
            st.update(l, r);
        } else {
            cout << st.query_sum(l, r) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
