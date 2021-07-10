#include <bits/stdc++.h>

/**
 * This Sparse Table stores indices of things
 * For destructive combinations like gcd, use associative_range_query.cpp
 * Use this for min, max, and when you need the indices of things
 */

template <class T> struct SparseTable {
	std::vector<T> v;
	std::vector<std::vector<int>> jump;

	int level(int x) { return 31 - __builtin_clz(x); }

	int comb(int a, int b) {
		return v[a] == v[b] ? std::min(a, b) : (v[a] < v[b] ? a : b);
	}

	void init(const std::vector<T>& _v) {
		v = _v;
		jump = {std::vector<int>((int)v.size())};
		iota(jump[0].begin(), jump[0].end(), 0);
		for (int j = 1; (1 << j) <= (int)v.size(); j++) {
			jump.push_back(std::vector<int>((int)v.size() - (1 << j) + 1));
			for (int i = 0; i < (int)jump[j].size(); i++) {
				jump[j][i] = comb(jump[j - 1][i], jump[j - 1][i + (1 << (j - 1))]);
			}
		}
	}

	int index(int l, int r) {
		assert(l <= r);
		int d = level(r - l + 1);
		return comb(jump[d][l], jump[d][r - (1 << d) + 1]);
	}

	T query(int l, int r) {
		return v[index(l, r)];
	}
};

int main() {
	return 0;
}
