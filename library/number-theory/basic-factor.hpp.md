---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-FACT0.test.cpp
    title: verify/spoj/spoj-FACT0.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nnamespace FactorBasic {\r\n\r\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factor(T x) {\r\n\tstd::vector<std::pair<T, int>> pri;\r\n\tfor (T i =\
    \ 2; i * i <= x; ++i) {\r\n\t\tif (x % i == 0) {\r\n\t\t\tint t = 0;\r\n\t\t\t\
    while (x % i == 0) x /= i, t++;\r\n\t\t\tpri.push_back({i, t});\r\n\t\t}\r\n\t\
    }\r\n\tif (x > 1) pri.push_back({x, 1});\r\n\treturn pri;\r\n}\r\n\r\ntemplate\
    \ <class T> T phi(T x) {\r\n\tfor (auto& a : factor(x)) x -= x / a.first;\r\n\t\
    return x;\r\n}\r\n\r\ntemplate <class T> void tour(std::vector<std::pair<T, int>>&\
    \ v, std::vector<T>& res, int ind, T cur) {\r\n\tif (ind == (int)v.size()) res.push_back(cur);\r\
    \n\telse {\r\n\t\tT mul = 1;\r\n\t\tfor (int i = 0; i < v[ind].second + 1; i++)\
    \ {\r\n\t\t\ttour(v, res, ind + 1, cur * mul);\r\n\t\t\tmul *= v[ind].first;\r\
    \n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate <class T> std::vector<T> get_divisor(T x)\
    \ {\r\n\tauto v = factor(x);\r\n\tstd::vector<T> res; \r\n\ttour(v, res, 0, (T)\
    \ 1);\r\n\tsort(res.begin(), res.end());\r\n\treturn res;\r\n}\r\n\r\n}\n"
  code: "#pragma once\r\n\r\nnamespace FactorBasic {\r\n\r\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factor(T x) {\r\n\tstd::vector<std::pair<T, int>> pri;\r\n\tfor (T i =\
    \ 2; i * i <= x; ++i) {\r\n\t\tif (x % i == 0) {\r\n\t\t\tint t = 0;\r\n\t\t\t\
    while (x % i == 0) x /= i, t++;\r\n\t\t\tpri.push_back({i, t});\r\n\t\t}\r\n\t\
    }\r\n\tif (x > 1) pri.push_back({x, 1});\r\n\treturn pri;\r\n}\r\n\r\ntemplate\
    \ <class T> T phi(T x) {\r\n\tfor (auto& a : factor(x)) x -= x / a.first;\r\n\t\
    return x;\r\n}\r\n\r\ntemplate <class T> void tour(std::vector<std::pair<T, int>>&\
    \ v, std::vector<T>& res, int ind, T cur) {\r\n\tif (ind == (int)v.size()) res.push_back(cur);\r\
    \n\telse {\r\n\t\tT mul = 1;\r\n\t\tfor (int i = 0; i < v[ind].second + 1; i++)\
    \ {\r\n\t\t\ttour(v, res, ind + 1, cur * mul);\r\n\t\t\tmul *= v[ind].first;\r\
    \n\t\t}\r\n\t}\r\n}\r\n\r\ntemplate <class T> std::vector<T> get_divisor(T x)\
    \ {\r\n\tauto v = factor(x);\r\n\tstd::vector<T> res; \r\n\ttour(v, res, 0, (T)\
    \ 1);\r\n\tsort(res.begin(), res.end());\r\n\treturn res;\r\n}\r\n\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/basic-factor.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-FACT0.test.cpp
documentation_of: library/number-theory/basic-factor.hpp
layout: document
title: Basic Factoring
---

## Basic Factoring

We support basic number theory operations. 

### Functions
- `factor(x)`: Factors $x$ in $\mathcal O(\sqrt x)$. It returns a list of primes and exponents in sorted order. 
- `phi(x)`: Returns $\phi(x)$ in $\mathcal O(\sqrt x)$.
- `get_divisors(x)`: Returns list of divisors in sorted order in $\mathcal O(\sqrt x)$. 

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/number-theory%20(11.1)/Primality/FactorBasic.h)
