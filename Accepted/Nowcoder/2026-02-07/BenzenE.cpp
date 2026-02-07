#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<int> p(70);
unordered_set<int> pos[70];
unordered_set<int> ans;
void insert(int x, int idx) {
    unordered_set<int> st;
    st.insert(idx);
    for (int i = 63; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (p[i] == 0) {
                p[i] = x;
                pos[i] = st;
                break;
            }else{
                x ^= p[i];
                for (auto &iii : pos[i]) {
                    if (st.count(iii)) st.erase(iii);
                    else st.insert(iii);
                }
            }
        }
    }
}

int get_max_xor() {
    int res = 0;
    for (int i = 63; i >= 0; i--) res = max(res, res^p[i]);
    return res;
}

bool check(int x) {
    for (int i = 63; i >= 0; i--) {
        if ((x >> i) & 1) {
            if (p[i]) {
                x ^= p[i];
                for (auto iii : pos[i]) {
                    if (ans.count(iii)) ans.erase(iii);
                    else ans.insert(iii);
                }
            }
            else return false;
        }
    }
    return !x;
}

void solve(){
    for (int i = 0; i <= 63; i++) {
        p[i] = 0;
        pos[i].clear();
    }
    ans.clear();
    int n;cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];


    int res = 0;
    for (int i = 1; i <= n; i++) res ^= a[i];
    if (res == 0) {
        for (int i = 1; i <= n; i++) {
            cout << a[i] << " \n"[i == n];
        }
        return;
    }


    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        arr[i] = (a[i] ^ b[i]);
    }
    for (int i = 1; i <= n; i++) {
        insert(arr[i], i);
    }
    if (!check(res)) {
        cout << -1 << endl;
        return;
    } else {
        for (auto &idx : ans) {
            a[idx] = b[idx];
        }
        for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
