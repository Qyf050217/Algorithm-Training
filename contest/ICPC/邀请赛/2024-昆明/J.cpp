#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PPI pair<PII, int>
const int maxN = 5e5 + 7;
unordered_map<int, vector<int>> company;      // 公司的车票是哪几张
unordered_map<int, vector<int>> k_tree;       // 每个公司对应的车票写一个区间max
vector<pair<int, PII>> adj[maxN];   // {v,{c, l}}
vector<int> len(maxN);              // 每张车票的距离
vector<int> belong(maxN);           // 车票归属公司

// vec - 第几张车票
// len - 车票对应的可行使长度
// c   - 哪家公司
void build(int p, int l, int r, vector<int> &vec, int c) {
    if (l == r) {
        int ticket = vec[l];
        int x = len[ticket];
        k_tree[c][p] = x;
        return;
    }
    int mid = l + r >> 1;
    build(2 * p, l, mid, vec, c);
    build(2 * p + 1, mid+1, r, vec, c);
    k_tree[c][p] = max(k_tree[c][2 * p], k_tree[c][2 * p + 1]);
}

// [x, y] 区间内的最大值
int calc(int p, int l, int r, int x, int y, int c) {
    if (x <= l && r <= y) return k_tree[c][p];
    int mid = l + r >> 1;
    int res = 0;
    if (x <= mid) res = max(res, calc(2*p, l, mid, x, y, c));
    if (y >= mid + 1) res = max(res, calc(2*p+1, mid+1, r, x, y, c));
    return res;
}

// [x, y] 区间内的大于aid的 **下标**
// todo: 进函数前记得check有无符合要求的下标
int ef(int p, int l, int r, int ql, int qr, int val, int c) {
    if (l > qr || r < ql || k_tree[c][p] < val) return -1;

    if (l == r) return l;

    int mid = l + r >> 1;
    int res = ef(2 * p, l, mid, ql, qr, val, c);
    if (res == -1) {
        res = ef(2 * p + 1, mid + 1, r, ql, qr, val, c);
    }
    return res;
}


void dijkstra(int s, int n) {
    vector<PII> dis(n + 7, {LNF, LNF});    // {ticketNo, usedDis}
    vector<char> vis(n + 7, 0);
    priority_queue<PPI, vector<PPI>, greater<PPI>> pq;  // {{ticketNo, usedDis}, u}
    dis[s] = {0, 0};
    pq.push({{0, 0}, s});

    while (pq.size()) {
        int ticket = pq.top().first.first;
        int used = pq.top().first.second;
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto &[v, cl] : adj[u]) {
            if (vis[v]) continue;
            int c = cl.first, l = cl.second;

            if (c == belong[ticket] && len[ticket] >= used + l) {
                if (dis[v].first > ticket || (dis[v].first == ticket && dis[v].second > used + l)) {
                    dis[v] = {ticket, used + l};
                    pq.push({dis[v], v});
                    continue;
                }
            }
            
            if (!company.count(c)) continue;

            auto it = upper_bound(company[c].begin() + 1, company[c].end(), ticket);
            if (it == company[c].end()) continue;
            int L = it - company[c].begin();

            int vn = company[c].size() - 1;
            if (calc(1, 1, vn, L, vn, c) < l) continue;
            int idx = ef(1, 1, vn, L, vn, l, c);
            int newTicket = company[c][idx];
            if (dis[v].first > newTicket || (dis[v].first == newTicket && dis[v].second > l)) {
                dis[v] = {newTicket, l};
                pq.push({dis[v], v});
                continue;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i].first != LNF) cout << 1;
        else cout << 0;
    }
    cout << endl;
}


void solve(){
    int n, m, k;cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int u, v, c, l;cin >> u >> v >> c >> l;
        adj[u].push_back({v, {c, l}});
        adj[v].push_back({u, {c, l}});
    }
    for (int i = 1; i <= k; i++) {
        int c, l;cin >> c >> l;
        len[i] = l;
        belong[i] = c;
        if (company.count(c)) company[c].push_back(i);
        else {
            company[c].push_back(0);
            company[c].push_back(i);
        }
    }
    for (auto &[c, vec] : company) {
        int vn = vec.size() - 1;
        k_tree[c].resize(4 * vn + 7);
        build(1, 1, vn, vec, c);
    }
    dijkstra(1, n);

    company.clear();
    k_tree.clear();
    for (int i = 1; i <= n; i++) adj[i].clear();
}   

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
// ac