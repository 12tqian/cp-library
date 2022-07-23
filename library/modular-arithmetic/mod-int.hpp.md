---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.cpp
    title: library/contest/template-full.cpp
  - icon: ':question:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1551F.test.cpp
    title: verify/codeforces/codeforces-1551F.test.cpp
  - icon: ':x:'
    path: verify/unit-test/unit-test-big-integer.test.cpp
    title: verify/unit-test/unit-test-big-integer.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-fraction.test.cpp
    title: verify/unit-test/unit-test-fraction.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-gosper-hack.test.cpp
    title: verify/unit-test/unit-test-gosper-hack.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-hashing.test.cpp
    title: verify/unit-test/unit-test-hashing.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/unit-test/unit-test-template-full.test.cpp
    title: verify/unit-test/unit-test-template-full.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\r\nconst int MOD = 1e9 + 7; // 998244353\r\n\r\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \r\nstruct mi {\r\n\tmod_t v;\r\n\texplicit operator mod_t() const {\
    \ return v; }\r\n\texplicit operator bool() const { return v != 0; }\r\n\tmi()\
    \ { v = 0; }\r\n\tmi(const long long& _v) {\r\n\t\tv = (-MOD <= _v && _v < MOD)\
    \ ? _v : _v % MOD;\r\n\t\tif (v < 0) v += MOD; }\r\n\tfriend std::istream& operator>>(std::istream&\
    \ in, mi& a) { \r\n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\r\n\
    \tfriend std::ostream& operator<<(std::ostream& os, const mi& a) { return os <<\
    \ a.v; }\r\n\tfriend bool operator==(const mi& a, const mi& b) { return a.v ==\
    \ b.v; }\r\n\tfriend bool operator!=(const mi& a, const mi& b) { return !(a ==\
    \ b); }    \r\n\tfriend bool operator<(const mi& a, const mi& b) { return a.v\
    \ < b.v; }\r\n\tfriend bool operator>(const mi& a, const mi& b) { return a.v >\
    \ b.v; }\r\n\tfriend bool operator<=(const mi& a, const mi& b) { return a.v <=\
    \ b.v; }\r\n\tfriend bool operator>=(const mi& a, const mi& b) { return a.v >=\
    \ b.v; }\r\n\tmi operator-() const { return mi(-v); }\r\n\tmi& operator+=(const\
    \ mi& m) {\r\n\t\tif ((v += m.v) >= MOD) v -= MOD;\r\n\t\treturn *this; }\r\n\t\
    mi& operator-=(const mi& m) {\r\n\t\tif ((v -= m.v) < 0) v += MOD;\r\n\t\treturn\
    \ *this; }\r\n\tmi& operator*=(const mi& m) { v = (long long)v * m.v % MOD;\r\n\
    \t\treturn *this; }\r\n\tfriend mi pow(mi a, long long p) {\r\n\t\tmi ans = 1;\
    \ assert(p >= 0);\r\n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\t\t\
    return ans; }\r\n\tfriend mi inv(const mi& a) { assert(a != 0); return pow(a,\
    \ MOD - 2); }\r\n\tmi& operator/=(const mi& m) { return (*this) *= inv(m); }\r\
    \n\tfriend mi operator+(mi a, const mi& b) { return a += b; }\r\n\tfriend mi operator-(mi\
    \ a, const mi& b) { return a -= b; }\r\n\tfriend mi operator*(mi a, const mi&\
    \ b) { return a *= b; }\r\n\tfriend mi operator/(mi a, const mi& b) { return a\
    \ /= b; }\r\n};\n"
  code: "#pragma once\r\n\r\nconst int MOD = 1e9 + 7; // 998244353\r\n\r\ntypedef\
    \ std::decay<decltype(MOD)>::type mod_t; \r\nstruct mi {\r\n\tmod_t v;\r\n\texplicit\
    \ operator mod_t() const { return v; }\r\n\texplicit operator bool() const { return\
    \ v != 0; }\r\n\tmi() { v = 0; }\r\n\tmi(const long long& _v) {\r\n\t\tv = (-MOD\
    \ <= _v && _v < MOD) ? _v : _v % MOD;\r\n\t\tif (v < 0) v += MOD; }\r\n\tfriend\
    \ std::istream& operator>>(std::istream& in, mi& a) { \r\n\t\tlong long x; std::cin\
    \ >> x; a = mi(x); return in; }\r\n\tfriend std::ostream& operator<<(std::ostream&\
    \ os, const mi& a) { return os << a.v; }\r\n\tfriend bool operator==(const mi&\
    \ a, const mi& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const mi&\
    \ a, const mi& b) { return !(a == b); }    \r\n\tfriend bool operator<(const mi&\
    \ a, const mi& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const mi& a,\
    \ const mi& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const mi& a,\
    \ const mi& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const mi& a,\
    \ const mi& b) { return a.v >= b.v; }\r\n\tmi operator-() const { return mi(-v);\
    \ }\r\n\tmi& operator+=(const mi& m) {\r\n\t\tif ((v += m.v) >= MOD) v -= MOD;\r\
    \n\t\treturn *this; }\r\n\tmi& operator-=(const mi& m) {\r\n\t\tif ((v -= m.v)\
    \ < 0) v += MOD;\r\n\t\treturn *this; }\r\n\tmi& operator*=(const mi& m) { v =\
    \ (long long)v * m.v % MOD;\r\n\t\treturn *this; }\r\n\tfriend mi pow(mi a, long\
    \ long p) {\r\n\t\tmi ans = 1; assert(p >= 0);\r\n\t\tfor (; p; p /= 2, a *= a)\
    \ if (p & 1) ans *= a;\r\n\t\treturn ans; }\r\n\tfriend mi inv(const mi& a) {\
    \ assert(a != 0); return pow(a, MOD - 2); }\r\n\tmi& operator/=(const mi& m) {\
    \ return (*this) *= inv(m); }\r\n\tfriend mi operator+(mi a, const mi& b) { return\
    \ a += b; }\r\n\tfriend mi operator-(mi a, const mi& b) { return a -= b; }\r\n\
    \tfriend mi operator*(mi a, const mi& b) { return a *= b; }\r\n\tfriend mi operator/(mi\
    \ a, const mi& b) { return a /= b; }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/modular-arithmetic/mod-int.hpp
  requiredBy:
  - library/contest/template-full.cpp
  - library/contest/template-full.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/unit-test/unit-test-fraction.test.cpp
  - verify/unit-test/unit-test-gosper-hack.test.cpp
  - verify/unit-test/unit-test-big-integer.test.cpp
  - verify/unit-test/unit-test-hashing.test.cpp
  - verify/unit-test/unit-test-template-full.test.cpp
  - verify/codeforces/codeforces-1551F.test.cpp
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
documentation_of: library/modular-arithmetic/mod-int.hpp
layout: document
redirect_from:
- /library/library/modular-arithmetic/mod-int.hpp
- /library/library/modular-arithmetic/mod-int.hpp.html
title: library/modular-arithmetic/mod-int.hpp
---
