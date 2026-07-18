#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


const int maxN = 1.5e5 + 7;
vector<int> arr(maxN + 7);
vector<int> tree(4 * maxN + 7);
vector<int> lazy(4 * maxN + 7);

void build(int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
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

void solve() {
    int n;cin >> n;
    for (int i = 0; i <= 4*n + 7; i++) {
        lazy[i] = tree[i] = 0;
    }
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    map<int, vector<int>> mp;
    for (int i = 1; i <= n; i++) mp[arr[i]].push_back(i);

    int L, R;
    int ans = 0;
    for (int i = 1; i < n - 1; i++) {
        int x = arr[i];
        int idx = lower_bound(mp[x].begin(), mp[x].end(), i) - mp[x].begin();
        int sz = mp[x].size();

        if (sz >= 3) {
            if (idx == 0) {
                int a = mp[x][1] + 1;
                int b = mp[x].back();
                if (a <= b) change(1, 1, n, a, b, 1);
            } else if (idx < sz - 1) {
                int a = mp[x][idx] + 1;
                int b = mp[x][idx + 1]; 
                if (a <= b) change(1, 1, n, a, b, -1);
            }
        }

        if (i + 2 <= n) {
            int res = calc(1, 1, n, i + 2, n);
            if (res > ans) {
                ans = res;
                L = i + 1;
                R = query_first(1, 1, n, i + 2, n, res);
            }
        }

        // for (int i = 1; i <= n; i++) cout << calc(1, 1, n, i, i) << ' ';
        // cout << endl;
    }
    cout << ans << endl;
    cout << L << ' ' << R << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
