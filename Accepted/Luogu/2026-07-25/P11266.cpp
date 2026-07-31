#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct Element {
    int val1, val2;

    // 重载符号
    bool operator>(const Element& other) const {
        if (val1 != other.val1) return val1 > other.val1;
        return val2 > other.val2;
    }
    
    bool operator<(const Element& other) const {
        if (val1 != other.val1) return val1 < other.val1;
        return val2 < other.val2;
    }
    
    bool operator==(const Element& other) const {
        return val1 == other.val1 && val2 == other.val2;
    }
};

const int MAXN = 2e6 + 7;
struct Node {
    Element data; 
    int lc, rc, dist, sz;
} t[MAXN];
int node_cnt = 0;

// 左偏树
struct LeftistHeap {
    int root;

    LeftistHeap() : root(0) {}

    // 核心的合并函数
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        
        if (t[x].data > t[y].data || (t[x].data == t[y].data && x > y)) swap(x, y); // 小根堆
        // if (t[x].data < t[y].data || (t[x].data == t[y].data && x < y)) swap(x, y); // 大根堆
        t[x].rc = merge(t[x].rc, y);
        
        if (t[t[x].lc].dist < t[t[x].rc].dist) {
            swap(t[x].lc, t[x].rc);
        }
        t[x].dist = t[t[x].rc].dist + 1;
        t[x].sz = t[t[x].lc].sz + t[t[x].rc].sz + 1;
        return x;
    }

    void push(Element d) {
        t[++node_cnt] = {d, 0, 0, 1, 1}; // 创建新节点，外节点 dist 为 1, sz 为 1
        root = merge(root, node_cnt);
    }

    void pop() {
        if (root) {
            root = merge(t[root].lc, t[root].rc);
        }
    }

    Element top() {
        return t[root].data;
    }

    bool empty() {
        return root == 0;
    }

    void join(LeftistHeap& other) {
        root = merge(root, other.root);
        other.root = 0; 
    }
    
    int size() {
        return t[root].sz;
    }
};


vector<int> fa(MAXN);
int find(int x) {
    if (x == fa[x]) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve(){
    int n, q;cin >> n >> q;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> del(n + 1);
    vector<LeftistHeap> heap(n + 1);

    for (int i = 1; i <= n; i++) {
        heap[i].push({arr[i], i});
        fa[i] = i;
    }
    while (q--) {
        int op;cin >> op;
        if (op == 0) {
            int x, y;cin >> x >> y;
            del[y] = 1;
        } else if (op == 1) {
            int x;cin >> x;
            int x_fa = find(x);
            while (true) {
                int val = heap[x_fa].top().val1;
                int idx = heap[x_fa].top().val2;
                
                if (del[idx] || val != arr[idx]) {
                    heap[x_fa].pop();
                } else {
                    cout << val << endl;
                    break;
                }
            }
        } else if (op == 2) {
            int x, y;cin >> x >> y;
            int x_fa = find(x);
            int y_fa = find(y);
            if (x_fa == y_fa) continue;
            heap[x_fa].join(heap[y_fa]);
            fa[y_fa] = x_fa;
        } else {
            int x, y, z;cin >> x >> y >> z;
            arr[y] = z;
            heap[find(x)].push({arr[y], y});
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
