#pragma once

#include "dsu.hpp"

// weight, start, end
long long kruskal(std::vector<std::array<int, 3>> edge) {
	DSU D;
	int n = 0;
	for (auto& a : edge) {
		n = std::max(n, a[1]);
		n = std::max(n, a[2]);
	}
	++n;
	D.init(n);
	sort(edge.begin(), edge.end());
	long long ans = 0;
	for (auto& a : edge) {
		if (D.unite(a[1], a[2])) {
			ans += a[0];
		}
	}
	return ans;
}
