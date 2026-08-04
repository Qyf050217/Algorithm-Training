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
    vector<int> tree;

    void change(int p, int l, int r, int pos, int num) {
        if (l == r && pos == l) {
            tree[p] = max(tree[p], num);
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) change(2 * p, l, mid, pos, num);
        if (pos >= mid + 1) change(2 * p + 1, mid + 1, r, pos, num);
        
        tree[p] = max(tree[2 * p], tree[2 * p + 1]);
    }

    int calc(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) return tree[p];
        int res = -LNF; 
        int mid = (l + r) >> 1;
        if (x <= mid) res = max(res, calc(2 * p, l, mid, x, y));
        if (y >= mid + 1) res = max(res, calc(2 * p + 1, mid + 1, r, x, y));
        return res;
    }
public:
    // 构造函数
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n + 7, 0);
    }

    void update(int pos, int num) {
        change(1, 1, n, pos, num);
    }

    // 区间最大值查询：查询 [x, y] 区间内的最大值
    int query_max(int x, int y) {
        if (x > y) return -LNF;
        return calc(1, 1, n, x, y);
    }
};


vector<int> all; // 离散化
int get_id(int x){
    return lower_bound(all.begin(), all.end(),x) - all.begin() + 1;
}

void solve(){
    int n, q;cin >> n >> q;
    vector<pair<PII, int>> arr(n + 1);
    all.clear();
    for (int i = 1; i <= n; i++) {
        int l, r;cin >> l >> r;
        arr[i] = {{l, r}, r - l + 1};

        all.push_back(l);
        all.push_back(r);
    }
    vector<pair<PII, int>> query(q + 1);
    for (int i = 1; i <= q; i++) {
        int L, R;cin >> L >> R;
        query[i] = {{L, R}, i};

        all.push_back(L);
        all.push_back(R);
    }

    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    int mx = all.size();


    for (int i = 1; i <= n; i++) {
        arr[i].first.first = get_id(arr[i].first.first);
        arr[i].first.second = get_id(arr[i].first.second);
    }
    for (int i = 1; i <= q; i++) {
        query[i].first.first = get_id(query[i].first.first);
        query[i].first.second = get_id(query[i].first.second);
    }

    ranges::sort(arr.begin() + 1, arr.end(), greater<pair<PII, int>>());
    ranges::sort(query.begin() + 1, query.end(), greater<pair<PII, int>>());

    int idx = 1;
    SegmentTree st(mx);
    vector<int> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        int L = query[i].first.first;
        int R = query[i].first.second;
        while (idx <= n && arr[idx].first.first >= L) {
            st.update(arr[idx].first.second, arr[idx].second);
            idx++;
        }

        ans[query[i].second] = st.query_max(1, R);
    }

    for (int i = 1; i <= q; i++) cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
