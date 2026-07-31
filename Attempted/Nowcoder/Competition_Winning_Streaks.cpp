#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int k,x1,x2,y1,y2;
    cin>>k>>x1>>y1>>x2>>y2;
    int mn=(x2-x1+y2-y1)/(y2-y1+1);
    cout<<mn<<' ';
    int mx=mn;
    mx=max(mx,min(k-1,x2)-x1);

    if(y1>=k)
    {
        mx=min(mx,2ll);
    }
    else
    {
        y1=min(y2,k-1);
        if(y1!=y2)
        {
            mx=max(mx,min(k,x2)-x1);
        }
        else 
        {
            mx=max(mx,min(k+1,x2)-x1);
        }
    }
    cout<<mx<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}