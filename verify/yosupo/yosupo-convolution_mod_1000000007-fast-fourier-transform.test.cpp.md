---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/numerical/fast-fourier-transform.hpp
    title: library/numerical/fast-fourier-transform.hpp
  - icon: ':question:'
    path: library/numerical/mod-int2.hpp
    title: library/numerical/mod-int2.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n\n// 5 is a root of both mods\ntemplate <int MOD, int RT> struct Mint {\n\t\
    static const int mod = MOD;\n\tstatic constexpr Mint rt() { return RT; } // primitive\
    \ root for FFT\n\tint v; \n\texplicit operator int() const { return v; } // explicit\
    \ -> don't silently convert to int\n\texplicit operator bool() const { return\
    \ v != 0; }\n\tMint() { v = 0; }\n\tMint(long long _v) { v = int((-MOD <= _v &&\
    \ _v < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\n\tfriend bool operator==(const\
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
    \ operator/(Mint a, const Mint &b) { return a /= b; }\n};\n\nnamespace FFT {\n\
    \ntemplate <class T> void fft(std::vector<T> &A, bool inv = 0) {\n\tint n = (int)A.size();\n\
    \tassert((T::mod - 1) % n == 0);\n\tstd::vector<T> B(n);\n\tfor (int b = n / 2;\
    \ b; b /= 2, A.swap(B)) {\n\t\tT w = pow(T::rt(), (T::mod - 1) / n * b);\n\t\t\
    T m = 1;\n\t\tfor (int i = 0; i < n; i += b * 2, m *= w)\n\t\t\tfor (int j = 0;\
    \ j < b; j++) {\n\t\t\t\tT u = A[i + j];\n\t\t\t\tT v = A[i + j + b] * m;\n\t\t\
    \t\tB[i / 2 + j] = u + v;\n\t\t\t\tB[i / 2 + j + n / 2] = u - v;\n\t\t\t}\n\t\
    }\n\tif (inv) {\n\t\tstd::reverse(1 + A.begin(), A.end());\n\t\tT z = T(1) / T(n);\n\
    \t\tfor (auto &t : A) \n\t\t\tt *= z;\n\t}\n}\n\ntemplate <class T> std::vector<T>\
    \ multiply(std::vector<T> A, std::vector<T> B) {\n\tint sa = (int)A.size();\n\t\
    int sb = (int)B.size();\n\tif (!std::min(sa, sb))\n\t\treturn {};\n\tint s = sa\
    \ + sb - 1;\n\tint n = 1;\n\tfor (; n < s; n *= 2);\n\tbool eq = A == B;\n\tA.resize(n);\n\
    \tfft(A);\n\tif (eq) \n\t\tB = A;\n\telse \n\t\tB.resize(n), fft(B);\n\tfor (int\
    \ i = 0; i < n; i++)\n\t\tA[i] *= B[i];\n\tfft(A, 1);\n\tA.resize(s);\n\treturn\
    \ A;\n}\n\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
    \ x, std::vector<T> y) {\n\tauto convert = [](const std::vector<T> &v) {\n\t\t\
    std::vector<M> w((int)v.size());\n\t\tfor (int i =  0; i < (int)v.size(); i++)\n\
    \t\t\tw[i] = (int) v[i];\n\t\treturn w;\n\t};\n\treturn multiply(convert(x), convert(y));\n\
    }\n\ntemplate <class T> std::vector<T> general_multiply(const std::vector<T> &A,\
    \ const std::vector<T> &B) { \n\t// arbitrary modulus\n\tusing m0 = Mint<(119\
    \ << 23) + 1, 62>; \n\tusing m1 = Mint<(5 << 25) + 1, 62>;\n\tusing m2 = Mint<(7\
    \ << 26) + 1, 62>;\n\tauto c0 = multiply_mod<m0>(A, B);\n\tauto c1 = multiply_mod<m1>(A,\
    \ B);\n\tauto c2 = multiply_mod<m2>(A, B);\n\tint n = (int)c0.size();\n\tstd::vector<T>\
    \ res(n);\n\tm1 r01 = 1 / m1(m0::mod);\n\tm2 r02 = 1 / m2(m0::mod);\n\tm2 r12\
    \ = 1 / m2(m1::mod);\n\tfor (int i = 0; i < n; i++) {\n\t\tint a = c0[i].v;\n\t\
    \tint b = ((c1[i] - a) * r01).v;\n\t\tint c = (((c2[i] - a) * r02 - b) * r12).v;\n\
    \t\tres[i] = (T(c) * m1::mod + b) * m0::mod + a;\n\t}\n\treturn res;\n}\n\n} //\
    \ namespace FFT\n\nint main() {\n\tusing namespace std;\n\tusing namespace FFT;\n\
    \tios_base::sync_with_stdio(0);\n\tint n, m; \n\tcin >> n >> m;\n\tconst int MOD\
    \ = 1e9 + 7;\n\tusing mi = Mint<MOD, 5>;\n\tvector<mi> a(n), b(m);\n\tfor (int\
    \ i = 0; i < n; i++)\n\t\tcin >> a[i];\n\tfor (int i = 0; i < m; i++)\n\t\tcin\
    \ >> b[i];\n\tvector<mi> c = general_multiply(a, b);\n\tfor (int i = 0; i < (int)c.size();\
    \ i++)\n\t\tcout << c[i] << \" \";\n\tcout << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/numerical/fast-fourier-transform.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tusing namespace FFT;\n\tios_base::sync_with_stdio(0);\n\
    \tint n, m; \n\tcin >> n >> m;\n\tconst int MOD = 1e9 + 7;\n\tusing mi = Mint<MOD,\
    \ 5>;\n\tvector<mi> a(n), b(m);\n\tfor (int i = 0; i < n; i++)\n\t\tcin >> a[i];\n\
    \tfor (int i = 0; i < m; i++)\n\t\tcin >> b[i];\n\tvector<mi> c = general_multiply(a,\
    \ b);\n\tfor (int i = 0; i < (int)c.size(); i++)\n\t\tcout << c[i] << \" \";\n\
    \tcout << '\\n';\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/numerical/fast-fourier-transform.hpp
  - library/numerical/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
  requiredBy: []
  timestamp: '2021-07-30 23:07:00-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp.html
title: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
---
