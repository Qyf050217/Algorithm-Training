#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n;cin>>n;
    string _; getline(cin, _);

    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) getline(cin, arr[i]);
    vector<int> cnt(n + 1); // 0 全部缩写 1 第一个单词细化
    vector<string> ans(n + 1);

    vector<vector<string>> fc(n + 1);
    for (int i = 1; i <= n; i++) {
        string t = arr[i];
        string temple;
        for (auto &c : t) {
            if (c == ' ') {
                fc[i].push_back(temple);
                temple.clear();
            } else temple += c;
        }
        if (temple.size()) fc[i].push_back(temple);
    }


    for (int i = 1; i <= n; i++) {
        string res;
        for (auto &s : fc[i]) res += s[0];
        ans[i] = res;
    }

    while (1) {
        map<string, vector<int>> check;
        for (int i = 1; i <= n; i++) {
            check[ans[i]].push_back(i);
        }

        int f = 1;
        for (auto [s, vec] : check) {
            if (vec.size() < 2) continue;
            f = 0;
            for (auto &i : vec) {
                cnt[i]++;
            }
        }
        if (f) break;
        for (int i = 1; i <= n; i++) {
            string res;
            for (int j = 0; j < cnt[i]; j++) res += fc[i][j];
            for (int j = cnt[i]; j < fc[i].size(); j++) res += fc[i][j][0];
            ans[i] = res;
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
