#include<bits/stdc++.h>

const long long INF = 1e18;

struct ConvexHullTrick {
	// modified for minimums
	struct line {
		long long m, b; long double x, val;
		bool is_query;

		line(long long _m = 0, long long _b = 0) {
			m = _m, b = _b, val = 0, x = -INF, is_query = false;
		}

		long long eval(long long x) const { return m * x + b; }
		bool parallel(const line &l) const { return m == l.m; }
		long double intersect(const line &l) const {
			return parallel(l) ? INF : 1.0 * (l.b - b) / (m - l.m);
		}

		bool operator<(const line &l) const {
			if (l.is_query) return x < l.val;
			else return m < l.m;
		}
	};

	std::set<line> hull;

	bool hull_prev(std::set<line>::iterator it) { return it != hull.begin(); }
	bool hull_next(std::set<line>::iterator it) { return it != hull.end() && next(it) != hull.end(); }
	bool bad(const line &l1, const line &l2, const line &l3) { return l1.intersect(l3) <= l1.intersect(l2); }
	bool bad(std::set<line>::iterator it) { return hull_prev(it) && hull_next(it) && bad(*prev(it), *it, *next(it)); }

	std::set<line>::iterator update(std::set<line>::iterator it) {
		if (!hull_prev(it)) return it;
		long double x = it->intersect(*prev(it));
		line tmp(*it); tmp.x = x;
		it = hull.erase(it);
		return hull.insert(it, tmp);
	}

	void add_line(long long m, long long b) {
		m = -m, b = -b;
		line l(m, b);
		std::set<line>::iterator it = hull.lower_bound(l);
		if (it != hull.end() && l.parallel(*it)) {
			if(it->b < b) it = hull.erase(it);
			else return;
		}
		it = hull.insert(it, l);
		if (bad(it)) return (void) hull.erase(it);
		while (hull_prev(it) && bad(prev(it))) hull.erase(prev(it));
		while (hull_next(it) && bad(next(it))) hull.erase(next(it));
		it = update(it);
		if (hull_prev(it)) update(prev(it));
		if (hull_next(it)) update(next(it));
	}
	
	long long query(long long x) const {
		if (hull.empty()) return INF;
		line q; q.val = x, q.is_query = 1;
		std::set<line>::iterator it = --hull.lower_bound(q);
		return -(it->eval(x));
	}
};

int main() {
	return 0;
}
