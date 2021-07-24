#include <bits/stdc++.h>

template <class T> struct RangeSetSeg {
	const T UNUSED = -1;
	std::vector<T> sum, lazy;
	int sz;

	// lazy stores what to set to
	void init(int sz_) {
		sz = 1;
		while (sz < sz_) sz *= 2;
		sum.assign(2 * sz, 0);
		lazy.assign(2 * sz, UNUSED);
	}

	void push(int ind, int L, int R) {
		if (L != R) {
			if(lazy[ind] != UNUSED){
				for(int i = 0; i < 2; i++){
					lazy[2 * ind + i] = lazy[ind];
				}
			}
		}
		if (lazy[ind] != UNUSED) sum[ind] = (R - L + 1) * lazy[ind];
		lazy[ind] = UNUSED;
	}

	void pull(int ind) { sum[ind] = sum[2 * ind] + sum[2 * ind + 1]; }

	void range_set(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc;
			push(ind, L, R); return;
		}
		int M = (L + R) / 2;
		range_set(lo, hi, inc, 2 * ind, L, M); range_set(lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}

	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R); if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}
};

int main() {
	return 0;
}
