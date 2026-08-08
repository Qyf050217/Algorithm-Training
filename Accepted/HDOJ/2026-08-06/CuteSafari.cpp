#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k;cin >> n >> k;
    string a, b;cin >> a >> b;


    // 字符相等
    map<char, int> A, B;
    for (int i = 0; i < n; i++) A[a[i]]++;
    for (int i = 0; i < n; i++) B[b[i]]++;

    for (auto [c, cnt] : A) {
        if (cnt != B[c]) {
            cout << "No" << endl;
            return;
        }
    }

    // 中间无法动
    if (n < 2 * k) {
        if (a != b) {
            swap(a[0], a[n - 1]);
            if (a != b) {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
        return;
    }

    
    
    a = "#" + a, b = "#" + b;
    for (int i = 2; i <= k - 1; i++) {
        if (a[i] != b[i]) {
            cout << "No" << endl;
            return;
        }
    }
    for (int i = n - 1; i >= n - k + 2; i--) {
        if (a[i] != b[i]) {
            cout << "No" << endl;
            return;
        }
    }

    if (n == 2 * k) {
        char A = a[1], B = a[n];
        if ((A == b[1] && B == b[n]) || (A == b[n] && B == b[1]) || (A == b[k] && B == b[k + 1]) || (A == b[k + 1] && B == b[k])) cout << "Yes" << endl;
        else {
            cout << "No" << endl;
        }
        return;
    }

    cout << "Yes" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
