#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
void solve() {
    string s;
    getline(cin, s);
    int a = 0, b = 0;
    for (auto &c : s) {
        if (c == '?') a++;
        else if (c == '!') b++;
    }

    cout << a << ' ' << b << endl;
    if (a > b) cout << "Excited!";
    if (a < b) cout << "Curious?";
    if (a == b) {
        if (a) cout << "Balanced=";
        else cout << "Plain.";
    }
    

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;//cin >> T;
    while (T--) solve();
}