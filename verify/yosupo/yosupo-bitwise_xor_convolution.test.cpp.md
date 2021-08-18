---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \n\n#include <bits/stdc++.h>\n\ntemplate <class T> \nvoid walsh_hadamard_transformation(std::vector<T>&\
    \ f, bool inverse = false) {\n\tint n = (int)f.size();\n\tfor (int i = 1; i <\
    \ n; i <<= 1) {\n\t\tfor (int j = 0; j < n; ++j) {\n\t\t\tif ((j & i) == 0) {\n\
    \t\t\t\tT x = f[j], y = f[j | i];\n\t\t\t\tf[j] = x + y;\n\t\t\t\tf[j | i] = x\
    \ - y;\n\t\t\t}\n\t\t}\n\t}\n\tif (inverse) {\n\t\tif constexpr(std::is_integral<T>::value)\
    \ {\n\t\t\tfor (auto& x : f) x /= n;\n\t\t} else {\n\t\t\tT divide = T(1) / T(f.size());\n\
    \t\t\tfor (auto& x : f) x *= divide;\n\t\t}\n\t}\n}\n\n// 5 is a root of both\
    \ mods\ntemplate <int MOD, int RT> struct Mint {\n\tstatic const int mod = MOD;\n\
    \tstatic constexpr Mint rt() { return RT; } // primitive root for FFT\n\tstatic\
    \ constexpr int md() { return MOD; } // primitive root for FFT\n\tint v; \n\t\
    explicit operator int() const { return v; } // explicit -> don't silently convert\
    \ to int\n\texplicit operator bool() const { return v != 0; }\n\tMint() { v =\
    \ 0; }\n\tMint(long long _v) { v = int((-MOD <= _v && _v < MOD) ? _v : _v % MOD);\
    \ if (v < 0) v += MOD; }\n\tfriend bool operator==(const Mint& a, const Mint&\
    \ b) { return a.v == b.v; }\n\tfriend bool operator!=(const Mint& a, const Mint&\
    \ b) { return !(a == b); }\n\tfriend bool operator<(const Mint& a, const Mint&\
    \ b) { return a.v < b.v; }\n\tfriend bool operator>(const Mint& a, const Mint&\
    \ b) { return a.v > b.v; }\n\tfriend bool operator<=(const Mint& a, const Mint&\
    \ b) { return a.v <= b.v; }\n\tfriend bool operator>=(const Mint& a, const Mint&\
    \ b) { return a.v >= b.v; }\n\tfriend std::istream& operator >> (std::istream&\
    \ in, Mint& a) { \n\t\tlong long x; std::cin >> x; a = Mint(x); return in; }\n\
    \tfriend std::ostream& operator << (std::ostream& os, const Mint& a) { return\
    \ os << a.v; }\n\tMint& operator+=(const Mint& m) { \n\t\tif ((v += m.v) >= MOD)\
    \ v -= MOD; \n\t\treturn *this; }\n\tMint& operator-=(const Mint& m) { \n\t\t\
    if ((v -= m.v) < 0) v += MOD; \n\t\treturn *this; }\n\tMint& operator*=(const\
    \ Mint& m) { \n\t\tv = (long long)v * m.v % MOD; return *this; }\n\tMint& operator/=(const\
    \ Mint& m) { return (*this) *= inv(m); }\n\tfriend Mint pow(Mint a, long long\
    \ p) {\n\t\tMint ans = 1; assert(p >= 0);\n\t\tfor (; p; p /= 2, a *= a) if (p\
    \ & 1) ans *= a;\n\t\treturn ans; \n\t}\n\tfriend Mint inv(const Mint& a) { assert(a.v\
    \ != 0); return pow(a, MOD - 2); }\n\tMint operator-() const { return Mint(-v);\
    \ }\n\tMint& operator++() { return *this += 1; }\n\tMint& operator--() { return\
    \ *this -= 1; }\n\tfriend Mint operator+(Mint a, const Mint& b) { return a +=\
    \ b; }\n\tfriend Mint operator-(Mint a, const Mint& b) { return a -= b; }\n\t\
    friend Mint operator*(Mint a, const Mint& b) { return a *= b; }\n\tfriend Mint\
    \ operator/(Mint a, const Mint& b) { return a /= b; }\n};\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nusing namespace std;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\tvector<mi> a(1 << n);\n\tvector<mi>\
    \ b(1 << n);\n\tfor (int i = 0; i < 1 << n; ++i) {\n\t\tcin >> a[i];\n\t}\n\t\
    for (int i = 0; i < 1 << n; ++i) {\n\t\tcin >> b[i];\n\t}\n\twalsh_hadamard_transformation(a);\n\
    \twalsh_hadamard_transformation(b);\n\tvector<mi> c(1 << n);\n\tfor (int i = 0;\
    \ i < 1 << n; ++i) {\n\t\tc[i] = a[i] * b[i];\n\t}\n\twalsh_hadamard_transformation(c,\
    \ true);\n\tfor (int i = 0; i < 1 << n; ++i) {\n\t\tcout << c[i] << ' ';\n\t}\n\
    \tcout << '\\n';\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include <bits/stdc++.h>\n#include <vector>\n#include \"../../library/set-function/walsh-hadamard-transform.hpp\"\
    \n#include \"../../library/modular-arithmetic/mod-int2.hpp\"\n\nusing mi = Mint<998244353,\
    \ 5>;\n\nusing namespace std;\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n;\n\tcin >> n;\n\tvector<mi> a(1 << n);\n\tvector<mi>\
    \ b(1 << n);\n\tfor (int i = 0; i < 1 << n; ++i) {\n\t\tcin >> a[i];\n\t}\n\t\
    for (int i = 0; i < 1 << n; ++i) {\n\t\tcin >> b[i];\n\t}\n\twalsh_hadamard_transformation(a);\n\
    \twalsh_hadamard_transformation(b);\n\tvector<mi> c(1 << n);\n\tfor (int i = 0;\
    \ i < 1 << n; ++i) {\n\t\tc[i] = a[i] * b[i];\n\t}\n\twalsh_hadamard_transformation(c,\
    \ true);\n\tfor (int i = 0; i < 1 << n; ++i) {\n\t\tcout << c[i] << ' ';\n\t}\n\
    \tcout << '\\n';\n\treturn 0;\n}"
  dependsOn:
  - library/set-function/walsh-hadamard-transform.hpp
  - library/modular-arithmetic/mod-int2.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-08-15 17:58:43-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
- /verify/verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp.html
title: verify/yosupo/yosupo-bitwise_xor_convolution.test.cpp
---
