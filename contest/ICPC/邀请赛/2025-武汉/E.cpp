#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define ll long long
const int N=3e5;
struct node{
    int v,id;
};
vector<node>e[N];
int cnt[N]={0};
//unordered_set<int>s;
//unordered_map<int,int>vis,vis2;
int s[N]={0},vis[N],vis2[N];
ll ans=0;
stack<pair<int,int>>sc;
int res = 0;
void dfs(int u,int fa)
{

    
    for(int i=cnt[u];i<e[u].size();i=cnt[u])
    {
        res++;
        int v=e[u][i].v;
        cnt[u]++;
        if(vis2[e[u][i].id])continue;
        vis2[e[u][i].id]=1;
        sc.push({u,e[u][i].id});
        s[u]=1;
        

        
        //cout<<u<<"   "<<v<<" "<<e[u][i].id<<'\n'; 
        
        if(s[v]==1)
        {
            //cout<<"-----\n";
            ans++;
            vis[e[u][i].id]=ans;
            //cout<<ans<<'\n';
            while(sc.size())
            {
                int x=sc.top().first;
                vis[sc.top().second]=ans;
                sc.pop();
                s[x]=0;
                if(x==v)
                break;
            }
        }
        if(cnt[v]<e[v].size())
        dfs(v,u);
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        e[u].push_back({v,i});
        e[v].push_back({u,i});
    }
    stack<int>sc;
    int x=m+1;
    for(int i=1;i<=n;i++)
    {
        if(e[i].size()%2)
        {
            if(sc.size()==0)
            sc.push(i);
            else
            {
                int u=sc.top();
                int v=i;
                e[u].push_back({v,x});
                e[v].push_back({u,x});
                x++;
                sc.pop();
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]<e[i].size())
        dfs(i,0);
    }
    //cout<<1<<'\n';
    for(int i=1;i<=m;i++)
    {

        cout<<vis[i]<<' ';
    }
    for(int i=0;i<=max(x,n);i++)
    {
        vis[i]=vis2[i]=s[i]=0;
    }
    cout<<'\n';
    ans=0;
    for(int i=1;i<=n;i++)
    {
        cnt[i]=0;
        e[i].clear();
    }
    //cout<<x<<'\n';
    //cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
}
// ac