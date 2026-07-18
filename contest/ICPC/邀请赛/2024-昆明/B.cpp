#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int>v;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        ans+=a/k;
        a%=k;
        if(a)
        v.push_back(k-a);

    }
    int m;
    cin>>m;
    sort(v.begin(),v.end());
    for(int x:v)
    {
        if(m>=x)
        {
            m-=x;
            ans++;
        }
    }
    ans+=m/k;
    cout<<ans<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}