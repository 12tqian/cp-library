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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \nnamespace Karatsuba {\n\nint size(int s) {\n\treturn s > 1 ? 32 - __builtin_clz(s\
    \ - 1) : 0;\n}\n\ntemplate <class T> void karatsuba(T *a, T *b, T *c, T *t, int\
    \ n) {\n\tint ca = 0, cb = 0;\n\tfor (int i = 0; i < n; i++)\n\t\tca += (a[i]\
    \ != 0), cb += (b[i] != 0);\n\tif (std::min(ca, cb) <= 1500 / n) { // not many\
    \ multiplications\n\t\tif (ca > cb) \n\t\t\tstd::swap(ca, cb);\n\t\tfor (int i\
    \ = 0; i < n; i++) \n\t\t\tif (a[i] != 0)\n\t\t\t\tfor (int j = 0; j < n; j++)\n\
    \t\t\t\t\tc[i + j] += a[i] * b[j];\n\n\t} else {\n\t\tint h = n >> 1;\n\t\tkaratsuba(a,\
    \ b, c, t, h); // a0 * b0\n\t\tkaratsuba(a + h, b + h, c + n, t, h); // a1 * b1\n\
    \t\tfor (int i = 0; i < h; i++)\n\t\t\ta[i] += a[i + h], b[i] += b[i + h];\n\t\
    \tkaratsuba(a, b, t, t + n, h); // (a0 + a1) * (b0 + b1)\n\t\tfor (int i = 0;\
    \ i < h; i++)\n\t\t\ta[i] -= a[i + h], b[i] -= b[i + h];\n\t\tfor (int i = 0;\
    \ i < n; i++)\n\t\t\tt[i] -= c[i] + c[i + n];\n\t\tfor (int i = 0; i < n; i++)\n\
    \t\t\tc[i + h] += t[i], t[i] = 0;\n\t}\n}\n\ntemplate <class T> std::vector<T>\
    \ convolution(std::vector<T> a, std::vector<T> b) {\n\tint sa = (int)a.size(),\
    \ sb = (int)b.size();\n\tif (!sa || !sb) \n\t\treturn {};\n\tint n = (1 << size(std::max(sa,\
    \ sb)));\n\ta.resize(n);\n\tb.resize(n);\n\tstd::vector<T> c(2 * n), t(2 * n);\n\
    \tkaratsuba(&a[0], &b[0], &c[0], &t[0], n);\n\tc.resize(sa + sb - 1);\n\treturn\
    \ c;\n}\n\n}\n\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct\
    \ Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint rt() { return\
    \ RT; } // primitive root for FFT\n\tstatic constexpr int md() { return MOD; }\
    \ // primitive root for FFT\n\tint v; \n\texplicit operator int() const { return\
    \ v; } // explicit -> don't silently convert to int\n\texplicit operator bool()\
    \ const { return v != 0; }\n\tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD\
    \ <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const\
    \ Mint& a, const Mint& b) { return a.v == b.v; }\n\tfriend bool operator!=(const\
    \ Mint& a, const Mint& b) { return !(a == b); }\n\tfriend bool operator<(const\
    \ Mint& a, const Mint& b) { return a.v < b.v; }\n\tfriend bool operator>(const\
    \ Mint& a, const Mint& b) { return a.v > b.v; }\n\tfriend bool operator<=(const\
    \ Mint& a, const Mint& b) { return a.v <= b.v; }\n\tfriend bool operator>=(const\
    \ Mint& a, const Mint& b) { return a.v >= b.v; }\n\tfriend std::istream& operator\
    \ >> (std::istream& in, Mint& a) { \n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n\tfriend std::ostream& operator << (std::ostream& os, const Mint&\
    \ a) { return os << a.v; }\n\tMint& operator+=(const Mint& m) { \n\t\tif ((v +=\
    \ m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint&\
    \ m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint& m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint& m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint& a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint& b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint& b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint& b) { return a /= b; }\n};\n\nint main() {\n\t\
    const int MOD = 1e9 + 7;\n\tusing mi = Mint<MOD, 5>;\n\tusing namespace Karatsuba;\n\
    \tios_base::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint sa, sb;\n\tcin\
    \ >> sa >> sb;\n\tvector<mi> a(sa);\n\tfor (int i = 0; i < sa; i++)\n\t\tcin >>\
    \ a[i];\n\tvector<mi> b(sb);\n\tfor (int i = 0; i < sb; i++)\n\t\tcin >> b[i];\n\
    \tvector<mi> c = convolution<mi>(a, b);\n\tfor (int i = 0; i < (int)c.size();\
    \ i++)\n\t\tcout << c[i] << \" \";\n\tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/polynomial/karatsuba.hpp\"\
    \n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\n\nint main() {\n\
    \tconst int MOD = 1e9 + 7;\n\tusing mi = Mint<MOD, 5>;\n\tusing namespace Karatsuba;\n\
    \tios_base::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\tint sa, sb;\n\tcin\
    \ >> sa >> sb;\n\tvector<mi> a(sa);\n\tfor (int i = 0; i < sa; i++)\n\t\tcin >>\
    \ a[i];\n\tvector<mi> b(sb);\n\tfor (int i = 0; i < sb; i++)\n\t\tcin >> b[i];\n\
    \tvector<mi> c = convolution<mi>(a, b);\n\tfor (int i = 0; i < (int)c.size();\
    \ i++)\n\t\tcout << c[i] << \" \";\n\tcout << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/polynomial/karatsuba.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 17:58:43-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp.html
title: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
---
