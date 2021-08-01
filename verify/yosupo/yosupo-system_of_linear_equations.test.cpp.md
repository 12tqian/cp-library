---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':x:'
    path: library/numerical/matrix.hpp
    title: library/numerical/matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations
  bundledCode: "#define PROBELM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    template <class D> struct Matrix : std::vector<std::vector<D>> {\n\ttemplate <class\
    \ T> using V = std::vector<T>;\n\ttemplate <class T> using VV = V<V<T>>;\n\tusing\
    \ VV<D>::VV;\n\n\tint h() const { return int(this->size()); }\n\tint w() const\
    \ { return int((*this)[0].size()); }\n\n\tMatrix operator*(const Matrix& r) const\
    \ {\n\t\tassert(w() == r.h());\n\t\tMatrix res(h(), std::vector<D>(r.w()));\n\t\
    \tfor (int i = 0; i < h(); i++) {\n\t\t\tfor (int j = 0; j < r.w(); j++) {\n\t\
    \t\t\tfor (int k = 0; k < w(); k++) {\n\t\t\t\t\tres[i][j] += (*this)[i][k] *\
    \ r[k][j];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\t\treturn res;\n\t}\n\n\tMatrix<D>& operator+=(const\
    \ Matrix& r) {\n\t\tassert(h() == r.h() && w == r.w());\n\t\tfor (int i = 0; i\
    \ < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\t\t(*this)[i][j]\
    \ += r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix& operator-=(const\
    \ Matrix& r) {\n\t\tassert(h() == r.h() && w == r.w());\n\t\tfor (int i = 0; i\
    \ < h(); i++) {\n\t\t\tfor (int j = 0; j < h(); j++) {\n\t\t\t\t(*this)[i][j]\
    \ -= r[i][j];\n\t\t\t}\n\t\t}\n\t\treturn *this;\n\t}\n\n\tMatrix operator*(const\
    \ D& r) const {\n\t\tMatrix res = (*this);\n\t\tfor (int i = 0; i < h(); ++i)\
    \ {\n\t\t\tfor (int j = 0; j < w(); ++j) {\n\t\t\t\tres[i][j] *= r;\n\t\t\t}\n\
    \t\t}\n\t\treturn res;\n\t}\n\n\tMatrix operator/(const D &r) const{ return *this\
    \ * (1 / r); }\n\tMatrix& operator*=(const Matrix& r) { return *this = *this *\
    \ r; }\n\tMatrix operator+(const Matrix& r) { return *this += r; }\n\tMatrix operator-(const\
    \ Matrix& r) { return *this -= r; }\n\tMatrix& operator*=(const D& r) { return\
    \ *this = *this * r; }\n\tMatrix& operator/=(const D &r) { return *this = *this\
    \ / r; }\n\tfriend Matrix operator*(const D& r, Matrix m) { return m *= r; }\n\
    \n\tMatrix pow(long long n) const {\n\t\tassert(h() == w());\n\t\tMatrix x = *this,\
    \ r(h(), std::vector<D>(w()));\n\t\tfor (int i = 0; i < h(); i++) r[i][i] = D(1);\n\
    \t\twhile (n) {\n\t\t\tif (n & 1) r *= x;\n\t\t\tx *= x;\n\t\t\tn >>= 1;\n\t\t\
    }\n\t\treturn r;\n\t}\n};\n\nnamespace MatrixOperations {\n\ntemplate <class T>\
    \ Matrix<T> make_matrix(int r, int c) { return Matrix<T>(r, std::vector<T>(c));\
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
    \    }\n    return sols;\n}\n\n} // MatrixOperations\n\n// 5 is a root of both\
    \ mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic const int mod = MOD;\n\
    \tstatic constexpr Mint rt() { return RT; } // primitive root for FFT\n\tstatic\
    \ constexpr int md() { return MOD; } // primitive root for FFT\n\tint v; \n\t\
    explicit operator int() const { return v; } // explicit -> don't silently convert\
    \ to int\n\texplicit operator bool() const { return v != 0; }\n\tMint() { v =\
    \ 0; }\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD);\
    \ if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint &a, const Mint &b)\
    \ { return a.v == b.v; }\n\tfriend bool operator!=(const Mint &a, const Mint &b)\
    \ { return !(a == b); }\n\tfriend bool operator<(const Mint &a, const Mint &b)\
    \ { return a.v < b.v; }\n\tfriend bool operator>(const Mint &a, const Mint &b)\
    \ { return a.v > b.v; }\n\tfriend bool operator<=(const Mint &a, const Mint &b)\
    \ { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint &a, const Mint &b)\
    \ { return a.v >= b.v; }\n\tfriend std::istream& operator >> (std::istream &in,\
    \ Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\n\tfriend\
    \ std::ostream& operator << (std::ostream &os, const Mint &a) { return os << a.v;\
    \ }\n\tMint& operator+=(const Mint &m) { \n\t\tif ((v += m.v) >= MOD) v -= MOD;\
    \ \n\t\treturn *this; }\n\tMint& operator-=(const Mint &m) { \n\t\tif ((v -= m.v)\
    \ < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const Mint &m) { \n\
    \t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const Mint\
    \ &m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long p) {\n\
    \t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans\
    \ *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint &b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint &b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\
    using namespace MatrixOperations;\n\tint n, m;\n\tcin >> n >> m;\n\tMatrix<mi>\
    \ a = make_matrix<mi>(n, m);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j\
    \ = 0; j < m; ++j) {\n\t\t\tcin >> a[i][j];\n\t\t}\n\t}\n\tvector<mi> b(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tcin >> b[i];\n\t}\n\tauto ans = solve_linear(a,\
    \ b);\n\tif (ans.empty()) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tcout <<\
    \ (int)ans.size() - 1 << '\\n';\t\n\t\tfor (auto x : ans) {\n\t\t\tfor (auto y\
    \ : x) cout << y << ' ';\n\t\t\tcout << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBELM \"https://judge.yosupo.jp/problem/system_of_linear_equations\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/numerical/matrix.hpp\"\
    \n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nint main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\t\
    using namespace MatrixOperations;\n\tint n, m;\n\tcin >> n >> m;\n\tMatrix<mi>\
    \ a = make_matrix<mi>(n, m);\n\tfor (int i = 0; i < n; ++i) {\n\t\tfor (int j\
    \ = 0; j < m; ++j) {\n\t\t\tcin >> a[i][j];\n\t\t}\n\t}\n\tvector<mi> b(n);\n\t\
    for (int i = 0; i < n; ++i) {\n\t\tcin >> b[i];\n\t}\n\tauto ans = solve_linear(a,\
    \ b);\n\tif (ans.empty()) {\n\t\tcout << -1 << '\\n';\n\t} else {\n\t\tcout <<\
    \ (int)ans.size() - 1 << '\\n';\t\n\t\tfor (auto x : ans) {\n\t\t\tfor (auto y\
    \ : x) cout << y << ' ';\n\t\t\tcout << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/matrix.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
  requiredBy: []
  timestamp: '2021-07-31 22:31:54-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-system_of_linear_equations.test.cpp
- /verify/verify/yosupo/yosupo-system_of_linear_equations.test.cpp.html
title: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
---
