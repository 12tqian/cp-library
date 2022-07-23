---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/modular-arithmetic/mod-int2.hpp
    title: library/modular-arithmetic/mod-int2.hpp
  - icon: ':heavy_check_mark:'
    path: library/set-function/walsh-hadamard-transform.hpp
    title: library/set-function/walsh-hadamard-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n\r\ntemplate <class T> \r\nvoid walsh_hadamard_transformation(std::vector<T>&\
    \ f, bool inverse = false) {\r\n\tint n = (int)f.size();\r\n\tfor (int i = 1;\
    \ i < n; i <<= 1) {\r\n\t\tfor (int j = 0; j < n; ++j) {\r\n\t\t\tif ((j & i)\
    \ == 0) {\r\n\t\t\t\tT x = f[j], y = f[j | i];\r\n\t\t\t\tf[j] = x + y;\r\n\t\t\
    \t\tf[j | i] = x - y;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n\tif (inverse) {\r\n\t\tif\
    \ constexpr(std::is_integral<T>::value) {\r\n\t\t\tfor (auto& x : f) x /= n;\r\
    \n\t\t} else {\r\n\t\t\tT divide = T(1) / T(f.size());\r\n\t\t\tfor (auto& x :\
    \ f) x *= divide;\r\n\t\t}\r\n\t}\r\n}\n\r\n// 5 is a root of both mods\r\ntemplate\
    \ <int MOD, int RT> struct Mint {\r\n\tstatic const int mod = MOD;\r\n\tstatic\
    \ constexpr Mint rt() { return RT; } // primitive root for FFT\r\n\tstatic constexpr\
    \ int md() { return MOD; } // primitive root for FFT\r\n\tint v; \r\n\texplicit\
    \ operator int() const { return v; } // explicit -> don't silently convert to\
    \ int\r\n\texplicit operator bool() const { return v != 0; }\r\n\tMint() { v =\
    \ 0; }\r\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v %\
    \ MOD); if (v < 0) v += MOD; }\r\n\tfriend bool operator==(const Mint& a, const\
    \ Mint& b) { return a.v == b.v; }\r\n\tfriend bool operator!=(const Mint& a, const\
    \ Mint& b) { return !(a == b); }\r\n\tfriend bool operator<(const Mint& a, const\
    \ Mint& b) { return a.v < b.v; }\r\n\tfriend bool operator>(const Mint& a, const\
    \ Mint& b) { return a.v > b.v; }\r\n\tfriend bool operator<=(const Mint& a, const\
    \ Mint& b) { return a.v <= b.v; }\r\n\tfriend bool operator>=(const Mint& a, const\
    \ Mint& b) { return a.v >= b.v; }\r\n\tfriend std::istream& operator >> (std::istream&\
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
    \ }\r\n};\r\n\r\nusing mi = Mint<998244353, 5>;\r\n\r\nusing namespace std;\r\n\
    \r\nint main() {\r\n\tios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\t\
    int n;\r\n\tcin >> n;\r\n\tvector<mi> a(1 << n);\r\n\tvector<mi> b(1 << n);\r\n\
    \tfor (int i = 0; i < 1 << n; ++i) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tfor (int\
    \ i = 0; i < 1 << n; ++i) {\r\n\t\tcin >> b[i];\r\n\t}\r\n\twalsh_hadamard_transformation(a);\r\
    \n\twalsh_hadamard_transformation(b);\r\n\tvector<mi> c(1 << n);\r\n\tfor (int\
    \ i = 0; i < 1 << n; ++i) {\r\n\t\tc[i] = a[i] * b[i];\r\n\t}\r\n\twalsh_hadamard_transformation(c,\
    \ true);\r\n\tfor (int i = 0; i < 1 << n; ++i) {\r\n\t\tcout << c[i] << ' ';\r\
    \n\t}\r\n\tcout << '\\n';\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \r\n\r\n#include <bits/stdc++.h>\r\n#include <vector>\r\n#include \"../../library/set-function/walsh-hadamard-transform.hpp\"\
    \r\n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\r\n\r\nusing mi\
    \ = Mint<998244353, 5>;\r\n\r\nusing namespace std;\r\n\r\nint main() {\r\n\t\
    ios::sync_with_stdio(false);\r\n\tcin.tie(nullptr);\r\n\tint n;\r\n\tcin >> n;\r\
    \n\tvector<mi> a(1 << n);\r\n\tvector<mi> b(1 << n);\r\n\tfor (int i = 0; i <\
    \ 1 << n; ++i) {\r\n\t\tcin >> a[i];\r\n\t}\r\n\tfor (int i = 0; i < 1 << n; ++i)\
    \ {\r\n\t\tcin >> b[i];\r\n\t}\r\n\twalsh_hadamard_transformation(a);\r\n\twalsh_hadamard_transformation(b);\r\
    \n\tvector<mi> c(1 << n);\r\n\tfor (int i = 0; i < 1 << n; ++i) {\r\n\t\tc[i]\
    \ = a[i] * b[i];\r\n\t}\r\n\twalsh_hadamard_transformation(c, true);\r\n\tfor\
    \ (int i = 0; i < 1 << n; ++i) {\r\n\t\tcout << c[i] << ' ';\r\n\t}\r\n\tcout\
    \ << '\\n';\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/set-function/walsh-hadamard-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
- /verify/verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp.html
title: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
---
