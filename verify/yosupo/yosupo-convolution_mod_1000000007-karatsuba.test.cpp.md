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
    path: library/polynomial/karatsuba.hpp
    title: library/polynomial/karatsuba.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\nnamespace Karatsuba {\r\n\
    \r\nint size(int s) {\r\n\treturn s > 1 ? 32 - __builtin_clz(s - 1) : 0;\r\n}\r\
    \n\r\ntemplate <class T> void karatsuba(T* a, T* b, T* c, T* t, int n) {\r\n\t\
    int ca = 0, cb = 0;\r\n\tfor (int i = 0; i < n; i++)\r\n\t\tca += (a[i] != 0),\
    \ cb += (b[i] != 0);\r\n\tif (std::min(ca, cb) <= 1500 / n) { // not many multiplications\r\
    \n\t\tif (ca > cb) \r\n\t\t\tstd::swap(ca, cb);\r\n\t\tfor (int i = 0; i < n;\
    \ i++) \r\n\t\t\tif (a[i] != 0)\r\n\t\t\t\tfor (int j = 0; j < n; j++)\r\n\t\t\
    \t\t\tc[i + j] += a[i] * b[j];\r\n\r\n\t} else {\r\n\t\tint h = n >> 1;\r\n\t\t\
    karatsuba(a, b, c, t, h); // a0 * b0\r\n\t\tkaratsuba(a + h, b + h, c + n, t,\
    \ h); // a1 * b1\r\n\t\tfor (int i = 0; i < h; i++)\r\n\t\t\ta[i] += a[i + h],\
    \ b[i] += b[i + h];\r\n\t\tkaratsuba(a, b, t, t + n, h); // (a0 + a1) * (b0 +\
    \ b1)\r\n\t\tfor (int i = 0; i < h; i++)\r\n\t\t\ta[i] -= a[i + h], b[i] -= b[i\
    \ + h];\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tt[i] -= c[i] + c[i + n];\r\
    \n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\tc[i + h] += t[i], t[i] = 0;\r\n\t}\r\
    \n}\r\n\r\ntemplate <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T>\
    \ b) {\r\n\tint sa = (int)a.size(), sb = (int)b.size();\r\n\tif (!sa || !sb) \r\
    \n\t\treturn {};\r\n\tint n = (1 << size(std::max(sa, sb)));\r\n\ta.resize(n);\r\
    \n\tb.resize(n);\r\n\tstd::vector<T> c(2 * n), t(2 * n);\r\n\tkaratsuba(&a[0],\
    \ &b[0], &c[0], &t[0], n);\r\n\tc.resize(sa + sb - 1);\r\n\treturn c;\r\n}\r\n\
    \r\n}\n\r\n// 5 is a root of both mods\r\ntemplate <int MOD, int RT> struct Mint\
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
    \ }\r\n};\r\n\r\nint main() {\r\n\tconst int MOD = 1e9 + 7;\r\n\tusing mi = Mint<MOD,\
    \ 5>;\r\n\tusing namespace Karatsuba;\r\n\tios_base::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\tint sa, sb;\r\n\tcin >> sa >> sb;\r\n\tvector<mi> a(sa);\r\
    \n\tfor (int i = 0; i < sa; i++)\r\n\t\tcin >> a[i];\r\n\tvector<mi> b(sb);\r\n\
    \tfor (int i = 0; i < sb; i++)\r\n\t\tcin >> b[i];\r\n\tvector<mi> c = convolution<mi>(a,\
    \ b);\r\n\tfor (int i = 0; i < (int)c.size(); i++)\r\n\t\tcout << c[i] << \" \"\
    ;\r\n\tcout << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/polynomial/karatsuba.hpp\"\r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\
    \r\n\r\nint main() {\r\n\tconst int MOD = 1e9 + 7;\r\n\tusing mi = Mint<MOD, 5>;\r\
    \n\tusing namespace Karatsuba;\r\n\tios_base::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\
    \n\tint sa, sb;\r\n\tcin >> sa >> sb;\r\n\tvector<mi> a(sa);\r\n\tfor (int i =\
    \ 0; i < sa; i++)\r\n\t\tcin >> a[i];\r\n\tvector<mi> b(sb);\r\n\tfor (int i =\
    \ 0; i < sb; i++)\r\n\t\tcin >> b[i];\r\n\tvector<mi> c = convolution<mi>(a, b);\r\
    \n\tfor (int i = 0; i < (int)c.size(); i++)\r\n\t\tcout << c[i] << \" \";\r\n\t\
    cout << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/polynomial/karatsuba.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp.html
title: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
---
