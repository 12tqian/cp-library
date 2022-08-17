---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/kattis/kattis-equationsolver.test.cpp
    title: verify/kattis/kattis-equationsolver.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-inverse_matrix.test.cpp
    title: verify/yosupo/yosupo-inverse_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nnamespace MatrixOperations {\r\n\r\ntemplate <class T> using Matrix\
    \ = std::vector<std::vector<T>>;\r\n\r\ntemplate <class T> Matrix<T> make_matrix(int\
    \ r, int c) { return Matrix<T>(r, std::vector<T>(c)); }\r\n\r\ntemplate <class\
    \ T> Matrix<T>& operator+=(Matrix<T>& a, const Matrix<T>& b) {\r\n\tfor (int i\
    \ = 0; i < (int)a.size(); i++) {\r\n\t\tfor (int j = 0; j < (int)a[0].size();\
    \ j++) {\r\n\t\t\ta[i][j] += b[i][j];\r\n\t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\
    \ntemplate <class T> Matrix<T>& operator-=(Matrix<T>& a, const Matrix<T>& b) {\r\
    \n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\tfor (int j = 0; j < (int)a[0].size();\
    \ j++) {\r\n\t\t\ta[i][j] -= b[i][j];\r\n\t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\
    \ntemplate <class T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>&\
    \ b) {\r\n\tassert(a[0].size() == b.size());\r\n\tint x = (int)a.size();\r\n\t\
    int y = (int)a[0].size();\r\n\tint z = (int)b[0].size();\r\n\tMatrix<T> c = make_matrix<T>(x,\
    \ z);\r\n\tfor (int i = 0; i < x; i++) {\r\n\t\tfor (int j = 0; j < y; j++) {\r\
    \n\t\t\tfor (int k = 0; k < z; k++) {\r\n\t\t\t\tc[i][k] += a[i][j] * b[j][k];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn c;\r\n}\r\n\r\ntemplate <class T> Matrix<T>\
    \ operator+(Matrix<T> a, const Matrix<T>& b) { return a += b; }\r\ntemplate <class\
    \ T> Matrix<T> operator-(Matrix<T> a, const Matrix<T>& b) { return a -= b; }\r\
    \ntemplate <class T> Matrix<T>& operator*=(Matrix<T>& a, const Matrix<T>& b) {\
    \ return a = a * b; }\r\n\r\ntemplate <class T> Matrix<T> pow(Matrix<T> m, long\
    \ long p) {\r\n\tint n = (int)m.size();\r\n\tassert(n == (int)m[0].size() && p\
    \ >= 0);\r\n\tMatrix<T> res = make_matrix<T>(n, n);\r\n\tfor (int i = 0; i < n;\
    \ i++) \r\n\t\tres[i][i] = 1;\r\n\tfor (; p; p >>= 1, m *= m) {\r\n\t\tif (p &\
    \ 1) {\r\n\t\t\tres *= m;\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate\
    \ <class T> int get_row(Matrix<T>& m, int r, int i, int nxt) {\r\n\tfor (int j\
    \ = nxt; j < r; j++) {\r\n\t\tif (m[j][i] != 0) {\r\n\t\t\treturn j;\r\n\t\t}\r\
    \n\t}\r\n\treturn -1;\r\n}\r\n\r\nconst long double EPS = 1e-12;\r\n\r\ntemplate\
    \ <> int get_row<long double>(Matrix<long double>& m, int r, int i, int nxt) {\r\
    \n\tstd::pair<long double, int> best = {0, -1};\r\n\tfor (int j = nxt; j < r;\
    \ j++) {\r\n\t\tbest = std::max(best, {abs(m[j][i]), j});\r\n\t}\r\n\treturn best.first\
    \ < EPS ? -1 : best.second;\r\n}\r\n\r\n// returns a pair of determinant, rank,\
    \ while doing Gaussian elimination to m\r\ntemplate <class T> std::pair<T, int>\
    \ gauss(Matrix<T>& m) {\r\n\tint r = (int)m.size();\r\n\tint c = (int)m[0].size();\r\
    \n\tint rank = 0, nxt = 0;\r\n\tT prod = 1;\r\n\tfor (int i = 0; i < r; i++) {\r\
    \n\t\tint row = get_row(m, r, i, nxt);\r\n\t\tif (row == -1) {\r\n\t\t\tprod =\
    \ 0;\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tif (row != nxt) {\r\n\t\t\tprod *= -1;\r\
    \n\t\t\tm[row].swap(m[nxt]);\r\n\t\t}\r\n\t\tprod *= m[nxt][i];\r\n\t\trank++;\r\
    \n\t\tT x = 1 / m[nxt][i];\r\n\t\tfor (int k = i; k < c; k++) \r\n\t\t\tm[nxt][k]\
    \ *= x;\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tif (j != nxt) {\r\n\t\t\t\
    \tT v = m[j][i];\r\n\t\t\t\tif (v == 0) continue;\r\n\t\t\t\tfor (int k = i; k\
    \ < c; k++) {\r\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tnxt++;\r\n\t}\r\n\treturn {prod, rank};\r\n}\r\n\r\ntemplate <class\
    \ T> Matrix<T> inv(Matrix<T> m) {\r\n\tint r = (int)m.size();\r\n\tassert(r ==\
    \ (int)m[0].size());\r\n\tMatrix<T> x = make_matrix<T>(r, 2 * r);\r\n\tfor (int\
    \ i = 0; i < r; i++) {\r\n\t\tx[i][i + r] = 1;\r\n\t\tfor (int j = 0; j < r; j++)\
    \ {\r\n\t\t\tx[i][j] = m[i][j];\r\n\t\t}\r\n\t}\r\n\tif (gauss(x).second != r)\
    \ return Matrix<T>();\r\n\tMatrix<T> res = make_matrix<T>(r, r);\r\n\tfor (int\
    \ i = 0; i < r; i++) {\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tres[i][j]\
    \ = x[i][j + r];\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\n} // namespace MatrixOperations\n"
  code: "#pragma once\r\n\r\nnamespace MatrixOperations {\r\n\r\ntemplate <class T>\
    \ using Matrix = std::vector<std::vector<T>>;\r\n\r\ntemplate <class T> Matrix<T>\
    \ make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c)); }\r\n\r\n\
    template <class T> Matrix<T>& operator+=(Matrix<T>& a, const Matrix<T>& b) {\r\
    \n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\tfor (int j = 0; j < (int)a[0].size();\
    \ j++) {\r\n\t\t\ta[i][j] += b[i][j];\r\n\t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\
    \ntemplate <class T> Matrix<T>& operator-=(Matrix<T>& a, const Matrix<T>& b) {\r\
    \n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\tfor (int j = 0; j < (int)a[0].size();\
    \ j++) {\r\n\t\t\ta[i][j] -= b[i][j];\r\n\t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\
    \ntemplate <class T> Matrix<T> operator*(const Matrix<T>& a, const Matrix<T>&\
    \ b) {\r\n\tassert(a[0].size() == b.size());\r\n\tint x = (int)a.size();\r\n\t\
    int y = (int)a[0].size();\r\n\tint z = (int)b[0].size();\r\n\tMatrix<T> c = make_matrix<T>(x,\
    \ z);\r\n\tfor (int i = 0; i < x; i++) {\r\n\t\tfor (int j = 0; j < y; j++) {\r\
    \n\t\t\tfor (int k = 0; k < z; k++) {\r\n\t\t\t\tc[i][k] += a[i][j] * b[j][k];\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn c;\r\n}\r\n\r\ntemplate <class T> Matrix<T>\
    \ operator+(Matrix<T> a, const Matrix<T>& b) { return a += b; }\r\ntemplate <class\
    \ T> Matrix<T> operator-(Matrix<T> a, const Matrix<T>& b) { return a -= b; }\r\
    \ntemplate <class T> Matrix<T>& operator*=(Matrix<T>& a, const Matrix<T>& b) {\
    \ return a = a * b; }\r\n\r\ntemplate <class T> Matrix<T> pow(Matrix<T> m, long\
    \ long p) {\r\n\tint n = (int)m.size();\r\n\tassert(n == (int)m[0].size() && p\
    \ >= 0);\r\n\tMatrix<T> res = make_matrix<T>(n, n);\r\n\tfor (int i = 0; i < n;\
    \ i++) \r\n\t\tres[i][i] = 1;\r\n\tfor (; p; p >>= 1, m *= m) {\r\n\t\tif (p &\
    \ 1) {\r\n\t\t\tres *= m;\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\ntemplate\
    \ <class T> int get_row(Matrix<T>& m, int r, int i, int nxt) {\r\n\tfor (int j\
    \ = nxt; j < r; j++) {\r\n\t\tif (m[j][i] != 0) {\r\n\t\t\treturn j;\r\n\t\t}\r\
    \n\t}\r\n\treturn -1;\r\n}\r\n\r\nconst long double EPS = 1e-12;\r\n\r\ntemplate\
    \ <> int get_row<long double>(Matrix<long double>& m, int r, int i, int nxt) {\r\
    \n\tstd::pair<long double, int> best = {0, -1};\r\n\tfor (int j = nxt; j < r;\
    \ j++) {\r\n\t\tbest = std::max(best, {abs(m[j][i]), j});\r\n\t}\r\n\treturn best.first\
    \ < EPS ? -1 : best.second;\r\n}\r\n\r\n// returns a pair of determinant, rank,\
    \ while doing Gaussian elimination to m\r\ntemplate <class T> std::pair<T, int>\
    \ gauss(Matrix<T>& m) {\r\n\tint r = (int)m.size();\r\n\tint c = (int)m[0].size();\r\
    \n\tint rank = 0, nxt = 0;\r\n\tT prod = 1;\r\n\tfor (int i = 0; i < r; i++) {\r\
    \n\t\tint row = get_row(m, r, i, nxt);\r\n\t\tif (row == -1) {\r\n\t\t\tprod =\
    \ 0;\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tif (row != nxt) {\r\n\t\t\tprod *= -1;\r\
    \n\t\t\tm[row].swap(m[nxt]);\r\n\t\t}\r\n\t\tprod *= m[nxt][i];\r\n\t\trank++;\r\
    \n\t\tT x = 1 / m[nxt][i];\r\n\t\tfor (int k = i; k < c; k++) \r\n\t\t\tm[nxt][k]\
    \ *= x;\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tif (j != nxt) {\r\n\t\t\t\
    \tT v = m[j][i];\r\n\t\t\t\tif (v == 0) continue;\r\n\t\t\t\tfor (int k = i; k\
    \ < c; k++) {\r\n\t\t\t\t\tm[j][k] -= v * m[nxt][k];\r\n\t\t\t\t}\r\n\t\t\t}\r\
    \n\t\t}\r\n\t\tnxt++;\r\n\t}\r\n\treturn {prod, rank};\r\n}\r\n\r\ntemplate <class\
    \ T> Matrix<T> inv(Matrix<T> m) {\r\n\tint r = (int)m.size();\r\n\tassert(r ==\
    \ (int)m[0].size());\r\n\tMatrix<T> x = make_matrix<T>(r, 2 * r);\r\n\tfor (int\
    \ i = 0; i < r; i++) {\r\n\t\tx[i][i + r] = 1;\r\n\t\tfor (int j = 0; j < r; j++)\
    \ {\r\n\t\t\tx[i][j] = m[i][j];\r\n\t\t}\r\n\t}\r\n\tif (gauss(x).second != r)\
    \ return Matrix<T>();\r\n\tMatrix<T> res = make_matrix<T>(r, r);\r\n\tfor (int\
    \ i = 0; i < r; i++) {\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tres[i][j]\
    \ = x[i][j + r];\r\n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\n} // namespace MatrixOperations"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/matrix2.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-inverse_matrix.test.cpp
  - verify/kattis/kattis-equationsolver.test.cpp
documentation_of: library/numerical/matrix2.hpp
layout: document
redirect_from:
- /library/library/numerical/matrix2.hpp
- /library/library/numerical/matrix2.hpp.html
title: library/numerical/matrix2.hpp
---
