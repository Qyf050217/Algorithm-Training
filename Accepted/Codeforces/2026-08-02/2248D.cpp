#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, q;cin >> n >> q;
    string a, b;cin >> a >> b;
    a = "#" + a;
    b = "#" + b;

    vector<int> dif(n + 1);
    vector<int> dif_A1(n + 1), dif_A0(n + 1), dif_B1(n + 1), dif_B0(n + 1);
    vector<int> sam_A1(n + 1), sam_A0(n + 1), sam_B1(n + 1), sam_B0(n + 1);

    for (int i = 1; i <= n; i++) {
        if (a[i] != b[i]) dif[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) {
            if (a[i] == '1') {
                sam_A1[i]++;
                sam_B1[i]++;
            } else {
                sam_A0[i]++;
                sam_B0[i]++;
            }
        } else {
            if (a[i] == '1') {
                dif_A1[i]++;
                dif_B0[i]++;
            } else {
                dif_A0[i]++;
                dif_B1[i]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        dif[i] += dif[i - 1];
        dif_A0[i] += dif_A0[i - 1];
        dif_A1[i] += dif_A1[i - 1];
        sam_A0[i] += sam_A0[i - 1];
        sam_A1[i] += sam_A1[i - 1];

        dif_B0[i] += dif_B0[i - 1];
        dif_B1[i] += dif_B1[i - 1];
        sam_B0[i] += sam_B0[i - 1];
        sam_B1[i] += sam_B1[i - 1];
    }

    while (q--) {
        int l, r;cin >> l >> r;

        int dif_len = dif[r] - dif[l - 1];
        int len = r - l + 1;


        // +1
        int A_1 = (dif_A1[r] - dif_A1[l - 1]) + (sam_A1[r] - sam_A1[l - 1]);
        int B_1 = (dif_B1[r] - dif_B1[l - 1]) + (sam_B1[r] - sam_B1[l - 1]);
        if (A_1 >= (dif_len + sam_A1[r] - sam_A1[l - 1] + 1) / 2 && B_1 >= (dif_len + sam_B1[r] - sam_B1[l - 1] + 1) / 2) {
            cout << "YES" << endl;
            continue;
        }

        // +0
        int A_0 = (dif_A0[r] - dif_A0[l - 1]) + (sam_A0[r] - sam_A0[l - 1]);
        int B_0 = (dif_B0[r] - dif_B0[l - 1]) + (sam_B0[r] - sam_B0[l - 1]);
        if (A_0 >= (dif_len + sam_A0[r] - sam_A0[l - 1] + 1) / 2 && B_0 >= (dif_len + sam_B0[r] - sam_B0[l - 1] + 1) / 2) {
            cout << "YES" << endl;
            continue;
        }

        int duo = max((dif_A0[r] - dif_A0[l - 1]), (dif_A1[r] - dif_A1[l - 1])) - min((dif_A0[r] - dif_A0[l - 1]), (dif_A1[r] - dif_A1[l - 1]));
        if (duo <= (sam_A0[r] - sam_A0[l - 1]) + (sam_A1[r] - sam_A1[l - 1])) {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
