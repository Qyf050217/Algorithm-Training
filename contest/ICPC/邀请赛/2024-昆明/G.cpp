#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
set<int>s;
void solve(){
    int n;
    cin>>n;
    if(n%4==0||n==1)
    {
        cout<<"impossible\n";
        return;
    }
    cout<<"1 0 ";
    for(int i=2;i<n;i++)
    {
        int x=i;
        if(x%4==3)
        {
            x++;
        }
        else if(x%4==0)
        {
            x--;
        }
        cout<<x<<' ';
    }
    cout<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
// ac