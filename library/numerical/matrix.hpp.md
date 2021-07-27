---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/matrix.test.cpp
    title: test/matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nnamespace MatrixOperations {\n\ntemplate <class T> using Matrix\
    \ = std::vector<std::vector<T>>;\n\ntemplate <class T> Matrix<T> make_matrix(int\
    \ r, int c) { return Matrix<T>(r, std::vector<T>(c)); }\n\ntemplate <class T>\
    \ Matrix<T>& operator+=(Matrix<T>& a, const Matrix<T>& b) {\n\tfor (int i = 0;\
    \ i < (int)a.size(); i++) {\n\t\tfor (int j = 0; j < (int)a[0].size(); j++) {\n\
    \t\t\ta[i][j] += b[i][j];\n\t\t}\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T>&\
    \ operator-=(Matrix<T>& a, const Matrix<T>& b) {\n\tfor (int i = 0; i < (int)a.size();\
    \ i++) {\n\t\tfor (int j = 0; j < (int)a[0].size(); j++) {\n\t\t\ta[i][j] -= b[i][j];\n\
    \t\t}\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T> operator*(const Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tassert(a[0].size() == b.size());\n\tint x = (int)a.size();\n\
    \tint y = (int)a[0].size();\n\tint z = (int)b[0].size();\n\tMatrix<T> c = make_matrix<T>(x,\
    \ z);\n\tfor (int i = 0; i < x; i++) {\n\t\tfor (int j = 0; j < y; j++) {\n\t\t\
    \tfor (int k = 0; k < z; k++) {\n\t\t\t\tc[i][k] += a[i][j] * b[j][k];\n\t\t\t\
    }\n\t\t}\n\t}\n\treturn c;\n}\n\ntemplate <class T> Matrix<T> operator+(Matrix<T>\
    \ a, const Matrix<T>& b) { return a += b; }\ntemplate <class T> Matrix<T> operator-(Matrix<T>\
    \ a, const Matrix<T>& b) { return a -= b; }\ntemplate <class T> Matrix<T>& operator*=(Matrix<T>&\
    \ a, const Matrix<T>& b) { return a = a * b; }\n\ntemplate <class T> Matrix<T>\
    \ pow(Matrix<T> m, long long p) {\n\tint n = (int)m.size();\n\tassert(n == (int)m[0].size()\
    \ && p >= 0);\n\tMatrix<T> res = make_matrix<T>(n, n);\n\tfor (int i = 0; i <\
    \ n; i++) \n\t\tres[i][i] = 1;\n\tfor (; p; p >>= 1, m *= m) {\n\t\tif (p & 1)\
    \ {\n\t\t\tres *= m;\n\t\t}\n\t}\n\treturn res;\n}\n\ntemplate <class T> int get_row(Matrix<T>&\
    \ m, int r, int i, int nxt) {\n\tfor (int j = nxt; j < r; j++) {\n\t\tif (m[j][i]\
    \ != 0) {\n\t\t\treturn j;\n\t\t}\n\t}\n\treturn -1;\n}\n\nconst long double EPS\
    \ = 1e-12;\n\ntemplate <> int get_row<long double>(Matrix<long double>& m, int\
    \ r, int i, int nxt) {\n\tstd::pair<long double, int> best = {0, -1};\n\tfor (int\
    \ j = nxt; j < r; j++) {\n\t\tbest = std::max(best, {abs(m[j][i]), j});\n\t}\n\
    \treturn best.first < EPS ? -1 : best.second;\n}\n\n// returns a pair of determinant,\
    \ rank, while doing Gaussian elimination to m\ntemplate <class T> std::pair<T,\
    \ int> gauss(Matrix<T>& m) {\n\tint r = (int)m.size();\n\tint c = (int)m[0].size();\n\
    \tint rank = 0, nxt = 0;\n\tT prod = 1;\n\tfor (int i = 0; i < r; i++) {\n\t\t\
    int row = get_row(m, r, i, nxt);\n\t\tif (row == -1) {\n\t\t\tprod = 0;\n\t\t\t\
    continue;\n\t\t}\n\t\tif (row != nxt) {\n\t\t\tprod *= -1;\n\t\t\tm[row].swap(m[nxt]);\n\
    \t\t}\n\t\tprod *= m[nxt][i];\n\t\trank++;\n\t\tT x = 1 / m[nxt][i];\n\t\tfor\
    \ (int k = i; k < c; k++) \n\t\t\tm[nxt][k] *= x;\n\t\tfor (int j = 0; j < r;\
    \ j++) {\n\t\t\tif (j != nxt) {\n\t\t\t\tT v = m[j][i];\n\t\t\t\tif (v == 0) continue;\n\
    \t\t\t\tfor (int k = i; k < c; k++) {\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\tnxt++;\n\t}\n\treturn {prod, rank};\n}\n\ntemplate\
    \ <class T> Matrix<T> inv(Matrix<T> m) {\n\tint r = (int)m.size();\n\tassert(r\
    \ == (int)m[0].size());\n\tMatrix<T> x = make_matrix<T>(r, 2 * r);\n\tfor (int\
    \ i = 0; i < r; i++) {\n\t\tx[i][i + r] = 1;\n\t\tfor (int j = 0; j < r; j++)\
    \ {\n\t\t\tx[i][j] = m[i][j];\n\t\t}\n\t}\n\tif (gauss(x).second != r) return\
    \ Matrix<T>();\n\tMatrix<T> res = make_matrix<T>(r, r);\n\tfor (int i = 0; i <\
    \ r; i++) {\n\t\tfor (int j = 0; j < r; j++) {\n\t\t\tres[i][j] = x[i][j + r];\n\
    \t\t}\n\t}\n\treturn res;\n}\n\n} // namespace MatrixOperations\n"
  code: "#pragma once\n\nnamespace MatrixOperations {\n\ntemplate <class T> using\
    \ Matrix = std::vector<std::vector<T>>;\n\ntemplate <class T> Matrix<T> make_matrix(int\
    \ r, int c) { return Matrix<T>(r, std::vector<T>(c)); }\n\ntemplate <class T>\
    \ Matrix<T>& operator+=(Matrix<T>& a, const Matrix<T>& b) {\n\tfor (int i = 0;\
    \ i < (int)a.size(); i++) {\n\t\tfor (int j = 0; j < (int)a[0].size(); j++) {\n\
    \t\t\ta[i][j] += b[i][j];\n\t\t}\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T>&\
    \ operator-=(Matrix<T>& a, const Matrix<T>& b) {\n\tfor (int i = 0; i < (int)a.size();\
    \ i++) {\n\t\tfor (int j = 0; j < (int)a[0].size(); j++) {\n\t\t\ta[i][j] -= b[i][j];\n\
    \t\t}\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T> operator*(const Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tassert(a[0].size() == b.size());\n\tint x = (int)a.size();\n\
    \tint y = (int)a[0].size();\n\tint z = (int)b[0].size();\n\tMatrix<T> c = make_matrix<T>(x,\
    \ z);\n\tfor (int i = 0; i < x; i++) {\n\t\tfor (int j = 0; j < y; j++) {\n\t\t\
    \tfor (int k = 0; k < z; k++) {\n\t\t\t\tc[i][k] += a[i][j] * b[j][k];\n\t\t\t\
    }\n\t\t}\n\t}\n\treturn c;\n}\n\ntemplate <class T> Matrix<T> operator+(Matrix<T>\
    \ a, const Matrix<T>& b) { return a += b; }\ntemplate <class T> Matrix<T> operator-(Matrix<T>\
    \ a, const Matrix<T>& b) { return a -= b; }\ntemplate <class T> Matrix<T>& operator*=(Matrix<T>&\
    \ a, const Matrix<T>& b) { return a = a * b; }\n\ntemplate <class T> Matrix<T>\
    \ pow(Matrix<T> m, long long p) {\n\tint n = (int)m.size();\n\tassert(n == (int)m[0].size()\
    \ && p >= 0);\n\tMatrix<T> res = make_matrix<T>(n, n);\n\tfor (int i = 0; i <\
    \ n; i++) \n\t\tres[i][i] = 1;\n\tfor (; p; p >>= 1, m *= m) {\n\t\tif (p & 1)\
    \ {\n\t\t\tres *= m;\n\t\t}\n\t}\n\treturn res;\n}\n\ntemplate <class T> int get_row(Matrix<T>&\
    \ m, int r, int i, int nxt) {\n\tfor (int j = nxt; j < r; j++) {\n\t\tif (m[j][i]\
    \ != 0) {\n\t\t\treturn j;\n\t\t}\n\t}\n\treturn -1;\n}\n\nconst long double EPS\
    \ = 1e-12;\n\ntemplate <> int get_row<long double>(Matrix<long double>& m, int\
    \ r, int i, int nxt) {\n\tstd::pair<long double, int> best = {0, -1};\n\tfor (int\
    \ j = nxt; j < r; j++) {\n\t\tbest = std::max(best, {abs(m[j][i]), j});\n\t}\n\
    \treturn best.first < EPS ? -1 : best.second;\n}\n\n// returns a pair of determinant,\
    \ rank, while doing Gaussian elimination to m\ntemplate <class T> std::pair<T,\
    \ int> gauss(Matrix<T>& m) {\n\tint r = (int)m.size();\n\tint c = (int)m[0].size();\n\
    \tint rank = 0, nxt = 0;\n\tT prod = 1;\n\tfor (int i = 0; i < r; i++) {\n\t\t\
    int row = get_row(m, r, i, nxt);\n\t\tif (row == -1) {\n\t\t\tprod = 0;\n\t\t\t\
    continue;\n\t\t}\n\t\tif (row != nxt) {\n\t\t\tprod *= -1;\n\t\t\tm[row].swap(m[nxt]);\n\
    \t\t}\n\t\tprod *= m[nxt][i];\n\t\trank++;\n\t\tT x = 1 / m[nxt][i];\n\t\tfor\
    \ (int k = i; k < c; k++) \n\t\t\tm[nxt][k] *= x;\n\t\tfor (int j = 0; j < r;\
    \ j++) {\n\t\t\tif (j != nxt) {\n\t\t\t\tT v = m[j][i];\n\t\t\t\tif (v == 0) continue;\n\
    \t\t\t\tfor (int k = i; k < c; k++) {\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\n\t\
    \t\t\t}\n\t\t\t}\n\t\t}\n\t\tnxt++;\n\t}\n\treturn {prod, rank};\n}\n\ntemplate\
    \ <class T> Matrix<T> inv(Matrix<T> m) {\n\tint r = (int)m.size();\n\tassert(r\
    \ == (int)m[0].size());\n\tMatrix<T> x = make_matrix<T>(r, 2 * r);\n\tfor (int\
    \ i = 0; i < r; i++) {\n\t\tx[i][i + r] = 1;\n\t\tfor (int j = 0; j < r; j++)\
    \ {\n\t\t\tx[i][j] = m[i][j];\n\t\t}\n\t}\n\tif (gauss(x).second != r) return\
    \ Matrix<T>();\n\tMatrix<T> res = make_matrix<T>(r, r);\n\tfor (int i = 0; i <\
    \ r; i++) {\n\t\tfor (int j = 0; j < r; j++) {\n\t\t\tres[i][j] = x[i][j + r];\n\
    \t\t}\n\t}\n\treturn res;\n}\n\n} // namespace MatrixOperations"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/matrix.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/matrix.test.cpp
documentation_of: library/numerical/matrix.hpp
layout: document
redirect_from:
- /library/library/numerical/matrix.hpp
- /library/library/numerical/matrix.hpp.html
title: library/numerical/matrix.hpp
---
