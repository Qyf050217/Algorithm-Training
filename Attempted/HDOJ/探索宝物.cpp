#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
const int N = 1e5+100;
const int MOD = 1e9 + 7;
#define inv(x) (ksm(x, MOD - 2))
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
int a[N];
typedef __int128 i128;
int cjp(int x)
{
    return (x%MOD+MOD)%MOD;
}
int db(int a1, int q, int n) {
    return a1 * (((1 - ksm(q, n) % MOD) + MOD) % MOD)%MOD * inv(((1 - q) % MOD + MOD) % MOD) % MOD;
}

int calc_c(int n,int q) {
    return ((((inv(q-1)*(n+1)%MOD-q*ksm(inv(q-1),2)%MOD)%MOD+MOD)%MOD*ksm(q,n+1)%MOD%MOD+q*ksm(inv(((q-1)+MOD)%MOD),2))%MOD+MOD)%MOD;
}
// int calc(int m, int k, int z, int c) {
//     int res = (c * inv(m) % MOD * db(1, z * inv(m) % MOD, k) % MOD + k * c % MOD * inv(m) % MOD * ksm(z, k) % MOD * inv(ksm(m, k) % MOD) % MOD) % MOD;
//     int xs = (1 - z * inv(m) % MOD + MOD) % MOD;
//     res = res * inv(xs) % MOD;
//     return res;
// }

// int calc(int n, int q) {
//     int res = (db(1, q, n) + n * ksm(q, n + 1) % MOD) % MOD;
//     res = (res * inv(((1 - q) % MOD + MOD)) % MOD) % MOD;
//     return res;
// }
void solve(){
    int n,m,c;
    cin>>n>>m>>c;
    int sum=0,x=0;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
        sum+=a[i];
        x+=i*a[i];
    }
    if(c>m)
    {
        cout<<0<<'\n';
        return;
    }
    int z=m+1,b=0;
    for(int i=0;i<=m;i++)
    {
        if(i)
        x-=sum-b;
        b+=a[i];  
        i128 y=c*sum;
        if(x<y)
        {
            z=i;
            break;
        }
    }
    int ans=0;
    x=0;
    for(int i=1;i<z;i++)
    {
        x+=a[i];
        int y=ksm(x,n)*ksm(inv(sum),n)-ksm(x-a[i],n)*ksm(inv(sum),n)+MOD;
        y%=MOD;
        ans+=y*(i-n*c);
        ans=(ans%MOD+MOD)%MOD;
    }

    if(x==sum)
    {
        cout<<ans%MOD<<'\n';
        return;
    }
    for(int i=z;i<=m;i++)
    {
        if(n>1)
        ans+=-calc_c(n,inv(sum)*x%MOD)*c%MOD*inv(x)%MOD*a[i]%MOD;
        else
        {
            ans+=-inv(sum)*c%MOD*a[i]%MOD;
        }
        
        ans=(ans%MOD+MOD)%MOD;
        ans+=i*db(a[i]*inv(sum)%MOD,x*inv(sum),n)%MOD;
        ans=(ans%MOD+MOD)%MOD;
        //cout<<i<<' '<<calc_c(n,inv(sum)*x%MOD)*c%MOD*inv(x)%MOD*a[i]%MOD%MOD<<'\n';
    }
    cout<<ans%MOD<<'\n';

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}