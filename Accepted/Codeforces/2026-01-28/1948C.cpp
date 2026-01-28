#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 2e5 + 7;
int n;
vector<string> arr(3);
vector<vector<int>> dp(3, vector<int>(maxN + 1));
vector<vector<int>> vis(3, vector<int>(maxN + 1));
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isValid(int x, int y) {
    return x >= 1 && x <= 2 && y >= 1 && y <= n;
}

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        dp[1][i] = dp[2][i] = vis[1][i] = vis[2][i] = 0;
    }
    cin >> arr[1] >> arr[2];
    arr[1] = "#" + arr[1];
    arr[2] = "#" + arr[2];
    dp[1][1] = 1;
    queue<PII> q;
    q.push({1, 1});
    while (q.size()) {
        auto [x, y] = q.front();q.pop();
        if (vis[x][y]) continue;
        vis[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx, ny)) {
                if (arr[nx][ny] == '<' && isValid(nx, ny-1)) {
                    dp[nx][ny-1] = 1;
                    q.push({nx, ny-1});
                } else if (arr[nx][ny] == '>' && isValid(nx, ny+1)) {
                    dp[nx][ny+1] = 1;
                    q.push({nx, ny+1});
                }
            }
        }
    }
    // for (int i = 1; i <= 2; i++) for (int j = 1; j <= n; j++) cout << dp[i][j] << " \n"[j == n];
    cout << (dp[2][n] ? "YES" : "NO") << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
