#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string s;cin >> s;
    string b = s;
    reverse(b.begin(), b.end());
    if (s > b) cout << "left";
    else if (b > s) cout << "right";
    else cout << "equal";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
