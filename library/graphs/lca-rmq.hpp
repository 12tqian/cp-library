#pragma once

/**
 * O(n log n) preprocessing with O(1) query
 * Compress compute sthe minimal subtree containing
 * all node LCAs and comrpesses edges
 * O(S log S) compression
 * Returns list of (parent, original index)
 * Parent is the parent of node in compressed tree
 * Original index is the node it represents
 * get_child also returns the subtree child of node and -1 if it doesn't exist in O(1)
 * To support forest, gen on all the roots, initialize tmp and sparse at the end
 */

#include "../data-structures/1d-range-queries/sparse-table.hpp"

struct LCARMQ {
	int n; 
	std::vector<std::vector<int>> adj;
	std::vector<int> dep, in, par, rev, out, pos;
	std::vector<std::pair<int, int>> tmp;
	SparseTable<std::pair<int, int>> S;
	std::vector<std::vector<int>> sparse;
	int ti = 0;

	void init(int _n) {
		n = _n;
		adj.resize(n);
		dep = in = out = par = rev = pos = std::vector<int>(n);
		sparse = {std::vector<int>(n)};
		for (int j = 1; (1 << j) <= n; j++) {
			sparse.push_back(std::vector<int>(n - (1 << j) + 1));
		}
	}

	void ae(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	void dfs(int src) {
		in[src] = ti++;
		sparse[0][in[src]] = src;
		pos[src] = (int)tmp.size();
		tmp.emplace_back(dep[src], src);
		for (auto &nxt : adj[src]) {
			if (nxt == par[src]) continue;
			dep[nxt] = dep[par[nxt] = src] + 1;
			dfs(nxt);
			tmp.emplace_back(dep[src], src);
		}
		out[src] = ti;
	}

	inline int mini(int u, int v) {
		return (dep[u] < dep[v] || (dep[u] == dep[v] && in[u] > in[v])) ? u : v;
	}

	void gen(int root = 0) {
		par[root] = root;
		dfs(root);
		S.init(tmp); 
		for (int j = 1; j < (int)sparse.size(); j++) {
			for (int i = 0; i < (int)sparse[j].size(); i++) {
				sparse[j][i] = mini(sparse[j - 1][i], sparse[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int lca(int u, int v) {
		u = pos[u];
		v = pos[v];
		if (u > v) std::swap(u, v);
		return S.query(u, v).second;
	}

	int dist(int u, int v) {
		return dep[u] + dep[v] - 2 * dep[lca(u, v)];
	}

	bool is_ancestor(int anc, int src) {
		return in[anc] <= in[src] && out[anc] >= out[src];
	}

	int get_child(int anc, int src) {
		if (!is_ancestor(anc, src)) return -1;
		int l = in[anc] + 1;
		int r = in[src];
		int d = 31 - __builtin_clz(r - l + 1);
		return mini(sparse[d][l], sparse[d][r - (1 << d) + 1]);
	}
	
	std::vector<std::pair<int, int>> compress(std::vector<int> nodes) {
		auto cmp = [&](int a, int b) {
			return pos[a] < pos[b];
		};
		sort(nodes.begin(), nodes.end(), cmp);
		for (int i = (int)nodes.size() - 2; i >= 0; i--) {
			nodes.push_back(lca(nodes[i], nodes[i + 1]));
		}
		sort(nodes.begin(), nodes.end(), cmp);
		nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
		std::vector<std::pair<int, int>> ret{{0, nodes[0]}};
		for (int i = 0; i < (int)nodes.size(); i++) {
			rev[nodes[i]] = i;
		}
		for (int i = 1; i < (int)nodes.size(); i++) {
			ret.emplace_back(rev[lca(nodes[i - 1], nodes[i])], nodes[i]);
		}
		return ret;
	}
};
