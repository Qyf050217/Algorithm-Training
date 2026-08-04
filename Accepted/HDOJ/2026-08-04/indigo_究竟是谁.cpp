#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int n, k, m, q;cin >> n >> k >> m >> q;
    map<string, int> cnt; // 出现次数  
    map<string, int> fr; // 第一次出现
    map<string, int> valid; // 什么时间达到的k
    vector<string> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (valid.count(arr[i])) continue;
        int j = i;
        while (j <= n && arr[j] == arr[i]) j++;
        if (j - i >= k) valid[arr[i]] = i + k - 1;
        i = j - 1;
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        string s = arr[i];
        if (fr[s] == 0) { // 从未出现过
            cnt[s]++;
            fr[s] = i;
            continue;
        }
        if (i - fr[s] - 1 < m) { // 间隔不足m  ***
            cnt[s]++;
            continue;
        }
        if (cnt[s] < k) {
            cnt[s]++;
            continue;
        }
        if (cnt[s] >= q) { // 复读超过 q
            cnt[s]++;
            continue;
        }
        if (!valid.count(s) || i <= valid[s]) {
            cnt[s]++;
            continue;
        }
        ans.push_back(i);
        cnt[s]++;
    }

    if (ans.size() == 0) cout << "empty" << endl;
    else {
        for (auto &i : ans) cout << i << ' ';
        cout << endl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
