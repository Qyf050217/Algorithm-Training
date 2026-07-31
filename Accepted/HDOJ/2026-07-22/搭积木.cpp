#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
vector<int> a(maxN), b(maxN);
vector<int> fa(maxN);
vector<int> sumA(maxN), sumB(maxN);
vector<int> adj[maxN];
vector<int> dp(maxN, 0);


struct node {
    int x, y;
    int id;
};
struct cmp {
    bool operator()(const node& a, const node& b) {
        return (__int128)a.x * b.y < (__int128)b.x * a.y;
    }
};

int find(int x) {
    if (fa[x] == x) return x;
    fa[x] = find(fa[x]);
    return fa[x];
}

void solve(){
    int n; cin >> n;
    
    for (int i = 0; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<int> father(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> father[i];
    }
    
    priority_queue<node, vector<node>, cmp> pq;
    
    sumA[0] = 0; sumB[0] = 0;
    for (int i = 1; i <= n; i++) {
        sumA[i] = a[i];
        sumB[i] = b[i];
        pq.push({a[i], b[i], i});
    }

    int res = 0;
    
    while (pq.size()) {
        auto cur = pq.top(); pq.pop();
        int cur_a = cur.x, cur_b = cur.y;
        int idx = cur.id;
        
        if (find(idx) != idx || sumA[idx] != cur_a || sumB[idx] != cur_b) continue;
        
        int father_block = find(father[idx]);
        
        res += cur_a * sumB[father_block];
        
        fa[idx] = father_block;
        sumA[father_block] += cur_a;
        sumB[father_block] += cur_b;
        
        if (father_block != 0) {
            pq.push({sumA[father_block], sumB[father_block], father_block});
        }
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
