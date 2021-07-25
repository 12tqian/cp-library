---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/karatsuba.test.cpp
    title: test/karatsuba.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\nnamespace Karatsuba {\n\nint size(int s) {\n\treturn s > 1 ? 32\
    \ - __builtin_clz(s - 1) : 0;\n}\n\ntemplate <class T> void karatsuba(T *a, T\
    \ *b, T *c, T *t, int n) {\n\tint ca = 0, cb = 0;\n\tfor (int i = 0; i < n; i++)\n\
    \t\tca += (a[i] != 0), cb += (b[i] != 0);\n\tif (std::min(ca, cb) <= 1500 / n)\
    \ { // not many multiplications\n\t\tif (ca > cb) \n\t\t\tstd::swap(ca, cb);\n\
    \t\tfor (int i = 0; i < n; i++) \n\t\t\tif (a[i] != 0)\n\t\t\t\tfor (int j = 0;\
    \ j < n; j++)\n\t\t\t\t\tc[i + j] += a[i] * b[j];\n\n\t} else {\n\t\tint h = n\
    \ >> 1;\n\t\tkaratsuba(a, b, c, t, h); // a0 * b0\n\t\tkaratsuba(a + h, b + h,\
    \ c + n, t, h); // a1 * b1\n\t\tfor (int i = 0; i < h; i++)\n\t\t\ta[i] += a[i\
    \ + h], b[i] += b[i + h];\n\t\tkaratsuba(a, b, t, t + n, h); // (a0 + a1) * (b0\
    \ + b1)\n\t\tfor (int i = 0; i < h; i++)\n\t\t\ta[i] -= a[i + h], b[i] -= b[i\
    \ + h];\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tt[i] -= c[i] + c[i + n];\n\t\t\
    for (int i = 0; i < n; i++)\n\t\t\tc[i + h] += t[i], t[i] = 0;\n\t}\n}\n\ntemplate\
    \ <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T> b) {\n\
    \tint sa = (int)a.size(), sb = (int)b.size();\n\tif (!sa || !sb) \n\t\treturn\
    \ {};\n\tint n = (1 << size(std::max(sa, sb)));\n\ta.resize(n);\n\tb.resize(n);\n\
    \tstd::vector<T> c(2 * n), t(2 * n);\n\tkaratsuba(&a[0], &b[0], &c[0], &t[0],\
    \ n);\n\tc.resize(sa + sb - 1);\n\treturn c;\n}\n\n}\n"
  code: "#pragma once\n\nnamespace Karatsuba {\n\nint size(int s) {\n\treturn s >\
    \ 1 ? 32 - __builtin_clz(s - 1) : 0;\n}\n\ntemplate <class T> void karatsuba(T\
    \ *a, T *b, T *c, T *t, int n) {\n\tint ca = 0, cb = 0;\n\tfor (int i = 0; i <\
    \ n; i++)\n\t\tca += (a[i] != 0), cb += (b[i] != 0);\n\tif (std::min(ca, cb) <=\
    \ 1500 / n) { // not many multiplications\n\t\tif (ca > cb) \n\t\t\tstd::swap(ca,\
    \ cb);\n\t\tfor (int i = 0; i < n; i++) \n\t\t\tif (a[i] != 0)\n\t\t\t\tfor (int\
    \ j = 0; j < n; j++)\n\t\t\t\t\tc[i + j] += a[i] * b[j];\n\n\t} else {\n\t\tint\
    \ h = n >> 1;\n\t\tkaratsuba(a, b, c, t, h); // a0 * b0\n\t\tkaratsuba(a + h,\
    \ b + h, c + n, t, h); // a1 * b1\n\t\tfor (int i = 0; i < h; i++)\n\t\t\ta[i]\
    \ += a[i + h], b[i] += b[i + h];\n\t\tkaratsuba(a, b, t, t + n, h); // (a0 + a1)\
    \ * (b0 + b1)\n\t\tfor (int i = 0; i < h; i++)\n\t\t\ta[i] -= a[i + h], b[i] -=\
    \ b[i + h];\n\t\tfor (int i = 0; i < n; i++)\n\t\t\tt[i] -= c[i] + c[i + n];\n\
    \t\tfor (int i = 0; i < n; i++)\n\t\t\tc[i + h] += t[i], t[i] = 0;\n\t}\n}\n\n\
    template <class T> std::vector<T> convolution(std::vector<T> a, std::vector<T>\
    \ b) {\n\tint sa = (int)a.size(), sb = (int)b.size();\n\tif (!sa || !sb) \n\t\t\
    return {};\n\tint n = (1 << size(std::max(sa, sb)));\n\ta.resize(n);\n\tb.resize(n);\n\
    \tstd::vector<T> c(2 * n), t(2 * n);\n\tkaratsuba(&a[0], &b[0], &c[0], &t[0],\
    \ n);\n\tc.resize(sa + sb - 1);\n\treturn c;\n}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/numerical/karatsuba.hpp
  requiredBy: []
  timestamp: '2021-07-24 22:46:46-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/karatsuba.test.cpp
documentation_of: library/numerical/karatsuba.hpp
layout: document
redirect_from:
- /library/library/numerical/karatsuba.hpp
- /library/library/numerical/karatsuba.hpp.html
title: library/numerical/karatsuba.hpp
---
