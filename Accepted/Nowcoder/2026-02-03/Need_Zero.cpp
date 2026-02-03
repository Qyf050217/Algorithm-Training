#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    int p = n % 10;
    if (p == 0) {
        cout << 1;
        return;
    } else if (p == 1) {
        cout << 10;
    } else if (p == 2) {
        cout << 5;
    } else if (p == 3) {
        cout << 10;
    } else if (p == 4) {
        cout << 5;
    } else if (p == 5) {
        cout << 2;
    } else if (p == 6) {
        cout << 5;
    } else if (p == 7) {
        cout << 10;
    } else if (p == 8) {
        cout << 5;
    } else if (p == 9) {
        cout << 10;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
