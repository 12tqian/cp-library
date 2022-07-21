#pragma once

#include "dsu-rollback.hpp"

struct OfflineDynamicConnectivity {
	DSURollBack dsu;
	int sz;
	std::vector<std::vector<std::pair<int, int>>> seg;
	std::vector<std::vector<std::pair<int, int>>> queries;
	std::vector<int> ans;

	void upd(int l, int r, std::pair<int, int> p) {
		// add edge p from time [l, r]
		for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) seg[l++].push_back(p);
			if (r & 1) seg[--r].push_back(p);
		}
	}

	void process(int ind) {
		for (auto& t : seg[ind]) {
			dsu.unite(t.first, t.second);
		}
		if (ind >= sz) {
			// Process the queries at time ti
			// Do stuff with D
			int ti = ind - sz; 
			for (auto& qq : queries[ti]) {
				ans.push_back(dsu.same_set(qq.first, qq.second));
			}
		} else {
			process(2 * ind); process(2 * ind + 1);
		}
		for (auto& t : seg[ind]) {
			dsu.rollback();
		}
	}

	void init(int n, int max_time) {
		sz = 1;
		while (sz < max_time) sz *= 2;
		seg.assign(2 * sz, {});
		queries.assign(sz, {});
		dsu.init(n);
	}

	void add_query(int ti, int u, int v) {
		queries[ti].emplace_back(u, v);
	}
	
	std::vector<int> solve() {
		process(1);
		return ans;
	}
};