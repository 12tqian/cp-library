#pragma once 

#include "polynomial.hpp"

template <class D> Poly<D> berlekamp_massey(const Poly<D>& s) {
	int n = int(s.size());
	std::vector<D> b = {D(-1)}, c = {D(-1)};
	D y = D(1);
	for (int ed = 1; ed <= n; ed++) {
		int l = int(c.size()), m = int(b.size());
		D x = 0;
		for (int i = 0; i < l; i++) {
			x += c[i] * s[ed - l + i];
		}
		b.push_back(0);
		m++;
		if (!x) continue;
		D freq = x / y;
		if (l < m) {
			// use b
			auto tmp = c;
			c.insert(begin(c), m - l, D(0));
			for (int i = 0; i < m; i++) {
				c[m - 1 - i] -= freq * b[m - 1 - i];
			}
			b = tmp;
			y = x;
		} else {
			// use c
			for (int i = 0; i < m; i++) {
				c[l - 1 - i] -= freq * b[m - 1 - i];
			}
		}
	}
	return c;
}
