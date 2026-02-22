#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
int n;
const int maxN = 2e5 + 7;
vector<int> val(maxN);
vector<int> sum(maxN);
vector<int> adj[maxN];
vector<int> height(maxN);
vector<int> ans(maxN);
vector<int> add(maxN);

vector<int> mxDep(maxN);
vector<int> cxDep(maxN);
vector<int> zSon(maxN);

void pre(int x, int fa, int h) {
    height[x] = h;
    mxDep[x] = h;
    cxDep[x] = h;
    zSon[x] = 0;
    
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        pre(son, x, h + 1);
        sum[x] += sum[son];
        val[x] += val[son] + sum[son];
        if (mxDep[son] > mxDep[x]) {
            cxDep[x] = mxDep[x];
            mxDep[x] = mxDep[son];
            zSon[x] = son;
        } else if (mxDep[son] > cxDep[x]) {
            cxDep[x] = mxDep[son];
        }
    }
}

void dfs(int x, int fa) {
    int mxAdd = 0;
    for (auto &son : adj[x]) {
        if (son == fa) continue;
        dfs(son, x); 
        mxAdd = max(mxAdd, add[son]);
        int MD = (son == zSon[x]) ? cxDep[x] : mxDep[x];
        mxAdd = max(mxAdd, sum[son] * (MD - height[x]));
    }
    
    add[x] = mxAdd;
    ans[x] = val[x] + add[x];
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        val[i] = 0;
        add[i] = 0;
    }
    for (int i = 1; i <= n; i++) cin >> sum[i];
    for (int i = 1; i < n; i++) {
        int u, v;cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pre(1, 0, 1);
    dfs(1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
