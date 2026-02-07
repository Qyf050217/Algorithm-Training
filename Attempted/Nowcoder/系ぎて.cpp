#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, m;cin >> n >> m;
    vector<string> arr(n + 1);
    PII a1 = {0, 0};
    PII a2 = {0, 0};
    PII b1 = {0, 0};
    PII b2 = {0, 0};
    for (int i = 1; i <= n; i++) {
        string s;cin >> s;
        s = '#' + s;
        arr[i] = s;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == '1') {
                if (a1.first) a2 = {i, j};
                else a1 = {i, j};
            } else {
                if (b1.first) b2 = {i, j};
                else b1 = {i, j};
            }
        }
    }

    if (a1.first > a2.first) swap(a1, a2);
    if (b1.first > b2.first) swap(b1, b2);
    

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}