#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define inv(x) (ksm(x, MOD - 2))
const int MOD = 998244353;
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

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int a[] = {1,2,3,4};
    map<int, int> cnt;
    int sum = 0;
    do{
        for(int i=0;i<4;i++) {
            cout<< a[i] << '*' << i + 1 << ' ';
            sum += a[i] * (i + 1);
            if (a[i] == 1) cnt[i + 1]++;
        }
        
    }while(next_permutation(a,a+4));

    for (auto &i : cnt) {
        cout << i.first << ' ' << i.second << endl;
    }
    // cout << 8 * inv(3) << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}