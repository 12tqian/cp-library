---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kattis/kattis-equationsolver-matrix.test.cpp
    title: verify/kattis/kattis-equationsolver-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
    title: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class D> struct Matrix : std::vector<std::vector<D>> {\n\
    \tusing std::vector<std::vector<D>>::vector;\n\n\tint h() const { return int(this->size());\
    \ }\n\tint w() const { return int((*this)[0].size()); }\n\n\tMatrix operator*(const\
    \ Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tMatrix res(h(), std::vector<D>(r.w()));\n\
    \t\tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < r.w(); j++) {\n\
    \t\t\t\tfor (int k = 0; k < w(); k++) {\n\t\t\t\t\tres[i][j] += (*this)[i][k]\
    \ * r[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tMatrix<D>&\
    \ operator+=(const Matrix& r) {\n\t\tassert(h() == r.h() && w() == r.w());\n\t\
    \tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\
    \t\t(*this)[i][j] += r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix&\
    \ operator-=(const Matrix& r) {\n\t\tassert(h() == r.h() && w() == r.w());\n\t\
    \tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\
    \t\t(*this)[i][j] -= r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix\
    \ operator*(const D& r) const {\n\t\tMatrix res = (*this);\n\t\tfor (int i = 0;\
    \ i < h(); ++i) {\n\t\t\tfor (int j = 0; j < w(); ++j) {\n\t\t\t\tres[i][j] *=\
    \ r;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tMatrix operator/(const D &r) const{\
    \ return *this * (1 / r); }\n\tMatrix& operator*=(const Matrix& r) { return *this\
    \ = *this * r; }\n\tMatrix operator+(const Matrix& r) { return *this += r; }\n\
    \tMatrix operator-(const Matrix& r) { return *this -= r; }\n\tMatrix& operator*=(const\
    \ D& r) { return *this = *this * r; }\n\tMatrix& operator/=(const D &r) { return\
    \ *this = *this / r; }\n\tfriend Matrix operator*(const D& r, Matrix m) { return\
    \ m *= r; }\n\n\tMatrix pow(long long n) const {\n\t\tassert(h() == w());\n\t\t\
    Matrix x = *this, r(h(), std::vector<D>(w()));\n\t\tfor (int i = 0; i < h(); i++)\
    \ r[i][i] = D(1);\n\t\twhile (n) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\
    \t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n};\n\nnamespace MatrixOperations {\n\n\
    template <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c));\
    \ }\n\n\ntemplate <class D> Matrix<D> inv(Matrix<D> m, const D& EPS = -1) {\n\t\
    int r = m.h();\n\tassert(m.h() == m.w());\n\tMatrix<D> x = make_matrix<D>(r, 2\
    \ * r);\n\tfor (int i = 0; i < r; i++) {\n\t\tx[i][i + r] = 1;\n\t\tfor (int j\
    \ = 0; j < r; j++) {\n\t\t\tx[i][j] = m[i][j];\n\t\t}\n\t}\n\tif (gauss(x, EPS).second\
    \ != r) return Matrix<D>();\n\tMatrix<D> res = make_matrix<D>(r, r);\n\tfor (int\
    \ i = 0; i < r; i++) {\n\t\tfor (int j = 0; j < r; j++) {\n\t\t\tres[i][j] = x[i][j\
    \ + r];\n\t\t}\n\t}\n\treturn res;\n}\n\ntemplate <class D> int get_row(Matrix<D>&\
    \ m, int r, int i, int nxt, const D& EPS = -1) {\n\tstd::pair<D, int> best = {0,\
    \ -1};\n\tfor (int j = nxt; j < r; j++) {\n\t\tif (EPS == D(-1) && m[j][i] !=\
    \ 0) {\n\t\t\treturn j;\n\t\t}\n\t\tauto v = m[j][i];\n\t\tif (v < 0) v = -v;\n\
    \t\tbest = std::max(best, std::make_pair(v, j));\n\t}\n\treturn best.first < EPS\
    \ ? -1 : best.second;\n}\n\n// returns a pair of determinant, rank, while doing\
    \ Gaussian elimination to m\ntemplate <class D> std::pair<D, int> gauss(Matrix<D>&\
    \ m, const D& EPS = -1) {\n\tint r = m.h();\n\tint c = m.w();\n\tint rank = 0,\
    \ nxt = 0;\n\tD prod = 1;\n\tfor (int i = 0; i < r; i++) {\n\t\tint row = get_row(m,\
    \ r, i, nxt, EPS);\n\t\tif (row == -1) {\n\t\t\tprod = 0;\n\t\t\tcontinue;\n\t\
    \t}\n\t\tif (row != nxt) {\n\t\t\tprod *= -1;\n\t\t\tm[row].swap(m[nxt]);\n\t\t\
    }\n\t\tprod *= m[nxt][i];\n\t\trank++;\n\t\tD x = 1 / m[nxt][i];\n\t\tfor (int\
    \ k = i; k < c; k++) \n\t\t\tm[nxt][k] *= x;\n\t\tfor (int j = 0; j < r; j++)\
    \ {\n\t\t\tif (j != nxt) {\n\t\t\t\tD v = m[j][i];\n\t\t\t\tif (v == 0) continue;\n\
    \t\t\t\tfor (int k = i; k < c; k++) {\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\tnxt++;\n\t}\n\treturn {prod, rank};\n}\n\ntemplate\
    \ <class D> int calc_rank(Matrix<D> a, const D& EPS = -1) { return gauss(a, EPS).second;\
    \ }\ntemplate <class D> D calc_det(Matrix<D> a, const D& EPS = -1) { return gauss(a,\
    \ EPS).first; }\n\ntemplate <class D> std::vector<std::vector<D>> solve_linear(Matrix<D>\
    \ a, std::vector<D> b, const D& EPS = -1) {\n\tint h = a.h(), w = a.w();\n\tassert(int(b.size())\
    \ == h);\n\tint r = 0;\n\tstd::vector<bool> used(w);\n\tstd::vector<int> idxs;\n\
    \tfor (int x = 0; x < w; x++) {\n\t\tint my = get_row(a, h, x, r, EPS);\n\t\t\
    if (my == -1) continue;\n\t\tif (r != my) std::swap(a[r], a[my]);\n\t\tstd::swap(b[r],\
    \ b[my]);\n\t\tfor (int y = r + 1; y < h; y++) {\n\t\t\tif (!a[y][x]) continue;\n\
    \t\t\tauto freq = a[y][x] / a[r][x];\n\t\t\tfor (int k = x; k < w; k++) a[y][k]\
    \ -= freq * a[r][k];\n\t\t\tb[y] -= freq * b[r];\n\t\t}\n\t\tr++;\n\t\tused[x]\
    \ = true;\n\t\tidxs.push_back(x);\n\t\tif (r == h) break;\n\t}\n\tauto zero =\
    \ [&](const D& x) {\n\t\treturn EPS == D(-1) ? x == 0 : -EPS < x && x < EPS;\n\
    \t};\n\tfor (int y = r; y < h; y++) {\n\t\tif (!zero(b[y])) return {};\n\t}\n\t\
    std::vector<std::vector<D>> sols;\n\t{ // initial solution\n\t\tstd::vector<D>\
    \ v(w);\n\t\tfor (int y = r - 1; y >= 0; y--) {\n\t\t\tint f = idxs[y];\n\t\t\t\
    v[f] = b[y];\n\t\t\tfor (int x = f + 1; x < w; x++) {\n\t\t\t\tv[f] -= a[y][x]\
    \ * v[x];\n\t\t\t}\n\t\t\tv[f] /= a[y][f];\n\t\t}\n\t\tsols.push_back(v);\n\t\
    }\n\tfor (int s = 0; s < w; s++) {\n\t\tif (used[s]) continue;\n\t\tstd::vector<D>\
    \ v(w);\n\t\tv[s] = D(1);\n\t\tfor (int y = r - 1; y >= 0; y--) {\n\t\t\tint f\
    \ = idxs[y];\n\t\t\tfor (int x = f + 1; x < w; x++) {\n\t\t\t\tv[f] -= a[y][x]\
    \ * v[x];\n\t\t\t}\n\t\t\tv[f] /= a[y][f];\n\t\t}\n\t\tsols.push_back(v);\n\t\
    }\n\treturn sols;\n}\n\n} // MatrixOperations\n"
  code: "#pragma once\n\ntemplate <class D> struct Matrix : std::vector<std::vector<D>>\
    \ {\n\tusing std::vector<std::vector<D>>::vector;\n\n\tint h() const { return\
    \ int(this->size()); }\n\tint w() const { return int((*this)[0].size()); }\n\n\
    \tMatrix operator*(const Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tMatrix\
    \ res(h(), std::vector<D>(r.w()));\n\t\tfor (int i = 0; i < h(); i++) {\n\t\t\t\
    for (int j = 0; j < r.w(); j++) {\n\t\t\t\tfor (int k = 0; k < w(); k++) {\n\t\
    \t\t\t\tres[i][j] += (*this)[i][k] * r[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\t\
    return res;\n\t}\n\n\tMatrix<D>& operator+=(const Matrix& r) {\n\t\tassert(h()\
    \ == r.h() && w() == r.w());\n\t\tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int\
    \ j = 0; j < h(); j++) {\n\t\t\t\t(*this)[i][j] += r[i][j];\n\t\t\t}\n\t\t}\n\t\
    \treturn *this;\n\t}\n\n\tMatrix& operator-=(const Matrix& r) {\n\t\tassert(h()\
    \ == r.h() && w() == r.w());\n\t\tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int\
    \ j = 0; j < h(); j++) {\n\t\t\t\t(*this)[i][j] -= r[i][j];\n\t\t\t}\n\t\t}\n\t\
    \treturn *this;\n\t}\n\n\tMatrix operator*(const D& r) const {\n\t\tMatrix res\
    \ = (*this);\n\t\tfor (int i = 0; i < h(); ++i) {\n\t\t\tfor (int j = 0; j < w();\
    \ ++j) {\n\t\t\t\tres[i][j] *= r;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\t\
    Matrix operator/(const D &r) const{ return *this * (1 / r); }\n\tMatrix& operator*=(const\
    \ Matrix& r) { return *this = *this * r; }\n\tMatrix operator+(const Matrix& r)\
    \ { return *this += r; }\n\tMatrix operator-(const Matrix& r) { return *this -=\
    \ r; }\n\tMatrix& operator*=(const D& r) { return *this = *this * r; }\n\tMatrix&\
    \ operator/=(const D &r) { return *this = *this / r; }\n\tfriend Matrix operator*(const\
    \ D& r, Matrix m) { return m *= r; }\n\n\tMatrix pow(long long n) const {\n\t\t\
    assert(h() == w());\n\t\tMatrix x = *this, r(h(), std::vector<D>(w()));\n\t\t\
    for (int i = 0; i < h(); i++) r[i][i] = D(1);\n\t\twhile (n) {\n\t\t\tif (n &\
    \ 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n};\n\n\
    namespace MatrixOperations {\n\ntemplate <class T> Matrix<T> make_matrix(int r,\
    \ int c) { return Matrix<T>(r, std::vector<T>(c)); }\n\n\ntemplate <class D> Matrix<D>\
    \ inv(Matrix<D> m, const D& EPS = -1) {\n\tint r = m.h();\n\tassert(m.h() == m.w());\n\
    \tMatrix<D> x = make_matrix<D>(r, 2 * r);\n\tfor (int i = 0; i < r; i++) {\n\t\
    \tx[i][i + r] = 1;\n\t\tfor (int j = 0; j < r; j++) {\n\t\t\tx[i][j] = m[i][j];\n\
    \t\t}\n\t}\n\tif (gauss(x, EPS).second != r) return Matrix<D>();\n\tMatrix<D>\
    \ res = make_matrix<D>(r, r);\n\tfor (int i = 0; i < r; i++) {\n\t\tfor (int j\
    \ = 0; j < r; j++) {\n\t\t\tres[i][j] = x[i][j + r];\n\t\t}\n\t}\n\treturn res;\n\
    }\n\ntemplate <class D> int get_row(Matrix<D>& m, int r, int i, int nxt, const\
    \ D& EPS = -1) {\n\tstd::pair<D, int> best = {0, -1};\n\tfor (int j = nxt; j <\
    \ r; j++) {\n\t\tif (EPS == D(-1) && m[j][i] != 0) {\n\t\t\treturn j;\n\t\t}\n\
    \t\tauto v = m[j][i];\n\t\tif (v < 0) v = -v;\n\t\tbest = std::max(best, std::make_pair(v,\
    \ j));\n\t}\n\treturn best.first < EPS ? -1 : best.second;\n}\n\n// returns a\
    \ pair of determinant, rank, while doing Gaussian elimination to m\ntemplate <class\
    \ D> std::pair<D, int> gauss(Matrix<D>& m, const D& EPS = -1) {\n\tint r = m.h();\n\
    \tint c = m.w();\n\tint rank = 0, nxt = 0;\n\tD prod = 1;\n\tfor (int i = 0; i\
    \ < r; i++) {\n\t\tint row = get_row(m, r, i, nxt, EPS);\n\t\tif (row == -1) {\n\
    \t\t\tprod = 0;\n\t\t\tcontinue;\n\t\t}\n\t\tif (row != nxt) {\n\t\t\tprod *=\
    \ -1;\n\t\t\tm[row].swap(m[nxt]);\n\t\t}\n\t\tprod *= m[nxt][i];\n\t\trank++;\n\
    \t\tD x = 1 / m[nxt][i];\n\t\tfor (int k = i; k < c; k++) \n\t\t\tm[nxt][k] *=\
    \ x;\n\t\tfor (int j = 0; j < r; j++) {\n\t\t\tif (j != nxt) {\n\t\t\t\tD v =\
    \ m[j][i];\n\t\t\t\tif (v == 0) continue;\n\t\t\t\tfor (int k = i; k < c; k++)\
    \ {\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\tnxt++;\n\
    \t}\n\treturn {prod, rank};\n}\n\ntemplate <class D> int calc_rank(Matrix<D> a,\
    \ const D& EPS = -1) { return gauss(a, EPS).second; }\ntemplate <class D> D calc_det(Matrix<D>\
    \ a, const D& EPS = -1) { return gauss(a, EPS).first; }\n\ntemplate <class D>\
    \ std::vector<std::vector<D>> solve_linear(Matrix<D> a, std::vector<D> b, const\
    \ D& EPS = -1) {\n\tint h = a.h(), w = a.w();\n\tassert(int(b.size()) == h);\n\
    \tint r = 0;\n\tstd::vector<bool> used(w);\n\tstd::vector<int> idxs;\n\tfor (int\
    \ x = 0; x < w; x++) {\n\t\tint my = get_row(a, h, x, r, EPS);\n\t\tif (my ==\
    \ -1) continue;\n\t\tif (r != my) std::swap(a[r], a[my]);\n\t\tstd::swap(b[r],\
    \ b[my]);\n\t\tfor (int y = r + 1; y < h; y++) {\n\t\t\tif (!a[y][x]) continue;\n\
    \t\t\tauto freq = a[y][x] / a[r][x];\n\t\t\tfor (int k = x; k < w; k++) a[y][k]\
    \ -= freq * a[r][k];\n\t\t\tb[y] -= freq * b[r];\n\t\t}\n\t\tr++;\n\t\tused[x]\
    \ = true;\n\t\tidxs.push_back(x);\n\t\tif (r == h) break;\n\t}\n\tauto zero =\
    \ [&](const D& x) {\n\t\treturn EPS == D(-1) ? x == 0 : -EPS < x && x < EPS;\n\
    \t};\n\tfor (int y = r; y < h; y++) {\n\t\tif (!zero(b[y])) return {};\n\t}\n\t\
    std::vector<std::vector<D>> sols;\n\t{ // initial solution\n\t\tstd::vector<D>\
    \ v(w);\n\t\tfor (int y = r - 1; y >= 0; y--) {\n\t\t\tint f = idxs[y];\n\t\t\t\
    v[f] = b[y];\n\t\t\tfor (int x = f + 1; x < w; x++) {\n\t\t\t\tv[f] -= a[y][x]\
    \ * v[x];\n\t\t\t}\n\t\t\tv[f] /= a[y][f];\n\t\t}\n\t\tsols.push_back(v);\n\t\
    }\n\tfor (int s = 0; s < w; s++) {\n\t\tif (used[s]) continue;\n\t\tstd::vector<D>\
    \ v(w);\n\t\tv[s] = D(1);\n\t\tfor (int y = r - 1; y >= 0; y--) {\n\t\t\tint f\
    \ = idxs[y];\n\t\t\tfor (int x = f + 1; x < w; x++) {\n\t\t\t\tv[f] -= a[y][x]\
    \ * v[x];\n\t\t\t}\n\t\t\tv[f] /= a[y][f];\n\t\t}\n\t\tsols.push_back(v);\n\t\
    }\n\treturn sols;\n}\n\n} // MatrixOperations"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/matrix.hpp
  requiredBy: []
  timestamp: '2021-08-13 10:21:59-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-system_of_linear_equations.test.cpp
  - verify/kattis/kattis-equationsolver-matrix.test.cpp
documentation_of: library/numerical/matrix.hpp
layout: document
redirect_from:
- /library/library/numerical/matrix.hpp
- /library/library/numerical/matrix.hpp.html
title: library/numerical/matrix.hpp
---
