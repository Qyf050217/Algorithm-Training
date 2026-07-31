#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>


int calc(int x) {
    int cnt = 0;
    int t = x;
    while (t) {
        t /= 2;
        cnt++;
    }
    return (1 << (cnt - 1));
}

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    s = "#" + s;
    int N = (1 << n) - 1;

    
    vector<int> one, zero;
    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (s[i] == '1') {
            arr[i] = 1;
            one.push_back(i);
        } else zero.push_back(i);
    }

    int idx = 0;
    for (auto &i : one) {
        idx ^= i;
    }

    vector<int> f;
    int c = 1;
    for (auto &i : one) {
        if (i == idx) {
            c = 0;
        } else f.push_back(i);
    }

    
    vector<int> ans(N + 1);
    vector<int> fin(N + 1, 0);
    fin[idx] = 1;

    for (int i = N; i >= 1; i--) {
        if ((s[i]) != (fin[i] + '0')) {
            ans[i] = i - calc(i);
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " \n"[i == N];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
