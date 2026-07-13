#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2e5 + 5;
const int M = 1e6 + 5;

int n, m = 1e6, a[N], d[M];

vector<pair<int, int>> F(int x) {
	vector<pair<int, int>> res;
	while (x > 1) {
		int t = d[x], cnt = 0;
		while (d[x] == t) {
			x /= d[x], ++cnt;
		}
		res.emplace_back(t, cnt);
	}
	return res;
}

struct node {
	int val, lson, rson;
} t[N << 8];

int root[N], cnt;

int cpnode(int u) {
	t[++cnt] = t[u];
	return cnt;
}

void build(int &i, int l, int r) {
	i = ++cnt;
	if (l == r) {
		return;
	}
	int mid = (l + r) >> 1;
	build(t[i].lson, l, mid);
	build(t[i].rson, mid + 1, r);
}

void update(int &i, int l, int r, int pos, int k) {
	i = cpnode(i);
	if (l == r) {
		t[i].val += k;
		return;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) {
		update(t[i].lson, l, mid, pos, k);
	} else {
		update(t[i].rson, mid + 1, r, pos, k);
	}
}

int query(int i, int l, int r, int pos) {
	if (l == r) {
		return t[i].val;
	}
	int mid = (l + r) >> 1;
	if (pos <= mid) {
		return query(t[i].lson, l, mid, pos);
	}
	return query(t[i].rson, mid + 1, r, pos);
}

int f[N][20], dep[N];

int lca(int u, int v) {
	if (dep[u] < dep[v]) {
		swap(u, v);
	}
	int d = dep[u] - dep[v];
	for (int i = 0; i < 20; ++i) {
		if (d & (1 << i)) {
			u = f[u][i];
		}
	}
	if (u == v) {
		return u;
	}
	for (int i = 19; ~i; --i) {
		if (f[u][i] != f[v][i]) {
			u = f[u][i];
			v = f[v][i];
		}
	}
	return f[u][0];
}

int main() {

	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	cin >> n >> a[1];
	for (int i = m; i > 1; --i) {
		for (int j = i; j <= m; j += i) {
			d[j] = i;
		}
	}
	build(root[1], 1, m);
	{
		vector<pair<int, int>> x = F(a[1]);
		for (auto [k, cnt]: x) {
			update(root[1], 1, m, k, cnt);
		}
	}
	for (int i = 2; i <= n; ++i) {
		int val, u, v;
		cin >> val >> u >> v;
		dep[i] = dep[v] + 1;
		f[i][0] = v;
		for (int j = 1; j < 20; ++j) {
			f[i][j] = f[f[i][j - 1]][j - 1];
		}
		int p = lca(u, v);
		vector<pair<int, int>> x = F(val), y;
		for (auto [k, cnt]: x) {
			int t = query(root[u], 1, m, k) + query(root[v], 1, m, k) - query(root[p], 1, m, k) - query(root[f[p][0]], 1, m, k);
			if (cnt > t) {
				y.emplace_back(k, cnt - t);
			}
		}
		a[i] = 1;
		root[i] = root[v];
		for (auto [k, cnt]: y) {
			update(root[i], 1, m, k, cnt);
			while (cnt--) {
				a[i] *= k;
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		cout << a[i] << " \n"[i == n];
	}
}