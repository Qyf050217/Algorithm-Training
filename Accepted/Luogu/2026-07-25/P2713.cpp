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

const int MAXN = 1e6 + 7;
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
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    
    vector<int> del(n + 1, 0);
    vector<LeftistHeap> heap(n + 1);

    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        heap[i].push({arr[i], i});
    }

    int q;cin >> q;
    while (q--) {
        char op;cin >> op;
        if (op == 'M') {
            int i, j;cin >> i >> j;
            if (del[i] || del[j]) continue;
            int i_fa = find(i);
            int j_fa = find(j);
            if (i_fa == j_fa) continue;

            heap[i_fa].join(heap[j_fa]);
            fa[j_fa] = i_fa;
        } else {
            int x;cin >> x;
            if (del[x]) {
                cout << 0 << endl;
                continue;
            }
            while (!heap[find(x)].empty()) {
                auto [val, idx] = heap[find(x)].top();
                if (del[idx]) {
                    heap[find(x)].pop();
                    continue;
                } else {
                    del[idx] = 1;
                    cout << val << endl;
                    break;
                }
            }

            if (heap[find(x)].empty()) {
                cout << 0 << endl;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
