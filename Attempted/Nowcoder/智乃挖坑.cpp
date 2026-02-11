#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<PII> op(2e5 + 7);
vector<int> k(2e5 + 7);
bool check(int x) {
    for (int i = 1; i <= x + 7; i++) k[i] = 0;
    for (int i = 1; i <= x; i++) {
        auto [p, f] = op[i];
    }
}

void solve(){
    int n, m, h;cin >> n >> m >> h;
    for (int i = 1; i <= m; i++) {
        int p, f;cin >> p >> f;
        op[i] = {p, f};
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}