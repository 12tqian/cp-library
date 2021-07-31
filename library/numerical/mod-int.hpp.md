---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/codeforces/codeforces-1551F.test.cpp
    title: verify/codeforces/codeforces-1551F.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\nconst int MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return\
    \ val; }\n\texplicit operator bool() const { return v != 0; }\n\tmi() { val =\
    \ 0; }\n\tmi(const long long &v) {\n\t\tval = (-MOD <= v && v < MOD) ? v : v %\
    \ MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator>>(std::istream\
    \ &in, mi &a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\t\
    friend std::ostream& operator<<(std::ostream &os, const mi &a) { return os <<\
    \ a.val; }\n\tfriend bool operator==(const mi &a, const mi &b) { return a.val\
    \ == b.val; }\n\tfriend bool operator!=(const mi &a, const mi &b) { return !(a\
    \ == b); }    \n\tfriend bool operator<(const mi &a, const mi &b) { return a.val\
    \ < b.val; }\n\tfriend bool operator>(const mi &a, const mi &b) { return a.val\
    \ > b.val; }\n\tfriend bool operator<=(const mi &a, const mi &b) { return a.val\
    \ <= b.val; }\n\tfriend bool operator>=(const mi &a, const mi &b) { return a.val\
    \ >= b.val; }\n\tmi operator-() const { return mi(-val); }\n\tmi& operator+=(const\
    \ mi &m) {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\t\
    mi& operator-=(const mi &m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn\
    \ *this; }\n\tmi& operator*=(const mi &m) { val = (long long)val * m.val % MOD;\n\
    \t\treturn *this; }\n\tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p\
    \ >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans;\
    \ }\n\tfriend mi inv(const mi &a) { assert(a != 0); return pow(a, MOD - 2); }\n\
    \tmi& operator/=(const mi &m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi\
    \ a, const mi &b) { return a += b; }\n\tfriend mi operator-(mi a, const mi &b)\
    \ { return a -= b; }\n\tfriend mi operator*(mi a, const mi &b) { return a *= b;\
    \ }\n\tfriend mi operator/(mi a, const mi &b) { return a /= b; }\n};\n"
  code: "#pragma once\n\nconst int MOD = 1e9 + 7;\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return\
    \ val; }\n\texplicit operator bool() const { return v != 0; }\n\tmi() { val =\
    \ 0; }\n\tmi(const long long &v) {\n\t\tval = (-MOD <= v && v < MOD) ? v : v %\
    \ MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator>>(std::istream\
    \ &in, mi &a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\t\
    friend std::ostream& operator<<(std::ostream &os, const mi &a) { return os <<\
    \ a.val; }\n\tfriend bool operator==(const mi &a, const mi &b) { return a.val\
    \ == b.val; }\n\tfriend bool operator!=(const mi &a, const mi &b) { return !(a\
    \ == b); }    \n\tfriend bool operator<(const mi &a, const mi &b) { return a.val\
    \ < b.val; }\n\tfriend bool operator>(const mi &a, const mi &b) { return a.val\
    \ > b.val; }\n\tfriend bool operator<=(const mi &a, const mi &b) { return a.val\
    \ <= b.val; }\n\tfriend bool operator>=(const mi &a, const mi &b) { return a.val\
    \ >= b.val; }\n\tmi operator-() const { return mi(-val); }\n\tmi& operator+=(const\
    \ mi &m) {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\t\
    mi& operator-=(const mi &m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn\
    \ *this; }\n\tmi& operator*=(const mi &m) { val = (long long)val * m.val % MOD;\n\
    \t\treturn *this; }\n\tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p\
    \ >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans;\
    \ }\n\tfriend mi inv(const mi &a) { assert(a != 0); return pow(a, MOD - 2); }\n\
    \tmi& operator/=(const mi &m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi\
    \ a, const mi &b) { return a += b; }\n\tfriend mi operator-(mi a, const mi &b)\
    \ { return a -= b; }\n\tfriend mi operator*(mi a, const mi &b) { return a *= b;\
    \ }\n\tfriend mi operator/(mi a, const mi &b) { return a /= b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/mod-int.hpp
  requiredBy: []
  timestamp: '2021-07-30 23:07:00-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/codeforces/codeforces-1551F.test.cpp
documentation_of: library/numerical/mod-int.hpp
layout: document
redirect_from:
- /library/library/numerical/mod-int.hpp
- /library/library/numerical/mod-int.hpp.html
title: library/numerical/mod-int.hpp
---
