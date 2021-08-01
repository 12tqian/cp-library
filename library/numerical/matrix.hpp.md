---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/kattis/kattis-equationsolver-matrix.test.cpp
    title: verify/kattis/kattis-equationsolver-matrix.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
    title: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "template <class D> struct Matrix : std::vector<std::vector<D>> {\n\
    \ttemplate <class T> using V = std::vector<T>;\n\ttemplate <class T> using VV\
    \ = V<V<T>>;\n\tusing VV<D>::VV;\n\n\tint h() const { return int(this->size());\
    \ }\n\tint w() const { return int((*this)[0].size()); }\n\n\tMatrix operator*(const\
    \ Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tMatrix res(h(), std::vector<D>(r.w()));\n\
    \t\tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < r.w(); j++) {\n\
    \t\t\t\tfor (int k = 0; k < w(); k++) {\n\t\t\t\t\tres[i][j] += (*this)[i][k]\
    \ * r[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tMatrix<D>&\
    \ operator+=(const Matrix& r) {\n\t\tassert(h() == r.h() && w == r.w());\n\t\t\
    for (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\t\
    \t(*this)[i][j] += r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix&\
    \ operator-=(const Matrix& r) {\n\t\tassert(h() == r.h() && w == r.w());\n\t\t\
    for (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\t\
    \t(*this)[i][j] -= r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix\
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
    \ a, std::vector<D> b, const D& EPS = -1) {\n    int h = a.h(), w = a.w();\n \
    \   assert(int(b.size()) == h);\n    int r = 0;\n    std::vector<bool> used(w);\n\
    \    std::vector<int> idxs;\n    for (int x = 0; x < w; x++) {\n        int my\
    \ = get_row(a, h, x, r, EPS);\n        if (my == -1) continue;\n        if (r\
    \ != my) std::swap(a[r], a[my]);\n        swap(b[r], b[my]);\n        for (int\
    \ y = r + 1; y < h; y++) {\n            if (!a[y][x]) continue;\n            auto\
    \ freq = a[y][x] / a[r][x];\n            for (int k = x; k < w; k++) a[y][k] -=\
    \ freq * a[r][k];\n            b[y] -= freq * b[r];\n        }\n        r++;\n\
    \        used[x] = true;\n        idxs.push_back(x);\n        if (r == h) break;\n\
    \    }\n    for (int y = r; y < h; y++) {\n        if (b[y]) return {};\n    }\n\
    \    std::vector<std::vector<D>> sols;\n    { // initial solution\n        std::vector<D>\
    \ v(w);\n        for (int y = r - 1; y >= 0; y--) {\n            int f = idxs[y];\n\
    \            v[f] = b[y];\n            for (int x = f + 1; x < w; x++) {\n   \
    \             v[f] -= a[y][x] * v[x];\n            }\n            v[f] /= a[y][f];\n\
    \        }\n        sols.push_back(v);\n    }\n    for (int s = 0; s < w; s++)\
    \ {\n        if (used[s]) continue;\n        std::vector<D> v(w);\n        v[s]\
    \ = D(1);\n        for (int y = r - 1; y >= 0; y--) {\n            int f = idxs[y];\n\
    \            for (int x = f + 1; x < w; x++) {\n                v[f] -= a[y][x]\
    \ * v[x];\n            }\n            v[f] /= a[y][f];\n        }\n        sols.push_back(v);\n\
    \    }\n    return sols;\n}\n\n} // MatrixOperations\n"
  code: "#pragma once\ntemplate <class D> struct Matrix : std::vector<std::vector<D>>\
    \ {\n\ttemplate <class T> using V = std::vector<T>;\n\ttemplate <class T> using\
    \ VV = V<V<T>>;\n\tusing VV<D>::VV;\n\n\tint h() const { return int(this->size());\
    \ }\n\tint w() const { return int((*this)[0].size()); }\n\n\tMatrix operator*(const\
    \ Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tMatrix res(h(), std::vector<D>(r.w()));\n\
    \t\tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < r.w(); j++) {\n\
    \t\t\t\tfor (int k = 0; k < w(); k++) {\n\t\t\t\t\tres[i][j] += (*this)[i][k]\
    \ * r[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tMatrix<D>&\
    \ operator+=(const Matrix& r) {\n\t\tassert(h() == r.h() && w == r.w());\n\t\t\
    for (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\t\
    \t(*this)[i][j] += r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix&\
    \ operator-=(const Matrix& r) {\n\t\tassert(h() == r.h() && w == r.w());\n\t\t\
    for (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\t\
    \t(*this)[i][j] -= r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix\
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
    \ a, std::vector<D> b, const D& EPS = -1) {\n    int h = a.h(), w = a.w();\n \
    \   assert(int(b.size()) == h);\n    int r = 0;\n    std::vector<bool> used(w);\n\
    \    std::vector<int> idxs;\n    for (int x = 0; x < w; x++) {\n        int my\
    \ = get_row(a, h, x, r, EPS);\n        if (my == -1) continue;\n        if (r\
    \ != my) std::swap(a[r], a[my]);\n        swap(b[r], b[my]);\n        for (int\
    \ y = r + 1; y < h; y++) {\n            if (!a[y][x]) continue;\n            auto\
    \ freq = a[y][x] / a[r][x];\n            for (int k = x; k < w; k++) a[y][k] -=\
    \ freq * a[r][k];\n            b[y] -= freq * b[r];\n        }\n        r++;\n\
    \        used[x] = true;\n        idxs.push_back(x);\n        if (r == h) break;\n\
    \    }\n    for (int y = r; y < h; y++) {\n        if (b[y]) return {};\n    }\n\
    \    std::vector<std::vector<D>> sols;\n    { // initial solution\n        std::vector<D>\
    \ v(w);\n        for (int y = r - 1; y >= 0; y--) {\n            int f = idxs[y];\n\
    \            v[f] = b[y];\n            for (int x = f + 1; x < w; x++) {\n   \
    \             v[f] -= a[y][x] * v[x];\n            }\n            v[f] /= a[y][f];\n\
    \        }\n        sols.push_back(v);\n    }\n    for (int s = 0; s < w; s++)\
    \ {\n        if (used[s]) continue;\n        std::vector<D> v(w);\n        v[s]\
    \ = D(1);\n        for (int y = r - 1; y >= 0; y--) {\n            int f = idxs[y];\n\
    \            for (int x = f + 1; x < w; x++) {\n                v[f] -= a[y][x]\
    \ * v[x];\n            }\n            v[f] /= a[y][f];\n        }\n        sols.push_back(v);\n\
    \    }\n    return sols;\n}\n\n} // MatrixOperations"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/matrix.hpp
  requiredBy: []
  timestamp: '2021-07-31 22:31:54-04:00'
  verificationStatus: LIBRARY_ALL_WA
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
