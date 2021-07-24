#include <bits/stdc++.h>

namespace Polynomial {

using T = int;
using Poly = std::vector<T>;

T eval(const Poly &p, const T &x) {
	T res = 0;
	for (int i = (int)p.size() - 1; i >= 0; --i) {
		res = x * res + p[i];
	}
	return res;
}

Poly& operator+=(Poly &l, const Poly &r ){
	l.resize(std::max(l.size(), r.size()));
	for (int i = 0; i < r.size(); ++i) {
		l[i] += r[i];
	}
	return l;
}

Poly& operator-=(Poly &l, const Poly &r ){
	l.resize(std::max(l.size(), r.size()));
	for (int i = 0; i < r.size(); ++i) {
		l[i] -= r[i];
	}
	return l;
}

Poly& operator*=(Poly &l, const T& r) {
	for (int i = 0; i < l.size(); ++i) {
		l[i] *= r;
	}
	return l;
}

Poly& operator/=(Poly &l, const T& r) {
	for (int i = 0; i < l.size(); ++i) {
		l[i] /= r;
	}
	return l;
}

Poly operator*(const Poly &l, const Poly &r) {
	if (!std::min(l.size(), r.size())) {
		return {};
	}
	Poly res(l.size() + r.size() - 1);
	for (int i = 0; i < l.size(); ++i) {
		for (int j = 0; j < r.size(); ++j) {
			res[i + j] += l[i] * r[j];
		}
	}
	return res;
}

Poly operator+(Poly l, const Poly &r) { return l += r; }
Poly operator-(Poly l, const Poly &r) { return l -= r; }
Poly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }
Poly operator*(Poly l, const T &r) { return l *= r; }
Poly operator*(const T& r, const Poly &l) { return l * r; }
Poly operator/(Poly l, const T &r) { return l /= r;	}
Poly& operator*=(Poly &l, const Poly &r) { return l = l * r; }

Poly derivative(const Poly &p) {
	Poly res;
	for (int i = 1; i < p.size(); ++i) {
		res.push_back(T(i) * p[i]);
	}
	return res;
}

Poly integral(const Poly &p) {
	static Poly invs{0, 1};
	for (int i = invs.size(); i <= p.size(); ++i ){
		invs.push_back(1 / T(i));
	}
	Poly res(p.size() + 1);
	for (int i = 0; i < p.size(); ++i) {
		res[i + 1] = p[i] * invs[i + 1];
	}
	return res;
}

}


