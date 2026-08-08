#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n;
const int MAXN = 2e5 + 7;
vector<int> arr(MAXN);
vector<int> adj[MAXN];
vector<int> dp(MAXN);
int deep[MAXN];
int ans=0;
void dfs(int u) {
    ans-=deep[u]*arr[u];
    //cout<<u<<" "<<deep[u]*arr[u]<<'\n';
    for(int v:adj[u])
    {
        deep[v]=deep[u];
        if(v>u)
        deep[v]++;
        dfs(v);
    }
}



void solve(){
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        dp[i] = 0;
        deep[i]=0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (i != 1) sum += arr[i];
    }

    for (int i = 2; i <= n; i++) {
        int f;cin >> f;
        adj[f].push_back(i);
    }
    if (sum > 0) cout << 1 << endl;
    else if (sum < 0) cout << -1 << endl;
    else
    {
        ans=0;
        dfs(1);
        
        if (ans > 0) cout << 1 << endl;
        else if (ans < 0) cout << -1 << endl;
        else
        {
            cout << 0 << endl;
        }
        
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
