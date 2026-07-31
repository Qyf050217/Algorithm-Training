#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
constexpr int N = 1e5+100;
int a[N]={0},dp[N]={0};
void solve(){
    // int n;
    // cin>>n;
    // for(int i=1;i<=n;i++)
    // {
    //     cin>>a[i];
    //     dp[i]=0;
    // }
    // a[n+1]=0;
    // a[0]=0;
    // dp[1]=a[2];
    // for(int i=2;i<=n;i++)
    // {
    //     dp[i]=min(dp[i-1]+a[i+1],dp[i-2]+max(a[i-1],a[i+1]));
    //     if(i>=2)
    //     {
    //         dp[i]=min(dp[i-3]+max(a[i-1],a[i+1])+min(a[i-1],a[i-2]),dp[i]);
    //     }
    // }
    // cout<<dp[n]<<'\n';

    // int n;cin >> n;
    // vector<int> arr(n + 7);
    // for (int i = 1; i <= n; i++) cin >> arr[i];
    // dp[1] = a[2];
    // for (int i = 2; i <= n; i++) {
    //     dp[i] = min(dp[i - 2] + a[i], dp[i - 1] + a[i + 1]);
    // }
    // cout << dp[n] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}