#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

// ============================欧拉筛===========================
std::vector<int> minp, primes, phi;
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    phi.resize(n + 1);
    phi[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            phi[i] = i - 1;
        }
        
        for (auto p : primes) {
            if (i * p > n) break;
            minp[i * p] = p;
            if (p == minp[i]) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
}
bool isprime(int n) {
    return minp[n] == n;
}
// ==============================================================
// ==========================树剖================================
int MOD, n;
int tim = 0;
const int maxN = 1e6 + 7;
vector<int> adj[maxN];
int arr[maxN], val[maxN];
int fa[maxN], siz[maxN], zSon[maxN], dep[maxN];
int dfn[maxN], id[maxN], top[maxN];

void dfs_heavy(int x, int f, int h) {
    dep[x] = h; fa[x] = f; siz[x] = 1;
    for (auto &son : adj[x]) {
        if (son == f) continue;
        dfs_heavy(son, x, h+1);
        if (!zSon[x] || siz[zSon[x]] < siz[son]) zSon[x] = son;
        siz[x] += siz[son];
    }
}

void dfs_order(int x, int f) {
    dfn[x] = ++tim;
    arr[tim] = val[x];
    id[tim] = x;

    if (zSon[x]) {
        top[zSon[x]] = top[x];
        dfs_order(zSon[x], x);
    }
    for (auto &son : adj[x]) {
        if (son != f && son != zSon[x]) {
            top[son] = son;
            dfs_order(son, x);
        }
    }
}

int LCA(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        x = fa[top[x]];
    }
    return (dep[x] < dep[y] ? x : y);
}

int k_root(int x, int k) {
    if (dep[x] <= k) return 0;
    while (x) {
        int dist = dep[x] - dep[top[x]];
        if (k <= dist) {
            return id[dfn[x] - k]; 
        }
        k -= dist + 1;
        x = fa[top[x]];
    }
    return 0;
}

void init(int n) {
    tim = 0;
    
    for (int i = 0; i <= n; ++i) {
        adj[i].clear();
        zSon[i] = 0;
        // 理论上不需要清空
        // top[i] = dfn[i] = fa[i] = dep[i] = siz[i] = arr[i] = rnk[i] = 0;
    }
}

void build(int root) {
    dfs_heavy(root, 0, 1);
    top[root] = root;
    dfs_order(root, 0);
}
// ==========================================================================


unordered_map<int, vector<PII>> pri; // 质数 - {{pos1, cnt1}, {pos2, cnt2}, ......}
unordered_map<int, vector<int>> sum;
int xc(int u, int v, int p) {

}


void solve(){
    cin >> n;
    cin >> arr[1];
    vector<vector<int>> op(n + 1, vector<int>(3));
    

    for (int i = 2; i <= n; i++) {
        int u, v, x;cin >> x >> u >> v;
        op[i][0] = u;
        op[i][1] = v;
        op[i][2] = x;
        adj[v].push_back(i);
        adj[i].push_back(v);
    }

    build(1);

    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    sieve(1e6 + 7);
    int T = 1;//cin >> T;
    while (T--) solve();
}