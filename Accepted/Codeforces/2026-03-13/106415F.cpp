#include <bits/stdc++.h>
using namespace std;
#define int long long
// #define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
#define lowbit(x) (x & -x)

int len(int x) {
    int res = 0;
    while (x) {
        x >>= 1;
        res++;
    }
    return res;
}

int query(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    char c;cin >> c;
    int sum;cin >> sum;
    return sum;
}

int calc(int x) {
    if (lowbit(x) == x) {
        return query(x, x) / 2;
    }
    int h = 1LL << len(x);
    return query(h - x, x) - calc(h - x);
}

void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int res = calc(arr[i]);
        cout << "! " << res << endl;
        char c;cin >> c;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
