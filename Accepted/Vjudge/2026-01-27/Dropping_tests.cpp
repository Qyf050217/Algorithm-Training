#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

const int maxN = 1e3 + 7;
const double eps = 1e-6;
int n, k;
vector<double> arr(maxN);

bool check() {
    int aid = n - k;
    sort(arr.begin()+1, arr.begin()+n+1, greater<double>());
    double ans = 0.0;
    for (int i = 1; i <= aid; i++) ans += arr[i];
    return ans >= 0.0;
}

bool solve(){
    cin >> n >> k;
    if (!n && !k) return false;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    double l = -10, r = 110.0;
    double ans = 0.0;
    while (r - l > eps) {
        double mid = (l + r) / 2.0;
        for (int i = 1; i <= n; i++) arr[i] = a[i] - mid * b[i];
        if (check()) {
            l = mid;
            ans = l;
        } else {
            r = mid;
        }
    }
    cout << (int)(100 * ans + 0.5) << endl;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (solve());
}
