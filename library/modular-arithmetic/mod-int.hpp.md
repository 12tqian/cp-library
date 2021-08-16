---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.cpp
    title: library/contest/template-full.cpp
  - icon: ':heavy_check_mark:'
    path: library/contest/template-full.hpp
    title: library/contest/template-full.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1551F.test.cpp
    title: verify/codeforces/codeforces-1551F.test.cpp
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nconst int MOD = 1e9 + 7; // 998244353\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return\
    \ val; }\n\texplicit operator bool() const { return val != 0; }\n\tmi() { val\
    \ = 0; }\n\tmi(const long long& v) {\n\t\tval = (-MOD <= v && v < MOD) ? v : v\
    \ % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator>>(std::istream&\
    \ in, mi& a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.val;\
    \ }\n\tfriend bool operator==(const mi& a, const mi& b) { return a.val == b.val;\
    \ }\n\tfriend bool operator!=(const mi& a, const mi& b) { return !(a == b); }\
    \    \n\tfriend bool operator<(const mi& a, const mi& b) { return a.val < b.val;\
    \ }\n\tfriend bool operator>(const mi& a, const mi& b) { return a.val > b.val;\
    \ }\n\tfriend bool operator<=(const mi& a, const mi& b) { return a.val <= b.val;\
    \ }\n\tfriend bool operator>=(const mi& a, const mi& b) { return a.val >= b.val;\
    \ }\n\tmi operator-() const { return mi(-val); }\n\tmi& operator+=(const mi& m)\
    \ {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\tmi& operator-=(const\
    \ mi& m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn *this; }\n\tmi&\
    \ operator*=(const mi& m) { val = (long long)val * m.val % MOD;\n\t\treturn *this;\
    \ }\n\tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\
    \tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans; }\n\tfriend\
    \ mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const\
    \ mi& m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi a, const mi&\
    \ b) { return a += b; }\n\tfriend mi operator-(mi a, const mi& b) { return a -=\
    \ b; }\n\tfriend mi operator*(mi a, const mi& b) { return a *= b; }\n\tfriend\
    \ mi operator/(mi a, const mi& b) { return a /= b; }\n};\n"
  code: "#pragma once\n\nconst int MOD = 1e9 + 7; // 998244353\n\ntypedef std::decay<decltype(MOD)>::type\
    \ mod_t; \nstruct mi {\n\tmod_t val;\n\texplicit operator mod_t() const { return\
    \ val; }\n\texplicit operator bool() const { return val != 0; }\n\tmi() { val\
    \ = 0; }\n\tmi(const long long& v) {\n\t\tval = (-MOD <= v && v < MOD) ? v : v\
    \ % MOD;\n\t\tif (val < 0) val += MOD; }\n\tfriend std::istream& operator>>(std::istream&\
    \ in, mi& a) { \n\t\tlong long x; std::cin >> x; a = mi(x); return in; }\n\tfriend\
    \ std::ostream& operator<<(std::ostream& os, const mi& a) { return os << a.val;\
    \ }\n\tfriend bool operator==(const mi& a, const mi& b) { return a.val == b.val;\
    \ }\n\tfriend bool operator!=(const mi& a, const mi& b) { return !(a == b); }\
    \    \n\tfriend bool operator<(const mi& a, const mi& b) { return a.val < b.val;\
    \ }\n\tfriend bool operator>(const mi& a, const mi& b) { return a.val > b.val;\
    \ }\n\tfriend bool operator<=(const mi& a, const mi& b) { return a.val <= b.val;\
    \ }\n\tfriend bool operator>=(const mi& a, const mi& b) { return a.val >= b.val;\
    \ }\n\tmi operator-() const { return mi(-val); }\n\tmi& operator+=(const mi& m)\
    \ {\n\t\tif ((val += m.val) >= MOD) val -= MOD;\n\t\treturn *this; }\n\tmi& operator-=(const\
    \ mi& m) {\n\t\tif ((val -= m.val) < 0) val += MOD;\n\t\treturn *this; }\n\tmi&\
    \ operator*=(const mi& m) { val = (long long)val * m.val % MOD;\n\t\treturn *this;\
    \ }\n\tfriend mi pow(mi a, long long p) {\n\t\tmi ans = 1; assert(p >= 0);\n\t\
    \tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\n\t\treturn ans; }\n\tfriend\
    \ mi inv(const mi& a) { assert(a != 0); return pow(a, MOD - 2); }\n\tmi& operator/=(const\
    \ mi& m) { return (*this) *= inv(m); }\n\tfriend mi operator+(mi a, const mi&\
    \ b) { return a += b; }\n\tfriend mi operator-(mi a, const mi& b) { return a -=\
    \ b; }\n\tfriend mi operator*(mi a, const mi& b) { return a *= b; }\n\tfriend\
    \ mi operator/(mi a, const mi& b) { return a /= b; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/modular-arithmetic/mod-int.hpp
  requiredBy:
  - library/contest/template-full.hpp
  - library/contest/template-full.cpp
  timestamp: '2021-08-16 13:47:16-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/codeforces/codeforces-1551F.test.cpp
  - verify/unit-test/unit-test-template-full.test.cpp
  - verify/unit-test/unit-test-hashing.test.cpp
  - verify/unit-test/unit-test-fraction.test.cpp
  - verify/unit-test/unit-test-big-integer.test.cpp
  - verify/unit-test/unit-test-gosper-hack.test.cpp
documentation_of: library/modular-arithmetic/mod-int.hpp
layout: document
redirect_from:
- /library/library/modular-arithmetic/mod-int.hpp
- /library/library/modular-arithmetic/mod-int.hpp.html
title: library/modular-arithmetic/mod-int.hpp
---