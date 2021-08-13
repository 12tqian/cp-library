---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/2d-range-queries/general-fenwick-tree.hpp
    title: General Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://codeforces.com/contest/869/problem/E
    links:
    - https://codeforces.com/contest/869/problem/E
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/869/problem/E\"\n\
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n/**\n * 1-indexed \n * log(n)^2 query, update\n * O(n^2) space\n */\n\nconstexpr\
    \ int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x); } \n\ntemplate\
    \ <class T, int ...Ns> struct BIT {\n\tT val = 0; void upd(T v) { val += v; }\n\
    \tT query() { return val; }\n};\n\ntemplate <class T, int N, int... Ns> struct\
    \ BIT<T, N, Ns...> {\n\tBIT<T, Ns...> bit[N + 1];\n\n\ttemplate <typename... Args>\
    \ void upd(int pos, Args... args) { \n\t\tassert(pos > 0);\n\t\tfor (; pos <=\
    \ N; pos += pos & -pos) \n\t\t\tbit[pos].upd(args...); \n\t}\n\n\ttemplate <typename...\
    \ Args> T sum(int r, Args... args) {\n\t\tT res = 0; \n\t\tfor (; r; r -= r &\
    \ -r) \n\t\t\tres += bit[r].query(args...); \n\t\treturn res; \n\t}\n\n\ttemplate\
    \ <typename... Args> T query(int l, int r, Args... args) { \n\t\treturn sum(r,\
    \ args...) - sum(l - 1, args...); \n\t}\n\n\tint get_kth(T des) { \n\t\tassert(des\
    \ > 0);\n\t\tint ind = 0;\n\t\tfor (int i = 1 << bits(N); i; i /= 2)\n\t\t\tif\
    \ (ind + i <= N && bit[ind + i].val < des)\n\t\t\t\tdes -= bit[ind += i].val;\n\
    \t\tassert(ind < N); return ind + 1;\n\t}\n}; \n\n\n// 5 is a root of both mods\n\
    template <int MOD, int RT> struct Mint {\n\tstatic const int mod = MOD;\n\tstatic\
    \ constexpr Mint rt() { return RT; } // primitive root for FFT\n\tstatic constexpr\
    \ int md() { return MOD; } // primitive root for FFT\n\tint v; \n\texplicit operator\
    \ int() const { return v; } // explicit -> don't silently convert to int\n\texplicit\
    \ operator bool() const { return v != 0; }\n\tMint() { v = 0; }\n\tMint(long long\
    \ _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD;\
    \ }\n\tfriend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v;\
    \ }\n\tfriend bool operator!=(const Mint &a, const Mint &b) { return !(a == b);\
    \ }\n\tfriend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v;\
    \ }\n\tfriend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v;\
    \ }\n\tfriend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v;\
    \ }\n\tfriend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v;\
    \ }\n\tfriend std::istream& operator >> (std::istream &in, Mint &a) { \n\t\tlong\
    \ long x; std::cin >> x; a = Mint(x); return in; }\n\tfriend std::ostream& operator\
    \ << (std::ostream &os, const Mint &a) { return os << a.v; }\n\tMint& operator+=(const\
    \ Mint &m) { \n\t\tif ((v += m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\t\
    Mint& operator-=(const Mint &m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn\
    \ *this; }\n\tMint& operator*=(const Mint &m) { \n\t\tv = (long long)v * m.v %\
    \ MOD; return *this; }\n\tMint& operator/=(const Mint &m) { return (*this) *=\
    \ inv(m); }\n\tfriend Mint pow(Mint a, long long p) {\n\t\tMint ans = 1; assert(p\
    \ >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans;\
    \ \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v != 0); return pow(a, MOD\
    \ - 2); }\n\tMint operator-() const { return Mint(-v); }\n\tMint& operator++()\
    \ { return *this += 1; }\n\tMint& operator--() { return *this -= 1; }\n\tfriend\
    \ Mint operator+(Mint a, const Mint &b) { return a += b; }\n\tfriend Mint operator-(Mint\
    \ a, const Mint &b) { return a -= b; }\n\tfriend Mint operator*(Mint a, const\
    \ Mint &b) { return a *= b; }\n\tfriend Mint operator/(Mint a, const Mint &b)\
    \ { return a /= b; }\n};\n\nconst int N = 2505;\n\nconst int P = 998244353;\n\
    const int B = 2;\n\nusing mi = Mint<998244353, 5>;\n\nBIT<mi, N, N> bit;\n\nint\
    \ main() {\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint n, m, q;\n\
    \tcin >> m >> m >> q;\n\tmap<array<int, 4>, mi> rects;\n\tmi run = 1;\n\twhile\
    \ (q--) {\n\t\tint t, xl, xr, yl, yr;\n\t\tcin >> t >> xl >> yl >> xr >> yr;\n\
    \t\tauto rect = [&]() {\n\t\t\tmi v;\n\t\t\tif (t == 1) {\n\t\t\t\trects[{xl,\
    \ xr, yl, yr}] = run;\n\t\t\t\tv = run;\n\t\t\t\trun *= 2;\n\t\t\t} else {\n\t\
    \t\t\tv = rects[{xl, xr, yl, yr}];\n\t\t\t\tv *= -1;\n\t\t\t}\n\t\t\tbit.upd(xl,\
    \ yl, v);\n\t\t\tbit.upd(xl, yr + 1, -v);\n\t\t\tbit.upd(xr + 1, yl, -v);\n\t\t\
    \tbit.upd(xr + 1, yr + 1, v);\n\t\t};\n\t\tif (t <= 2) {\n\t\t\trect();\n\t\t\
    } else {\t\n\t\t\tif (bit.query(1, xl, 1, yl) == bit.query(1, xr, 1, yr)) {\n\t\
    \t\t\tcout << \"Yes\" << '\\n';\n\t\t\t} else {\n\t\t\t\tcout << \"No\" << '\\\
    n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/869/problem/E\"\n\n#include\
    \ \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/2d-range-queries/general-fenwick-tree.hpp\"\
    \n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\n\nconst int N =\
    \ 2505;\n\nconst int P = 998244353;\nconst int B = 2;\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nBIT<mi, N, N> bit;\n\nint main() {\n\tios::sync_with_stdio(false);\n\t\
    cin.tie(nullptr);\n\tint n, m, q;\n\tcin >> m >> m >> q;\n\tmap<array<int, 4>,\
    \ mi> rects;\n\tmi run = 1;\n\twhile (q--) {\n\t\tint t, xl, xr, yl, yr;\n\t\t\
    cin >> t >> xl >> yl >> xr >> yr;\n\t\tauto rect = [&]() {\n\t\t\tmi v;\n\t\t\t\
    if (t == 1) {\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\n\t\t\t\tv = run;\n\t\t\t\
    \trun *= 2;\n\t\t\t} else {\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\n\t\t\t\tv *=\
    \ -1;\n\t\t\t}\n\t\t\tbit.upd(xl, yl, v);\n\t\t\tbit.upd(xl, yr + 1, -v);\n\t\t\
    \tbit.upd(xr + 1, yl, -v);\n\t\t\tbit.upd(xr + 1, yr + 1, v);\n\t\t};\n\t\tif\
    \ (t <= 2) {\n\t\t\trect();\n\t\t} else {\t\n\t\t\tif (bit.query(1, xl, 1, yl)\
    \ == bit.query(1, xr, 1, yr)) {\n\t\t\t\tcout << \"Yes\" << '\\n';\n\t\t\t} else\
    \ {\n\t\t\t\tcout << \"No\" << '\\n';\n\t\t\t}\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/2d-range-queries/general-fenwick-tree.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-869E-general-fwt.test.cpp
  requiredBy: []
  timestamp: '2021-07-31 01:42:23-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-869E-general-fwt.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-869E-general-fwt.test.cpp
- /verify/verify/codeforces/codeforces-869E-general-fwt.test.cpp.html
title: verify/codeforces/codeforces-869E-general-fwt.test.cpp
---
