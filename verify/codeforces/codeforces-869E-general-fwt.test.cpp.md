---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  bundledCode: "#define PROBLEM \"https://codeforces.com/contest/869/problem/E\"\r\
    \n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n#include\
    \ <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\n\
    #include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nconstexpr int bits(int x)\
    \ { return x == 0 ? 0 : 31 - __builtin_clz(x); } \r\n\r\ntemplate <class T, int\
    \ ...Ns> struct BIT {\r\n\tT val = 0; void upd(T v) { val += v; }\r\n\tT query()\
    \ { return val; }\r\n};\r\n\r\ntemplate <class T, int N, int... Ns> struct BIT<T,\
    \ N, Ns...> {\r\n\tBIT<T, Ns...> bit[N + 1];\r\n\r\n\ttemplate <typename... Args>\
    \ void upd(int pos, Args... args) { \r\n\t\tassert(pos > 0);\r\n\t\tfor (; pos\
    \ <= N; pos += pos & -pos) \r\n\t\t\tbit[pos].upd(args...); \r\n\t}\r\n\r\n\t\
    template <typename... Args> T sum(int r, Args... args) {\r\n\t\tT res = 0; \r\n\
    \t\tfor (; r; r -= r & -r) \r\n\t\t\tres += bit[r].query(args...); \r\n\t\treturn\
    \ res; \r\n\t}\r\n\r\n\ttemplate <typename... Args> T query(int l, int r, Args...\
    \ args) { \r\n\t\treturn sum(r, args...) - sum(l - 1, args...); \r\n\t}\r\n\r\n\
    \tint get_kth(T des) { \r\n\t\tassert(des > 0);\r\n\t\tint ind = 0;\r\n\t\tfor\
    \ (int i = 1 << bits(N); i; i /= 2)\r\n\t\t\tif (ind + i <= N && bit[ind + i].val\
    \ < des)\r\n\t\t\t\tdes -= bit[ind += i].val;\r\n\t\tassert(ind < N); return ind\
    \ + 1;\r\n\t}\r\n}; \r\n\r\n\r\n// 5 is a root of both mods\r\ntemplate <int MOD,\
    \ int RT> struct Mint {\r\n\tstatic const int mod = MOD;\r\n\tstatic constexpr\
    \ Mint rt() { return RT; } // primitive root for FFT\r\n\tstatic constexpr int\
    \ md() { return MOD; } // primitive root for FFT\r\n\tint v; \r\n\texplicit operator\
    \ int() const { return v; } // explicit -> don't silently convert to int\r\n\t\
    explicit operator bool() const { return v != 0; }\r\n\tMint() { v = 0; }\r\n\t\
    Mint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v\
    \ < 0) v += MOD; }\r\n\tfriend bool operator==(const Mint& a, const Mint& b) {\
    \ return a.v == b.v; }\r\n\tfriend bool operator!=(const Mint& a, const Mint&\
    \ b) { return !(a == b); }\r\n\tfriend bool operator<(const Mint& a, const Mint&\
    \ b) { return a.v < b.v; }\r\n\tfriend bool operator>(const Mint& a, const Mint&\
    \ b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const Mint& a, const Mint&\
    \ b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const Mint& a, const Mint&\
    \ b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator >> (std::istream&\
    \ in, Mint& a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\r\
    \n\tfriend std::ostream& operator << (std::ostream& os, const Mint& a) { return\
    \ os << a.v; }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\tif ((v += m.v) >=\
    \ MOD) v -= MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const Mint& m)\
    \ { \r\n\t\tif ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\tMint& operator*=(const\
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
    \ int B = 2;\r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nBIT<mi, N, N> bit;\r\
    \n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\
    \tint n, m, q;\r\n\tcin >> m >> m >> q;\r\n\tmap<array<int, 4>, mi> rects;\r\n\
    \tmi run = 1;\r\n\twhile (q--) {\r\n\t\tint t, xl, xr, yl, yr;\r\n\t\tcin >> t\
    \ >> xl >> yl >> xr >> yr;\r\n\t\tauto rect = [&]() {\r\n\t\t\tmi v;\r\n\t\t\t\
    if (t == 1) {\r\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\r\n\t\t\t\tv = run;\r\n\
    \t\t\t\trun *= 2;\r\n\t\t\t} else {\r\n\t\t\t\tv = rects[{xl, xr, yl, yr}];\r\n\
    \t\t\t\tv *= -1;\r\n\t\t\t}\r\n\t\t\tbit.upd(xl, yl, v);\r\n\t\t\tbit.upd(xl,\
    \ yr + 1, -v);\r\n\t\t\tbit.upd(xr + 1, yl, -v);\r\n\t\t\tbit.upd(xr + 1, yr +\
    \ 1, v);\r\n\t\t};\r\n\t\tif (t <= 2) {\r\n\t\t\trect();\r\n\t\t} else {\t\r\n\
    \t\t\tif (bit.query(1, xl, 1, yl) == bit.query(1, xr, 1, yr)) {\r\n\t\t\t\tcout\
    \ << \"Yes\" << '\\n';\r\n\t\t\t} else {\r\n\t\t\t\tcout << \"No\" << '\\n';\r\
    \n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://codeforces.com/contest/869/problem/E\"\r\n\r\n\
    #include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/2d-range-queries/general-fenwick-tree.hpp\"\
    \r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\r\n\r\nconst int\
    \ N = 2505;\r\n\r\nconst int P = 998244353;\r\nconst int B = 2;\r\n\r\nusing mi\
    \ = Mint<998244353, 5>;\r\n\r\nBIT<mi, N, N> bit;\r\n\r\nint main() {\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint n, m, q;\r\n\tcin >> m >> m >> q;\r\n\tmap<array<int,\
    \ 4>, mi> rects;\r\n\tmi run = 1;\r\n\twhile (q--) {\r\n\t\tint t, xl, xr, yl,\
    \ yr;\r\n\t\tcin >> t >> xl >> yl >> xr >> yr;\r\n\t\tauto rect = [&]() {\r\n\t\
    \t\tmi v;\r\n\t\t\tif (t == 1) {\r\n\t\t\t\trects[{xl, xr, yl, yr}] = run;\r\n\
    \t\t\t\tv = run;\r\n\t\t\t\trun *= 2;\r\n\t\t\t} else {\r\n\t\t\t\tv = rects[{xl,\
    \ xr, yl, yr}];\r\n\t\t\t\tv *= -1;\r\n\t\t\t}\r\n\t\t\tbit.upd(xl, yl, v);\r\n\
    \t\t\tbit.upd(xl, yr + 1, -v);\r\n\t\t\tbit.upd(xr + 1, yl, -v);\r\n\t\t\tbit.upd(xr\
    \ + 1, yr + 1, v);\r\n\t\t};\r\n\t\tif (t <= 2) {\r\n\t\t\trect();\r\n\t\t} else\
    \ {\t\r\n\t\t\tif (bit.query(1, xl, 1, yl) == bit.query(1, xr, 1, yr)) {\r\n\t\
    \t\t\tcout << \"Yes\" << '\\n';\r\n\t\t\t} else {\r\n\t\t\t\tcout << \"No\" <<\
    \ '\\n';\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/2d-range-queries/general-fenwick-tree.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/codeforces/codeforces-869E-general-fwt.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/codeforces/codeforces-869E-general-fwt.test.cpp
layout: document
redirect_from:
- /verify/verify/codeforces/codeforces-869E-general-fwt.test.cpp
- /verify/verify/codeforces/codeforces-869E-general-fwt.test.cpp.html
title: verify/codeforces/codeforces-869E-general-fwt.test.cpp
---
