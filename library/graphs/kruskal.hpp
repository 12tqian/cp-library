#pragma once

struct DSU {
	std::vector<int> e;
	void init(int n) {
		e = std::vector<int>(n, -1);
	}

	int get(int x) {
		return e[x] < 0 ? x : e[x] = get(e[x]);
	}

	bool same_set(int a, int b) {
		return get(a) == get(b);
	}

	int size(int x) {
		return -e[get(x)];
	}

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) std::swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

// weight, start, end
long long kruskal(std::vector<std::array<int, 3>> edge) {
	DSU D;
	int n = 0;
	for (auto &a : edge) {
		n = std::max(n, a[1]);
		n = std::max(n, a[2]);
	}
	++n;
	D.init(n);
	sort(edge.begin(), edge.end());
	long long ans = 0;
	for (auto &a : edge) {
		if (D.unite(a[1], a[2])) {
			ans += a[0];
		}
	}
	return ans;
}
