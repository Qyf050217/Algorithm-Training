#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

struct Element {
    int val1;

    // 重载符号
    bool operator>(const Element& other) const {
        return val1 > other.val1;
    }
    
    bool operator<(const Element& other) const {
        return val1 < other.val1;
    }
    
    bool operator==(const Element& other) const {
        return val1 == other.val1;
    }
};

const int MAXN = 1e5 + 7;
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


void solve(){
    int n;cin >> n;
    LeftistHeap heap;
    while (n--) {
        int op;cin >> op;
        if (op == 1) {
            int x;cin >> x;
            heap.push({x});
        } else if (op == 2) {
            cout << heap.top().val1 << endl;
        } else heap.pop();
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
