---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/2d-range-queries/quadtree.hpp
    title: Quadtree
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_GCC: ''
    links:
    - https://codeforces.com/contest/1074/problem/F
  bundledCode: "#define IGNORE \"this will TLE, but it works\"\r\n#define PROBLEM\
    \ \"https://codeforces.com/contest/1074/problem/F\"\r\n\r\n\r\n#include <algorithm>\r\
    \n#include <array>\r\n#include <bitset>\r\n#include <cassert>\r\n#include <chrono>\r\
    \n#include <cmath>\r\n#include <complex>\r\n#include <cstdio>\r\n#include <cstdlib>\r\
    \n#include <cstring>\r\n#include <ctime>\r\n#include <deque>\r\n#include <iostream>\r\
    \n#include <iomanip>\r\n#include <list>\r\n#include <map>\r\n#include <numeric>\r\
    \n#include <queue>\r\n#include <random>\r\n#include <set>\r\n#include <stack>\r\
    \n#include <string>\r\n#include <unordered_map>\r\n#include <vector>\r\n\r\nusing\
    \ namespace std;\n\r\ntemplate <class T, int N, int M> struct QuadTree {\r\n\t\
    T sm[16 * N * M];\r\n\r\n\tQuadTree() { memset(sm, 0, sizeof(sm)); }\r\n\r\n\t\
    void upd(int x, int y, T inc, int n = 1, int x1 = 0, int y1 = 0, int x2 = N -\
    \ 1, int y2 = M - 1) {\r\n\t\tif (x1 == x2 && y1 == y2) \r\n\t\t\tsm[n] += inc;\r\
    \n\t\telse {\r\n\t\t\tint xm = (x1 + x2) >> 1;\r\n\t\t\tint ym = (y1 + y2) >>\
    \ 1;\r\n\t\t\tif (x <= xm && y <= ym) \r\n\t\t\t\tupd(x, y, inc, 4 * n, x1, y1,\
    \ xm, ym);\r\n\t\t\telse if (x <= xm && y > ym) \r\n\t\t\t\tupd(x, y, inc, 4 *\
    \ n + 1, x1, ym + 1, xm, y2);\r\n\t\t\telse if (x > xm && y > ym) \r\n\t\t\t\t\
    upd(x, y, inc, 4 * n + 2, xm + 1, ym + 1, x2, y2);\r\n\t\t\telse \r\n\t\t\t\t\
    upd(x, y, inc, 4 * n + 3, xm + 1, y1, x2, ym);\r\n\t\t\tsm[n] = sm[4 * n] + sm[4\
    \ * n + 1] + sm[4 * n + 2] + sm[4 * n + 3];\r\n\t\t}\r\n\t}\r\n\r\n\tT query(int\
    \ qx1, int qy1, int qx2, int qy2, int n = 1, int x1 = 0, int y1 = 0, int x2 =\
    \ N - 1, int y2 = M - 1) {\r\n\t\tif (qx2 < x1 || qy1 > y2 || qx1 > x2 || qy2\
    \ < y1) \r\n\t\t\treturn 0;\r\n\t\telse if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1\
    \ && y2 <= qy2) \r\n\t\t\treturn sm[n];\r\n\t\tint xm = (x1 + x2) >> 1;\r\n\t\t\
    int ym = (y1 + y2) >> 1;\r\n\t\treturn query(qx1, qy1, qx2, qy2, 4 * n, x1, y1,\
    \ xm, ym) \r\n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 1, x1, ym + 1, xm, y2)\
    \ \r\n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 2, xm + 1, ym + 1, x2, y2) \r\
    \n\t\t\t\t+ query(qx1, qy1, qx2, qy2, 4 * n + 3, xm + 1, y1, x2, ym);\r\n\t}\r\
    \n};\n\r\n// 5 is a root of both mods\r\ntemplate <int MOD, int RT> struct Mint\
    \ {\r\n\tstatic const int mod = MOD;\r\n\tstatic constexpr Mint rt() { return\
    \ RT; } // primitive root for FFT\r\n\tstatic constexpr int md() { return MOD;\
    \ } // primitive root for FFT\r\n\tint v; \r\n\texplicit operator int() const\
    \ { return v; } // explicit -> don't silently convert to int\r\n\texplicit operator\
    \ bool() const { return v != 0; }\r\n\tMint() { v = 0; }\r\n\tMint(long long _v)\
    \ { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\r\
    \n\tfriend bool operator==(const Mint& a, const Mint& b) { return a.v == b.v;\
    \ }\r\n\tfriend bool operator!=(const Mint& a, const Mint& b) { return !(a ==\
    \ b); }\r\n\tfriend bool operator<(const Mint& a, const Mint& b) { return a.v\
    \ < b.v; }\r\n\tfriend bool operator>(const Mint& a, const Mint& b) { return a.v\
    \ > b.v; }\r\n\tfriend bool operator<=(const Mint& a, const Mint& b) { return\
    \ a.v <= b.v; }\r\n\tfriend bool operator>=(const Mint& a, const Mint& b) { return\
    \ a.v >= b.v; }\r\n\tfriend std::istream& operator >> (std::istream& in, Mint&\
    \ a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\r\n\tfriend\
    \ std::ostream& operator << (std::ostream& os, const Mint& a) { return os << a.v;\
    \ }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\tif ((v += m.v) >= MOD) v -=\
    \ MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const Mint& m) { \r\n\t\t\
    if ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\tMint& operator*=(const\
    \ Mint& m) { \r\n\t\tv = (long long)v * m.v % MOD; return *this; }\r\n\tMint&\
    \ operator/=(const Mint& m) { return (*this) *= inv(m); }\r\n\tfriend Mint pow(Mint\
    \ a, long long p) {\r\n\t\tMint ans = 1; assert(p >= 0);\r\n\t\tfor (; p; p /=\
    \ 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; \r\n\t}\r\n\tfriend Mint\
    \ inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }\r\n\tMint operator-()\
    \ const { return Mint(-v); }\r\n\tMint& operator++() { return *this += 1; }\r\n\
    \tMint& operator--() { return *this -= 1; }\r\n\tfriend Mint operator+(Mint a,\
    \ const Mint& b) { return a += b; }\r\n\tfriend Mint operator-(Mint a, const Mint&\
    \ b) { return a -= b; }\r\n\tfriend Mint operator*(Mint a, const Mint& b) { return\
    \ a *= b; }\r\n\tfriend Mint operator/(Mint a, const Mint& b) { return a /= b;\
    \ }\r\n};\r\n\r\nconst int N = 2505;\r\n\r\nconst int P = 998244353;\r\nconst\
    \ int B = 2;\r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nQuadTree<mi, N, N> bit;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\
    \tint n, m, q;\r\n\tcin >> m >> m >> q;\r\n\tmap<array<int, 4>, mi> rects;\r\n\
    \tmi run = 1;\r\n\twhile (q--) {\r\n\t\tint t, xl, xr, yl, yr;\r\n\t\tcin >> t\
    \ >> xl >> yl >> xr >> yr;\r\n\t\tauto rect = [&]() {\r\n\t\t\tmi v;\r\n\t\t\t\
    if (t == 1) {\r\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\r\n\t\t\t\tv = run;\r\n\
    \t\t\t\trun *= 2;\r\n\t\t\t} else {\r\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\r\n\
    \t\t\t\tv *= -1;\r\n\t\t\t}\r\n\t\t\tbit.upd(xl, yl, v);\r\n\t\t\tbit.upd(xl,\
    \ yr + 1, -v);\r\n\t\t\tbit.upd(xr + 1, yl, -v);\r\n\t\t\tbit.upd(xr + 1, yr +\
    \ 1, v);\r\n\t\t};\r\n\t\tif (t <= 2) {\r\n\t\t\trect();\r\n\t\t} else {\t\r\n\
    \t\t\tif (bit.query(1,  1, xl, yl) == bit.query(1, 1, xr, yr)) {\r\n\t\t\t\tcout\
    \ << \"Yes\" << '\\n';\r\n\t\t\t} else {\r\n\t\t\t\tcout << \"No\" << '\\n';\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define IGNORE \"this will TLE, but it works\"\r\n#define PROBLEM \"https://codeforces.com/contest/1074/problem/F\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/data-structures/2d-range-queries/quadtree.hpp\"\r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\
    \r\n\r\nconst int N = 2505;\r\n\r\nconst int P = 998244353;\r\nconst int B = 2;\r\
    \n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nQuadTree<mi, N, N> bit;\r\n\r\nint\
    \ main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n,\
    \ m, q;\r\n\tcin >> m >> m >> q;\r\n\tmap<array<int, 4>, mi> rects;\r\n\tmi run\
    \ = 1;\r\n\twhile (q--) {\r\n\t\tint t, xl, xr, yl, yr;\r\n\t\tcin >> t >> xl\
    \ >> yl >> xr >> yr;\r\n\t\tauto rect = [&]() {\r\n\t\t\tmi v;\r\n\t\t\tif (t\
    \ == 1) {\r\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\r\n\t\t\t\tv = run;\r\n\t\t\
    \t\trun *= 2;\r\n\t\t\t} else {\r\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\r\n\t\t\
    \t\tv *= -1;\r\n\t\t\t}\r\n\t\t\tbit.upd(xl, yl, v);\r\n\t\t\tbit.upd(xl, yr +\
    \ 1, -v);\r\n\t\t\tbit.upd(xr + 1, yl, -v);\r\n\t\t\tbit.upd(xr + 1, yr + 1, v);\r\
    \n\t\t};\r\n\t\tif (t <= 2) {\r\n\t\t\trect();\r\n\t\t} else {\t\r\n\t\t\tif (bit.query(1,\
    \  1, xl, yl) == bit.query(1, 1, xr, yr)) {\r\n\t\t\t\tcout << \"Yes\" << '\\\
    n';\r\n\t\t\t} else {\r\n\t\t\t\tcout << \"No\" << '\\n';\r\n\t\t\t}\r\n\t\t}\r\
    \n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/2d-range-queries/quadtree.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-869E-quadtree.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-869E-quadtree.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-869E-quadtree.test.cpp
- /verify/verify/codeforces/codeforces-869E-quadtree.test.cpp.html
title: verify/codeforces/codeforces-869E-quadtree.test.cpp
---
