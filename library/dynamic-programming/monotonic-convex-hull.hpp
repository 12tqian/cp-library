#pragma once

const long long INF = 1e18;

struct Line {
	mutable long long a, b, lst;

	long long eval(long long x) {
		return a * x + b;
	}

	bool operator<(const Line& y) const {
		return a < y.a;
	}

	long long floor_div(long long a, long long b) {
		return a / b - ((a ^ b) < 0 && a % b);
	}

	long long bet(const Line& y) {
		assert(a <= y.a);
		return a == y.a ? (b >= y.b ? INF : -INF) : floor_div(b - y.b, y.a - a);
	}
};

struct ConvexHullDeque : std::deque<Line> {
	void add_back(Line L) {
		while (true) {
			auto a = back();
			pop_back();
			a.lst = a.bet(L);
			if (size() && back().lst >= a.lst) {
				continue;
			}
			push_back(a);
			break;
		}
		L.lst = INF;
		push_back(L);
	}

	void add_front(Line L) {
		while (true) {
			if (!size()) {
				L.lst = INF;
				break;
			}
			if ((L.lst = L.bet(front())) >= front().lst) {
				pop_front();
			} else {
				break;
			}
		}
		push_front(L);
	}

	void add(long long a, long long b) {
		// comment this out for max
		a = -a; b = -b;
		if (!size() || a <= front().a) {
			add_front({a, b, 0});
		} else {
			assert(a >= back().a);
			add_back({a, b, 0});
		}
	}

	int ord = 1; // 1 = increasing, -1 = decreasing

	long long query(long long x) {
		// flip negatives for max
		assert(ord);
		if (ord == 1) {
			while (front().lst < x) {
				pop_front();
			}
			return -front().eval(x);
		} else {
			while (size() > 1 && prev(prev(end()))->lst >= x) {
				pop_back();
			}
			return -back().eval(x);
		}
	}
};