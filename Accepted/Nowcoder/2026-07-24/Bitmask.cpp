#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int cnt[40][2][2] = {0};   // 10 的贡献为1其余无贡献
    for (int i = 1; i <= n; i++) {
        for (int bit = 0; bit <= 30; bit++) {
            int a = (arr[i] >> bit) & 1;          // 第bit位
            int b = (arr[i] >> (bit + 1)) & 1;    // 第bit+1位
            cnt[bit][a][b]++;
        }
    }

    int q;cin >> q;
    while (q--) {
        int op, x;cin >> op >> x;
        if (op == 1) { // &
            for (int bit = 0; bit <= 30; bit++) {
                int a = (x >> bit) & 1;
                int b = (x >> (bit + 1)) & 1;
                int t[2][2] = {0};
                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        int A = a & i, B = b & j;
                        t[A][B] += cnt[bit][i][j];
                    }
                }
                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        cnt[bit][i][j] = t[i][j];
                    }
                }
            }
        } else if (op == 2) { // |
            for (int bit = 0; bit <= 30; bit++) {
                int a = (x >> bit) & 1;
                int b = (x >> (bit + 1)) & 1;
                int t[2][2] = {0};
                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        int A = a | i, B = b | j;
                        t[A][B] += cnt[bit][i][j];
                    }
                }
                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        cnt[bit][i][j] = t[i][j];
                    }
                }
            }
        } else { // ^
            for (int bit = 0; bit <= 30; bit++) {
                int a = (x >> bit) & 1;
                int b = (x >> (bit + 1)) & 1;
                int t[2][2] = {0};
                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        int A = a ^ i, B = b ^ j;
                        t[A][B] += cnt[bit][i][j];
                    }
                }
                for (int i = 0; i <= 1; i++) {
                    for (int j = 0; j <= 1; j++) {
                        cnt[bit][i][j] = t[i][j];
                    }
                }
            }
        }


        int res = 0;
        for (int bit = 0; bit <= 30; bit++) res += cnt[bit][1][0];
        // for (int i = 0; i <= 1; i++) {
        //     for (int j = 0; j <= 1; j++) {
        //         int sum = 0;
        //         for (int bit = 0; bit <= 30; bit++) {
        //             sum += cnt[bit][i][j];
        //         }
        //         cout << i << ' ' << j << ' ' << sum << endl;
        //     }
        // }
        cout << res << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
