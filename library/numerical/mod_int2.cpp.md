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
    \n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct Mint {\n    static\
    \ const int mod = MOD;\n    static constexpr Mint rt() { return RT; } // primitive\
    \ root for FFT\n    int v; \n    explicit operator int() const { return v; } //\
    \ explicit -> don't silently convert to int\n    Mint() { v = 0; }\n    Mint(long\
    \ long _v) { v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v +=\
    \ MOD; }\n    friend bool operator == (const Mint& a, const Mint& b) { return\
    \ a.v == b.v; }\n    friend bool operator != (const Mint& a, const Mint& b) {\
    \ return !(a == b); }\n    friend bool operator < (const Mint& a, const Mint&\
    \ b) { return a.v < b.v; }\n    friend bool operator > (const Mint& a, const Mint&\
    \ b) { return a.v > b.v; }\n    friend bool operator <= (const Mint& a, const\
    \ Mint& b) { return a.v <= b.v; }\n    friend bool operator >= (const Mint& a,\
    \ const Mint& b) { return a.v >= b.v; }\n    friend std::istream& operator >>\
    \ (std::istream& in, Mint& a) { \n        long long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n    friend std::ostream& operator << (std::ostream& os, const\
    \ Mint& a) { return os << a.v; }\n    Mint& operator += (const Mint& m) { \n \
    \       if ((v += m.v) >= MOD) v -= MOD; \n        return *this; }\n    Mint&\
    \ operator -= (const Mint& m) { \n        if ((v -= m.v) < 0) v += MOD; \n   \
    \     return *this; }\n    Mint& operator *= (const Mint& m) { \n        v = (long\
    \ long ) v * m.v % MOD; return *this; }\n    Mint& operator /= (const Mint& m)\
    \ { return (*this) *= inv(m); }\n    friend Mint pow(Mint a, long long p) {\n\
    \        Mint ans = 1; assert(p >= 0);\n        for (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n        return ans; \n    }\n    friend Mint inv(const Mint&\
    \ a) { assert(a.v != 0); return pow(a, MOD - 2); }\n    Mint operator - () const\
    \ { return Mint(-v); }\n    Mint& operator ++ () { return *this += 1; }\n    Mint&\
    \ operator -- () { return *this -= 1; }\n    friend Mint operator + (Mint a, const\
    \ Mint& b) { return a += b; }\n    friend Mint operator - (Mint a, const Mint&\
    \ b) { return a -= b; }\n    friend Mint operator * (Mint a, const Mint& b) {\
    \ return a *= b; }\n    friend Mint operator / (Mint a, const Mint& b) { return\
    \ a /= b; }\n};\n\nint main() {\n    return 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\n// 5 is a root of both mods\ntemplate <int MOD,\
    \ int RT> struct Mint {\n    static const int mod = MOD;\n    static constexpr\
    \ Mint rt() { return RT; } // primitive root for FFT\n    int v; \n    explicit\
    \ operator int() const { return v; } // explicit -> don't silently convert to\
    \ int\n    Mint() { v = 0; }\n    Mint(long long _v) { v = int((-MOD < _v && _v\
    \ < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n    friend bool operator ==\
    \ (const Mint& a, const Mint& b) { return a.v == b.v; }\n    friend bool operator\
    \ != (const Mint& a, const Mint& b) { return !(a == b); }\n    friend bool operator\
    \ < (const Mint& a, const Mint& b) { return a.v < b.v; }\n    friend bool operator\
    \ > (const Mint& a, const Mint& b) { return a.v > b.v; }\n    friend bool operator\
    \ <= (const Mint& a, const Mint& b) { return a.v <= b.v; }\n    friend bool operator\
    \ >= (const Mint& a, const Mint& b) { return a.v >= b.v; }\n    friend std::istream&\
    \ operator >> (std::istream& in, Mint& a) { \n        long long x; std::cin >>\
    \ x; a = Mint(x); return in; }\n    friend std::ostream& operator << (std::ostream&\
    \ os, const Mint& a) { return os << a.v; }\n    Mint& operator += (const Mint&\
    \ m) { \n        if ((v += m.v) >= MOD) v -= MOD; \n        return *this; }\n\
    \    Mint& operator -= (const Mint& m) { \n        if ((v -= m.v) < 0) v += MOD;\
    \ \n        return *this; }\n    Mint& operator *= (const Mint& m) { \n      \
    \  v = (long long ) v * m.v % MOD; return *this; }\n    Mint& operator /= (const\
    \ Mint& m) { return (*this) *= inv(m); }\n    friend Mint pow(Mint a, long long\
    \ p) {\n        Mint ans = 1; assert(p >= 0);\n        for (; p; p /= 2, a *=\
    \ a) if (p & 1) ans *= a;\n        return ans; \n    }\n    friend Mint inv(const\
    \ Mint& a) { assert(a.v != 0); return pow(a, MOD - 2); }\n    Mint operator -\
    \ () const { return Mint(-v); }\n    Mint& operator ++ () { return *this += 1;\
    \ }\n    Mint& operator -- () { return *this -= 1; }\n    friend Mint operator\
    \ + (Mint a, const Mint& b) { return a += b; }\n    friend Mint operator - (Mint\
    \ a, const Mint& b) { return a -= b; }\n    friend Mint operator * (Mint a, const\
    \ Mint& b) { return a *= b; }\n    friend Mint operator / (Mint a, const Mint&\
    \ b) { return a /= b; }\n};\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod_int2.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/numerical/mod_int2.cpp
layout: document
redirect_from:
- /library/library/numerical/mod_int2.cpp
- /library/library/numerical/mod_int2.cpp.html
title: library/numerical/mod_int2.cpp
---
