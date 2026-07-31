/* 
01011011
01010101
00010101

01100100
00110010
00101110

10000100  132
01111000  120

    1010  10
00111100  60
00101010  42


*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int N=5e5+100;
int b[200]={0};
int a[N]={0};
int s=0;
void insert(int x)
{
    for(int i=40;i>=0;i--)
    {
        if(x>>i&1)
        {
            if(b[i])
            {
                x^=b[i];
            }
            else if((s>>i&1))
            {
                x^=1ll<<i;
            }
            else
            {
                //cout<<x<<'\n';
                b[i]=x;
                return;
            }
            
        }
    }
}
void solve(){
    int n;
    cin>>n;
    s=0;
    for(int i=0;i<=50;i++)
    {
        b[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s^=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        insert(a[i]);
    }
    int x=0,y=0;
    for(int i=40;i>=0;i--)
    {
        if((x>>i&1)==0)
        {
            if(b[i])
            {
                //cout<<x<<' '<<b[i]<<'\n';
                x^=b[i];      
                // cout<<b[i]<<'\n';
            }
        }
    }
    y=s^x;
    cout<<x+y<<'\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
