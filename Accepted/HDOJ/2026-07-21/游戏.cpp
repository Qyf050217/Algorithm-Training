#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int N=1e6+1;
int a[N]={0};
int n;

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==1)
    {
        cout<<"NO\n";
        return;
    }
    if(n==2)
    {
        cout<<"YES\n";
        return;
    }
    int x=0,y=0;
    if(n%2)
    {
        int f=0;//0 a先 1 b先
        for(int i=1;i<=n/2;i++)
        {
            x+=a[i];
            y+=a[n+1-i];
            if(x>y)
            {
                f=1;
            }
            else if(x<y)
            {
                f=0;
            }
        }
        if(x>y)
        {
            cout<<"YES\n";
        }
        else if(x<y)
        {
            cout<<"NO\n";
        }
        else
        {
            if(f==0)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
            
        }
        
    }
    else
    {
        a[1]+=a[2];
        for(int i=2;i<n;i++)
        {
            a[i]=a[i+1];
        }
        n--;
        int f=1;//0 a先 1 b先
        for(int i=1;i<=n/2;i++)
        {
            x+=a[i];
            y+=a[n+1-i];
            if(x>y)
            {
                f=1;
            }
            else if(x<y)
            {
                f=0;
            }
        }
        if(x>y)
        {
            cout<<"YES\n";
        }
        else if(x<y)
        {
            cout<<"NO\n";
        }
        else
        {
            if(f==0)
            {
                cout<<"NO\n";
            }
            else
            {
                cout<<"YES\n";
            }
            
        }
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
