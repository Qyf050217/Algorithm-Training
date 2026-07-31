#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int N=2e5+100;
int a[N]={0},b[N];
vector<int>e[N];
void solve(){
    int n;
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=0;
        e[i].clear();
    }
    map<int, vector<int>> mp;
    for(int i=1;i<=n;i++)
    {
        int x=0;
        cin>>x;
        a[x]++;
        mx=max(mx,x);
        mp[x].push_back(i);
    }
    a[mx]--;
    for(int i=1;i<=mx;i++)
    {
        int u=max(mx-i+1,i);
        b[i]=u;
    }
    for(int i=1;i<mx;i++)
    {
        int u=max(mx-i+1,i);
        int v=max(mx-(i+1)+1,i+1);
        if(a[v]<=0)
        {
            cout<<"No\n";
            return;
        }
        a[v]--;
        e[i].push_back(i+1);
        
        //e[i+1].push_back(i);
    }
    int id=mx;
    for(int i=2;i<mx;i++)
    {
        int u=max(mx-i+1,i);
        while(a[u+1])
        {
            a[u+1]--;
            e[i].push_back(++id);
            b[id]=u+1;

        }
    }
    if(id<n)
    {
        cout<<"No\n";
    }
    else
    {
        cout<<"Yes\n";
        for(int i=1;i<=n;i++)
        {
            int x=b[i];
            b[i]=mp[b[i]].back();
            mp[x].pop_back();
        }
        for(int i=1;i<=n;i++)
        {
            for(int x:e[i])
            {

                cout<<b[i]<<' '<<b[x]<<'\n';
            }
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}