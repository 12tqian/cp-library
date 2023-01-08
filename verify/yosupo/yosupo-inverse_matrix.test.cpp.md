---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/matrix2.hpp
    title: library/numerical/matrix2.hpp
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
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nnamespace MatrixOperations\
    \ {\r\n\r\ntemplate <class T> using Matrix = std::vector<std::vector<T>>;\r\n\r\
    \ntemplate <class T> Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r,\
    \ std::vector<T>(c)); }\r\n\r\ntemplate <class T> Matrix<T>& operator+=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\r\n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\
    \tfor (int j = 0; j < (int)a[0].size(); j++) {\r\n\t\t\ta[i][j] += b[i][j];\r\n\
    \t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate <class T> Matrix<T>& operator-=(Matrix<T>&\
    \ a, const Matrix<T>& b) {\r\n\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\
    \tfor (int j = 0; j < (int)a[0].size(); j++) {\r\n\t\t\ta[i][j] -= b[i][j];\r\n\
    \t\t}\r\n\t}\r\n\treturn a;\r\n}\r\n\r\ntemplate <class T> Matrix<T> operator*(const\
    \ Matrix<T>& a, const Matrix<T>& b) {\r\n\tassert(a[0].size() == b.size());\r\n\
    \tint x = (int)a.size();\r\n\tint y = (int)a[0].size();\r\n\tint z = (int)b[0].size();\r\
    \n\tMatrix<T> c = make_matrix<T>(x, z);\r\n\tfor (int i = 0; i < x; i++) {\r\n\
    \t\tfor (int j = 0; j < y; j++) {\r\n\t\t\tfor (int k = 0; k < z; k++) {\r\n\t\
    \t\t\tc[i][k] += a[i][j] * b[j][k];\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn c;\r\
    \n}\r\n\r\ntemplate <class T> Matrix<T> operator+(Matrix<T> a, const Matrix<T>&\
    \ b) { return a += b; }\r\ntemplate <class T> Matrix<T> operator-(Matrix<T> a,\
    \ const Matrix<T>& b) { return a -= b; }\r\ntemplate <class T> Matrix<T>& operator*=(Matrix<T>&\
    \ a, const Matrix<T>& b) { return a = a * b; }\r\n\r\ntemplate <class T> Matrix<T>\
    \ pow(Matrix<T> m, long long p) {\r\n\tint n = (int)m.size();\r\n\tassert(n ==\
    \ (int)m[0].size() && p >= 0);\r\n\tMatrix<T> res = make_matrix<T>(n, n);\r\n\t\
    for (int i = 0; i < n; i++) \r\n\t\tres[i][i] = 1;\r\n\tfor (; p; p >>= 1, m *=\
    \ m) {\r\n\t\tif (p & 1) {\r\n\t\t\tres *= m;\r\n\t\t}\r\n\t}\r\n\treturn res;\r\
    \n}\r\n\r\ntemplate <class T> int get_row(Matrix<T>& m, int r, int i, int nxt)\
    \ {\r\n\tfor (int j = nxt; j < r; j++) {\r\n\t\tif (m[j][i] != 0) {\r\n\t\t\t\
    return j;\r\n\t\t}\r\n\t}\r\n\treturn -1;\r\n}\r\n\r\nconst long double EPS =\
    \ 1e-12;\r\n\r\ntemplate <> int get_row<long double>(Matrix<long double>& m, int\
    \ r, int i, int nxt) {\r\n\tstd::pair<long double, int> best = {0, -1};\r\n\t\
    for (int j = nxt; j < r; j++) {\r\n\t\tbest = std::max(best, {abs(m[j][i]), j});\r\
    \n\t}\r\n\treturn best.first < EPS ? -1 : best.second;\r\n}\r\n\r\n// returns\
    \ a pair of determinant, rank, while doing Gaussian elimination to m\r\ntemplate\
    \ <class T> std::pair<T, int> gauss(Matrix<T>& m) {\r\n\tint r = (int)m.size();\r\
    \n\tint c = (int)m[0].size();\r\n\tint rank = 0, nxt = 0;\r\n\tT prod = 1;\r\n\
    \tfor (int i = 0; i < r; i++) {\r\n\t\tint row = get_row(m, r, i, nxt);\r\n\t\t\
    if (row == -1) {\r\n\t\t\tprod = 0;\r\n\t\t\tcontinue;\r\n\t\t}\r\n\t\tif (row\
    \ != nxt) {\r\n\t\t\tprod *= -1;\r\n\t\t\tm[row].swap(m[nxt]);\r\n\t\t}\r\n\t\t\
    prod *= m[nxt][i];\r\n\t\trank++;\r\n\t\tT x = 1 / m[nxt][i];\r\n\t\tfor (int\
    \ k = i; k < c; k++) \r\n\t\t\tm[nxt][k] *= x;\r\n\t\tfor (int j = 0; j < r; j++)\
    \ {\r\n\t\t\tif (j != nxt) {\r\n\t\t\t\tT v = m[j][i];\r\n\t\t\t\tif (v == 0)\
    \ continue;\r\n\t\t\t\tfor (int k = i; k < c; k++) {\r\n\t\t\t\t\tm[j][k] -= v\
    \ * m[nxt][k];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tnxt++;\r\n\t}\r\n\treturn\
    \ {prod, rank};\r\n}\r\n\r\ntemplate <class T> Matrix<T> inv(Matrix<T> m) {\r\n\
    \tint r = (int)m.size();\r\n\tassert(r == (int)m[0].size());\r\n\tMatrix<T> x\
    \ = make_matrix<T>(r, 2 * r);\r\n\tfor (int i = 0; i < r; i++) {\r\n\t\tx[i][i\
    \ + r] = 1;\r\n\t\tfor (int j = 0; j < r; j++) {\r\n\t\t\tx[i][j] = m[i][j];\r\
    \n\t\t}\r\n\t}\r\n\tif (gauss(x).second != r) return Matrix<T>();\r\n\tMatrix<T>\
    \ res = make_matrix<T>(r, r);\r\n\tfor (int i = 0; i < r; i++) {\r\n\t\tfor (int\
    \ j = 0; j < r; j++) {\r\n\t\t\tres[i][j] = x[i][j + r];\r\n\t\t}\r\n\t}\r\n\t\
    return res;\r\n}\r\n\r\n} // namespace MatrixOperations\n\r\n// 5 is a root of\
    \ both mods\r\ntemplate <int MOD, int RT> struct Mint {\r\n\tstatic const int\
    \ mod = MOD;\r\n\tstatic constexpr Mint rt() { return RT; } // primitive root\
    \ for FFT\r\n\tstatic constexpr int md() { return MOD; } // primitive root for\
    \ FFT\r\n\tint v; \r\n\texplicit operator int() const { return v; } // explicit\
    \ -> don't silently convert to int\r\n\texplicit operator bool() const { return\
    \ v != 0; }\r\n\tMint() { v = 0; }\r\n\tMint(long long _v) { v = int((-MOD <=\
    \ _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\r\n\tfriend bool operator==(const\
    \ Mint& a, const Mint& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const\
    \ Mint& a, const Mint& b) { return !(a == b); }\r\n\tfriend bool operator<(const\
    \ Mint& a, const Mint& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const\
    \ Mint& a, const Mint& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const\
    \ Mint& a, const Mint& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const\
    \ Mint& a, const Mint& b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator\
    \ >> (std::istream& in, Mint& a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\r\n\tfriend std::ostream& operator << (std::ostream& os, const\
    \ Mint& a) { return os << a.v; }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\
    \tif ((v += m.v) >= MOD) v -= MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const\
    \ Mint& m) { \r\n\t\tif ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\
    \tMint& operator*=(const Mint& m) { \r\n\t\tv = (long long)v * m.v % MOD; return\
    \ *this; }\r\n\tMint& operator/=(const Mint& m) { return (*this) *= inv(m); }\r\
    \n\tfriend Mint pow(Mint a, long long p) {\r\n\t\tMint ans = 1; assert(p >= 0);\r\
    \n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; \r\n\t\
    }\r\n\tfriend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD -\
    \ 2); }\r\n\tMint operator-() const { return Mint(-v); }\r\n\tMint& operator++()\
    \ { return *this += 1; }\r\n\tMint& operator--() { return *this -= 1; }\r\n\t\
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }\r\n\tfriend Mint\
    \ operator-(Mint a, const Mint& b) { return a -= b; }\r\n\tfriend Mint operator*(Mint\
    \ a, const Mint& b) { return a *= b; }\r\n\tfriend Mint operator/(Mint a, const\
    \ Mint& b) { return a /= b; }\r\n};\r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\
    \nint main() {\r\n\tusing namespace MatrixOperations;\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n;\r\n\tcin >> n;\r\n\tauto a = make_matrix<mi>(n,\
    \ n);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tfor (int j = 0; j < n; ++j) {\r\
    \n\t\t\tcin >> a[i][j];\r\n\t\t}\r\n\t}\r\n\tauto tmp = a;\r\n\tmi det = gauss(tmp).first;\r\
    \n\tif (det == 0) {\r\n\t\tcout << -1 << '\\n';\r\n\t} else {\r\n\t\tauto ans\
    \ = inv(a);\r\n\t\tfor (int i = 0; i < n; ++i) {\r\n\t\t\tfor (int j = 0; j <\
    \ n; ++j) {\r\n\t\t\t\tcout << ans[i][j] << ' ';\r\n\t\t\t}\r\n\t\t\tcout << '\\\
    n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/numerical/matrix2.hpp\"\
    \r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\r\n\r\nusing mi\
    \ = Mint<998244353, 5>;\r\n\r\nint main() {\r\n\tusing namespace MatrixOperations;\r\
    \n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n;\r\n\tcin >>\
    \ n;\r\n\tauto a = make_matrix<mi>(n, n);\r\n\tfor (int i = 0; i < n; ++i) {\r\
    \n\t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\tcin >> a[i][j];\r\n\t\t}\r\n\t}\r\
    \n\tauto tmp = a;\r\n\tmi det = gauss(tmp).first;\r\n\tif (det == 0) {\r\n\t\t\
    cout << -1 << '\\n';\r\n\t} else {\r\n\t\tauto ans = inv(a);\r\n\t\tfor (int i\
    \ = 0; i < n; ++i) {\r\n\t\t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\t\tcout <<\
    \ ans[i][j] << ' ';\r\n\t\t\t}\r\n\t\t\tcout << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn\
    \ 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/matrix2.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-inverse_matrix.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-inverse_matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-inverse_matrix.test.cpp
- /verify/verify/yosupo/yosupo-inverse_matrix.test.cpp.html
title: verify/yosupo/yosupo-inverse_matrix.test.cpp
---
