#include <bits/stdc++.h>

namespace MatrixOperations {

template <class T> using Matrix = std::vector<std::vector<T>>;

template <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c)); }

template <class T> Matrix<T>& operator += (Matrix<T>& a, const Matrix<T>& b) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            a[i][j] += b[i][j];
        }
    }
    return a;
}

template <class T> Matrix<T>& operator -= (Matrix<T>& a, const Matrix<T>& b) {
    for (int i = 0; i < (int)a.size(); i++) {
        for (int j = 0; j < (int)a[0].size(); j++) {
            a[i][j] -= b[i][j];
        }
    }
    return a;
}

template <class T> Matrix<T> operator * (const Matrix<T>& a, const Matrix<T>& b) {
    assert(a[0].size() == b.size());
    int x = (int)a.size();
    int y = (int)a[0].size();
    int z = (int)b[0].size();
    Matrix<T> c = make_matrix<T>(x, z);
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            for (int k = 0; k < z; k++) {
                c[i][k] += a[i][j] * b[j][k];
            }
        }
    }
    return c;
}

template <class T> Matrix<T> operator + (Matrix<T> a, const Matrix<T>& b) { return a += b; }
template <class T> Matrix<T> operator - (Matrix<T> a, const Matrix<T>& b) { return a -= b; }
template <class T> Matrix<T>& operator *= (Matrix<T>& a, const Matrix<T>& b) { return a = a * b; }

template <class T> Matrix<T> pow(Matrix<T> m, long long p) {
    int n = (int)m.size();
    assert(n == (int)m[0].size() && p >= 0);
    Matrix<T> res = make_matrix<T>(n, n);
    for (int i = 0; i < n; i++) 
        res[i][i] = 1;
    for (; p; p >>= 1, m *= m) {
        if (p & 1) {
            res *= m;
        }
    }
    return res;
}

template <class T> int get_row(Matrix<T>& m, int r, int i, int nxt) {
    for (int j = nxt; j < r; j++) {
        if (m[j][i] != 0) {
            return j;
        }
    }
    return -1;
}

const long double EPS = 1e-12;

template <> int get_row<long double>(Matrix<long double>& m, int r, int i, int nxt) {
    std::pair<long double, int> best = {0, -1};
    for (int j = nxt; j < r; j++) {
        best = std::max(best, {abs(m[j][i]), j});
    }
    return best.first < EPS ? -1 : best.second;
}

// returns a pair of determinant, rank, while doing Gaussian elimination to m
template <class T> std::pair<T, int> gauss(Matrix<T>& m) {
    int r = (int)m.size();
    int c = (int)m[0].size();
    int rank = 0, nxt = 0;
    T prod = 1;
    for (int i = 0; i < r; i++) {
        int row = get_row(m, r, i, nxt);
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
        T x = 1 / m[nxt][i];
        for (int k = i; k < c; k++) 
            m[nxt][k] *= x;
        for (int j = 0; j < r; j++) {
            if (j != nxt) {
                T v = m[j][i];
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

template <class T> Matrix<T> inv(Matrix<T> m) {
    int r = (int)m.size();
    assert(r == (int)m[0].size());
    Matrix<T> x = make_matrix<T>(r, 2 * r);
    for (int i = 0; i < r; i++) {
        x[i][i + r] = 1;
        for (int j = 0; j < r; j++) {
            x[i][j] = m[i][j];
        }
    }
    if (gauss(x).second != r) return Matrix<T>();
    Matrix<T> res = make_matrix<T>(r, r);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            res[i][j] = x[i][j + r];
        }
    }
    return res;
}

} // namespace MatrixOperations

int main() {
    using namespace std;
    using namespace MatrixOperations;
    using Mat = Matrix<long double>;
    while (true) {
        int n; cin >> n;
        if (n == 0) break;
        Mat a = make_matrix<long double>(n, n + 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> a[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i][n];
        }
        auto res = gauss(a);
        vector<long double> ans;
        bool inf = false;
        bool sol = true;
        for (int i = 0; i < n; i++) {  
            bool one = false;
            for (int j = 0; j < n; j++) {
                if (abs(a[i][j] - 1) < EPS) {
                    one = true;
                    break;
                }
            }
            if (one) {
                ans.push_back(a[i].back());
                continue;
            }
            if (abs(a[i].back()) >= EPS) {
                sol = false;
                break;
            } 
            if (abs(a[i].back()) < EPS) {
                inf = true;
            }
        }
        if (!sol) {
            cout << "inconsistent\n";
        } else if (inf) {
            cout << "multiple\n";
        } else {
            for (auto& t : ans) 
                cout << t << " ";
            cout << '\n';
        }
    }
    return 0;
}