#pragma once 

#include "polynomial.hpp"
template <typename D> Poly<D> berlekamp_massey(const Poly<D>& s) {
	const int N = (int)s.size();
	Poly<D> b, c;
	b.reserve(N + 1);
	c.reserve(N + 1);
	b.push_back(1);
	c.push_back(1);
	D y = D(1);
	for (int ed = 1; ed <= N; ed++) {
		int l = (int)c.size(), m = (int)b.size();
		D x = 0;
		for (int i = 0; i < l; i++) x += c[i] * s[ed - l + i];
		b.emplace_back(D(0));
		m++;
		if (x == D(0)) continue;
		D freq = x / y;
		if (l < m) {
			auto tmp = c;
			c.insert(c.begin(), m - l, 0);
			for (int i = 0; i < m; i++) c[m - 1 - i] -= freq * b[m - 1 - i];
			b = tmp;
			y = x;
		} else {
			for (int i = 0; i < m; i++) c[l - 1 - i] -= freq * b[m - 1 - i];
		}
	}
	reverse(c.begin(), c.end());
	return c;
}