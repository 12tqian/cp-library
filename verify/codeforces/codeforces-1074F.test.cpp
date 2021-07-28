#define PROBLEM "https://codeforces.com/contest/1074/problem/F"

#include "../../library/contest/template-minimal.hpp"
#include "../../library/graphs/lca-rmq.hpp"

template <class T> struct SegmentTree {
	using U = pair<T, int>;

	const U ID = make_pair(numeric_limits<T>::max(), 1);

	int sz;	
	
	vector<U> st; // min, cnt
	vector<T> lz; // lazy

	void init(int _sz) {
		sz = 1;
		while (sz < _sz) {
			sz <<= 1;
		}
		st.assign(2 * sz, make_pair(0, 1));
		lz.assign(2 * sz, 0);
		for (int i = sz - 1; i >= 1; --i) {
			pull(i);
		}
	}

	U comb(U x, U y) {
		U res;
		if (x.first < y.first) {
			res = x;
		} else if (x.first > y.first) {
			res = y;
		} else {
			res.first = x.first;
			res.second = x.second + y.second;
		}
		return res;
	}

	void pull(int i) {
		st[i] = comb(st[2 * i], st[2 * i + 1]);
	}

	void push(int i, int l, int r) {
		if (lz[i] == 0) {
			return;
		}
		st[i].first += lz[i];
		if (l != r) {
			for (int j = 0; j < 2; ++j) {
				lz[2 * i + j] += lz[i];
			}
		}
		lz[i] = 0;
	}

	void upd(int lo, int hi, T inc, int i = 1, int l = 0, int r = -1) {
		if (r == -1) {
			r += sz;
		}
		push(i, l, r);
		if (r < lo || hi < l) {

		} else if (lo <= l && r <= hi) {
			lz[i] = inc;
			push(i, l, r);
		} else {
			int m = (l + r) >> 1;
			upd(lo, hi, inc, 2 * i, l, m);
			upd(lo, hi, inc, 2 * i + 1, m + 1, r);
			pull(i);
		}
	}

	U query(int lo, int hi, int i = 1, int l = 0, int r = -1) {
		if (r == -1) {
			r += sz;
		}
		push(i, l, r);
		if (r < lo || hi < l) {
			return ID;
		} else if (lo <= l && r <= hi) {
			return st[i];
		} else {
			int m = (l + r) >> 1;
			return comb(query(lo, hi, 2 * i, l, m), query(lo, hi, 2 * i + 1, m + 1, r));
		}
	}

	int zeros(int lo, int hi) {
		auto res = query(lo, hi);
		if (res.first == 0) {
			return res.second;
		} else {
			return 0;
		}
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	LCARMQ L;
	L.init(n);
	vector<vector<int>> g(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
		L.ae(u, v);
	}	
	vector<int> in(n);
	vector<int> out(n);
	int ti = 0;
	function<void(int, int)> dfs = [&](int u, int p) {
		in[u] = ti++;
		for (int v : g[u]) {
			if (v != p) {
				dfs(v, u);
			}
		}
		out[u] = ti - 1;
	};
	dfs(0, -1);
	L.gen(0);
	set<pair<int, int>> used;
	SegmentTree<int> seg;
	seg.init(n);	
	while (q--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		if (u > v) {
			swap(u, v);
		}
		auto add = [&](int u, int v, int t) {
			int lca = L.lca(u, v);
			if (lca == v) {
				swap(u, v);
			}
			if (lca == u) {
				int child = L.get_child(u, v);
				seg.upd(in[child], out[child], t);
				seg.upd(in[v], out[v], -t);
			} else {
				seg.upd(0, n - 1, t);
				seg.upd(in[u], out[u], -t);
				seg.upd(in[v], out[v], -t);
			}
		};
		if (used.count(make_pair(u, v))) {
			used.erase(make_pair(u, v));
			add(u, v, -1);
		} else {
			used.emplace(u, v);
			add(u, v, 1);
		}
		cout << seg.zeros(0, n - 1) << '\n';
	}
	return 0;
}
