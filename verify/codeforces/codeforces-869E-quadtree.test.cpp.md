---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/2d-range-queries/quadtree.hpp
    title: library/data-structures/2d-range-queries/quadtree.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/mod-int2.hpp
    title: library/numerical/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://codeforces.com/contest/1074/problem/F
  bundledCode: "#define IGNORE \"this will TLE, but it works\"\n#define PROBLEM \"\
    https://codeforces.com/contest/1074/problem/F\"\n\n\n#include <algorithm>\n#include\
    \ <array>\n#include <bitset>\n#include <cassert>\n#include <chrono>\n#include\
    \ <cmath>\n#include <complex>\n#include <cstdio>\n#include <cstdlib>\n#include\
    \ <cstring>\n#include <ctime>\n#include <deque>\n#include <iostream>\n#include\
    \ <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n#include <queue>\n\
    #include <random>\n#include <set>\n#include <stack>\n#include <string>\n#include\
    \ <unordered_map>\n#include <vector>\n\nusing namespace std;\n\n/**\n * Handles\
    \ point update in log(n), and query in O(n) worst case \n */\n\ntemplate <class\
    \ T, int N, int M> struct QuadTree {\n\tT sm[16 * N * M];\n\n\tQuadTree() { memset(sm,\
    \ 0, sizeof(sm)); }\n\n\tvoid upd(int x, int y, T inc, int n = 1, int x1 = 0,\
    \ int y1 = 0, int x2 = N - 1, int y2 = M - 1) {\n\t\tif (x1 == x2 && y1 == y2)\
    \ \n\t\t\tsm[n] += inc;\n\t\telse {\n\t\t\tint xm = (x1 + x2) >> 1;\n\t\t\tint\
    \ ym = (y1 + y2) >> 1;\n\t\t\tif (x <= xm && y <= ym) \n\t\t\t\tupd(x, y, inc,\
    \ 4 * n, x1, y1, xm, ym);\n\t\t\telse if (x <= xm && y > ym) \n\t\t\t\tupd(x,\
    \ y, inc, 4 * n + 1, x1, ym + 1, xm, y2);\n\t\t\telse if (x > xm && y > ym) \n\
    \t\t\t\tupd(x, y, inc, 4 * n + 2, xm + 1, ym + 1, x2, y2);\n\t\t\telse \n\t\t\t\
    \tupd(x, y, inc, 4 * n + 3, xm + 1, y1, x2, ym);\n\t\t\tsm[n] = sm[4 * n] + sm[4\
    \ * n + 1] + sm[4 * n + 2] + sm[4 * n + 3];\n\t\t}\n\t}\n\n\tT query(int qx1,\
    \ int qy1, int qx2, int qy2, int n = 1, int x1 = 0, int y1 = 0, int x2 = N - 1,\
    \ int y2 = M - 1) {\n\t\tif (qx2 < x1 || qy1 > y2 || qx1 > x2 || qy2 < y1) \n\t\
    \t\treturn 0;\n\t\telse if (qx1 <= x1 && x2 <= qx2 && qy1 <= y1 && y2 <= qy2)\
    \ \n\t\t\treturn sm[n];\n\t\tint xm = (x1 + x2) >> 1;\n\t\tint ym = (y1 + y2)\
    \ >> 1;\n\t\treturn query(qx1, qy1, qx2, qy2, 4 * n, x1, y1, xm, ym) \n\t\t\t\t\
    + query(qx1, qy1, qx2, qy2, 4 * n + 1, x1, ym + 1, xm, y2) \n\t\t\t\t+ query(qx1,\
    \ qy1, qx2, qy2, 4 * n + 2, xm + 1, ym + 1, x2, y2) \n\t\t\t\t+ query(qx1, qy1,\
    \ qx2, qy2, 4 * n + 3, xm + 1, y1, x2, ym);\n\t}\n};\n\n// 5 is a root of both\
    \ mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic const int mod = MOD;\n\
    \tstatic constexpr Mint rt() { return RT; } // primitive root for FFT\n\tint v;\
    \ \n\texplicit operator int() const { return v; } // explicit -> don't silently\
    \ convert to int\n\tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD <=\
    \ _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const\
    \ Mint &a, const Mint &b) { return a.v == b.v; }\n\tfriend bool operator!=(const\
    \ Mint &a, const Mint &b) { return !(a == b); }\n\tfriend bool operator<(const\
    \ Mint &a, const Mint &b) { return a.v < b.v; }\n\tfriend bool operator>(const\
    \ Mint &a, const Mint &b) { return a.v > b.v; }\n\tfriend bool operator<=(const\
    \ Mint &a, const Mint &b) { return a.v <= b.v; }\n\tfriend bool operator>=(const\
    \ Mint &a, const Mint &b) { return a.v >= b.v; }\n\tfriend std::istream& operator\
    \ >> (std::istream &in, Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x);\
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
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n\nconst int N = 2505;\n\
    \nconst int P = 998244353;\nconst int B = 2;\n\nusing mi = Mint<998244353, 5>;\n\
    \nQuadTree<mi, N, N> bit;\n\nint main() {\n\tios::sync_with_stdio(false);\n\t\
    cin.tie(nullptr);\n\tint n, m, q;\n\tcin >> m >> m >> q;\n\tmap<array<int, 4>,\
    \ mi> rects;\n\tmi run = 1;\n\twhile (q--) {\n\t\tint t, xl, xr, yl, yr;\n\t\t\
    cin >> t >> xl >> yl >> xr >> yr;\n\t\tauto rect = [&]() {\n\t\t\tmi v;\n\t\t\t\
    if (t == 1) {\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\n\t\t\t\tv = run;\n\t\t\t\
    \trun *= 2;\n\t\t\t} else {\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\n\t\t\t\tv *=\
    \ -1;\n\t\t\t}\n\t\t\tbit.upd(xl, yl, v);\n\t\t\tbit.upd(xl, yr + 1, -v);\n\t\t\
    \tbit.upd(xr + 1, yl, -v);\n\t\t\tbit.upd(xr + 1, yr + 1, v);\n\t\t};\n\t\tif\
    \ (t <= 2) {\n\t\t\trect();\n\t\t} else {\t\n\t\t\tif (bit.query(1,  1, xl, yl)\
    \ == bit.query(1, 1, xr, yr)) {\n\t\t\t\tcout << \"Yes\" << '\\n';\n\t\t\t} else\
    \ {\n\t\t\t\tcout << \"No\" << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define IGNORE \"this will TLE, but it works\"\n#define PROBLEM \"https://codeforces.com/contest/1074/problem/F\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/2d-range-queries/quadtree.hpp\"\
    \n#include \"../../library/numerical/mod-int2.hpp\"\n\nconst int N = 2505;\n\n\
    const int P = 998244353;\nconst int B = 2;\n\nusing mi = Mint<998244353, 5>;\n\
    \nQuadTree<mi, N, N> bit;\n\nint main() {\n\tios::sync_with_stdio(false);\n\t\
    cin.tie(nullptr);\n\tint n, m, q;\n\tcin >> m >> m >> q;\n\tmap<array<int, 4>,\
    \ mi> rects;\n\tmi run = 1;\n\twhile (q--) {\n\t\tint t, xl, xr, yl, yr;\n\t\t\
    cin >> t >> xl >> yl >> xr >> yr;\n\t\tauto rect = [&]() {\n\t\t\tmi v;\n\t\t\t\
    if (t == 1) {\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\n\t\t\t\tv = run;\n\t\t\t\
    \trun *= 2;\n\t\t\t} else {\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\n\t\t\t\tv *=\
    \ -1;\n\t\t\t}\n\t\t\tbit.upd(xl, yl, v);\n\t\t\tbit.upd(xl, yr + 1, -v);\n\t\t\
    \tbit.upd(xr + 1, yl, -v);\n\t\t\tbit.upd(xr + 1, yr + 1, v);\n\t\t};\n\t\tif\
    \ (t <= 2) {\n\t\t\trect();\n\t\t} else {\t\n\t\t\tif (bit.query(1,  1, xl, yl)\
    \ == bit.query(1, 1, xr, yr)) {\n\t\t\t\tcout << \"Yes\" << '\\n';\n\t\t\t} else\
    \ {\n\t\t\t\tcout << \"No\" << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/2d-range-queries/quadtree.hpp
  - library/numerical/mod-int2.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-869E-quadtree.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 21:00:40-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-869E-quadtree.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-869E-quadtree.test.cpp
- /verify/verify/codeforces/codeforces-869E-quadtree.test.cpp.html
title: verify/codeforces/codeforces-869E-quadtree.test.cpp
---
