#include <bits/stdc++.h>

template <class T> struct IntervalUnion {
	const T INF = std::numeric_limits<T>::max();
	std::set<std::pair<T, T>> le, ri;

	void reset() {
		le.clear();
		ri.clear();
	}

	// inserts an interval while returning the intervals it intersected with
	std::vector<std::pair<T, T>> insert(std::pair<T, T> x) {
		std::set<std::pair<T, T>> bad;
		std::vector<std::pair<T, T>> ret;
		std::pair<T, T> use1 = {x.first, -INF}, use2 = {x.second, INF};
		auto it1 = le.lower_bound(use1);
		auto it2 = ri.lower_bound(use2);
		if (it2 != ri.end()) {
			T lo = (*it2).second, hi = (*it2).first;
			if (lo <= x.first && x.second <= hi) {
				ret.emplace_back(lo, hi);
				T mn = x.first, mx = x.second;
				for (auto& b : ret) {
					le.erase(b); ri.erase({b.second, b.first});
					mn = std::min(mn, b.first); mx = std::max(mx, b.second);
				}
				le.emplace(mn, mx); ri.emplace(mx, mn);
				return ret;
			}
		}
		if (it1 != le.end()) {
			while (it1 != le.end()) {
				auto val = (*it1);
				if (val.first <= x.second) bad.insert(val);
				else break;
				it1 = next(it1);
			}
		}
		if (it2 != ri.begin()) {
			it2 = prev(it2);
			while (true) {
				auto val = (*it2);
				if (val.first >= x.first) bad.emplace(val.second, val.first);
				else break;
				if (it2 == ri.begin()) break;
				it2 = prev(it2);
			}
		}
		for (auto& b : bad) ret.emplace_back(b);
		T mn = x.first, mx = x.second;
		for (auto& b : ret) {
			le.erase(b); ri.erase({b.second, b.first});
			mn = std::min(mn, b.first); mx = std::max(mx, b.second);
		}
		le.emplace(mn, mx); ri.emplace(mx, mn);
		return ret;
	}
};

int main() {
	return 0;
}
