#pragma once

/**
 * Maximizes c^Tx given Ax <= b, x >= 0
 * Returns -INF if no solution
 * INF if there are many good solutions
 * Maximum value of c^Tx otherwise
 */

template <class T> struct Simplex {
	const T EPS = 1e-8;
	const T INF = 1 / .0;
	
	int m, n; // constraints, variables

	std::vector<int> N, B;

	std::vector<std::vector<T>> D;

	Simplex(const std::vector<std::vector<T>> &A, const std::vector<T> &b, const std::vector<T> &c) : 
	m(b.size()), n(c.size()), N(n + 1), B(m), D(m + 2, std::vector<T>(n + 2)) {
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				D[i][j] = A[i][j];
			}
		}
		for (int i = 0; i < m; ++i) {
			B[i] = n + i;
			D[i][n] = -1;
			D[i][n + 1] = b[i];
		}
		for (int j = 0; j < n; ++j) {
			N[j] = j;
			D[m][j] = -c[j];
		}
		N[n] = -1;
		D[m + 1][n] = 1;
	}

	void pivot(int r, int s) {
		T *a = D[r].data(), inv = 1 / a[s];
		for (int i = 0; i < m + 2; ++i) {
			if (i != r && std::abs(D[i][s]) > EPS) {
				T *b = D[i].data(), binv = b[s] * inv;
				for (int j = 0; j < n + 2; ++j) {
					b[j] -= a[j] * binv;
				}
				b[s] = a[s] * binv;
			}
		}
		for (int j = 0; j < n + 2; ++j) {
			if (j != s) {
				D[r][j] *= inv;
			}
		}
		for (int i = 0; i < m + 2; ++i) {
			if (i != r) {
				D[i][s] *= -inv;
			}
		}
		D[r][s] = inv;
		std::swap(B[r], N[s]);
	}

	bool simplex(int phase) {
		int x = m + phase - 1;
		while (true) {
			int s = -1;
			for (int j = 0; j < n + 1; ++j) {
				if (N[j] != -phase) {
					if (s == -1 || std::make_pair(D[x][j], N[j]) < std::make_pair(D[x][s], N[s])) {
						s = j;
					}
				}
			}
			if (D[x][s] >= -EPS) {
				return true;
			}
			int r = -1;
			for (int i = 0; i < m; ++i) {
				if (D[i][s] <= EPS) {
					continue;
				}
				if (r == -1 || std::make_pair(D[i][n + 1] / D[i][s], B[i]) 
					< std::make_pair(D[r][n + 1] / D[r][s], B[r])) {
					r = i;
				}
			}
			if (r == -1) {
				return false;
			}
			pivot(r, s);
		}
	}

	T solve(std::vector<T> &x) {
		int r = 0;
		for (int i = 1; i < m; ++i) {
			if (D[i][n + 1] < D[r][n + 1]) {
				r = i;
			}
		}
		if (D[r][n + 1] < -EPS) {
			pivot(r, n);
			if (!simplex(2) || D[m + 1][n + 1] < -EPS) {
				return -INF;
			}
			for (int i = 0; i < m; ++i) {
				if (B[i] == -1) {
					int s = 0;
					for (int j = 1; j < n + 1; ++j) {
						if (s == -1 || std::make_pair(D[i][j], N[j]) < std::make_pair(D[i][s], N[s])) {
							s = j;
						}
					}
					pivot(i, s);
				}
			}
		}
		bool ok = simplex(1);
		x.assign(n, 0);
		for (int i = 0; i < m; ++i) {
			if (B[i] < n) {
				x[B[i]] = D[i][n + 1];
			}
		}
		return ok ? D[m][n + 1] : INF;
	}
};