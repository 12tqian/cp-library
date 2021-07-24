#include<bits/stdc++.h>

template <class T> struct AffineSeg {
	int sz;
	std::vector<T> sum, mult, add;

	void push(int ind, int L, int R) { // modify values for current node
		sum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];
		if (L != R) {
			mult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];
			add[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];
			add[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];
		}
		add[ind] = 0; mult[ind] = 1;
	}

	void init(int n) {
		sz = 1;
		while (sz < n) sz *= 2;
		mult.assign(2 * sz, 1);
		sum.assign(2 * sz, 0);
		add.assign(2 * sz, 0);
	}

	void pull(int ind) {
		sum[ind] = sum[2 * ind] + sum[2 * ind + 1];
	}

	// t == 0 is add, t == 1 is for multiplying
	void upd(int t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (hi < L || R < lo) return;
		if (lo <= L && R <= hi) {
			if(t == 0) add[ind] = inc;  
			else mult[ind] = inc;
			push(ind, L, R); return;
		}
		int M = (L + R) / 2;
		upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);
		pull(ind);
	}
	
	T qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {
		if (R == -1) R += sz;
		push(ind, L, R);
		if (lo > R || L > hi) return 0;
		if (lo <= L && R <= hi) return sum[ind];
		int M = (L + R) / 2;
		return qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);
	}
};
