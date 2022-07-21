#pragma once

template <class T> struct Affine {
	T a, b;
	
	constexpr Affine() : a(1), b(0) {}
	constexpr Affine(T _a, T _b) : a(_a), b(_b) {}
	constexpr Affine(T _b) : a(0), b(_b) {}

	T operator()(T x) { return a * x + b; }
	
	Affine operator-() { return Affine(-a, -b); }
	
	friend Affine operator*(const Affine& l, const Affine& r) {
		return Affine(l.a * r.a, l.b * r.a + r.b); }
	friend Affine operator-(const Affine& l, const Affine& r) { return Affine(l.a - r.a, l.b - r.b); }
	friend Affine operator+(const Affine& l, const Affine& r) { return Affine(l.a + r.a, l.b + r.b); }
	
	friend Affine operator+(const Affine& l, const T& r) { return Affine(l.a, l.b + r); }
	friend Affine operator-(const Affine& l, const T& r) { return Affine(l.a, l.b - r); }
	friend Affine operator*(const Affine& l, const T& r) { return Affine(l.a * r, l.b * r); }
	friend Affine operator/(const Affine& l, const T& r) { return Affine(l.a / r, l.b / r); }

	friend Affine operator+(const T& l, Affine& r) { return r + l; }
	friend Affine operator-(const T& l, Affine& r) { return -r + l; }
	friend Affine operator*(const T& l, Affine& r) { return r * l; }
	
	friend Affine& operator+=(Affine& l, const Affine& r) { return l = l + r; }
	friend Affine& operator-=(Affine& l, const Affine& r) { return l = l - r; }
	friend Affine& operator*=(Affine& l, const Affine& r) { return l = l * r; }

	friend Affine& operator+=(Affine& l, const T& r) { return l = l + r; }
	friend Affine& operator-=(Affine& l, const T& r) { return l = l - r; }
	friend Affine& operator*=(Affine& l, const T& r) { return l = l * r; }

	bool operator==(const Affine& r) const { return a == r.a && b == r.b; }
	bool operator!=(const Affine& r) const { return a != r.a || b != r.b; }

	friend ostream& operator<<(ostream& os, const Affine& r) {
		os << "( " << r.a << ", " << r.b << " )"; return os; }
};