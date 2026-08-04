#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


typedef __int128 i128;
i128 x;
i128 a[200];
int b[200];
void insert(int s)
{
    for(int i=105;i>=0;i--)
    {
        if(x>>i&1)
        {
            if(a[i]==0)
            {
                a[i]=x;
                b[i]=s;
                return;
            }
            else
            {
                x^=a[i];
                s^=b[i];
            }
            
        }
    }
}
void solve(){
    for(int i=0;i<=111;i++)
    {
        a[i]=b[i]=0;
    }
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int c,s;
        cin>>c>>s;
        x=0;
        for(int j=1;j<=c;j++)
        {
            int y;
            cin>>y;
            x^=(i128)1<<y;
        }
        insert(s);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int c,s=0;
        cin>>c;
        x=0;
        for(int j=1;j<=c;j++)
        {
            int y;
            cin>>y;
            x^=(i128)1<<y;
        }
        for(int i=105;i>=0;i--)
        {
            if(x>>i&1)
            {
                if(a[i])
                {
                    x^=a[i];
                    s^=b[i];
                }
                else
                {
                    break;
                }
                
            }
        }
        if(x==0)
        {
            cout<<s<<'\n';
        }
        else
        {
            cout<<-1<<'\n';
        }
        
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1; cin >> T;
    while (T--) solve();
}
