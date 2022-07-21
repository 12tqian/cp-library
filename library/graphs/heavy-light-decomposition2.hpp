#pragma once

#include "../data-structures/1d-range-queries/lazy-segment-tree.hpp"

const bool VALUES_IN_VERTICES = true;

template <class T> struct HeavyLight {
	std::vector<int> parent, heavy, depth, root, tree_pos;
	LazySeg<T> tree;

	template <class G> int dfs(const G& graph, int v) {
		int size = 1, max_subtree = 0;
		for (int u : graph[v]) if (u != parent[v]) {
			parent[u] = v;
			depth[u] = depth[v] + 1;
			int subtree = dfs(graph, u);
			if (subtree > max_subtree) heavy[v] = u, max_subtree = subtree;
			size += subtree;
		}
		return size;
	}

	template <class B> void process_path(int u, int v, B op) {
		for (; root[u] != root[v]; v = parent[root[v]]) {
			if (depth[root[u]] > depth[root[v]]) std::swap(u, v);
			op(tree_pos[root[v]], tree_pos[v]);
		}
		if (depth[u] > depth[v]) std::swap(u, v);
		op(tree_pos[u] + (VALUES_IN_VERTICES ? 0 : 1), tree_pos[v]);
	}

	template <class G>
	void init(const G& graph, int r = 0) {
		int n = (int)graph.size();
		heavy.assign(n, -1);
		parent.assign(n, 0);
		depth.assign(n, 0);
		root.assign(n, 0);
		tree_pos.assign(n, 0);
		tree.init(n);
		parent[r] = -1;
		depth[r] = 0;
		dfs(graph, r);
		for (int i = 0, current_pos = 0; i < n; ++i)
			if (parent[i] == -1 || heavy[parent[i]] != i)
			for (int j = i; j != -1; j = heavy[j]) {
				root[j] = i;
				tree_pos[j] = current_pos++;
			}
	}

	void modify_path(int u, int v, const T& value) {
		process_path(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
	}
	
	T query_path(int u, int v) {
		T res = 0;
		process_path(u, v, [this, &res](int l, int r) { res += tree.qsum(l, r); });
		return res;
	}
};
