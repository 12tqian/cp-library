#include<bits/stdc++.h>

/**
 * To support forest, call gen for each roots
 */
struct LCAJump {
	int n;
	std::vector<std::vector<int>> par;
	std::vector<std::vector<int>> adj;
	std::vector<int> depth;

	void init(int _n) {
		n = _n;
		int d = 1;
		while ((1 << d) < n) d++;
		par.assign(d, std::vector<int>(n));
		adj.resize(n);
		depth.resize(n);
	}

	void ae(int x, int y) {
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void gen(int root = 0) {
		par[0][root] = root;
		dfs(root);
	}

	void dfs(int src = 0) {
		for (int i = 1; i < (int)par.size(); i++) {
			par[i][src] = par[i - 1][par[i - 1][src]];
		}
		for (int nxt: adj[src]) {
			if (nxt == par[0][src]) continue;
			depth[nxt] = depth[par[0][nxt] = src] + 1;
			dfs(nxt);
		}
	}

	int jump(int x, int d) {
		for (int i = 0; i < (int)par.size(); i++) {
			if ((d >> i) & 1) {
				x = par[i][x];
			}
		}
		return x;
	}
	
	int lca(int x, int y) {
		if (depth[x] < depth[y]) std::swap(x, y);
		x = jump(x, depth[x] - depth[y]);
		if (x == y) return x;
		for (int i = (int)par.size() - 1; i >= 0; i--) {
			int nx = par[i][x];
			int ny = par[i][y];
			if (nx != ny) x = nx, y = ny;
		}
		return par[0][x];
	}
};

int main() {
	using namespace std;
	cin.tie(0)->sync_with_stdio(0);
	int n, q; cin >> n >> q;
	LCAJump L;
	L.init(n);
	for (int i = 1; i < n; i++) {
		int p; cin >> p;
		L.ae(i, p);
	}
	L.gen(0);
	while (q--) {
		int u, v; cin >> u >> v;
		cout << L.lca(u, v) << '\n';
	}
}