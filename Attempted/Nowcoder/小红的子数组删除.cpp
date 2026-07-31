#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int MAXN = 2e5 + 7;
vector<int> tree(4 * MAXN);

void change(int p, int l, int r, int x, int k) {
    if (l == r && l == x) {
        tree[p] += k;
        return;
    }

    int mid = l + r >> 1;
    if (mid <= x) change(2 * p, l, mid, x, k);
    else change(2 * p + 1, mid + 1, r, x, k);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}


int calc(int p, int l, int r, int k) { // 第 k 大
    if (l == r) return l;
    int mid = l + r >> 1;
    if (tree[mid] >= k) return calc(2 * p, l, mid, k);
    else return calc(2 * p + 1, mid + 1, r, k);
}


void solve(){
    int n, k, x;cin >> n >> k >> x;
    vector<int> arr(n + 1);
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }

    map<int, int> mp;
    int idx = 0;
    for (auto &i : st) mp[i] = ++idx;

    for (int i = k + 1; i <= n; i++) change(1, 1, n, mp[arr[i]], 1);

    int len = n - k;
    int a = (len + 1) / 2, b = (len + 1) / 2 + 1;
    int ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}