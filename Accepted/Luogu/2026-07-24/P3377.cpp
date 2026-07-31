#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


const int MAXN = 1e5 + 7;
struct Node {
    int val, lc, rc, dist;
} t[MAXN];
int node_cnt = 0;

// 左偏树
struct LeftistHeap {
    int root;

    LeftistHeap() : root(0) {}

    // 核心的合并函数
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        // if (t[x].val < t[y].val) swap(x, y); // 大根堆
        if (t[x].val > t[y].val || (t[x].val == t[y].val && x > y)) swap(x, y); // 小根堆
        t[x].rc = merge(t[x].rc, y);
        
        if (t[t[x].lc].dist < t[t[x].rc].dist) {
            swap(t[x].lc, t[x].rc);
        }
        t[x].dist = t[t[x].rc].dist + 1;
        return x;
    }

    void push(int val) {
        t[++node_cnt] = {val, 0, 0, 1}; // 创建新节点  外节点 dist 初始为 1
        root = merge(root, node_cnt);
    }

    void pop() {
        if (root) {
            root = merge(t[root].lc, t[root].rc);
        }
    }

    int top() {
        return t[root].val;
    }

    bool empty() {
        return root == 0;
    }

    // 合并另一个堆
    void join(LeftistHeap& other) {
        root = merge(root, other.root);
        other.root = 0; // 另一个堆被掏空
    }
};

vector<int> fa(MAXN);

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve(){
    int n, q;cin >> n >> q; 
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<bool> del(n + 1, 0);
    LeftistHeap heap[n + 1];
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        heap[i].push(arr[i]);
    }
    while (q--) {
        int op;cin >> op;
        if (op == 1) {
            int x, y;cin >> x >> y;
            if (del[x] || del[y]) continue;
            int x_fa = find(x);
            int y_fa = find(y);
            if (x_fa == y_fa) continue;
            fa[x_fa] = y_fa;
            heap[y_fa].join(heap[x_fa]);
        } else {
            int x;cin >> x;
            if (del[x]) {
                cout << -1 << endl;
                continue;
            }
            int x_fa = find(x);
            cout << heap[x_fa].top() << endl;
            del[heap[x_fa].root] = true; 
            heap[x_fa].pop();
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
