#pragma once

template <class T> struct SegmentTree {
	SegmentTree<T>* left, * right;
	T sum, lazy;

	SegmentTree(int l, int r) {
		lazy = 0;
		if (l == r) {
			sum = 0;
		} else {
			int m = (l + r) >> 1;
			left = new SegmentTree<T>(l, m);
			right = new SegmentTree<T>(m + 1, r);
			pull();
		}
	}

	void pull() {
		sum = left->sum + right->sum;
	}

	void push(int l, int r) {
		sum += (r - l + 1) * lazy;
		if (l != r) {
			left->lazy += lazy;
			right->lazy += lazy;
		}
		lazy = 0;
	}

	void update(int lo, int hi, T inc, int l, int r) {
		push(l, r);
		if (r < lo || hi < l) {
			return;
		} else if (lo <= l && r <= hi) {
			lazy = inc;
			push(l, r);
		} else {
			int m = (l + r) >> 1;
			left->update(lo, hi, inc, l, m);
			right->update(lo, hi, inc, m + 1, r);
			pull();
		}
	}

	T query(int lo, int hi, int l, int r) {
		push(l, r);
		if (r < lo || hi < l) {
			return 0;
		} else if (lo <= l && r <= hi) {
			return sum;
		} else {
			int m = (l + r) >> 1;
			return left->query(lo, hi, l, m) + right->query(lo, hi, m + 1, r);
		}
	}
};