#pragma once

#include "number-theoretic-transform.hpp"

template <class D> struct Poly : std::vector<D> {
	using vector<D>::vector;
	Poly(const std::vector<D>& _v = {}) { 
		for (int i = 0; i < (int)_v.size(); ++i) {
			this->push_back(_v[i]);
		}
		shrink(); 
	}

	void shrink() {
		while (this->size() && !this->back()) this->pop_back();
	}

	D freq(int p) const { return (p < this->size()) ? (*this)[p] : D(0); }
	
	Poly operator+(const Poly& r) const {
		auto n = max(this->size(), r.size());
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);
		return res;
	}
	
	Poly operator-(const Poly& r) const {
		int n = max(this->size(), r.size());
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);
		return res;
	}
	
	Poly operator*(const Poly& r) const { return {NTT::multiply((*this), r)}; }
	
	Poly operator*(const D& r) const {
		int n = this->size();
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = (*this)[i] * r;
		return res;
	}

	Poly operator/(const D &r) const{ return *this * (1 / r); }
	
	Poly operator/(const Poly& r) const {
		if (this->size() < r.size()) return {{}};
		int n = (int)this->size() - r.size() + 1;
		return (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
	}
	
	Poly operator%(const Poly& r) const { return *this - *this / r * r; }
	
	Poly operator<<(int s) const {
		std::vector<D> res(this->size() + s);
		for (int i = 0; i < this->size(); i++) res[i + s] = (*this)[i];
		return res;
	}

	Poly operator>>(int s) const {
		if (this->size() <= s) return Poly();
		std::vector<D> res(this->size() - s);
		for (int i = 0; i < this->size() - s; i++) res[i] = (*this)[i + s];
		return res;
	}
	
	Poly& operator+=(const Poly& r) { return *this = *this + r; }
	Poly& operator-=(const Poly& r) { return *this = *this - r; }
	Poly& operator*=(const Poly& r) { return *this = *this * r; }
	Poly& operator*=(const D& r) { return *this = *this * r; }
	Poly& operator/=(const Poly& r) { return *this = *this / r; }
	Poly& operator/=(const D &r) {return *this = *this / r;}
	Poly& operator%=(const Poly& r) { return *this = *this % r; }
	Poly& operator<<=(const size_t& n) { return *this = *this << n; }
	Poly& operator>>=(const size_t& n) { return *this = *this >> n; }

	Poly pre(int le) const { return Poly(this->begin(), this->begin() + min((int)this->size(), le)); }
	
	Poly rev(int n = -1) const {
		Poly res = *this;
		if (n != -1) res.resize(n);
		reverse(res.begin(), res.end());
		return res;
	}
	
	Poly diff() const {
		std::vector<D> res(max(0, (int)this->size() - 1));
		for (int i = 1; i < this->size(); i++) res[i - 1] = freq(i) * i;
		return res;
	}
	
	Poly inte() const {
		std::vector<D> res(this->size() + 1);
		for (int i = 0; i < this->size(); i++) res[i + 1] = freq(i) / (i + 1);
		return res;
	}

	// f * f.inv() = 1 + g(x)x^m
	Poly inv(int m) const {
		Poly res = Poly({D(1) / freq(0)});
		for (int i = 1; i < m; i *= 2) {
			res = (res * D(2) - res * res * pre(2 * i)).pre(2 * i);
		}
		return res.pre(m);
	}
	
	Poly exp(int n) const {
		assert(freq(0) == 0);
		Poly f({1}), g({1});
		for (int i = 1; i < n; i *= 2) {
			g = (g * 2 - f * g * g).pre(i);
			Poly q = diff().pre(i - 1);
			Poly w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);
			f = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);
		}
		return f.pre(n);
	}
	
	Poly log(int n) const {
		assert(freq(0) == 1);
		auto f = pre(n);
		return (f.diff() * f.inv(n - 1)).pre(n - 1).inte();
	}

	Poly pow_mod(long long n, const Poly& mod) {
		Poly x = *this, r = {{1}};
		while (n) {
			if (n & 1) r = r * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return r;
	}

	Poly pow(int n, long long e) {
		Poly b = pre(n + 1);
		Poly r({1});
		while (e) {
			if (e & 1) {
				r *= b;
				r.resize(n + 1);
			}
			b *= b;
			b.resize(n + 1);
			e >>= 1;
		}
		return r;
	}

	friend ostream& operator<<(ostream& os, const Poly& p) {
		if (p.size() == 0) return os << "0";
		for (auto i = 0; i < p.size(); i++) {
			if (p[i]) {
				os << p[i] << "x^" << i;
				if (i != p.size() - 1) os << "+";
			}
		}
		return os;
	}
};
