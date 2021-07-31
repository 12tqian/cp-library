---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fast-fourier-transform.hpp
    title: library/polynomial/fast-fourier-transform.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/polynomial2.hpp
    title: library/polynomial/polynomial2.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-869E-general-fwt.test.cpp
    title: verify/codeforces/codeforces-869E-general-fwt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-869E-quadtree.test.cpp
    title: verify/codeforces/codeforces-869E-quadtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-981G.test.cpp
    title: verify/codeforces/codeforces-981G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
    title: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
    title: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-inverse_matrix.test.cpp
    title: verify/yosupo/yosupo-inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
    title: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
    title: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct Mint\
    \ {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint rt() { return RT;\
    \ } // primitive root for FFT\n\tint v; \n\texplicit operator int() const { return\
    \ v; } // explicit -> don't silently convert to int\n\texplicit operator bool()\
    \ const { return v != 0; }\n\tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD\
    \ <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const\
    \ Mint &a, const Mint &b) { return a.v == b.v; }\n\tfriend bool operator!=(const\
    \ Mint &a, const Mint &b) { return !(a == b); }\n\tfriend bool operator<(const\
    \ Mint &a, const Mint &b) { return a.v < b.v; }\n\tfriend bool operator>(const\
    \ Mint &a, const Mint &b) { return a.v > b.v; }\n\tfriend bool operator<=(const\
    \ Mint &a, const Mint &b) { return a.v <= b.v; }\n\tfriend bool operator>=(const\
    \ Mint &a, const Mint &b) { return a.v >= b.v; }\n\tfriend std::istream& operator\
    \ >> (std::istream &in, Mint &a) { \n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\n\tfriend std::ostream& operator << (std::ostream &os, const Mint\
    \ &a) { return os << a.v; }\n\tMint& operator+=(const Mint &m) { \n\t\tif ((v\
    \ += m.v) >= MOD) v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint\
    \ &m) { \n\t\tif ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
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
  code: "#pragma once\n\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct\
    \ Mint {\n\tstatic const int mod = MOD;\n\tstatic constexpr Mint rt() { return\
    \ RT; } // primitive root for FFT\n\tint v; \n\texplicit operator int() const\
    \ { return v; } // explicit -> don't silently convert to int\n\texplicit operator\
    \ bool() const { return v != 0; }\n\tMint() { v = 0; }\n\tMint(long long _v) {\
    \ v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\t\
    friend bool operator==(const Mint &a, const Mint &b) { return a.v == b.v; }\n\t\
    friend bool operator!=(const Mint &a, const Mint &b) { return !(a == b); }\n\t\
    friend bool operator<(const Mint &a, const Mint &b) { return a.v < b.v; }\n\t\
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
  dependsOn: []
  isVerificationFile: false
  path: library/modular-arithmetic/mod-int2.hpp
  requiredBy:
  - library/polynomial/polynomial2.hpp
  - library/polynomial/fast-fourier-transform.hpp
  timestamp: '2021-07-30 23:56:29-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
  - verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
  - verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-multipoint_evaluation.test.cpp
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-range_affine_range_sum.test.cpp
  - verify/yosupo/yosupo-inverse_matrix.test.cpp
  - verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - verify/codeforces/codeforces-981G.test.cpp
  - verify/codeforces/codeforces-869E-general-fwt.test.cpp
  - verify/codeforces/codeforces-869E-quadtree.test.cpp
documentation_of: library/modular-arithmetic/mod-int2.hpp
layout: document
redirect_from:
- /library/library/modular-arithmetic/mod-int2.hpp
- /library/library/modular-arithmetic/mod-int2.hpp.html
title: library/modular-arithmetic/mod-int2.hpp
---
