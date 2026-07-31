#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
struct node{
    int bh,t1,v,t2,id;
    bool operator<(const node &my)const&{
        if(my.t2!=t2)
        return my.t2<t2;
        return my.t1<t1;
    }
};
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    priority_queue<int,vector<int>,greater<int>>q1;
    for(int i=1;i<=k;i++)
    {
        q1.push(1);
    }
    priority_queue<node>q2;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        q2.push({a,b,c,b,i});
    }
    map<int,int>mp,ans;
    while(q2.size())
    {
        node a=q2.top();
        q2.pop();
        //cout<<"---"<<a.id<<'\n';
        if(mp[a.bh]>a.t2)
        {
            a.t2=mp[a.bh];
            q2.push(a);
        }
        else
        {
            int x=q1.top();
            q1.pop();
            if(a.t2>=x)
            {
                ans[a.id]=a.t2;
                x=ans[a.id]+a.v;
                mp[a.bh]=x;
            }
            else if(a.t2<x)
            {
                a.t2=x;
                q2.push(a);
            }

            q1.push(x);
        }
        
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}