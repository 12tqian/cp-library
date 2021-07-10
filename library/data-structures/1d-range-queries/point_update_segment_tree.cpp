#include <bits/stdc++.h>

template <class T> struct SegmentTree {
	const T ID = 0;

	T comb(T a, T b) {
		return a + b;
	}

	int n;
	std::vector<T> seg;

	void init(int _n) {
		n = _n;
		seg.assign(2 * n, ID);
	}

	void pull(int p) {
		seg[p] = comb(seg[2 * p], seg[2 * p + 1]);
	}

	void upd(int p, T val) {
		seg[p += n] = val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	void add(int p, T val) {
		seg[p += n] += val;
		for (p /= 2; p; p /= 2) pull(p);
	}

	T query(int l, int r) {
		T ra = ID, rb = ID;
		for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
			if (l & 1) ra = comb(ra, seg[l++]);
			if (r & 1) rb = comb(seg[--r], rb);
		}
		return comb(ra, rb);
	}
};

int main() {
	return 0;
}
