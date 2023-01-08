---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':heavy_check_mark:'
    path: library/polynomial/fast-fourier-transform.hpp
    title: library/polynomial/fast-fourier-transform.hpp
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
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n\r\n// 5 is a root of both\
    \ mods\r\ntemplate <int MOD, int RT> struct Mint {\r\n\tstatic const int mod =\
    \ MOD;\r\n\tstatic constexpr Mint rt() { return RT; } // primitive root for FFT\r\
    \n\tstatic constexpr int md() { return MOD; } // primitive root for FFT\r\n\t\
    int v; \r\n\texplicit operator int() const { return v; } // explicit -> don't\
    \ silently convert to int\r\n\texplicit operator bool() const { return v != 0;\
    \ }\r\n\tMint() { v = 0; }\r\n\tMint(long long _v) { v = int((-MOD <= _v && _v\
    \ < MOD) ? _v : _v % MOD); if (v < 0) v += MOD; }\r\n\tfriend bool operator==(const\
    \ Mint& a, const Mint& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const\
    \ Mint& a, const Mint& b) { return !(a == b); }\r\n\tfriend bool operator<(const\
    \ Mint& a, const Mint& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const\
    \ Mint& a, const Mint& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const\
    \ Mint& a, const Mint& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const\
    \ Mint& a, const Mint& b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator\
    \ >> (std::istream& in, Mint& a) { \r\n\t\tlong long x; std::cin >> x; a = Mint(x);\
    \ return in; }\r\n\tfriend std::ostream& operator << (std::ostream& os, const\
    \ Mint& a) { return os << a.v; }\r\n\tMint& operator+=(const Mint& m) { \r\n\t\
    \tif ((v += m.v) >= MOD) v -= MOD; \r\n\t\treturn *this; }\r\n\tMint& operator-=(const\
    \ Mint& m) { \r\n\t\tif ((v -= m.v) < 0) v += MOD; \r\n\t\treturn *this; }\r\n\
    \tMint& operator*=(const Mint& m) { \r\n\t\tv = (long long)v * m.v % MOD; return\
    \ *this; }\r\n\tMint& operator/=(const Mint& m) { return (*this) *= inv(m); }\r\
    \n\tfriend Mint pow(Mint a, long long p) {\r\n\t\tMint ans = 1; assert(p >= 0);\r\
    \n\t\tfor (; p; p /= 2, a *= a) if (p & 1) ans *= a;\r\n\t\treturn ans; \r\n\t\
    }\r\n\tfriend Mint inv(const Mint& a) { assert(a.v != 0); return pow(a, MOD -\
    \ 2); }\r\n\tMint operator-() const { return Mint(-v); }\r\n\tMint& operator++()\
    \ { return *this += 1; }\r\n\tMint& operator--() { return *this -= 1; }\r\n\t\
    friend Mint operator+(Mint a, const Mint& b) { return a += b; }\r\n\tfriend Mint\
    \ operator-(Mint a, const Mint& b) { return a -= b; }\r\n\tfriend Mint operator*(Mint\
    \ a, const Mint& b) { return a *= b; }\r\n\tfriend Mint operator/(Mint a, const\
    \ Mint& b) { return a /= b; }\r\n};\r\n\r\nnamespace FFT {\r\n\r\ntemplate <class\
    \ T> void fft(std::vector<T>& A, bool inv = 0) {\r\n\tint n = (int)A.size();\r\
    \n\tassert((T::mod - 1) % n == 0);\r\n\tstd::vector<T> B(n);\r\n\tfor (int b =\
    \ n / 2; b; b /= 2, A.swap(B)) {\r\n\t\tT w = pow(T::rt(), (T::mod - 1) / n *\
    \ b);\r\n\t\tT m = 1;\r\n\t\tfor (int i = 0; i < n; i += b * 2, m *= w)\r\n\t\t\
    \tfor (int j = 0; j < b; j++) {\r\n\t\t\t\tT u = A[i + j];\r\n\t\t\t\tT v = A[i\
    \ + j + b] * m;\r\n\t\t\t\tB[i / 2 + j] = u + v;\r\n\t\t\t\tB[i / 2 + j + n /\
    \ 2] = u - v;\r\n\t\t\t}\r\n\t}\r\n\tif (inv) {\r\n\t\tstd::reverse(1 + A.begin(),\
    \ A.end());\r\n\t\tT z = T(1) / T(n);\r\n\t\tfor (auto& t : A) \r\n\t\t\tt *=\
    \ z;\r\n\t}\r\n}\r\n\r\ntemplate <class T> std::vector<T> multiply(std::vector<T>\
    \ A, std::vector<T> B) {\r\n\tint sa = (int)A.size();\r\n\tint sb = (int)B.size();\r\
    \n\tif (!std::min(sa, sb))\r\n\t\treturn {};\r\n\tint s = sa + sb - 1;\r\n\tint\
    \ n = 1;\r\n\tfor (; n < s; n *= 2);\r\n\tbool eq = A == B;\r\n\tA.resize(n);\r\
    \n\tfft(A);\r\n\tif (eq) \r\n\t\tB = A;\r\n\telse \r\n\t\tB.resize(n), fft(B);\r\
    \n\tfor (int i = 0; i < n; i++)\r\n\t\tA[i] *= B[i];\r\n\tfft(A, 1);\r\n\tA.resize(s);\r\
    \n\treturn A;\r\n}\r\n\r\ntemplate <class M, class T> std::vector<M> multiply_mod(std::vector<T>\
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
    \r\nint main() {\r\n\tusing namespace std;\r\n\tusing namespace FFT;\r\n\tios_base::sync_with_stdio(0);\r\
    \n\tint n, m; \r\n\tcin >> n >> m;\r\n\tconst int MOD = 1e9 + 7;\r\n\tusing mi\
    \ = Mint<MOD, 5>;\r\n\tvector<mi> a(n), b(m);\r\n\tfor (int i = 0; i < n; i++)\r\
    \n\t\tcin >> a[i];\r\n\tfor (int i = 0; i < m; i++)\r\n\t\tcin >> b[i];\r\n\t\
    vector<mi> c = general_multiply(a, b);\r\n\tfor (int i = 0; i < (int)c.size();\
    \ i++)\r\n\t\tcout << c[i] << \" \";\r\n\tcout << '\\n';\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \r\n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"\
    ../../library/polynomial/fast-fourier-transform.hpp\"\r\n\r\nint main() {\r\n\t\
    using namespace std;\r\n\tusing namespace FFT;\r\n\tios_base::sync_with_stdio(0);\r\
    \n\tint n, m; \r\n\tcin >> n >> m;\r\n\tconst int MOD = 1e9 + 7;\r\n\tusing mi\
    \ = Mint<MOD, 5>;\r\n\tvector<mi> a(n), b(m);\r\n\tfor (int i = 0; i < n; i++)\r\
    \n\t\tcin >> a[i];\r\n\tfor (int i = 0; i < m; i++)\r\n\t\tcin >> b[i];\r\n\t\
    vector<mi> c = general_multiply(a, b);\r\n\tfor (int i = 0; i < (int)c.size();\
    \ i++)\r\n\t\tcout << c[i] << \" \";\r\n\tcout << '\\n';\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/polynomial/fast-fourier-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
- /verify/verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp.html
title: verify/yosupo/yosupo-convolution_mod_1000000007-fast-fourier-transform.test.cpp
---
