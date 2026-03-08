#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>


void solve() {
    int n, k;cin >> n >> k;
    string s;
    if (k < n || k > n * 26) {
        cout << "Impossible";
        return;
    }

    int Z = 0;
    for (Z = 0; n - Z + Z * 26 < k; Z++);
    int sum = Z * 26 + (n - Z);
    int duo = sum - k;
    for (int i = 1; i <= n - Z; i++) cout << 'a';
    if (Z) cout << char('z' - duo);
    for (int i = 1; i < Z; i++) cout << 'z';
    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;//cin >> T;
    while (T--) solve();
}