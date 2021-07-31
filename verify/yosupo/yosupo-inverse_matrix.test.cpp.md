---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/matrix.hpp
    title: library/numerical/matrix.hpp
  - icon: ':question:'
    path: library/numerical/mod-int2.hpp
    title: library/numerical/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nnamespace MatrixOperations {\n\ntemplate <class T> using Matrix = std::vector<std::vector<T>>;\n\
    \ntemplate <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r,\
    \ std::vector<T>(c)); }\n\ntemplate <class T> Matrix<T>& operator+=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\
    for (int j = 0; j < (int)a[0].size(); j++) {\n\t\t\ta[i][j] += b[i][j];\n\t\t\
    }\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T>& operator-=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\n\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\
    for (int j = 0; j < (int)a[0].size(); j++) {\n\t\t\ta[i][j] -= b[i][j];\n\t\t\
    }\n\t}\n\treturn a;\n}\n\ntemplate <class T> Matrix<T> operator*(const Matrix<T>&\
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
    \t\t}\n\t}\n\treturn res;\n}\n\n} // namespace MatrixOperations\n\n// 5 is a root\
    \ of both mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic const int mod\
    \ = MOD;\n\tstatic constexpr Mint rt() { return RT; } // primitive root for FFT\n\
    \tint v; \n\texplicit operator int() const { return v; } // explicit -> don't\
    \ silently convert to int\n\texplicit operator bool() const { return v != 0; }\n\
    \tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ?\
    \ _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint\
    \ &a, const Mint &b) { return a.v == b.v; }\n\tfriend bool operator!=(const Mint\
    \ &a, const Mint &b) { return !(a == b); }\n\tfriend bool operator<(const Mint\
    \ &a, const Mint &b) { return a.v < b.v; }\n\tfriend bool operator>(const Mint\
    \ &a, const Mint &b) { return a.v > b.v; }\n\tfriend bool operator<=(const Mint\
    \ &a, const Mint &b) { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint\
    \ &a, const Mint &b) { return a.v >= b.v; }\n\tfriend std::istream& operator >>\
    \ (std::istream &in, Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n\tfriend std::ostream& operator << (std::ostream &os, const Mint\
    \ &a) { return os << a.v; }\n\tMint& operator+=(const Mint &m) { \n\t\tif ((v\
    \ += m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint\
    \ &m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint &m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint &m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint &b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint &b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tusing namespace MatrixOperations;\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\tauto a = make_matrix<mi>(n, n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < n; ++j) {\n\t\t\tcin\
    \ >> a[i][j];\n\t\t}\n\t}\n\tauto tmp = a;\n\tmi det = gauss(tmp).first;\n\tif\
    \ (det == 0) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tauto ans = inv(a);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\
    \tcout << ans[i][j] << ' ';\n\t\t\t}\n\t\t\tcout << '\\n';\n\t\t}\n\t}\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/numerical/matrix.hpp\"\
    \n#include \"../../library/numerical/mod-int2.hpp\"\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tusing namespace MatrixOperations;\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\tauto a = make_matrix<mi>(n, n);\n\
    \tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j = 0; j < n; ++j) {\n\t\t\tcin\
    \ >> a[i][j];\n\t\t}\n\t}\n\tauto tmp = a;\n\tmi det = gauss(tmp).first;\n\tif\
    \ (det == 0) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tauto ans = inv(a);\n\
    \t\tfor (int i = 0; i < n; ++i) {\n\t\t\tfor (int j = 0; j < n; ++j) {\n\t\t\t\
    \tcout << ans[i][j] << ' ';\n\t\t\t}\n\t\t\tcout << '\\n';\n\t\t}\n\t}\n\treturn\
    \ 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/matrix.hpp
  - library/numerical/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2021-07-30 23:07:00-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-inverse_matrix.test.cpp
- /verify/verify/yosupo/yosupo-inverse_matrix.test.cpp.html
title: verify/yosupo/yosupo-inverse_matrix.test.cpp
---
