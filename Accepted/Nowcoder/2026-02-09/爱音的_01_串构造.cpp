#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int a, b;cin >> a >> b;
    int A = 0, B = 1;
    if (a > b) {
        swap(a, b);
        swap(A, B);
    }
    int k = b / (a + 1);
    int yu = b - (a + 1) * k;
    for (int i = 1; i <= a+1; i++) {
        for (int j = 1; j <= k; j++) cout << B;
        if (i <= yu) cout << B;
        if (i != a+1) cout << A;
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
