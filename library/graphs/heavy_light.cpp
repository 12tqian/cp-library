#include <bits/stdc++.h>

/**
 * To support forest, just change 
 * init to take in a vector of roots, and DFS each of them
 */
template <class T> struct LazySeg {
	std::vector<T> sum, lazy;
	int sz;

	void init(int sz_) {
		sz = 1;
		while (sz < sz_) sz *= 2;
		sum.assign(2 * sz, 0);
		lazy.assign(2 * sz, 0);
	}

	void push(int ind, int L, int R) {
		sum[ind] += (R - L + 1) * lazy[ind];
		if (L != R) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}

	void pull(int ind) {
		sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
	}

	void build() {
		for (int i = sz - 1; i >= 1; i--) {
			pull(i);
		}
	}

	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (hi < L || R < lo) return ;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc;
			push(ind, L, R);
			return;
		}
		int M = (L + R) / 2;
		upd(lo, hi, inc, 2 * ind, L, M);
		upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}

	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}
};

const bool VALUES_IN_VERTICES = true;

template <class T> struct HeavyLight {
	std::vector<int> parent, heavy, depth, root, tree_pos;
	LazySeg<T> tree;

	template <class G> int dfs(const G &graph, int v) {
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
	void init(const G &graph, int r = 0) {
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

	void modify_path(int u, int v, const T &value) {
		process_path(u, v, [this, &value](int l, int r) { tree.upd(l, r, value); });
	}
	
	T query_path(int u, int v) {
		T res = 0;
		process_path(u, v, [this, &res](int l, int r) { res += tree.qsum(l, r); });
		return res;
	}
};

int main() {
	using namespace std;
	HeavyLight<long long> H;
	int n, q; cin >> n >> q;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<vector<int>> graph(n);
	for (int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	H.init(graph);
	for (int i = 0; i < n; i++) H.modify_path(i, i, a[i]);
	while (q--) {
		int t; cin >> t;
		if (t == 0) {
			int p, x; cin >> p >> x;
			H.modify_path(p, p, x);
		} else {
			int u, v;
			cin >> u >> v;
			cout << H.query_path(u, v) << '\n';
		}
	}
	return 0;
}
