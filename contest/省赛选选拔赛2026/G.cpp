#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>

int x, y;
int dp[20][20][20];
string num;
int dfs(int idx, int cntX, int cntY, bool limit) {
    if (idx == num.size()) {
        return cntX > cntY;
    }
    if (!limit && dp[idx][cntX][cntY] != -1) return dp[idx][cntX][cntY];
    int upp = 9;
    if (limit) upp = num[idx] - '0';
    int res = 0;
    for (int i = 0; i <= upp; i++) {
        if (i == x) res += dfs(idx+1, cntX+1, cntY, limit && i == upp);
        else if (i == y) res += dfs(idx+1, cntX, cntY+1, limit && i == upp);
        else res += dfs(idx+1, cntX, cntY, limit && i == upp);
    }
    if (!limit) dp[idx][cntX][cntY] = res;
    return res;
}


int calc(int x) {
    memset(dp, -1, sizeof(dp));
    num = to_string(x);
    return dfs(0, 0, 0, 1);
}
void solve() {
    int l, r;cin >> l >> r;
    cin >> x >> y;
    if (x == y) {
        cout << 0 << endl;
        return;
    }
    cout << calc(r) - calc(l - 1) << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T;cin >> T;
    while (T--) solve();
}