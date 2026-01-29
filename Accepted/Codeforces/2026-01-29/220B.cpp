#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n, ans;
const int maxN = 1e5 + 7;
const int maxT = sqrt(maxN) + 1;
vector<int> arr(maxN + 7);
vector<int> pos(maxN + 7);
vector<int> st(maxT + 7);
vector<int> ed(maxT + 7);
unordered_map<int, int> cnt;

void add(int x) {
    int num = arr[x];
    cnt[num]++;
    if (cnt[num] == num) ans++;
    if (cnt[num] == num + 1) ans--;
}

void del(int x) {
    int num = arr[x];
    cnt[num]--;
    if (cnt[num] == num) ans++;
    if (cnt[num] == num - 1) ans--;
}

struct node{
    int L, R, k;
    inline bool operator < (const node &a) {
        if (pos[a.L] != pos[L]) return pos[L] < pos[a.L];
        if (pos[L] & 1) return R > a.R; // 奇偶性优化
        return R < a.R;
    }
};

void build() {
    int block = sqrt(n);
    int tot = (n + block - 1) / block;
    for (int i = 1; i <= tot; i++) {
        st[i] = ed[i - 1] + 1;
        ed[i] = i * block;
    }
    ed[tot] = n;

    for (int i = 1; i <= n; i++) pos[i] = (i - 1) / block + 1;
}
void solve(){
    int m;cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build();
    vector<node> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i].L >> q[i].R;
        q[i].k = i;
    }

    sort(q.begin(), q.end());

    vector<int> res(m);
    int L = 1;
    int R = 0;
    ans = 0;
    for (auto &i : q) {
        while (L < i.L) del(L++);
        while (L > i.L) add(--L);
        while (R < i.R) add(++R);
        while (R > i.R) del(R--);
        res[i.k] = ans;
    }
    for (auto &i : res) cout << i << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;//cin >> T;
    while (T--) solve();
}
