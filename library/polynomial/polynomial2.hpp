#pragma once

#include "fast-fourier-transform.hpp"

namespace Polynomial {

using T = long long;
using Poly = std::vector<T>;

T eval(const Poly& p, const T& x) {
	T res = 0;
	for (int i = (int)p.size() - 1; i >= 0; --i) {
		res = x * res + p[i];
	}
	return res;
}

Poly& operator+=(Poly& l, const Poly& r) {
	l.resize(std::max((int)l.size(), (int)r.size()));
	for (int i = 0; i < (int)r.size(); ++i) {
		l[i] += r[i];
	}
	return l;
}

Poly& operator-=(Poly& l, const Poly& r) {
	l.resize(std::max((int)l.size(), (int)r.size()));
	for (int i = 0; i < (int)r.size(); ++i) {
		l[i] -= r[i];
	}
	return l;
}

Poly& operator*=(Poly& l, const T& r) {
	for (int i = 0; i < (int)l.size(); ++i) {
		l[i] *= r;
	}
	return l;
}

Poly& operator/=(Poly& l, const T& r) {
	for (int i = 0; i < (int)l.size(); ++i) {
		l[i] /= r;
	}
	return l;
}

Poly operator*(const Poly& l, const Poly& r) {
	if (!std::min((int)l.size(), (int)r.size())) {
		return {};
	}
	return FFT::general_multiply(l, r);
	Poly res((int)l.size() + (int)r.size() - 1);
	for (int i = 0; i < (int)l.size(); ++i) {
		for (int j = 0; j < (int)r.size(); ++j) {
			res[i + j] += l[i] * r[j];
		}
	}
	return res;
}

Poly operator+(Poly l, const Poly& r) { return l += r; }
Poly operator-(Poly l, const Poly& r) { return l -= r; }
Poly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }
Poly operator*(Poly l, const T& r) { return l *= r; }
Poly operator*(const T& r, const Poly& l) { return l * r; }
Poly operator/(Poly l, const T& r) { return l /= r;	}
Poly& operator*=(Poly& l, const Poly& r) { return l = l * r; }

Poly derivative(const Poly& p) {
	Poly res;
	for (int i = 1; i < (int)p.size(); ++i) {
		res.push_back(T(i) * p[i]);
	}
	return res;
}

Poly integral(const Poly& p) {
	static Poly invs{0, 1};
	for (int i = invs.size(); i <= (int)p.size(); ++i ){
		invs.push_back(1 / T(i));
	}
	Poly res((int)p.size() + 1);
	for (int i = 0; i < (int)p.size(); ++i) {
		res[i + 1] = p[i] * invs[i + 1];
	}
	return res;
}

}