template <class G> 
struct HeavyLightDecomposition {
private:
	void dfs_sz(int cur) {
		size[cur] = 1;
		for (auto& dst : g[cur]) {
			if (dst == par[cur]) {
				if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
					swap(g[cur][0], g[cur][1]);
				else
					continue;
			}
			depth[dst] = depth[cur] + 1;
			par[dst] = cur;
			dfs_sz(dst);
			size[cur] += size[dst];
			if (size[dst] > size[g[cur][0]]) {
				swap(dst, g[cur][0]);
			}
		}
	}

	void dfs_hld(int cur) {
		down[cur] = id++;
		for (auto dst : g[cur]) {
			if (dst == par[cur]) continue;
			nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
			dfs_hld(dst);
		}
		up[cur] = id;
	}

	// [u, v)
	std::vector<std::pair<int, int>> ascend(int u, int v) const {
		std::vector<std::pair<int, int>> res;
		while (nxt[u] != nxt[v]) {
			res.emplace_back(down[u], down[nxt[u]]);
			u = par[nxt[u]];
		}
		if (u != v) res.emplace_back(down[u], down[v] + 1);
		return res;
	}

	// (u, v]
	std::vector<std::pair<int, int>> descend(int u, int v) const {
		if (u == v) return {};
		if (nxt[u] == nxt[v]) return {{down[u] + 1, down[v]}};
		auto res = descend(u, par[nxt[v]]);
		res.emplace_back(down[nxt[v]], down[v]);
		return res;
	}

public:
	G g;
	int id;
	std::vector<int> size, depth, down, up, nxt, par;

	HeavyLightDecomposition(G& _g, std::vector<int> roots = {0})
			: g(_g),
				id(0),
				size(g.size(), 0),
				depth(g.size(), 0),
				down(g.size(), -1),
				up(g.size(), -1),
				nxt(g.size(), 0), 
				par(g.size(), 0) {
		for (int root : roots) {
			par[root] = nxt[root] = root;
			dfs_sz(root);
			dfs_hld(root);
		}
	}

	void build(std::vector<int> roots) {
		for (int root : roots) {
			par[root] = nxt[root] = root;
			dfs_sz(root);
			dfs_hld(root);
		}
	}

	// [l, r], inclusive for subtree
	std::pair<int, int> idx(int i) const { return {down[i], up[i] - 1}; }

	template <class F>
	void path_query(int u, int v, bool vertex, const F& f) {
		int l = lca(u, v);
		for (auto&& [a, b] : ascend(u, l)) {
			int s = a + 1, t = b;
			s > t ? f(t, s - 1) : f(s, t - 1);
		}
		if (vertex) f(down[l], down[l]);
		for (auto&& [a, b] : descend(l, v)) {
			int s = a, t = b + 1;
			s > t ? f(t, s - 1) : f(s, t - 1);
		}
	}

	template <class F>
	void path_noncommutative_query(int u, int v, bool vertex, const F& f) {
		int l = lca(u, v);
		for (auto&& [a, b] : ascend(u, l)) f(a + 1, b - 1);
		if (vertex) f(down[l], down[l]);
		for (auto&& [a, b] : descend(l, v)) f(a, b);
	}

	template <class F>
	void subtree_query(int u, bool vertex, const F& f) {
		f(down[u] + int(!vertex), up[u] - 1);
	}

	int lca(int a, int b) {
		while (nxt[a] != nxt[b]) {
			if (down[a] < down[b]) swap(a, b);
			a = par[nxt[a]];
		}
		return depth[a] < depth[b] ? a : b;
	}

	int dist(int a, int b) { return depth[a] + depth[b] - depth[lca(a, b)] * 2; }
};