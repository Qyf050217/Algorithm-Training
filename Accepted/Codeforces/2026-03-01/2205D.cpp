#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 5e5 + 7;
vector<int> tree(4 * maxN);
vector<int> arr(maxN);
vector<int> pos(maxN);
int n;
void build (int p, int l, int r) {
    if (l == r) {
        tree[p] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build (2*p, l, mid);
    build (2*p+1, mid+1, r);
    tree[p] = max(tree[2*p], tree[2*p+1]);
}

int calc (int p, int l, int r, int x, int y) {
    if (x<=l && r<=y) {
        return tree[p];
    }
    int res = 0;
    int mid = (l + r) / 2;
    if (x <= mid) res = max(res, calc(2*p, l, mid, x, y));
    if (y >= mid+1) res = max(res, calc(2*p+1, mid+1, r, x, y));
    return res;
}

int query(int l, int r) {
    if (l > r) return 0;
    if (l == r) return 1;
    int mx = calc(1, 1, n, l, r);
    int idx = pos[mx];

    if (idx == l) {
        return 1 + query(l + 1, r);
    } else if (idx == r) {
        return 1 + query(l, r - 1);
    } else {
        return 1 + max(query(l, idx - 1), query(idx + 1, r));
    }
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        pos[arr[i]] = i;
    }
    cout << n - query(1, n) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
