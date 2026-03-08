#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

bool isPrime[1000010];
int minFac[1000010];
int Prime[1000010];
int res[1000010];

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
    int BOB = 1;
    int mmx = -LNF;
    for (int i = 1; i <= n; i++) {
        if (mmx > arr[i]) BOB = 0;
        mmx = max(mmx, arr[i]);
    }
    if (BOB) {
        cout << "Bob" << endl;
        return;
    }
    vector<int> bacP(n + 1);
    for (int i = n; i >= 1; i--) {
        if (i < n) bacP[i] = bacP[i + 1];
        else bacP[i] = arr[i];
        bacP[i] = min(bacP[i], minFac[arr[i]]);
    }
    
    int f = 0;
    for (int i = 1; i <= n; i++) {
        int num = arr[i];
        if (res[num]) f = 1; 
        int mx = minFac[num];
        int mn = mx;
        while (num != 1) {
            while (num % mn == 0) num /= mn;
            mn = minFac[num];
            mx = max(mx, mn);
        }
        if (i < n && mx > bacP[i + 1]) f = 1;
    }

    vector<int> p;
    for (int i = 1; i <= n; i++) {
        if (isPrime[arr[i]]) p.push_back(arr[i]);
    }
    int mx = -LNF;
    for (int i = 0; i < p.size(); i++) {
        if (mx > p[i]) f = 1;
        mx = max(mx, p[i]);
    }

    if (f) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    GetPrime(1e6 + 7);
    for (int i = 4; i <= 1e6 + 7; i++) {
        int mn = minFac[i];
        int cnt = 0;
        int t = i;
        while (t != 1) {
            while (t % mn == 0) t /= mn;
            mn = minFac[t];
            cnt++;
        }
        if (cnt > 1) res[i] = 1;
    }
    isPrime[1] = 1;
    int T = 1;cin >> T;
    while (T--) solve();
}
