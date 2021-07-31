---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n#include <bits/stdc++.h>\n\ntemplate <class D> struct Matrix : std::vector<std::vector<D>\
    \ {\n\tusing std::vector<std::vector<D>::std::vector<std::vector;\n\tusing std::vector<std::vector<D>::size;\n\
    \n\tint h() const { return int(size()); }\n\tint w() const { return int((*this)[0].size());\
    \ }\n\n\tMatrix operator*(const Matrix& r) const {\n\t\tassert(w() == r.h());\n\
    \t\tMatrix res(h(), std::vector<D>(r.w()));\n\t\tfor (int i = 0; i < h(); i++)\
    \ {\n\t\t\tfor (int j = 0; j < r.w(); j++) {\n\t\t\t\tfor (int k = 0; k < w();\
    \ k++) {\n\t\t\t\t\tres[i][j] += (*this)[i][k] * r[k][j];\n\t\t\t\t}\n\t\t\t}\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tMatrix<T>& operator+=(const Matrix& r) {\n\t\t\
    assert(h() == r.h() && w == r.w());\n\t\tfor (int i = 0; i < h(); i++) {\n\t\t\
    \tfor (int j = 0; j < h(); j++) {\n\t\t\t\t(*this)[i][j] += r[i][j];\n\t\t\t}\n\
    \t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix& operator-=(const Matrix& r) {\n\t\t\
    assert(h() == r.h() && w == r.w());\n\t\tfor (int i = 0; i < h(); i++) {\n\t\t\
    \tfor (int j = 0; j < h(); j++) {\n\t\t\t\t(*this)[i][j] -= r[i][j];\n\t\t\t}\n\
    \t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix operator*(const D& r) const {\n\t\t\
    Matrix res = (*this);\n\t\tfor (int i = 0; i < h(); ++i) {\n\t\t\tfor (int j =\
    \ 0; j < w(); ++j) {\n\t\t\t\tres[i][j] *= r;\n\t\t\t}\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tMatrix operator/(const D &r) const{ return *this * (1 / r); }\n\tMatrix&\
    \ operator*=(const Matrix& r) { return *this = *this * r; }\n\tMatrix operator+(Matrix\
    \ a, const Matrix& b) { return a += b; }\n\tMatrix operator-(Matrix a, const Matrix&\
    \ b) { return a -= b; }\n\tMatrix& operator*=(const D& r) { return *this = *this\
    \ * r; }\n\tMatrix& operator/=(const D &r) { return *this = *this / r; }\n\n\t\
    Matrix pow(long long n) const {\n\t\tassert(h() == w());\n\t\tMatrix x = *this,\
    \ r(h(), std::vector<D>(w()));\n\t\tfor (int i = 0; i < h(); i++) r[i][i] = D(1);\n\
    \t\twhile (n) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t\
    }\n\t\treturn r;\n\t}\n};\n\ntemplate <class D> std::vector<D> solve_linear(Matrix<D>\
    \ a, std::vector<D> b, D eps) {\n\tint h = a.h(), w = a.w();\n\tint r = 0;\n\t\
    std::vector<int> idxs;\n\tfor (int x = 0; x < w; x++) {\n\t\tfor (int y = r +\
    \ 1; y < h; y++) {\n\t\t\tD d = hypot(a[r][x], a[y][x]);\n\t\t\tif (abs(d) <=\
    \ eps) continue;\n\t\t\tD c = a[r][x] / d, s = a[y][x] / d;\n\t\t\tauto rot =\
    \ [&](D& u, D& v) {\n\t\t\t\ttie(u, v) = make_pair(c * u + s * v, c * v - s *\
    \ u);\n\t\t\t};\n\t\t\trot(b[r], b[y]);\n\t\t\tfor (int k = x; k < w; k++) rot(a[r][k],\
    \ a[y][k]);\n\t\t}\n\t\tif (a[r][x] <= eps) continue;\n\t\tr++;\n\t\tidxs.push_back(x);\n\
    \t\tif (r == h) break;\n\t}\n\tstd::vector<D> v(w);\n\tfor (int y = r - 1; y >=\
    \ 0; y--) {\n\t\tint f = idxs[y];\n\t\tv[f] = b[y];\n\t\tfor (int x = f + 1; x\
    \ < w; x++) {\n\t\t\tv[f] -= a[y][x] * v[x];\n\t\t}\n\t\tv[f] /= a[y][f];\n\t\
    }\n\treturn v;\n}\n\ntemplate <class Mint> std::vector<Mint> solve_linear(Matrix<Mint>\
    \ a, std::vector<Mint> b) {\n\tint h = a.h(), w = a.w();\n\tint r = 0;\n\tstd::vector<int>\
    \ idxs;\n\tfor (int x = 0; x < w; x++) {\n\t\tint my = -1;\n\t\tfor (int y = r;\
    \ y < h; y++) {\n\t\t\tif (a[y][x]) {\n\t\t\t\tmy = y;\n\t\t\t\tbreak;\n\t\t\t\
    }\n\t\t}\n\t\tif (my == -1) continue;\n\t\tif (r != my) std::swap(a[r], a[my]);\n\
    \t\tstd::swap(b[r], b[my]);\n\t\tfor (int y = r + 1; y < h; y++) {\n\t\t\tif (!a[y][x])\
    \ continue;\n\t\t\tauto freq = a[y][x] / a[r][x];\n\t\t\tfor (int k = x; k < w;\
    \ k++) a[y][k] -= freq * a[r][k];\n\t\t\tb[y] -= freq * b[r];\n\t\t}\n\t\tr++;\n\
    \t\tidxs.push_back(x);\n\t\tif (r == h) break;\n\t}\n\tstd::vector<Mint> v(w);\n\
    \tfor (int y = r - 1; y >= 0; y--) {\n\t\tint f = idxs[y];\n\t\tv[f] = b[y];\n\
    \t\tfor (int x = f + 1; x < w; x++) {\n\t\t\tv[f] -= a[y][x] * v[x];\n\t\t}\n\t\
    \tv[f] /= a[y][f];\n\t}\n\treturn v;\n}\n\ntemplate <class Mint> int calc_rank(Matrix<Mint>\
    \ a) {\n\tint h = a.h(), w = a.w();\n\tint r = 0;\n\tstd::vector<int> idxs;\n\t\
    for (int x = 0; x < w; x++) {\n\t\tint my = -1;\n\t\tfor (int y = r; y < h; y++)\
    \ {\n\t\t\tif (a[y][x]) {\n\t\t\t\tmy = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\
    \tif (my == -1) continue;\n\t\tif (r != my) std::swap(a[r], a[my]);\n\t\tfor (int\
    \ y = r + 1; y < h; y++) {\n\t\t\tif (!a[y][x]) continue;\n\t\t\tauto freq = a[y][x]\
    \ / a[r][x];\n\t\t\tfor (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];\n\t\
    \t}\n\t\tr++;\n\t\tidxs.push_back(x);\n\t\tif (r == h) break;\n\t}\n\treturn r;\n\
    }\n\ntemplate <class Mint> Mint calc_det(Matrix<Mint> a) {\n\tassert(a.h() ==\
    \ a.w());\n\tint n = a.h();\n\n\tbool flip = false;\n\tfor (int x = 0; x < n;\
    \ x++) {\n\t\tint my = -1;\n\t\tfor (int y = x; y < n; y++) {\n\t\t\tif (a[y][x])\
    \ {\n\t\t\t\tmy = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif (my == -1) return\
    \ 0;\n\t\tif (x != my) {\n\t\t\tstd::swap(a[x], a[my]);\n\t\t\tif ((x - my) %\
    \ 2) flip = !flip;\n\t\t}\n\t\tfor (int y = x + 1; y < n; y++) {\n\t\t\tif (!a[y][x])\
    \ continue;\n\t\t\tauto freq = a[y][x] / a[x][x];\n\t\t\tfor (int k = x; k < n;\
    \ k++) a[y][k] -= freq * a[x][k];\n\t\t}\n\t}\n\tMint det = (!flip ? 1 : -1);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tdet *= a[i][i];\n\t}\n\treturn det;\n}\n\n\
    template <class Mint> Matrix<Mint> inverse(Matrix<Mint> a) {\n\tassert(a.h() ==\
    \ a.w());\n\tint n = a.h();\n\tMatrix<Mint> b(n, std::vector<Mint>(n));\n\tfor\
    \ (int i = 0; i < n; i++) b[i][i] = 1;\n\tfor (int x = 0; x < n; x++) {\n\t\t\
    int my = -1;\n\t\tfor (int y = x; y < n; y++) {\n\t\t\tif (a[y][x]) {\n\t\t\t\t\
    my = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif (my == -1) return {};\n\t\tif\
    \ (x != my) {\n\t\t\tstd::swap(a[x], a[my]);\n\t\t\tstd::swap(b[x], b[my]);\n\t\
    \t}\n\t\tauto freq = a[x][x];\n\t\tfor (int j = 0; j < n; j++) {\n\t\t\ta[x][j]\
    \ /= freq;\n\t\t\tb[x][j] /= freq;\n\t\t}\n\t\tfor (int y = 0; y < n; y++) {\n\
    \t\t\tif (x == y) continue;\n\t\t\tif (!a[y][x]) continue;\n\t\t\tfreq = a[y][x];\n\
    \t\t\tfor (int k = 0; k < n; k++) a[y][k] -= freq * a[x][k];\n\t\t\tfor (int k\
    \ = 0; k < n; k++) b[y][k] -= freq * b[x][k];\n\t\t}\n\t}\n\treturn b;\n}\n\n\
    template <class D> Matrix<D> make_matrix(int r, int c) { return Matrix<D>(r, std::vector<D>(c));\
    \ }\n"
  code: "#pragma once\n\n#include <bits/stdc++.h>\n\ntemplate <class D> struct Matrix\
    \ : std::vector<std::vector<D> {\n\tusing std::vector<std::vector<D>::std::vector<std::vector;\n\
    \tusing std::vector<std::vector<D>::size;\n\n\tint h() const { return int(size());\
    \ }\n\tint w() const { return int((*this)[0].size()); }\n\n\tMatrix operator*(const\
    \ Matrix& r) const {\n\t\tassert(w() == r.h());\n\t\tMatrix res(h(), std::vector<D>(r.w()));\n\
    \t\tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < r.w(); j++) {\n\
    \t\t\t\tfor (int k = 0; k < w(); k++) {\n\t\t\t\t\tres[i][j] += (*this)[i][k]\
    \ * r[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tMatrix<T>&\
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
    \ = *this * r; }\n\tMatrix operator+(Matrix a, const Matrix& b) { return a +=\
    \ b; }\n\tMatrix operator-(Matrix a, const Matrix& b) { return a -= b; }\n\tMatrix&\
    \ operator*=(const D& r) { return *this = *this * r; }\n\tMatrix& operator/=(const\
    \ D &r) { return *this = *this / r; }\n\n\tMatrix pow(long long n) const {\n\t\
    \tassert(h() == w());\n\t\tMatrix x = *this, r(h(), std::vector<D>(w()));\n\t\t\
    for (int i = 0; i < h(); i++) r[i][i] = D(1);\n\t\twhile (n) {\n\t\t\tif (n &\
    \ 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t}\n\t\treturn r;\n\t}\n};\n\n\
    template <class D> std::vector<D> solve_linear(Matrix<D> a, std::vector<D> b,\
    \ D eps) {\n\tint h = a.h(), w = a.w();\n\tint r = 0;\n\tstd::vector<int> idxs;\n\
    \tfor (int x = 0; x < w; x++) {\n\t\tfor (int y = r + 1; y < h; y++) {\n\t\t\t\
    D d = hypot(a[r][x], a[y][x]);\n\t\t\tif (abs(d) <= eps) continue;\n\t\t\tD c\
    \ = a[r][x] / d, s = a[y][x] / d;\n\t\t\tauto rot = [&](D& u, D& v) {\n\t\t\t\t\
    tie(u, v) = make_pair(c * u + s * v, c * v - s * u);\n\t\t\t};\n\t\t\trot(b[r],\
    \ b[y]);\n\t\t\tfor (int k = x; k < w; k++) rot(a[r][k], a[y][k]);\n\t\t}\n\t\t\
    if (a[r][x] <= eps) continue;\n\t\tr++;\n\t\tidxs.push_back(x);\n\t\tif (r ==\
    \ h) break;\n\t}\n\tstd::vector<D> v(w);\n\tfor (int y = r - 1; y >= 0; y--) {\n\
    \t\tint f = idxs[y];\n\t\tv[f] = b[y];\n\t\tfor (int x = f + 1; x < w; x++) {\n\
    \t\t\tv[f] -= a[y][x] * v[x];\n\t\t}\n\t\tv[f] /= a[y][f];\n\t}\n\treturn v;\n\
    }\n\ntemplate <class Mint> std::vector<Mint> solve_linear(Matrix<Mint> a, std::vector<Mint>\
    \ b) {\n\tint h = a.h(), w = a.w();\n\tint r = 0;\n\tstd::vector<int> idxs;\n\t\
    for (int x = 0; x < w; x++) {\n\t\tint my = -1;\n\t\tfor (int y = r; y < h; y++)\
    \ {\n\t\t\tif (a[y][x]) {\n\t\t\t\tmy = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\
    \tif (my == -1) continue;\n\t\tif (r != my) std::swap(a[r], a[my]);\n\t\tstd::swap(b[r],\
    \ b[my]);\n\t\tfor (int y = r + 1; y < h; y++) {\n\t\t\tif (!a[y][x]) continue;\n\
    \t\t\tauto freq = a[y][x] / a[r][x];\n\t\t\tfor (int k = x; k < w; k++) a[y][k]\
    \ -= freq * a[r][k];\n\t\t\tb[y] -= freq * b[r];\n\t\t}\n\t\tr++;\n\t\tidxs.push_back(x);\n\
    \t\tif (r == h) break;\n\t}\n\tstd::vector<Mint> v(w);\n\tfor (int y = r - 1;\
    \ y >= 0; y--) {\n\t\tint f = idxs[y];\n\t\tv[f] = b[y];\n\t\tfor (int x = f +\
    \ 1; x < w; x++) {\n\t\t\tv[f] -= a[y][x] * v[x];\n\t\t}\n\t\tv[f] /= a[y][f];\n\
    \t}\n\treturn v;\n}\n\ntemplate <class Mint> int calc_rank(Matrix<Mint> a) {\n\
    \tint h = a.h(), w = a.w();\n\tint r = 0;\n\tstd::vector<int> idxs;\n\tfor (int\
    \ x = 0; x < w; x++) {\n\t\tint my = -1;\n\t\tfor (int y = r; y < h; y++) {\n\t\
    \t\tif (a[y][x]) {\n\t\t\t\tmy = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif (my\
    \ == -1) continue;\n\t\tif (r != my) std::swap(a[r], a[my]);\n\t\tfor (int y =\
    \ r + 1; y < h; y++) {\n\t\t\tif (!a[y][x]) continue;\n\t\t\tauto freq = a[y][x]\
    \ / a[r][x];\n\t\t\tfor (int k = x; k < w; k++) a[y][k] -= freq * a[r][k];\n\t\
    \t}\n\t\tr++;\n\t\tidxs.push_back(x);\n\t\tif (r == h) break;\n\t}\n\treturn r;\n\
    }\n\ntemplate <class Mint> Mint calc_det(Matrix<Mint> a) {\n\tassert(a.h() ==\
    \ a.w());\n\tint n = a.h();\n\n\tbool flip = false;\n\tfor (int x = 0; x < n;\
    \ x++) {\n\t\tint my = -1;\n\t\tfor (int y = x; y < n; y++) {\n\t\t\tif (a[y][x])\
    \ {\n\t\t\t\tmy = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif (my == -1) return\
    \ 0;\n\t\tif (x != my) {\n\t\t\tstd::swap(a[x], a[my]);\n\t\t\tif ((x - my) %\
    \ 2) flip = !flip;\n\t\t}\n\t\tfor (int y = x + 1; y < n; y++) {\n\t\t\tif (!a[y][x])\
    \ continue;\n\t\t\tauto freq = a[y][x] / a[x][x];\n\t\t\tfor (int k = x; k < n;\
    \ k++) a[y][k] -= freq * a[x][k];\n\t\t}\n\t}\n\tMint det = (!flip ? 1 : -1);\n\
    \tfor (int i = 0; i < n; i++) {\n\t\tdet *= a[i][i];\n\t}\n\treturn det;\n}\n\n\
    template <class Mint> Matrix<Mint> inverse(Matrix<Mint> a) {\n\tassert(a.h() ==\
    \ a.w());\n\tint n = a.h();\n\tMatrix<Mint> b(n, std::vector<Mint>(n));\n\tfor\
    \ (int i = 0; i < n; i++) b[i][i] = 1;\n\tfor (int x = 0; x < n; x++) {\n\t\t\
    int my = -1;\n\t\tfor (int y = x; y < n; y++) {\n\t\t\tif (a[y][x]) {\n\t\t\t\t\
    my = y;\n\t\t\t\tbreak;\n\t\t\t}\n\t\t}\n\t\tif (my == -1) return {};\n\t\tif\
    \ (x != my) {\n\t\t\tstd::swap(a[x], a[my]);\n\t\t\tstd::swap(b[x], b[my]);\n\t\
    \t}\n\t\tauto freq = a[x][x];\n\t\tfor (int j = 0; j < n; j++) {\n\t\t\ta[x][j]\
    \ /= freq;\n\t\t\tb[x][j] /= freq;\n\t\t}\n\t\tfor (int y = 0; y < n; y++) {\n\
    \t\t\tif (x == y) continue;\n\t\t\tif (!a[y][x]) continue;\n\t\t\tfreq = a[y][x];\n\
    \t\t\tfor (int k = 0; k < n; k++) a[y][k] -= freq * a[x][k];\n\t\t\tfor (int k\
    \ = 0; k < n; k++) b[y][k] -= freq * b[x][k];\n\t\t}\n\t}\n\treturn b;\n}\n\n\
    template <class D> Matrix<D> make_matrix(int r, int c) { return Matrix<D>(r, std::vector<D>(c));\
    \ }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/matrix.hpp
  requiredBy: []
  timestamp: '2021-07-31 15:16:41-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/matrix.hpp
layout: document
redirect_from:
- /library/library/numerical/matrix.hpp
- /library/library/numerical/matrix.hpp.html
title: library/numerical/matrix.hpp
---
