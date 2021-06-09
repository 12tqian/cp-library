#include <bits/stdc++.h>

/**
 * Call unite to join interval with right endpoint x and left endpoint y
 * It is assumed that x + 1 = y
 * get_interval finds the interval element x is in
 */

struct IntervalJoin {
	std::vector<int> e;
	std::vector<std::pair<int, int>> interval;

	void init(int n) {
		e = std::vector<int>(n, -1);
		interval.resize(n);
		for (int i = 0; i < n; i++) {
			interval[i].first = interval[i].second = i;
		}
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
		interval[x].first = std::min(interval[x].first, interval[y].first);
		interval[x].second = std::max(interval[x].second, interval[y].second);
		e[x] += e[y]; e[y] = x;
		return true;
	}
	
	std::pair<int, int> get_interval(int x) {
		x = get(x);
		return interval[x];
	}
};

int main() {
	return 0;
}