#pragma once

constexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); } 

template <class T, int ...Ns> struct BIT {
	T val = 0; void upd(T v) { val += v; }
	T query() { return val; }
};

template <class T, int N, int... Ns> struct BIT<T, N, Ns...> {
	BIT<T, Ns...> bit[N + 1];

	template <typename... Args> void upd(int pos, Args... args) { 
		assert(pos > 0);
		for (; pos <= N; pos += pos & -pos) 
			bit[pos].upd(args...); 
	}

	template <typename... Args> T sum(int r, Args... args) {
		T res = 0; 
		for (; r; r -= r & -r) 
			res += bit[r].query(args...); 
		return res; 
	}

	template <typename... Args> T query(int l, int r, Args... args) { 
		return sum(r, args...) - sum(l - 1, args...); 
	}

	int get_kth(T des) { 
		assert(des > 0);
		int ind = 0;
		for (int i = 1 << bits(N); i; i /= 2)
			if (ind + i <= N && bit[ind + i].val < des)
				des -= bit[ind += i].val;
		assert(ind < N); return ind + 1;
	}
}; 

