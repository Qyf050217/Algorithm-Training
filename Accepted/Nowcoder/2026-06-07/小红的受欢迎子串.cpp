#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    string a = "greet";
    string b = "invite";

    int n;cin >> n;
    string s;cin >> s;
    s = '#' + s;
    map<string, int> A, B;
    for (int i = 0; i < (1 << a.size()); i++) {
        string sub;
        int cnt = 0;
        for (int bit = 0; bit < a.size(); bit++) {
            if ((i >> bit) & 1) {
                sub += a[bit];
                cnt++;
            }
        }
        A[sub] = cnt;
    }
    for (int i = 0; i < (1 << b.size()); i++) {
        string sub;
        int cnt = 0;
        for (int bit = 0; bit < b.size(); bit++) {
            if ((i >> bit) & 1) {
                sub += b[bit];
                cnt++;
            }
        }
        B[sub] = cnt;
    }

    vector<int> frA(n + 7), baA(n + 7);
    vector<int> frB(n + 7), baB(n + 7);

    for (int i = 1; i <= n; i++) {
        for (int c = i; c >= max(1LL, i - 7); c--) {
            string sub = s.substr(c, i - c + 1);
            if (A.count(sub)) frA[i] = max(frA[i], A[sub]);
            if (B.count(sub)) frB[i] = max(frB[i], B[sub]);
        }
        for (int c = i; c <= min(i + 7, n); c++) {
            string sub = s.substr(i, c - i + 1);
            if (A.count(sub)) baA[i] = max(baA[i], A[sub]);
            if (B.count(sub)) baB[i] = max(baB[i], B[sub]);
        }
    }
    for (int i = 1; i <= n; i++) {
        frA[i] = max(frA[i - 1], frA[i]);
        frB[i] = max(frB[i - 1], frB[i]);
    }
    for (int i = n; i >= 1; i--) {
        baA[i] = max(baA[i + 1], baA[i]);
        baB[i] = max(baB[i + 1], baB[i]);
    }
 
    int mx = 0;
    for (int i = 0; i <= n; i++) {
        mx = max(mx, frA[i] + baB[i + 1]);
        mx = max(mx, frB[i] + baA[i + 1]);
    }

    cout << 11 - mx << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
