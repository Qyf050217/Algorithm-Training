#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


struct Element {
    int val, idx;

    // 重载符号
    bool operator>(const Element& other) const {
        if (val != other.val) return val > other.val;
        return idx < other.idx;
    }
    
    bool operator<(const Element& other) const {
        if (val != other.val) return val < other.val;
        return idx > other.idx;
    }
    
    bool operator==(const Element& other) const {
        return val == other.val && idx == other.idx;
    }
};

const int MAXN = 4e6 + 7;
struct Node {
    Element data; 
    int lc, rc, dist, sz;
} t[MAXN];
int node_cnt = 0;

// 左偏树
struct LeftistHeap {
    int root;

    LeftistHeap() : root(0) {}

    // 合并函数
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        
        // if (t[x].data > t[y].data || (t[x].data == t[y].data && x > y)) swap(x, y); // 小根堆
        if (t[x].data < t[y].data || (t[x].data == t[y].data && x < y)) swap(x, y); // 大根堆
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

int w, k;
void solve(){
    node_cnt = 0;
    int n, m;cin >> n >> m;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<LeftistHeap> heap(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
        heap[i].push({arr[i], i});
    }

    vector<int> del(n + 1);
    while (m--) {
        int op;cin >> op;
        if (op == 2) {
            int A;cin >> A;
            del[A] = 1;
        } else if (op == 3) {
            int A, B;cin >> A >> B;
            int A_fa = find(A);
            
            auto &hp = heap[A_fa];
            while (!hp.empty() && del[hp.top().idx]) {
                hp.pop();
            }
            if (hp.empty()) continue;
            auto [val, idx] = hp.top();
            hp.pop();
            hp.push({max(val - B, 0LL), idx});
        } else {
            int A, B;cin >> A >> B;
            int A_fa = find(A);
            int B_fa = find(B);
            if (A_fa == B_fa) continue;
            heap[A_fa].join(heap[B_fa]);
            fa[B_fa] = A_fa;
        }
    }

    int mx = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i != find(i)) continue;
        while (!heap[i].empty()) {
            if (del[heap[i].top().idx]) {
                heap[i].pop();
            } else {
                break;
            }
        }
        if (heap[i].empty()) continue;
        sum += heap[i].top().val;
        mx = max(mx, heap[i].top().val);
    }

    if (w == 2) sum -= mx;
    else if (w == 3) sum += mx;

    if (sum == 0) cout << "Gensokyo 0\n";
    else if (sum <= k) cout << "Heaven " << sum << "\n";
    else cout << "Hell " << sum << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    cin >> w >> k;
    while (T--) solve();
}
