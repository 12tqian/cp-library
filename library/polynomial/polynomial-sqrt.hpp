#pragma once

#include "polynomial.hpp"
#include "../modular-arithmetic/mod-sqrt.hpp"

#include <bits/stdc++.h>

template <class D> Poly<D> sqrt(const Poly<D>& p, int n = -1) {
	if (n == -1) n = (int)p.size();
	if (p.empty()) return Poly<D>(n);
	if (p[0] == 0) {
		for (int i = 1; i < (int)p.size(); ++i) {
			if (p[i] != 0) {
				if (i & 1) {
					return {};
				}
				if (n - i / 2 <= 0) break;
				auto ret = sqrt(p >> i, n - i / 2);
				if (ret.empty()) return {};
				ret = ret << (i / 2);
				if ((int)ret.size() < n) ret.resize(n);
				return ret;
			}
		}
		return Poly<D>(n);
	}
	auto v = mod_sqrt(p[0].v, D::md());
	if (v.empty()) return {};
	long long sqr = v[0];
	Poly<D> ret = {D(sqr)};
	D i2 = 1 / D(2);
	for (int i = 1; i < n; i <<= 1) {
		ret = (ret + p.pre(i << 1) * ret.inv(i << 1)) * i2;
	}
	return ret.pre(n);
}