---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fast-fourier-transform.hpp
    title: library/polynomial/fast-fourier-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n\r\n\r\n// 5 is a root of both mods\r\ntemplate <int MOD, int\
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
    \ }\r\n};\r\n\r\nnamespace FFT {\r\n\r\ntemplate <class T> void fft(std::vector<T>&\
    \ A, bool inv = 0) {\r\n\tint n = (int)A.size();\r\n\tassert((T::mod - 1) % n\
    \ == 0);\r\n\tstd::vector<T> B(n);\r\n\tfor (int b = n / 2; b; b /= 2, A.swap(B))\
    \ {\r\n\t\tT w = pow(T::rt(), (T::mod - 1) / n * b);\r\n\t\tT m = 1;\r\n\t\tfor\
    \ (int i = 0; i < n; i += b * 2, m *= w)\r\n\t\t\tfor (int j = 0; j < b; j++)\
    \ {\r\n\t\t\t\tT u = A[i + j];\r\n\t\t\t\tT v = A[i + j + b] * m;\r\n\t\t\t\t\
    B[i / 2 + j] = u + v;\r\n\t\t\t\tB[i / 2 + j + n / 2] = u - v;\r\n\t\t\t}\r\n\t\
    }\r\n\tif (inv) {\r\n\t\tstd::reverse(1 + A.begin(), A.end());\r\n\t\tT z = T(1)\
    \ / T(n);\r\n\t\tfor (auto& t : A) \r\n\t\t\tt *= z;\r\n\t}\r\n}\r\n\r\ntemplate\
    \ <class T> std::vector<T> multiply(std::vector<T> A, std::vector<T> B) {\r\n\t\
    int sa = (int)A.size();\r\n\tint sb = (int)B.size();\r\n\tif (!std::min(sa, sb))\r\
    \n\t\treturn {};\r\n\tint s = sa + sb - 1;\r\n\tint n = 1;\r\n\tfor (; n < s;\
    \ n *= 2);\r\n\tbool eq = A == B;\r\n\tA.resize(n);\r\n\tfft(A);\r\n\tif (eq)\
    \ \r\n\t\tB = A;\r\n\telse \r\n\t\tB.resize(n), fft(B);\r\n\tfor (int i = 0; i\
    \ < n; i++)\r\n\t\tA[i] *= B[i];\r\n\tfft(A, 1);\r\n\tA.resize(s);\r\n\treturn\
    \ A;\r\n}\r\n\r\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\r\n\tauto convert = [](const std::vector<T>& v) {\r\n\
    \t\tstd::vector<M> w((int)v.size());\r\n\t\tfor (int i =  0; i < (int)v.size();\
    \ i++)\r\n\t\t\tw[i] = (int)v[i];\r\n\t\treturn w;\r\n\t};\r\n\treturn multiply(convert(x),\
    \ convert(y));\r\n}\r\n\r\ntemplate <class T> std::vector<T> general_multiply(const\
    \ std::vector<T>& A, const std::vector<T>& B) { \r\n\t// arbitrary modulus\r\n\
    \tusing m0 = Mint<(119 << 23) + 1, 62>; \r\n\tusing m1 = Mint<(5 << 25) + 1, 62>;\r\
    \n\tusing m2 = Mint<(7 << 26) + 1, 62>;\r\n\tauto c0 = multiply_mod<m0>(A, B);\r\
    \n\tauto c1 = multiply_mod<m1>(A, B);\r\n\tauto c2 = multiply_mod<m2>(A, B);\r\
    \n\tint n = (int)c0.size();\r\n\tstd::vector<T> res(n);\r\n\tm1 r01 = 1 / m1(m0::mod);\r\
    \n\tm2 r02 = 1 / m2(m0::mod);\r\n\tm2 r12 = 1 / m2(m1::mod);\r\n\tfor (int i =\
    \ 0; i < n; i++) {\r\n\t\tint a = c0[i].v;\r\n\t\tint b = ((c1[i] - a) * r01).v;\r\
    \n\t\tint c = (((c2[i] - a) * r02 - b) * r12).v;\r\n\t\tres[i] = (T(c) * m1::mod\
    \ + b) * m0::mod + a;\r\n\t}\r\n\treturn res;\r\n}\r\n\r\n} // namespace FFT\n\
    \r\nnamespace Polynomial {\r\n\r\nusing T = long long;\r\nusing Poly = std::vector<T>;\r\
    \n\r\nT eval(const Poly& p, const T& x) {\r\n\tT res = 0;\r\n\tfor (int i = (int)p.size()\
    \ - 1; i >= 0; --i) {\r\n\t\tres = x * res + p[i];\r\n\t}\r\n\treturn res;\r\n\
    }\r\n\r\nPoly& operator+=(Poly& l, const Poly& r) {\r\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\r\n\tfor (int i = 0; i < (int)r.size(); ++i) {\r\n\t\tl[i]\
    \ += r[i];\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly& operator-=(Poly& l, const Poly&\
    \ r) {\r\n\tl.resize(std::max((int)l.size(), (int)r.size()));\r\n\tfor (int i\
    \ = 0; i < (int)r.size(); ++i) {\r\n\t\tl[i] -= r[i];\r\n\t}\r\n\treturn l;\r\n\
    }\r\n\r\nPoly& operator*=(Poly& l, const T& r) {\r\n\tfor (int i = 0; i < (int)l.size();\
    \ ++i) {\r\n\t\tl[i] *= r;\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly& operator/=(Poly&\
    \ l, const T& r) {\r\n\tfor (int i = 0; i < (int)l.size(); ++i) {\r\n\t\tl[i]\
    \ /= r;\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly operator*(const Poly& l, const\
    \ Poly& r) {\r\n\tif (!std::min((int)l.size(), (int)r.size())) {\r\n\t\treturn\
    \ {};\r\n\t}\r\n\treturn FFT::general_multiply(l, r);\r\n\tPoly res((int)l.size()\
    \ + (int)r.size() - 1);\r\n\tfor (int i = 0; i < (int)l.size(); ++i) {\r\n\t\t\
    for (int j = 0; j < (int)r.size(); ++j) {\r\n\t\t\tres[i + j] += l[i] * r[j];\r\
    \n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\nPoly operator+(Poly l, const Poly&\
    \ r) { return l += r; }\r\nPoly operator-(Poly l, const Poly& r) { return l -=\
    \ r; }\r\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }\r\n\
    Poly operator*(Poly l, const T& r) { return l *= r; }\r\nPoly operator*(const\
    \ T& r, const Poly& l) { return l * r; }\r\nPoly operator/(Poly l, const T& r)\
    \ { return l /= r;\t}\r\nPoly& operator*=(Poly& l, const Poly& r) { return l =\
    \ l * r; }\r\n\r\nPoly derivative(const Poly& p) {\r\n\tPoly res;\r\n\tfor (int\
    \ i = 1; i < (int)p.size(); ++i) {\r\n\t\tres.push_back(T(i) * p[i]);\r\n\t}\r\
    \n\treturn res;\r\n}\r\n\r\nPoly integral(const Poly& p) {\r\n\tstatic Poly invs{0,\
    \ 1};\r\n\tfor (int i = invs.size(); i <= (int)p.size(); ++i ){\r\n\t\tinvs.push_back(1\
    \ / T(i));\r\n\t}\r\n\tPoly res((int)p.size() + 1);\r\n\tfor (int i = 0; i < (int)p.size();\
    \ ++i) {\r\n\t\tres[i + 1] = p[i] * invs[i + 1];\r\n\t}\r\n\treturn res;\r\n}\r\
    \n\r\n}\n"
  code: "#pragma once\r\n\r\n#include \"fast-fourier-transform.hpp\"\r\n\r\nnamespace\
    \ Polynomial {\r\n\r\nusing T = long long;\r\nusing Poly = std::vector<T>;\r\n\
    \r\nT eval(const Poly& p, const T& x) {\r\n\tT res = 0;\r\n\tfor (int i = (int)p.size()\
    \ - 1; i >= 0; --i) {\r\n\t\tres = x * res + p[i];\r\n\t}\r\n\treturn res;\r\n\
    }\r\n\r\nPoly& operator+=(Poly& l, const Poly& r) {\r\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\r\n\tfor (int i = 0; i < (int)r.size(); ++i) {\r\n\t\tl[i]\
    \ += r[i];\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly& operator-=(Poly& l, const Poly&\
    \ r) {\r\n\tl.resize(std::max((int)l.size(), (int)r.size()));\r\n\tfor (int i\
    \ = 0; i < (int)r.size(); ++i) {\r\n\t\tl[i] -= r[i];\r\n\t}\r\n\treturn l;\r\n\
    }\r\n\r\nPoly& operator*=(Poly& l, const T& r) {\r\n\tfor (int i = 0; i < (int)l.size();\
    \ ++i) {\r\n\t\tl[i] *= r;\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly& operator/=(Poly&\
    \ l, const T& r) {\r\n\tfor (int i = 0; i < (int)l.size(); ++i) {\r\n\t\tl[i]\
    \ /= r;\r\n\t}\r\n\treturn l;\r\n}\r\n\r\nPoly operator*(const Poly& l, const\
    \ Poly& r) {\r\n\tif (!std::min((int)l.size(), (int)r.size())) {\r\n\t\treturn\
    \ {};\r\n\t}\r\n\treturn FFT::general_multiply(l, r);\r\n\tPoly res((int)l.size()\
    \ + (int)r.size() - 1);\r\n\tfor (int i = 0; i < (int)l.size(); ++i) {\r\n\t\t\
    for (int j = 0; j < (int)r.size(); ++j) {\r\n\t\t\tres[i + j] += l[i] * r[j];\r\
    \n\t\t}\r\n\t}\r\n\treturn res;\r\n}\r\n\r\nPoly operator+(Poly l, const Poly&\
    \ r) { return l += r; }\r\nPoly operator-(Poly l, const Poly& r) { return l -=\
    \ r; }\r\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }\r\n\
    Poly operator*(Poly l, const T& r) { return l *= r; }\r\nPoly operator*(const\
    \ T& r, const Poly& l) { return l * r; }\r\nPoly operator/(Poly l, const T& r)\
    \ { return l /= r;\t}\r\nPoly& operator*=(Poly& l, const Poly& r) { return l =\
    \ l * r; }\r\n\r\nPoly derivative(const Poly& p) {\r\n\tPoly res;\r\n\tfor (int\
    \ i = 1; i < (int)p.size(); ++i) {\r\n\t\tres.push_back(T(i) * p[i]);\r\n\t}\r\
    \n\treturn res;\r\n}\r\n\r\nPoly integral(const Poly& p) {\r\n\tstatic Poly invs{0,\
    \ 1};\r\n\tfor (int i = invs.size(); i <= (int)p.size(); ++i ){\r\n\t\tinvs.push_back(1\
    \ / T(i));\r\n\t}\r\n\tPoly res((int)p.size() + 1);\r\n\tfor (int i = 0; i < (int)p.size();\
    \ ++i) {\r\n\t\tres[i + 1] = p[i] * invs[i + 1];\r\n\t}\r\n\treturn res;\r\n}\r\
    \n\r\n}"
  dependsOn:
  - library/polynomial/fast-fourier-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: false
  path: library/polynomial/polynomial2.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
documentation_of: library/polynomial/polynomial2.hpp
layout: document
redirect_from:
- /library/library/polynomial/polynomial2.hpp
- /library/library/polynomial/polynomial2.hpp.html
title: library/polynomial/polynomial2.hpp
---
