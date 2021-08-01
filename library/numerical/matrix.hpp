#pragma once
template <class D> struct Matrix : std::vector<std::vector<D>> {
	template <class T> using V = std::vector<T>;
	template <class T> using VV = V<V<T>>;
	using VV<D>::VV;

	int h() const { return int(this->size()); }
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

	Matrix<D>& operator+=(const Matrix& r) {
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
	Matrix operator+(const Matrix& r) { return *this += r; }
	Matrix operator-(const Matrix& r) { return *this -= r; }
	Matrix& operator*=(const D& r) { return *this = *this * r; }
	Matrix& operator/=(const D &r) { return *this = *this / r; }
	friend Matrix operator*(const D& r, Matrix m) { return m *= r; }

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

namespace MatrixOperations {

template <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c)); }


template <class D> Matrix<D> inv(Matrix<D> m, const D& EPS = -1) {
	int r = m.h();
	assert(m.h() == m.w());
	Matrix<D> x = make_matrix<D>(r, 2 * r);
	for (int i = 0; i < r; i++) {
		x[i][i + r] = 1;
		for (int j = 0; j < r; j++) {
			x[i][j] = m[i][j];
		}
	}
	if (gauss(x, EPS).second != r) return Matrix<D>();
	Matrix<D> res = make_matrix<D>(r, r);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < r; j++) {
			res[i][j] = x[i][j + r];
		}
	}
	return res;
}

template <class D> int get_row(Matrix<D>& m, int r, int i, int nxt, const D& EPS = -1) {
	std::pair<D, int> best = {0, -1};
	for (int j = nxt; j < r; j++) {
		if (EPS == D(-1) && m[j][i] != 0) {
			return j;
		}
		auto v = m[j][i];
		if (v < 0) v = -v;
		best = std::max(best, std::make_pair(v, j));
	}
	return best.first < EPS ? -1 : best.second;
}

// returns a pair of determinant, rank, while doing Gaussian elimination to m
template <class D> std::pair<D, int> gauss(Matrix<D>& m, const D& EPS = -1) {
	int r = m.h();
	int c = m.w();
	int rank = 0, nxt = 0;
	D prod = 1;
	for (int i = 0; i < r; i++) {
		int row = get_row(m, r, i, nxt, EPS);
		if (row == -1) {
			prod = 0;
			continue;
		}
		if (row != nxt) {
			prod *= -1;
			m[row].swap(m[nxt]);
		}
		prod *= m[nxt][i];
		rank++;
		D x = 1 / m[nxt][i];
		for (int k = i; k < c; k++) 
			m[nxt][k] *= x;
		for (int j = 0; j < r; j++) {
			if (j != nxt) {
				D v = m[j][i];
				if (v == 0) continue;
				for (int k = i; k < c; k++) {
					m[j][k] -= v * m[nxt][k];
				}
			}
		}
		nxt++;
	}
	return {prod, rank};
}

template <class D> int calc_rank(Matrix<D> a, const D& EPS = -1) { return gauss(a, EPS).second; }
template <class D> D calc_det(Matrix<D> a, const D& EPS = -1) { return gauss(a, EPS).first; }

template <class D> std::vector<std::vector<D>> solve_linear(Matrix<D> a, std::vector<D> b, const D& EPS = -1) {
    int h = a.h(), w = a.w();
    assert(int(b.size()) == h);
    int r = 0;
    std::vector<bool> used(w);
    std::vector<int> idxs;
    for (int x = 0; x < w; x++) {
        int my = get_row(a, h, x, r, EPS);
        if (my == -1) continue;
        if (r != my) std::swap(a[r], a[my]);
        swap(b[r], b[my]);
        for (int y = r + 1; y < h; y++) {
            if (!a[y][x]) continue;
            auto freq = a[y][x] / a[r][x];
            for (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];
            b[y] -= freq * b[r];
        }
        r++;
        used[x] = true;
        idxs.push_back(x);
        if (r == h) break;
    }
	auto zero = [&](const D& x) {
		return EPS == D(-1) ? x != 0 : -EPS < x && x < EPS;
	}
    for (int y = r; y < h; y++) {
        if (!zero(b[y])) return {};
    }
    std::vector<std::vector<D>> sols;
    { // initial solution
        std::vector<D> v(w);
        for (int y = r - 1; y >= 0; y--) {
            int f = idxs[y];
            v[f] = b[y];
            for (int x = f + 1; x < w; x++) {
                v[f] -= a[y][x] * v[x];
            }
            v[f] /= a[y][f];
        }
        sols.push_back(v);
    }
    for (int s = 0; s < w; s++) {
        if (used[s]) continue;
        std::vector<D> v(w);
        v[s] = D(1);
        for (int y = r - 1; y >= 0; y--) {
            int f = idxs[y];
            for (int x = f + 1; x < w; x++) {
                v[f] -= a[y][x] * v[x];
            }
            v[f] /= a[y][f];
        }
        sols.push_back(v);
    }
    return sols;
}

} // MatrixOperations