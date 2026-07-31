#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


const int MAXN = 1e4 + 7;
vector<int> tree(4 * MAXN);

void change(int p, int l, int r, int x, int k) {
    if (l == r && l == x) {
        tree[p] += k;
        return;
    }

    int mid = l + r >> 1;
    if (x <= mid) change(2 * p, l, mid, x, k);
    else change(2 * p + 1, mid + 1, r, x, k);
    tree[p] = tree[2 * p] + tree[2 * p + 1];
}


int calc(int p, int l, int r, int k) { // 第 k 小
    if (l == r) return l;
    int mid = l + r >> 1;
    if (tree[2 * p] >= k) return calc(2 * p, l, mid, k);
    else return calc(2 * p + 1, mid + 1, r, k - tree[2 * p]);
}

void solve(){
    int n, k;cin >> n >> k;
    
    vector<int> arr(n + 1);
    
    set<int> st;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        st.insert(arr[i]);
    }
    if (k > st.size()) {
        cout << "NO RESULT" << endl;
        return;
    }
    map<int, int> a_b, b_a;
    int idx = 0;
    for (auto &i : st) {
        a_b[i] = ++idx;
        b_a[idx] = i;
    }
    // cout << idx << endl;
    // for (auto &i : a_b) {
    //     cout << i.first << ' ' << i.second << endl;
    // }
    for (auto &i : st) change(1, 1, idx, a_b[i], 1);

    cout << b_a[calc(1, 1, idx, k)] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
