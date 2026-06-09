#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n;
const int maxN = 2e5 + 7;
vector<int> arr(maxN);

bool check() {
    set<int> st;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != arr[i - 1]) {
            if (st.count(arr[i])) return false;
            st.insert(arr[i]);
        }
    }
    return true;
}


void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    if (check()) {
        cout << "YES" << endl;
        return;
    }

    map<int, set<int>> cnt;
    map<int, int> fr, la;
    for (int i = 1; i <= n; i++) {
        if (arr[i] != arr[i - 1]) {
            cnt[arr[i]].insert(i - 1);
            cnt[arr[i - 1]].insert(i);
            if (!fr.count(arr[i])) fr[arr[i]] = i;
        }
        la[arr[i]] = i;
    }

    for (auto &i : la) {
        cnt[i.first].insert(i.second + 1);
    }
    for (auto &i : fr) {
        cnt[i.first].insert(i.second - 1);
    }
    
    for (auto [num, vec] : cnt) {
        if (vec.size() <= 2) continue;
        for (auto &pos : vec) {
            if (pos < 1 || pos > n) continue;
            swap(arr[fr[num]], arr[pos]);
            if (check()) {
                cout << "YES" << endl;
                swap(arr[fr[num]], arr[pos]);
                return;
            }
            swap(arr[fr[num]], arr[pos]);
        }

        for (auto &pos : vec) {
            if (pos < 1 || pos > n) continue;
            swap(arr[la[num]], arr[pos]);
            if (check()) {
                cout << "YES" << endl;
                swap(arr[la[num]], arr[pos]);
                return;
            }
            swap(arr[la[num]], arr[pos]);
        }

        cout << "NO" << endl;
        return;
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
