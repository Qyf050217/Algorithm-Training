#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define PPI pair<PII, int>

int d[3][2] = {{1, 0} , {0, 1}, {-1, 0}};
void solve(){
    int n;cin >> n;
    int res = (n - 1) + n / 5;
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
