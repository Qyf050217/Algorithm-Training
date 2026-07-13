#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int MOD=998244353;
int ksm(int x, int n) {
    int ans = 1;
    x  %= MOD;
    while (n) {
        if (n & 1) ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;
    }
    return ans;
}


void solve(){
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    priority_queue<int,vector<int>,greater<int>>q1;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        mp[b]+=a;
    }
    for(auto [l,r]:mp)
    {
        q1.push(l);
    }
    while(q1.size())
    {
        int x=q1.top();
        q1.pop();
        if(mp[x]>m)
        {
            if(mp[x+1]==0)
            {
                q1.push((x+1));
            }
            if((mp[x]-m)%2==0)
            {
                mp[x+1]+=(mp[x]-m)/2;
                mp[x]-=mp[x]-m;

            }
            else
            {
                mp[x+1]+=(mp[x]-m+1)/2;
                mp[x]-=mp[x]-m+1;
            }
        }
    }
    priority_queue<int>q2;
    for(auto [l,r]:mp)
    {
        if(r)
        q2.push(l);
    }
    int ans=0,b=0;
    while(q2.size())
    {
        int x=q2.top();
        q2.pop();
        if(b>=mp[x])
        {
            b-=mp[x];
        }
        else
        {
            ans+=ksm(2, x);
            ans%=MOD;
            b+=m-mp[x];
        }
        if(q2.size()&&b)
        {
            int y=x-q2.top();
            if(y>35)
            break;
            b*=1<<(y/2);
            if(b>2e9) break;
            y-=(y/2);
            b*=1<<y;
            if(b>2e9) break;
        }
    }
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
// ac