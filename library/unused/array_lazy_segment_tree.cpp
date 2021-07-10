#include <bits/stdc++.h>
/**
make sure SZ is a power of 2
*/
template <class T, int SZ> struct LazySeg {
	T sum[2 * SZ], lazy[2 * SZ];
	LazySeg() {
		for (int i = 0; i < 2 * SZ; i++) {
			sum[i] = 0;
			lazy[i] = 0;
		}
	}
	void push(int ind, int L, int R) {
		sum[ind] += (R - L + 1) * lazy[ind];
		if (L != R) {
			lazy[2 * ind] += lazy[ind];
			lazy[2 * ind + 1] += lazy[ind];
		}
		lazy[ind] = 0;
	}
	void pull(int ind) {
		sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
	}
	void build() {
		for (int i = SZ - 1; i >= 1; i--) {
			pull(i);
		}
	}
	void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ - 1) {
		push(ind, L, R);
		if (hi < L || R < lo) return ;
		if (lo <= L && R <= hi) {
			lazy[ind] = inc;
			push(ind, L, R);
			return;
		}
		int M = (L + R) / 2;
		upd(lo, hi, inc, 2 * ind, L, M);
		upd(lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ - 1) {
		push(ind, L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}
};
int main() {
	return 0;
}
