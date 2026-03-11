#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>


void solve() {
    vector<char> arr;
    string s;cin >> s;
    for (auto &c : s) {
        if (c == '<') {
            if(!arr.empty()) arr.pop_back();
        } else if (c == '*') arr.clear();
        else arr.push_back(c);
    }
    if (arr.size()) {
        for (auto &c : arr) cout << c;
    }else cout << "EMPTY";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T = 1;//cin >> T;
    while (T--) solve();
}