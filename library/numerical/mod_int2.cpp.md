---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/mod_int2.cpp\"\n#include <bits/stdc++.h>\n\
    \n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic\
    \ const int mod = MOD;\n\tstatic constexpr Mint rt() { return RT; } // primitive\
    \ root for FFT\n\tint v; \n\texplicit operator int() const { return v; } // explicit\
    \ -> don't silently convert to int\n\tMint() { v = 0; }\n\tMint(long long _v)\
    \ { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\
    \tfriend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }\n\
    \tfriend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }\n\
    \tfriend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }\n\t\
    friend bool operator>(const Mint &a, const Mint &b) { return a.v > b.v; }\n\t\
    friend bool operator<=(const Mint &a, const Mint &b) { return a.v <= b.v; }\n\t\
    friend bool operator>=(const Mint &a, const Mint &b) { return a.v >= b.v; }\n\t\
    friend std::istream& operator >> (std::istream &in, Mint &a) { \n\t\tlong long\
    \ x; std::cin >> x; a = Mint(x); return in; }\n\tfriend std::ostream& operator\
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
    \ { return a /= b; }\n};\n"
  code: "#include <bits/stdc++.h>\n\n// 5 is a root of both mods\ntemplate <int MOD,\
    \ int RT> struct Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint\
    \ rt() { return RT; } // primitive root for FFT\n\tint v; \n\texplicit operator\
    \ int() const { return v; } // explicit -> don't silently convert to int\n\tMint()\
    \ { v = 0; }\n\tMint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v\
    \ % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint &a, const\
    \ Mint &b) { return a.v == b.v; }\n\tfriend bool operator!=(const Mint &a, const\
    \ Mint &b) { return !(a == b); }\n\tfriend bool operator<(const Mint &a, const\
    \ Mint &b) { return a.v < b.v; }\n\tfriend bool operator>(const Mint &a, const\
    \ Mint &b) { return a.v > b.v; }\n\tfriend bool operator<=(const Mint &a, const\
    \ Mint &b) { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint &a, const\
    \ Mint &b) { return a.v >= b.v; }\n\tfriend std::istream& operator >> (std::istream\
    \ &in, Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\n\
    \tfriend std::ostream& operator << (std::ostream &os, const Mint &a) { return\
    \ os << a.v; }\n\tMint& operator+=(const Mint &m) { \n\t\tif ((v += m.v) >= MOD)\
    \ v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint &m) { \n\t\t\
    if ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint &m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint &m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint &a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint &b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint &b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint &b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod_int2.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/mod_int2.cpp
layout: document
redirect_from:
- /library/library/numerical/mod_int2.cpp
- /library/library/numerical/mod_int2.cpp.html
title: library/numerical/mod_int2.cpp
---
