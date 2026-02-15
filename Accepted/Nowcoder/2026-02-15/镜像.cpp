#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int Y = 1;
int vis[10000007];
void dijkstra(int st, int ed) {

}

int reserve(int x) {
    if (!(x % 10)) return -1;
    int res = 0;
    while (x) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}
int cnt(int x) {
    int res = 0;
    while (x) {
        x /= 10;
        res++;
    }
    return res;
}
void solve(){
    Y++;
    int a, b, k;cin >> a >> b >> k;
    int limit = pow(10, cnt(b));
    queue<PII> q;
    q.push({a, 0});
    while (q.size()) {
        auto [x, c] = q.front();q.pop();
        if (x == b) {
            cout << c << endl;
            return;
        }
        int nx = reserve(x);
        if (nx < limit && nx != -1 && vis[nx] != Y) {
            vis[nx] = Y;
            q.push({nx, c + 1});
        }
        if (x+k < limit && vis[x + k] != Y) {
            vis[x + k] = Y;
            q.push({x + k, c + 1});
        }
    }
    cout << -1 << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
