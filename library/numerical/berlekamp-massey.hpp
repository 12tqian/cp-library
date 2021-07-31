#pragma once 

#include "polynomial.hpp"

template <class Mint> Poly<Mint> berlekamp_massey(const Poly<Mint>& s) {
	int n = int(s.size());
	std::vector<Mint> b = {Mint(-1)}, c = {Mint(-1)};
	Mint y = Mint(1);
	for (int ed = 1; ed <= n; ed++) {
		int l = int(c.size()), m = int(b.size());
		Mint x = 0;
		for (int i = 0; i < l; i++) {
			x += c[i] * s[ed - l + i];
		}
		b.push_back(0);
		m++;
		if (!x) continue;
		Mint freq = x / y;
		if (l < m) {
			// use b
			auto tmp = c;
			c.insert(begin(c), m - l, Mint(0));
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
