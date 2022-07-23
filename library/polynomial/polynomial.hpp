#pragma once

#include "number-theoretic-transform.hpp"

template <class D> struct Poly : std::vector<D> {
	using std::vector<D>::vector;

	static const int SMALL_DEGREE = 60;

	Poly(const std::vector<D>& _v = {}) { 
		for (int i = 0; i < (int)_v.size(); ++i) {
			this->push_back(_v[i]);
		}
		shrink(); 
	}

	void shrink() {
		while (this->size() && !this->back()) this->pop_back();
	}

	D freq(int p) const { return (p < (int)this->size()) ? (*this)[p] : D(0); }
	
	Poly operator+(const Poly& r) const {
		int n = std::max(this->size(), r.size());
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = freq(i) + r.freq(i);
		return res;
	}

	Poly operator-(const Poly& r) const {
		int n = std::max(this->size(), r.size());
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = freq(i) - r.freq(i);
		return res;
	}

	bool small(const Poly& r) const { return std::min((int)this->size(), (int)r.size()) <= SMALL_DEGREE; }

	Poly operator*(const Poly& r) const { 
		if (!std::min((int)this->size(), (int)r.size())) return {};
		if (small(r)){
			Poly res((int)this->size() + (int)r.size() - 1);
			for (int i = 0; i < (int)this->size(); ++i) {
				for (int j = 0; j < (int)r.size(); ++j) {
					res[i + j] += (*this)[i] * r[j];
				}
			}
			return res;
		} else {
			return {NTT::multiply((*this), r)}; 
		}
	}
	
	Poly operator*(const D& r) const {
		int n = this->size();
		std::vector<D> res(n);
		for (int i = 0; i < n; i++) res[i] = (*this)[i] * r;
		return res;
	}

	Poly operator/(const D &r) const{ return *this * (1 / r); }


	Poly& operator+=(const D& r) { 
		if (this->empty()) this->resize(1);
		(*this)[0] += r;
		return *this;
	}

	Poly& operator-=(const D& r) {
		(*this)[0] -= r;
		return *this;
	}
	
	Poly operator/(const Poly& r) const {
		if (this->size() < r.size()) return {};
		if (small(r)) {
			Poly a = (*this);
			Poly b = r;
			a.shrink(), b.shrink();
			D lst = b.back();
			D ilst = 1 / lst;
			for (auto& t : a) t *= ilst;
			for (auto& t : b) t *= ilst;
			Poly q(std::max((int)a.size() - (int)b.size() + 1, 0));
			for (int diff; (diff = (int)a.size() - (int)b.size()) >= 0; a.shrink()) {
				q[diff] = a.back();
				for (int i = 0; i < (int)b.size(); ++i) {
					a[i + diff] -= q[diff] * b[i];
				}
			}
			return q;
		} else {
			int n = (int)this->size() - r.size() + 1;
			return (rev().pre(n) * r.rev().inv(n)).pre(n).rev(n);
		}
	}
	
	Poly operator%(const Poly& r) const { return *this - *this / r * r; }
	
	Poly operator<<(int s) const {
		std::vector<D> res(this->size() + s);
		for (int i = 0; i < (int)this->size(); i++) res[i + s] = (*this)[i];
		return res;
	}

	Poly operator>>(int s) const {
		if ((int)this->size() <= s) return Poly();
		std::vector<D> res(this->size() - s);
		for (int i = 0; i < (int)this->size() - s; i++) res[i] = (*this)[i + s];
		return res;
	}
	
	Poly operator+(const D& r) { return Poly(*this) += r; }
	Poly operator-(const D& r) { return Poly(*this) -= r; }
	Poly operator-() const { return (*this) * -1; } 
	Poly& operator+=(const Poly& r) { return *this = *this + r; }
	Poly& operator-=(const Poly& r) { return *this = *this - r; }
	Poly& operator*=(const Poly& r) { return *this = *this * r; }
	Poly& operator*=(const D& r) { return *this = *this * r; }
	Poly& operator/=(const Poly& r) { return *this = *this / r; }
	Poly& operator/=(const D &r) { return *this = *this / r; }
	Poly& operator%=(const Poly& r) { return *this = *this % r; }
	Poly& operator<<=(const size_t& n) { return *this = *this << n; }
	Poly& operator>>=(const size_t& n) { return *this = *this >> n; }
	friend Poly operator*(D const& l, Poly r) { return r *= l; }
	friend Poly operator/(D const& l, Poly r) { return l * r.inv(); }
	friend Poly operator+(D const& l, Poly r) { return r += l; }
	friend Poly operator-(D const& l, Poly r) { return -r + l; }

	Poly pre(int le) const { return Poly(this->begin(), this->begin() + std::min((int)this->size(), le)); }
	
	Poly rev(int n = -1) const {
		Poly res = *this;
		if (n != -1) res.resize(n);
		reverse(res.begin(), res.end());
		return res;
	}
	
	Poly diff() const {
		std::vector<D> res(std::max(0, (int)this->size() - 1));
		for (int i = 1; i < (int)this->size(); i++) res[i - 1] = freq(i) * i;
		return res;
	}
	
	Poly inte() const {
		std::vector<D> res(this->size() + 1);
		for (int i = 0; i < (int)this->size(); i++) res[i + 1] = freq(i) / (i + 1);
		return res;
	}

	// f * f.inv() = 1 + g(x)x^m
	Poly inv(int m = -1) const {
		if (m == -1) m = (int)this->size();
		Poly res = Poly({D(1) / freq(0)});
		for (int i = 1; i < m; i *= 2) {
			res = (res * D(2) - res * res * pre(2 * i)).pre(2 * i);
		}
		return res.pre(m);
	}
	
	Poly exp(int n = -1) const {
		assert(freq(0) == 0);
		if (n == -1) n = (int)this->size();
		Poly f({1}), g({1});
		for (int i = 1; i < n; i *= 2) {
			g = (g * 2 - f * g * g).pre(i);
			Poly q = diff().pre(i - 1);
			Poly w = (q + g * (f.diff() - f * q)).pre(2 * i - 1);
			f = (f + f * (*this - w.inte()).pre(2 * i)).pre(2 * i);
		}
		return f.pre(n);
	}
	
	Poly log(int n = -1) const {
		if (n == -1) n = (int)this->size();
		assert(freq(0) == 1);
		auto f = pre(n);
		return (f.diff() * f.inv(n - 1)).pre(n - 1).inte();
	}

	Poly pow_mod(const Poly& mod, long long n = -1) {
		if (n == -1) n = this->size();
		Poly x = *this, r = {{1}};
		while (n) {
			if (n & 1) r = r * x % mod;
			x = x * x % mod;
			n >>= 1;
		}
		return r;
	}

	D _pow(D x, long long k) { 
		D r = 1;
		while (k) {
			if (k & 1) {
				r *= x;
			}
			x *= x;
			k >>= 1;
		}
		return r;
	}

	Poly pow(long long k, int n = -1) {
		if (n == -1) n = this->size();
		int sz = (int)this->size();
		for (int i = 0; i < sz; ++i) {
			if (freq(i) != 0) {
				if (i && k > n || i * k > n) return Poly(n);
				D rev = 1 / (*this)[i];
				Poly ret = (((*this * rev) >> i).log(n) * k).exp(n) * _pow((*this)[i], k);
				ret = (ret << (i * k)).pre(n);
				ret.resize(n);
				return ret;
			}
		}
		return Poly(n);
	}

	friend std::ostream& operator<<(std::ostream& os, const Poly& p) {
		if (p.empty()) return os << "0";
		for (auto i = 0; i < (int)p.size(); i++) {
			if (p[i]) {
				os << p[i] << "x^" << i;
				if (i != (int)p.size() - 1) os << "+";
			}
		}
		return os;
	}
};