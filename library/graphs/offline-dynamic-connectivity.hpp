#pragma once

/** 
 * Example of use: https://ideone.com/J3R7nb
 * Solves SPOJ DYNACON2
 */

struct DSURollBack {
	std::vector<int> e;

	void init(int n) {
		e = std::vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	std::vector<std::array<int, 4>> mod;

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) {
			mod.push_back({-1, -1, -1, -1});
			return 0;
		}
		if (e[x] > e[y]) std::swap(x, y);
		mod.push_back({x, y, e[x], e[y]});
		e[x] += e[y], e[y] = x;
		return true;
	}

	void rollback() {
		auto a = mod.back();
		mod.pop_back();
		if (a[0] != -1) {
			e[a[0]] = a[2];
			e[a[1]] = a[3];
		}
	}
};

struct OfflineDynamicConnectivity {
	DSURollBack D;
	int sz;
	std::vector<std::vector<std::pair<int, int>>> seg;

	void upd(int l, int r, std::pair<int, int> p) {
		// add edge p from time [l, r]
		for (l += sz, r += sz + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) seg[l++].push_back(p);
			if (r & 1) seg[--r].push_back(p);
		}
	}

	void process(int ind) {
		for (auto &t : seg[ind]) {
			D.unite(t.first, t.second);
		}
		if (ind >= sz) {
			// Process the queries at time ti
			// Do stuff with D
			int ti = ind - sz; 
		} else {
			process(2 * ind); process(2 * ind + 1);
		}
		for (auto &t : seg[ind]) {
			D.rollback();
		}
	}

	void init(int n, int max_time) {
		sz = 1;
		while (sz < max_time) sz *= 2;
		seg.assign(2 * sz, {});
		D.init(n);
	}
	
	void solve() {
		process(1);
	}
};

int main() {
	return 0;
}