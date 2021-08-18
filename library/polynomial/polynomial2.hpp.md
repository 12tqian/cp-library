---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':question:'
    path: library/polynomial/fast-fourier-transform.hpp
    title: library/polynomial/fast-fourier-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
    title: verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\n\n\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct\
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
    \ operator/(Mint a, const Mint& b) { return a /= b; }\n};\n\nnamespace FFT {\n\
    \ntemplate <class T> void fft(std::vector<T>& A, bool inv = 0) {\n\tint n = (int)A.size();\n\
    \tassert((T::mod - 1) % n == 0);\n\tstd::vector<T> B(n);\n\tfor (int b = n / 2;\
    \ b; b /= 2, A.swap(B)) {\n\t\tT w = pow(T::rt(), (T::mod - 1) / n * b);\n\t\t\
    T m = 1;\n\t\tfor (int i = 0; i < n; i += b * 2, m *= w)\n\t\t\tfor (int j = 0;\
    \ j < b; j++) {\n\t\t\t\tT u = A[i + j];\n\t\t\t\tT v = A[i + j + b] * m;\n\t\t\
    \t\tB[i / 2 + j] = u + v;\n\t\t\t\tB[i / 2 + j + n / 2] = u - v;\n\t\t\t}\n\t\
    }\n\tif (inv) {\n\t\tstd::reverse(1 + A.begin(), A.end());\n\t\tT z = T(1) / T(n);\n\
    \t\tfor (auto& t : A) \n\t\t\tt *= z;\n\t}\n}\n\ntemplate <class T> std::vector<T>\
    \ multiply(std::vector<T> A, std::vector<T> B) {\n\tint sa = (int)A.size();\n\t\
    int sb = (int)B.size();\n\tif (!std::min(sa, sb))\n\t\treturn {};\n\tint s = sa\
    \ + sb - 1;\n\tint n = 1;\n\tfor (; n < s; n *= 2);\n\tbool eq = A == B;\n\tA.resize(n);\n\
    \tfft(A);\n\tif (eq) \n\t\tB = A;\n\telse \n\t\tB.resize(n), fft(B);\n\tfor (int\
    \ i = 0; i < n; i++)\n\t\tA[i] *= B[i];\n\tfft(A, 1);\n\tA.resize(s);\n\treturn\
    \ A;\n}\n\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\n\tauto convert = [](const std::vector<T>& v) {\n\t\t\
    std::vector<M> w((int)v.size());\n\t\tfor (int i =  0; i < (int)v.size(); i++)\n\
    \t\t\tw[i] = (int)v[i];\n\t\treturn w;\n\t};\n\treturn multiply(convert(x), convert(y));\n\
    }\n\ntemplate <class T> std::vector<T> general_multiply(const std::vector<T>&\
    \ A, const std::vector<T>& B) { \n\t// arbitrary modulus\n\tusing m0 = Mint<(119\
    \ << 23) + 1, 62>; \n\tusing m1 = Mint<(5 << 25) + 1, 62>;\n\tusing m2 = Mint<(7\
    \ << 26) + 1, 62>;\n\tauto c0 = multiply_mod<m0>(A, B);\n\tauto c1 = multiply_mod<m1>(A,\
    \ B);\n\tauto c2 = multiply_mod<m2>(A, B);\n\tint n = (int)c0.size();\n\tstd::vector<T>\
    \ res(n);\n\tm1 r01 = 1 / m1(m0::mod);\n\tm2 r02 = 1 / m2(m0::mod);\n\tm2 r12\
    \ = 1 / m2(m1::mod);\n\tfor (int i = 0; i < n; i++) {\n\t\tint a = c0[i].v;\n\t\
    \tint b = ((c1[i] - a) * r01).v;\n\t\tint c = (((c2[i] - a) * r02 - b) * r12).v;\n\
    \t\tres[i] = (T(c) * m1::mod + b) * m0::mod + a;\n\t}\n\treturn res;\n}\n\n} //\
    \ namespace FFT\n\nnamespace Polynomial {\n\nusing T = long long;\nusing Poly\
    \ = std::vector<T>;\n\nT eval(const Poly& p, const T& x) {\n\tT res = 0;\n\tfor\
    \ (int i = (int)p.size() - 1; i >= 0; --i) {\n\t\tres = x * res + p[i];\n\t}\n\
    \treturn res;\n}\n\nPoly& operator+=(Poly& l, const Poly& r) {\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\n\tfor (int i = 0; i < (int)r.size(); ++i) {\n\t\tl[i] += r[i];\n\
    \t}\n\treturn l;\n}\n\nPoly& operator-=(Poly& l, const Poly& r) {\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\n\tfor (int i = 0; i < (int)r.size(); ++i) {\n\t\tl[i] -= r[i];\n\
    \t}\n\treturn l;\n}\n\nPoly& operator*=(Poly& l, const T& r) {\n\tfor (int i =\
    \ 0; i < (int)l.size(); ++i) {\n\t\tl[i] *= r;\n\t}\n\treturn l;\n}\n\nPoly& operator/=(Poly&\
    \ l, const T& r) {\n\tfor (int i = 0; i < (int)l.size(); ++i) {\n\t\tl[i] /= r;\n\
    \t}\n\treturn l;\n}\n\nPoly operator*(const Poly& l, const Poly& r) {\n\tif (!std::min((int)l.size(),\
    \ (int)r.size())) {\n\t\treturn {};\n\t}\n\treturn FFT::general_multiply(l, r);\n\
    \tPoly res((int)l.size() + (int)r.size() - 1);\n\tfor (int i = 0; i < (int)l.size();\
    \ ++i) {\n\t\tfor (int j = 0; j < (int)r.size(); ++j) {\n\t\t\tres[i + j] += l[i]\
    \ * r[j];\n\t\t}\n\t}\n\treturn res;\n}\n\nPoly operator+(Poly l, const Poly&\
    \ r) { return l += r; }\nPoly operator-(Poly l, const Poly& r) { return l -= r;\
    \ }\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }\nPoly operator*(Poly\
    \ l, const T& r) { return l *= r; }\nPoly operator*(const T& r, const Poly& l)\
    \ { return l * r; }\nPoly operator/(Poly l, const T& r) { return l /= r;\t}\n\
    Poly& operator*=(Poly& l, const Poly& r) { return l = l * r; }\n\nPoly derivative(const\
    \ Poly& p) {\n\tPoly res;\n\tfor (int i = 1; i < (int)p.size(); ++i) {\n\t\tres.push_back(T(i)\
    \ * p[i]);\n\t}\n\treturn res;\n}\n\nPoly integral(const Poly& p) {\n\tstatic\
    \ Poly invs{0, 1};\n\tfor (int i = invs.size(); i <= (int)p.size(); ++i ){\n\t\
    \tinvs.push_back(1 / T(i));\n\t}\n\tPoly res((int)p.size() + 1);\n\tfor (int i\
    \ = 0; i < (int)p.size(); ++i) {\n\t\tres[i + 1] = p[i] * invs[i + 1];\n\t}\n\t\
    return res;\n}\n\n}\n"
  code: "#pragma once\n\n#include \"fast-fourier-transform.hpp\"\n\nnamespace Polynomial\
    \ {\n\nusing T = long long;\nusing Poly = std::vector<T>;\n\nT eval(const Poly&\
    \ p, const T& x) {\n\tT res = 0;\n\tfor (int i = (int)p.size() - 1; i >= 0; --i)\
    \ {\n\t\tres = x * res + p[i];\n\t}\n\treturn res;\n}\n\nPoly& operator+=(Poly&\
    \ l, const Poly& r) {\n\tl.resize(std::max((int)l.size(), (int)r.size()));\n\t\
    for (int i = 0; i < (int)r.size(); ++i) {\n\t\tl[i] += r[i];\n\t}\n\treturn l;\n\
    }\n\nPoly& operator-=(Poly& l, const Poly& r) {\n\tl.resize(std::max((int)l.size(),\
    \ (int)r.size()));\n\tfor (int i = 0; i < (int)r.size(); ++i) {\n\t\tl[i] -= r[i];\n\
    \t}\n\treturn l;\n}\n\nPoly& operator*=(Poly& l, const T& r) {\n\tfor (int i =\
    \ 0; i < (int)l.size(); ++i) {\n\t\tl[i] *= r;\n\t}\n\treturn l;\n}\n\nPoly& operator/=(Poly&\
    \ l, const T& r) {\n\tfor (int i = 0; i < (int)l.size(); ++i) {\n\t\tl[i] /= r;\n\
    \t}\n\treturn l;\n}\n\nPoly operator*(const Poly& l, const Poly& r) {\n\tif (!std::min((int)l.size(),\
    \ (int)r.size())) {\n\t\treturn {};\n\t}\n\treturn FFT::general_multiply(l, r);\n\
    \tPoly res((int)l.size() + (int)r.size() - 1);\n\tfor (int i = 0; i < (int)l.size();\
    \ ++i) {\n\t\tfor (int j = 0; j < (int)r.size(); ++j) {\n\t\t\tres[i + j] += l[i]\
    \ * r[j];\n\t\t}\n\t}\n\treturn res;\n}\n\nPoly operator+(Poly l, const Poly&\
    \ r) { return l += r; }\nPoly operator-(Poly l, const Poly& r) { return l -= r;\
    \ }\nPoly operator-(Poly l) { for (auto &t : l) t *= -1; return l; }\nPoly operator*(Poly\
    \ l, const T& r) { return l *= r; }\nPoly operator*(const T& r, const Poly& l)\
    \ { return l * r; }\nPoly operator/(Poly l, const T& r) { return l /= r;\t}\n\
    Poly& operator*=(Poly& l, const Poly& r) { return l = l * r; }\n\nPoly derivative(const\
    \ Poly& p) {\n\tPoly res;\n\tfor (int i = 1; i < (int)p.size(); ++i) {\n\t\tres.push_back(T(i)\
    \ * p[i]);\n\t}\n\treturn res;\n}\n\nPoly integral(const Poly& p) {\n\tstatic\
    \ Poly invs{0, 1};\n\tfor (int i = invs.size(); i <= (int)p.size(); ++i ){\n\t\
    \tinvs.push_back(1 / T(i));\n\t}\n\tPoly res((int)p.size() + 1);\n\tfor (int i\
    \ = 0; i < (int)p.size(); ++i) {\n\t\tres[i + 1] = p[i] * invs[i + 1];\n\t}\n\t\
    return res;\n}\n\n}"
  dependsOn:
  - library/polynomial/fast-fourier-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: false
  path: library/polynomial/polynomial2.hpp
  requiredBy: []
  timestamp: '2021-08-18 19:17:11-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-frequency_table_of_tree_distance.test.cpp
documentation_of: library/polynomial/polynomial2.hpp
layout: document
redirect_from:
- /library/library/polynomial/polynomial2.hpp
- /library/library/polynomial/polynomial2.hpp.html
title: library/polynomial/polynomial2.hpp
---
