#pragma once

template <class T> struct LCAJumpSparse {
	int n;
	std::vector<std::vector<int>> par;
	std::vector<std::vector<T>> sparse;
	std::vector<T> vals;
	std::vector<std::vector<int>> adj;
	std::vector<int> depth;

	T comb(T a, T b) {
		return min(a, b);
	}

	void init(int _n) {
		n = _n;
		int d = 1;
		while ((1 << d) < n) d++;
		par.assign(d, std::vector<int>(n));
		adj.resize(n);
		depth.resize(n);
		vals.resize(n);
	}

	void set_val(int x, T v) {
		vals[x] = v;
	}

	void ae(int x, int y) {
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	void gen(int root = 0) {
		par[0][root] = root;
		sparse[0][root] = vals[root];
		dfs(root);
	}

	void dfs(int src = 0) {
		for (int i = 1; i < (int)par.size(); i++) {
			par[i][src] = par[i - 1][par[i - 1][src]];
			sparse[i][src] = comb(sparse[i - 1][src], sparse[i - 1][par[i - 1][src]]);
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

	T query(int x, int y) {
		int anc = lca(x, y);
		int d = 31 - __builtin_clz(depth[x] - depth[anc]);
		T res1 = comb(sparse[d][x], sparse[d][jump(x, depth[x] - depth[anc] - (1 << d) + 1)]);
		d = 31 - __builtin_clz(depth[y] - depth[anc]);
		T res2 = comb(sparse[d][y], sparse[d][jump(y, depth[y] - depth[anc] - (1 << d) + 1)]);
		return comb(res1, res2);
	}
};