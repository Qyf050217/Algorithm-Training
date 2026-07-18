#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
#define N 10010
ll a[N]={0},vis1[N]={0},rt=0,b[N]={0},dp[N][N]={0},c[N]={0},dfn[N]={0};
unordered_set<ll>s;
ll ans=0;
vector<int>e[N];
vector<int>tree[N];
int cnt=0;
void dfs1(int u,int fa)
{
    b[u]=dfn[u]=++cnt;
    for(int v:e[u])
    {
        dfs1(v,u);
    }
}
void dfs2(int u,int fa)
{

    for(int v:e[u])
    {
        dfs2(v,u);
        b[u]=min(b[u],b[v]);
    }
    
}
void dfs3(int u,int fa)
{
    int x=0;
    dp[u][0]=1;
    for(int v:tree[u])
    {
        dfs3(v,u);
        for(int i=0;i<=x;i++)
        {
            if(dp[u][i])
            for(int j=0;j<=c[v];j++)
            {
                if(dp[v][j])
                {
                    dp[u][i+j]=1;
                    s.insert(i+j);
                }
            }
        }
        x+=c[v];
        c[u]+=c[v];
    }
    dp[u][c[u]]=1;
    s.insert(c[u]);

}
void solve()
{
    s.insert(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        cin>>x>>y;
        vis1[y]=1;
        e[x].push_back(y);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis1[i]==0)
        {
            rt=i;
            break;
        }
    }
    b[rt]=1;
    dfs1(rt,0);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        b[y]=b[x]=min(b[x],b[y]);
    }
    dfs2(rt,0); 
    for(int i=1;i<=n;i++)
    {
        for(int v:e[i])
        {
            if(b[v]!=b[i])
            {
                tree[b[i]].push_back(b[v]);
            }
            
        }
        c[b[i]]+=a[i];
    }
    dfs3(1,0);
    cout<<s.size()<<'\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}