#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define lowbit(x) (x & -x)

int cnt(int x) {
    int res = 0;
    while (x) {
        if (x & 1) x--;
        else x /= 2;
        res++;
    }
    return res;
}

bool check(int x, int bit) {
    return ((x >> bit) << bit) == x;
}

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    int add = 0, ans = LNF;

    for (int bit = 0; bit <= 20; bit++) {
        int res = bit;

        for (int i = 1; i <= n; i++) {
            int x = arr[i];
            while (!check(x, bit)) x += lowbit(x);

            int mn = cnt(x) + x - arr[i];
            int fin = x;
            for (int BIT = bit; BIT <= 20; BIT++) {
                while (!check(x, BIT)) x += lowbit(x);
                int cost = cnt(x) + x - arr[i];
                if (cost < mn) {
                    mn = cost;
                    fin = x;
                }
            }
            res += fin - arr[i];
            res += cnt(fin / (1 << bit));
        }

        ans = min(ans, res);
    }

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}