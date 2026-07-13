#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int N=55;
int a[N][N]={0};
void solve(){
    int n,x;
    cin>>n>>x;
    if(x<n||x>n*n-n+1)
    {
        cout<<"No\n";
        return;
    }
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            a[i][j]=0;
        }
    }
    map<int,int>vis;
    vis[x]=1;
    int y=n*n;
    a[1][1]=x;
    for(int i=2;i<=n;i++)
    {
        while(vis[y]) y--;
        a[i][i]=y;
        vis[y]=1;
    }
    y=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0)
            {
                while(vis[y]) y++;
                a[i][j]=y;
                vis[y]=1;
            }
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
// ac