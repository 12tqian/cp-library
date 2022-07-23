---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
    title: verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nnamespace Karatsuba {\r\n\r\nint size(int s) {\r\n\treturn s >\
    \ 1 ? 32 - __builtin_clz(s - 1) : 0;\r\n}\r\n\r\ntemplate <class T> void karatsuba(T*\
    \ a, T* b, T* c, T* t, int n) {\r\n\tint ca = 0, cb = 0;\r\n\tfor (int i = 0;\
    \ i < n; i++)\r\n\t\tca += (a[i] != 0), cb += (b[i] != 0);\r\n\tif (std::min(ca,\
    \ cb) <= 1500 / n) { // not many multiplications\r\n\t\tif (ca > cb) \r\n\t\t\t\
    std::swap(ca, cb);\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\tif (a[i] != 0)\r\
    \n\t\t\t\tfor (int j = 0; j < n; j++)\r\n\t\t\t\t\tc[i + j] += a[i] * b[j];\r\n\
    \r\n\t} else {\r\n\t\tint h = n >> 1;\r\n\t\tkaratsuba(a, b, c, t, h); // a0 *\
    \ b0\r\n\t\tkaratsuba(a + h, b + h, c + n, t, h); // a1 * b1\r\n\t\tfor (int i\
    \ = 0; i < h; i++)\r\n\t\t\ta[i] += a[i + h], b[i] += b[i + h];\r\n\t\tkaratsuba(a,\
    \ b, t, t + n, h); // (a0 + a1) * (b0 + b1)\r\n\t\tfor (int i = 0; i < h; i++)\r\
    \n\t\t\ta[i] -= a[i + h], b[i] -= b[i + h];\r\n\t\tfor (int i = 0; i < n; i++)\r\
    \n\t\t\tt[i] -= c[i] + c[i + n];\r\n\t\tfor (int i = 0; i < n; i++)\r\n\t\t\t\
    c[i + h] += t[i], t[i] = 0;\r\n\t}\r\n}\r\n\r\ntemplate <class T> std::vector<T>\
    \ convolution(std::vector<T> a, std::vector<T> b) {\r\n\tint sa = (int)a.size(),\
    \ sb = (int)b.size();\r\n\tif (!sa || !sb) \r\n\t\treturn {};\r\n\tint n = (1\
    \ << size(std::max(sa, sb)));\r\n\ta.resize(n);\r\n\tb.resize(n);\r\n\tstd::vector<T>\
    \ c(2 * n), t(2 * n);\r\n\tkaratsuba(&a[0], &b[0], &c[0], &t[0], n);\r\n\tc.resize(sa\
    \ + sb - 1);\r\n\treturn c;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\nnamespace Karatsuba {\r\n\r\nint size(int s) {\r\n\t\
    return s > 1 ? 32 - __builtin_clz(s - 1) : 0;\r\n}\r\n\r\ntemplate <class T> void\
    \ karatsuba(T* a, T* b, T* c, T* t, int n) {\r\n\tint ca = 0, cb = 0;\r\n\tfor\
    \ (int i = 0; i < n; i++)\r\n\t\tca += (a[i] != 0), cb += (b[i] != 0);\r\n\tif\
    \ (std::min(ca, cb) <= 1500 / n) { // not many multiplications\r\n\t\tif (ca >\
    \ cb) \r\n\t\t\tstd::swap(ca, cb);\r\n\t\tfor (int i = 0; i < n; i++) \r\n\t\t\
    \tif (a[i] != 0)\r\n\t\t\t\tfor (int j = 0; j < n; j++)\r\n\t\t\t\t\tc[i + j]\
    \ += a[i] * b[j];\r\n\r\n\t} else {\r\n\t\tint h = n >> 1;\r\n\t\tkaratsuba(a,\
    \ b, c, t, h); // a0 * b0\r\n\t\tkaratsuba(a + h, b + h, c + n, t, h); // a1 *\
    \ b1\r\n\t\tfor (int i = 0; i < h; i++)\r\n\t\t\ta[i] += a[i + h], b[i] += b[i\
    \ + h];\r\n\t\tkaratsuba(a, b, t, t + n, h); // (a0 + a1) * (b0 + b1)\r\n\t\t\
    for (int i = 0; i < h; i++)\r\n\t\t\ta[i] -= a[i + h], b[i] -= b[i + h];\r\n\t\
    \tfor (int i = 0; i < n; i++)\r\n\t\t\tt[i] -= c[i] + c[i + n];\r\n\t\tfor (int\
    \ i = 0; i < n; i++)\r\n\t\t\tc[i + h] += t[i], t[i] = 0;\r\n\t}\r\n}\r\n\r\n\
    template <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T>\
    \ b) {\r\n\tint sa = (int)a.size(), sb = (int)b.size();\r\n\tif (!sa || !sb) \r\
    \n\t\treturn {};\r\n\tint n = (1 << size(std::max(sa, sb)));\r\n\ta.resize(n);\r\
    \n\tb.resize(n);\r\n\tstd::vector<T> c(2 * n), t(2 * n);\r\n\tkaratsuba(&a[0],\
    \ &b[0], &c[0], &t[0], n);\r\n\tc.resize(sa + sb - 1);\r\n\treturn c;\r\n}\r\n\
    \r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/polynomial/karatsuba.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-convolution_mod_1000000007-karatsuba.test.cpp
documentation_of: library/polynomial/karatsuba.hpp
layout: document
redirect_from:
- /library/library/polynomial/karatsuba.hpp
- /library/library/polynomial/karatsuba.hpp.html
title: library/polynomial/karatsuba.hpp
---
