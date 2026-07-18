#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

#define Yes cout << "Yes\n"
#define No cout << "No\n"


using pii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
typedef long long ll;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    vector<pii> vsi(n+1);
    vvi p(n+1, vi(m+1));
    vi ans(n+1);
    vi minn(n+1), maxx(n+1); // id
    map<int, int> mins, maxs; // s
    for (int i = 1; i <= n; ++i) {
        cin >> vsi[i].first; vsi[i].second = i;
        for (int j = 1; j <= m; ++j) {
            cin >> p[i][j];
            if (~p[i][j]) {
                minn[i] += p[i][j];
                maxx[i] += p[i][j];
            } else {
                maxx[i] += k;
            }
        }
        if (!mins.count(vsi[i].first)) {
            mins[vsi[i].first] = minn[i];
            maxs[vsi[i].first] = maxx[i];
        } else {
            mins[vsi[i].first] = min(minn[i], mins[vsi[i].first]);
            maxs[vsi[i].first] = max(maxx[i], maxs[vsi[i].first]);
        }
    }

    sort(vsi.begin()+1, vsi.begin()+1+n);

    int lastmax = -1, cid = 1; // cid in vsi
    bool ok = 1;
    for (auto [s, ma_] : maxs) {
        if (!ok) break;
        int nmax = -1;

        while (cid <= n && vsi[cid].first == s) {
            int i = vsi[cid].second;

            if (lastmax + 1 > maxx[i]) {
                ok = 0;
                break;
            }
            ans[i] = max(minn[i], lastmax + 1);
            nmax = max(nmax, ans[i]);

            ++cid;
        }

        lastmax = nmax;
    }
    

    if (!ok) { No; return; }

    vvi res(n+1, vi(m+1));
    for (int i = 1; i <= n; ++i) {
        int dv = ans[i] - minn[i];
        for (int j = 1; j <= m; ++j) {
            if (~p[i][j]) {
                res[i][j] = p[i][j];
            } else {
                if (dv >= k) {
                    res[i][j] = k;
                    dv -= k;
                }
                else if (dv) {
                    res[i][j] = dv;
                    dv = 0;
                }
                else {
                    res[i][j] = 0;
                }
            }
        }
    }

    Yes;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << res[i][j] << " \n"[j==m];
        }
    }

}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int T_ = 1;
    cin >> T_;
    while (T_--) solve();
}