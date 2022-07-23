---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/polynomial/fast-fourier-transform.hpp
    title: library/polynomial/fast-fourier-transform.hpp
  - icon: ':x:'
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
    path: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
    title: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
    title: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
    title: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-division_of_polynomials.test.cpp
    title: verify/yosupo/yosupo-division_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-find_linear_recurrence.test.cpp
    title: verify/yosupo/yosupo-find_linear_recurrence.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-inverse_matrix.test.cpp
    title: verify/yosupo/yosupo-inverse_matrix.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
    title: verify/yosupo/yosupo-multipoint_evaluation.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
    title: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
    title: verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
    title: verify/yosupo/yosupo-system_of_linear_equations.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\r\n// 5 is a root of both mods\r\ntemplate <int MOD, int RT> struct\
    \ Mint {\r\n\tstatic const int mod = MOD;\r\n\tstatic constexpr Mint rt() { return\
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
    \ }\r\n};\r\n"
  code: "#pragma once\r\n\r\n// 5 is a root of both mods\r\ntemplate <int MOD, int\
    \ RT> struct Mint {\r\n\tstatic const int mod = MOD;\r\n\tstatic constexpr Mint\
    \ rt() { return RT; } // primitive root for FFT\r\n\tstatic constexpr int md()\
    \ { return MOD; } // primitive root for FFT\r\n\tint v; \r\n\texplicit operator\
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
    \ }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/modular-arithmetic/mod-int2.hpp
  requiredBy:
  - library/polynomial/polynomial2.hpp
  - library/polynomial/fast-fourier-transform.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/codeforces/codeforces-869E-general-fwt.test.cpp
  - verify/codeforces/codeforces-869E-quadtree.test.cpp
  - verify/codeforces/codeforces-981G.test.cpp
  - verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
  - verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - verify/yosupo/yosupo-log_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  - verify/yosupo/yosupo-inverse_matrix.test.cpp
  - verify/yosupo/yosupo-division_of_polynomials.test.cpp
  - verify/yosupo/yosupo-system_of_linear_equations.test.cpp
  - verify/yosupo/yosupo-multipoint_evaluation.test.cpp
  - verify/yosupo/yosupo-sqrt_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-range_affine_range_sum.test.cpp
  - verify/yosupo/yosupo-inv_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-exp_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-pow_of_formal_power_series.test.cpp
  - verify/yosupo/yosupo-find_linear_recurrence.test.cpp
  - verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
  - verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
documentation_of: library/modular-arithmetic/mod-int2.hpp
layout: document
redirect_from:
- /library/library/modular-arithmetic/mod-int2.hpp
- /library/library/modular-arithmetic/mod-int2.hpp.html
title: library/modular-arithmetic/mod-int2.hpp
---
