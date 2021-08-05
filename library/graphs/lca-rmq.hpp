#pragma once

/**
 * O(n log n) preprocessing with O(1) query
 * Compress computes the minimal subtree containing
 * all node LCAs and compresses edges
 * O(S log S) compression
 * Returns list of (parent, original index)
 * Parent is the parent of node in compressed tree
 * Original index is the node it represents
 * get_child also returns the subtree child of node and -1 if it doesn't exist in O(1)
 * To support forest, gen on all the roots, initialize tmp and sparse at the end
 */

//#include "../data-structures/1d-range-queries/sparse-table.hpp"

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;
 
	int level(int x) { return 31 - __builtin_clz(x); }
 
	int comb(int a, int b) {
		//It is important that max(a, b) is used for ties. get_child requires it.
		return v[a].first == v[b].first ? std::max(a, b) : (v[a] < v[b] ? a : b);
	}
 
	void init(const std::vector<T> &_v) {
		v = _v;
		jump = {std::vector<int>((int)v.size())};
		iota(jump[0].begin(), jump[0].end(), 0);
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}
 
	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}
 
	T query(int l, int r) {
		return v[index(l, r)];
	}
};
 
struct LCARMQ {
	int n; 
	std::vector<std::vector<int>> adj;
	std::vector<int> dep, in, par, rev, out, pos;
	std::vector<std::pair<int, int>> euler, prefix;
	SparseTable<std::pair<int, int>> S;	//Euler tour order, indexed by pos[]
	SparseTable<std::pair<int, int>> T; //Prefix order, indexed by in[]
 
	void init(int _n) {
		n = _n;
		adj.resize(n);
		dep = in = out = par = rev = pos = std::vector<int>(n);
	}
 
	void ae(int u, int v) {
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
 
	void dfs(int src) {
		in[src] = (int)prefix.size();
		prefix.emplace_back(dep[src], src);
		pos[src] = (int)euler.size();
		euler.emplace_back(dep[src], src);
		for (auto &nxt : adj[src]) {
			if (nxt == par[src]) continue;
			dep[nxt] = dep[par[nxt] = src] + 1;
			dfs(nxt);
			euler.emplace_back(dep[src], src);
		}
		out[src] = (int)prefix.size() - 1;
	}
 
	void gen(int root = 0) {
		par[root] = root;
		dfs(root);
		S.init(euler);
		T.init(prefix);
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
		return T.query(l, r).second;
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