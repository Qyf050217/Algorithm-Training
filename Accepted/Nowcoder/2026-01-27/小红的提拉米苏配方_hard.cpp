#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

void solve(){
    int cntOne = 0;
    string s;cin >> s;
    int n = s.size();
    s = '#' + s;

    int idxZero = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {idxZero = i;break;}
    }

    

    vector<int> change;

    for (int i = n; i > idxZero; i--) if (s[i] == '1') change.push_back(i);
    
    int tail = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i] != '1') continue;
        int j = i;
        while (j <= n && s[j] == '1') j++;
        if (s[j] == '0') {
            for (int k = i; k < j; k++) {
                if (tail == change.size() || change[tail] < j) break;
                else {
                    // cout << k << ' ';
                    // cout << "+++++" << endl;
                    s[k] = '3';
                    tail++;
                }
            }
        }
        i = j;
    }
    // cout << tail << endl;
    for (int i = 0; i < tail; i++) s[change[i]] = '2';
    for (int i = 1; i <= n; i++) {
        if (s[i] <= '2') cout << s[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
