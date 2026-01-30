#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

vector<int> cnt(1e3 + 7);
bool isPrime[1010]; //isPrime[i] == 1表示：i是素数
int minFac[1010]; // 最小质因子
int Prime[1010]; // 质数表

void GetPrime(int n) {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[1] = 0;
	int cnt = 0;
	for(int i = 2; i <= n; i++) {
		if (isPrime[i]) {
        	Prime[++cnt] = i;
            minFac[i] = i;
        }
        
		for(int j = 1; j <= cnt && i*Prime[j] <= n; j++) {
            int p = Prime[j];
			isPrime[i * p] = 0;
            minFac[i * p] = Prime[j];
			if(i % p == 0)  break;
		}
	}
}
void solve(){
    int n;cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        if (cnt[arr[i]] <= 1) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    GetPrime(1007);
    for (int num = 1; num <= 1000; num++) {
        set<int> st;
        int t = num;
        int mn = minFac[num];
        while (t != 1) {
            st.insert(mn);
            while (t % mn == 0) t /= mn;
            mn = minFac[t];
        }
        cnt[num] = st.size();
    }
    int T = 1;cin >> T;
    while (T--) solve();
}
