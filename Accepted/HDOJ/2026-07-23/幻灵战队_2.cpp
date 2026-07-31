#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>
vector<int> arr;
int k;

int cost(int x, int c) { // 划分 c 次能获得的科技点
    if (c >= x) return 0;
    int mn = (x - c) / (c + 1);
    int yu = (x - c) % (c + 1);
    int a = 0;
    a += (1 + mn) * mn / 2 * (c + 1 - yu);
    a += (1 + mn + 1) * (mn + 1) / 2 * yu;
    return (x - c) * 20 + a * 5;
}

void solve(){
    int n;cin >> n >> k;
    string s;cin >> s;
    s = "#" + s;
    arr.clear();
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1') continue;
        int j = i;
        while (j <= n && s[j] == '0') j++;
        arr.push_back(j - i);
        i = j - 1;
    }
    if (arr.size() == 0) {
        cout << 0 << endl;
        return;
    }

    vector<int> mp(arr.size(), 0); // 切割次数
    priority_queue<PII> pq;
    for (int i = 0; i < arr.size(); i++) {
        pq.push({cost(arr[i], 0) - cost(arr[i], 1), i});
    }

    while (k--) {
        auto [val, idx] = pq.top(); pq.pop();
        mp[idx]++;
        pq.push({cost(arr[idx], mp[idx]) - cost(arr[idx], mp[idx] + 1), idx});
    }

    int res = 0;
    while (pq.size()) {
        auto [_, idx] = pq.top(); pq.pop();
        res += cost(arr[idx], mp[idx]);
    }
    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}
