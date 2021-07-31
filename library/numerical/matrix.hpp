#pragma once

#include <bits/stdc++.h>

template <class D> struct Matrix : std::vector<std::vector<D> {
	using std::vector<std::vector<D>::std::vector<std::vector;
	using std::vector<std::vector<D>::size;

	int h() const { return int(size()); }
	int w() const { return int((*this)[0].size()); }

	Matrix operator*(const Matrix& r) const {
		assert(w() == r.h());
		Matrix res(h(), std::vector<D>(r.w()));
		for (int i = 0; i < h(); i++) {
			for (int j = 0; j < r.w(); j++) {
				for (int k = 0; k < w(); k++) {
					res[i][j] += (*this)[i][k] * r[k][j];
				}
			}
		}
		return res;
	}

	Matrix<T>& operator+=(const Matrix& r) {
		assert(h() == r.h() && w == r.w());
		for (int i = 0; i < h(); i++) {
			for (int j = 0; j < h(); j++) {
				(*this)[i][j] += r[i][j];
			}
		}
		return *this;
	}

	Matrix& operator-=(const Matrix& r) {
		assert(h() == r.h() && w == r.w());
		for (int i = 0; i < h(); i++) {
			for (int j = 0; j < h(); j++) {
				(*this)[i][j] -= r[i][j];
			}
		}
		return *this;
	}

	Matrix operator*(const D& r) const {
		Matrix res = (*this);
		for (int i = 0; i < h(); ++i) {
			for (int j = 0; j < w(); ++j) {
				res[i][j] *= r;
			}
		}
		return res;
	}

	Matrix operator/(const D &r) const{ return *this * (1 / r); }
	Matrix& operator*=(const Matrix& r) { return *this = *this * r; }
	Matrix operator+(Matrix a, const Matrix& b) { return a += b; }
	Matrix operator-(Matrix a, const Matrix& b) { return a -= b; }
	Matrix& operator*=(const D& r) { return *this = *this * r; }
	Matrix& operator/=(const D &r) { return *this = *this / r; }

	Matrix pow(long long n) const {
		assert(h() == w());
		Matrix x = *this, r(h(), std::vector<D>(w()));
		for (int i = 0; i < h(); i++) r[i][i] = D(1);
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
};

template <class D> std::vector<D> solve_linear(Matrix<D> a, std::vector<D> b, D eps) {
	int h = a.h(), w = a.w();
	int r = 0;
	std::vector<int> idxs;
	for (int x = 0; x < w; x++) {
		for (int y = r + 1; y < h; y++) {
			D d = hypot(a[r][x], a[y][x]);
			if (abs(d) <= eps) continue;
			D c = a[r][x] / d, s = a[y][x] / d;
			auto rot = [&](D& u, D& v) {
				tie(u, v) = make_pair(c * u + s * v, c * v - s * u);
			};
			rot(b[r], b[y]);
			for (int k = x; k < w; k++) rot(a[r][k], a[y][k]);
		}
		if (a[r][x] <= eps) continue;
		r++;
		idxs.push_back(x);
		if (r == h) break;
	}
	std::vector<D> v(w);
	for (int y = r - 1; y >= 0; y--) {
		int f = idxs[y];
		v[f] = b[y];
		for (int x = f + 1; x < w; x++) {
			v[f] -= a[y][x] * v[x];
		}
		v[f] /= a[y][f];
	}
	return v;
}

template <class Mint> std::vector<Mint> solve_linear(Matrix<Mint> a, std::vector<Mint> b) {
	int h = a.h(), w = a.w();
	int r = 0;
	std::vector<int> idxs;
	for (int x = 0; x < w; x++) {
		int my = -1;
		for (int y = r; y < h; y++) {
			if (a[y][x]) {
				my = y;
				break;
			}
		}
		if (my == -1) continue;
		if (r != my) std::swap(a[r], a[my]);
		std::swap(b[r], b[my]);
		for (int y = r + 1; y < h; y++) {
			if (!a[y][x]) continue;
			auto freq = a[y][x] / a[r][x];
			for (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];
			b[y] -= freq * b[r];
		}
		r++;
		idxs.push_back(x);
		if (r == h) break;
	}
	std::vector<Mint> v(w);
	for (int y = r - 1; y >= 0; y--) {
		int f = idxs[y];
		v[f] = b[y];
		for (int x = f + 1; x < w; x++) {
			v[f] -= a[y][x] * v[x];
		}
		v[f] /= a[y][f];
	}
	return v;
}

template <class Mint> int calc_rank(Matrix<Mint> a) {
	int h = a.h(), w = a.w();
	int r = 0;
	std::vector<int> idxs;
	for (int x = 0; x < w; x++) {
		int my = -1;
		for (int y = r; y < h; y++) {
			if (a[y][x]) {
				my = y;
				break;
			}
		}
		if (my == -1) continue;
		if (r != my) std::swap(a[r], a[my]);
		for (int y = r + 1; y < h; y++) {
			if (!a[y][x]) continue;
			auto freq = a[y][x] / a[r][x];
			for (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];
		}
		r++;
		idxs.push_back(x);
		if (r == h) break;
	}
	return r;
}

template <class Mint> Mint calc_det(Matrix<Mint> a) {
	assert(a.h() == a.w());
	int n = a.h();

	bool flip = false;
	for (int x = 0; x < n; x++) {
		int my = -1;
		for (int y = x; y < n; y++) {
			if (a[y][x]) {
				my = y;
				break;
			}
		}
		if (my == -1) return 0;
		if (x != my) {
			std::swap(a[x], a[my]);
			if ((x - my) % 2) flip = !flip;
		}
		for (int y = x + 1; y < n; y++) {
			if (!a[y][x]) continue;
			auto freq = a[y][x] / a[x][x];
			for (int k = x; k < n; k++) a[y][k] -= freq * a[x][k];
		}
	}
	Mint det = (!flip ? 1 : -1);
	for (int i = 0; i < n; i++) {
		det *= a[i][i];
	}
	return det;
}

template <class Mint> Matrix<Mint> inverse(Matrix<Mint> a) {
	assert(a.h() == a.w());
	int n = a.h();
	Matrix<Mint> b(n, std::vector<Mint>(n));
	for (int i = 0; i < n; i++) b[i][i] = 1;
	for (int x = 0; x < n; x++) {
		int my = -1;
		for (int y = x; y < n; y++) {
			if (a[y][x]) {
				my = y;
				break;
			}
		}
		if (my == -1) return {};
		if (x != my) {
			std::swap(a[x], a[my]);
			std::swap(b[x], b[my]);
		}
		auto freq = a[x][x];
		for (int j = 0; j < n; j++) {
			a[x][j] /= freq;
			b[x][j] /= freq;
		}
		for (int y = 0; y < n; y++) {
			if (x == y) continue;
			if (!a[y][x]) continue;
			freq = a[y][x];
			for (int k = 0; k < n; k++) a[y][k] -= freq * a[x][k];
			for (int k = 0; k < n; k++) b[y][k] -= freq * b[x][k];
		}
	}
	return b;
}

template <class D> Matrix<D> make_matrix(int r, int c) { return Matrix<D>(r, std::vector<D>(c)); }
