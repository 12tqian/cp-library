---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/numerical/mod_int2.cpp\"\n#include <bits/stdc++.h>\r\
    \n\r\n// 5 is a root of both mods\r\ntemplate <int MOD, int RT> struct Mint {\r\
    \n    static const int mod = MOD;\r\n    static constexpr Mint rt() { return RT;\
    \ } // primitive root for FFT\r\n    int v; \r\n    explicit operator int() const\
    \ { return v; } // explicit -> don't silently convert to int\r\n    Mint() { v\
    \ = 0; }\r\n    Mint(long long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v\
    \ % MOD); if (v < 0) v += MOD; }\r\n    friend bool operator == (const Mint& a,\
    \ const Mint& b) { return a.v == b.v; }\r\n    friend bool operator != (const\
    \ Mint& a, const Mint& b) { return !(a == b); }\r\n    friend bool operator <\
    \ (const Mint& a, const Mint& b) { return a.v < b.v; }\r\n    friend bool operator\
    \ > (const Mint& a, const Mint& b) { return a.v > b.v; }\r\n    friend bool operator\
    \ <= (const Mint& a, const Mint& b) { return a.v <= b.v; }\r\n    friend bool\
    \ operator >= (const Mint& a, const Mint& b) { return a.v >= b.v; }\r\n    friend\
    \ std::istream& operator >> (std::istream& in, Mint& a) { \r\n        long long\
    \ x; std::cin >> x; a = Mint(x); return in; }\r\n    friend std::ostream& operator\
    \ << (std::ostream& os, const Mint& a) { return os << a.v; }\r\n    Mint& operator\
    \ += (const Mint& m) { \r\n        if ((v += m.v) >= MOD) v -= MOD; \r\n     \
    \   return *this; }\r\n    Mint& operator -= (const Mint& m) { \r\n        if\
    \ ((v -= m.v) < 0) v += MOD; \r\n        return *this; }\r\n    Mint& operator\
    \ *= (const Mint& m) { \r\n        v = (long long ) v * m.v % MOD; return *this;\
    \ }\r\n    Mint& operator /= (const Mint& m) { return (*this) *= inv(m); }\r\n\
    \    friend Mint pow(Mint a, long long p) {\r\n        Mint ans = 1; assert(p\
    \ >= 0);\r\n        for (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n       \
    \ return ans; \r\n    }\r\n    friend Mint inv(const Mint& a) { assert(a.v !=\
    \ 0); return pow(a, MOD - 2); }\r\n    Mint operator - () const { return Mint(-v);\
    \ }\r\n    Mint& operator ++ () { return *this += 1; }\r\n    Mint& operator --\
    \ () { return *this -= 1; }\r\n    friend Mint operator + (Mint a, const Mint&\
    \ b) { return a += b; }\r\n    friend Mint operator - (Mint a, const Mint& b)\
    \ { return a -= b; }\r\n    friend Mint operator * (Mint a, const Mint& b) { return\
    \ a *= b; }\r\n    friend Mint operator / (Mint a, const Mint& b) { return a /=\
    \ b; }\r\n};\r\n\r\nint main() {\r\n    return 0;\r\n}\n"
  code: "#include <bits/stdc++.h>\r\n\r\n// 5 is a root of both mods\r\ntemplate <int\
    \ MOD, int RT> struct Mint {\r\n    static const int mod = MOD;\r\n    static\
    \ constexpr Mint rt() { return RT; } // primitive root for FFT\r\n    int v; \r\
    \n    explicit operator int() const { return v; } // explicit -> don't silently\
    \ convert to int\r\n    Mint() { v = 0; }\r\n    Mint(long long _v) { v = int((-MOD\
    \ < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\r\n    friend bool\
    \ operator == (const Mint& a, const Mint& b) { return a.v == b.v; }\r\n    friend\
    \ bool operator != (const Mint& a, const Mint& b) { return !(a == b); }\r\n  \
    \  friend bool operator < (const Mint& a, const Mint& b) { return a.v < b.v; }\r\
    \n    friend bool operator > (const Mint& a, const Mint& b) { return a.v > b.v;\
    \ }\r\n    friend bool operator <= (const Mint& a, const Mint& b) { return a.v\
    \ <= b.v; }\r\n    friend bool operator >= (const Mint& a, const Mint& b) { return\
    \ a.v >= b.v; }\r\n    friend std::istream& operator >> (std::istream& in, Mint&\
    \ a) { \r\n        long long x; std::cin >> x; a = Mint(x); return in; }\r\n \
    \   friend std::ostream& operator << (std::ostream& os, const Mint& a) { return\
    \ os << a.v; }\r\n    Mint& operator += (const Mint& m) { \r\n        if ((v +=\
    \ m.v) >= MOD) v -= MOD; \r\n        return *this; }\r\n    Mint& operator -=\
    \ (const Mint& m) { \r\n        if ((v -= m.v) < 0) v += MOD; \r\n        return\
    \ *this; }\r\n    Mint& operator *= (const Mint& m) { \r\n        v = (long long\
    \ ) v * m.v % MOD; return *this; }\r\n    Mint& operator /= (const Mint& m) {\
    \ return (*this) *= inv(m); }\r\n    friend Mint pow(Mint a, long long p) {\r\n\
    \        Mint ans = 1; assert(p >= 0);\r\n        for (; p; p /= 2, a *= a) if\
    \ (p & 1) ans *= a;\r\n        return ans; \r\n    }\r\n    friend Mint inv(const\
    \ Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }\r\n    Mint operator\
    \ - () const { return Mint(-v); }\r\n    Mint& operator ++ () { return *this +=\
    \ 1; }\r\n    Mint& operator -- () { return *this -= 1; }\r\n    friend Mint operator\
    \ + (Mint a, const Mint& b) { return a += b; }\r\n    friend Mint operator - (Mint\
    \ a, const Mint& b) { return a -= b; }\r\n    friend Mint operator * (Mint a,\
    \ const Mint& b) { return a *= b; }\r\n    friend Mint operator / (Mint a, const\
    \ Mint& b) { return a /= b; }\r\n};\r\n\r\nint main() {\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod_int2.cpp
  requiredBy: []
  timestamp: '2020-11-28 20:59:18-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/mod_int2.cpp
layout: document
redirect_from:
- /library/library/numerical/mod_int2.cpp
- /library/library/numerical/mod_int2.cpp.html
title: library/numerical/mod_int2.cpp
---
