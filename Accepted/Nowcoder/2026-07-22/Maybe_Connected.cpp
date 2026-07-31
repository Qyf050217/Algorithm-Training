#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n,m;
    cin>>n>>m;
    if(m<=n-1)
    {
        int ans=(m-1)*m/2;
        cout<<ans<<'\n';
    }
    else
    {
        int ans=(n-2)*(n-1)/2-(m-n+1);
        cout<<ans<<'\n';
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
