#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;
    cin>>s;
    int f=0;
    int n=s.size();
    int x=1;
    int ans=0;
    vector<int>v;
    for(int i=1;i<n;i++)
    {
        if(s[i]==s[i-1])
        {
            x++;
        }
        else
        {
            v.push_back(x);
            x=1;
        }
    }
    if(s[0]==s[n-1])
    {
        if(v.size())
        {
            v[0]+=x;
        }
        else
        {
            v.push_back(x);
        }
    }
    else
    {
        v.push_back(x);
        
    }
    
    for(int x:v)
    {
        ans+=x/2;
        if(x%2==0&&v.size()!=1)
        {
            f=1;
        }
    }
    cout<<ans-f<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}