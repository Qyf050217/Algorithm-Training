#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int MAXN = 5e6 + 5;
struct Node {
    int val, lc, rc, dist,id;
} t[MAXN];
int node_cnt = 0;
int deep[MAXN];
// 左偏树
struct LeftistHeap {
    int root;

    LeftistHeap() : root(0) {}

    // 核心的合并函数
    int merge(int x, int y) {
        if (!x || !y) return x + y;
        if (t[x].val < t[y].val) swap(x, y); // 大根堆
        // if (t[x].val > t[y].val || (t[x].val == t[y].val && x > y)) swap(x, y); // 小根堆
        t[x].rc = merge(t[x].rc, y);
        
        if (t[t[x].lc].dist < t[t[x].rc].dist) {
            swap(t[x].lc, t[x].rc);
        }
        t[x].dist = t[t[x].rc].dist + 1;
        return x;
    }

    void push(int val,int id) {
        t[++node_cnt] = {val, 0, 0, 1,id}; // 创建新节点  外节点 dist 初始为 1
        root = merge(root, node_cnt);
    }

    void pop() {
        if (root) {
            root = merge(t[root].lc, t[root].rc);
        }
    }

    int top() {
        return t[root].id;
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
LeftistHeap heap[MAXN];
vector<int>e[MAXN],tree[MAXN];
void dfs1(int u)
{
    for(int v:e[u])
    {
        deep[v]=deep[u]+1;
        dfs1(v);
    }
}
void dfs2(int u)
{
    for(int v:e[u])
    {
        dfs2(v);
    }
    if(heap[u].empty())
    {
        if(u==1) return;
        tree[1].push_back(u);
    }
    else
    {
        int x=heap[u].top();
        tree[x].push_back(u);
        while(!heap[u].empty()&&x==heap[u].top())
        heap[u].pop();
        heap[x].join(heap[u]);
    }
    
}
int ans=0;
void dfs3(int u,int d)
{
    ans+=d;

    for(int v:tree[u])
    {
        dfs3(v,d+1);
    }
}
void solve(){
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;i++)
    {
        int fa;
        cin>>fa;
        e[fa].push_back(i);
    }
    dfs1(1);
    
    for(int i=1;i<=q;i++)
    {
        int u,v;
        cin>>u>>v;
        heap[u].push(deep[v],v);
    }
    dfs2(1);
    
    dfs3(1,0);
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
