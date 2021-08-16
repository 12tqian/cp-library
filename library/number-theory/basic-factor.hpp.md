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
  bundledCode: "\nnamespace FactorBasic {\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factor(T x) {\n\tstd::vector<std::pair<T, int>> pri;\n\tfor (T i = 2;\
    \ i * i <= x; ++i) {\n\t\tif (x % i == 0) {\n\t\t\tint t = 0;\n\t\t\twhile (x\
    \ % i == 0) x /= i, t++;\n\t\t\tpri.push_back({i, t});\n\t\t}\n\t}\n\tif (x >\
    \ 1) pri.push_back({x, 1});\n\treturn pri;\n}\n\ntemplate <class T> T phi(T x)\
    \ {\n\tfor (auto& a : factor(x)) x -= x / a.first;\n\treturn x;\n}\n\ntemplate\
    \ <class T> void tour(std::vector<std::pair<T, int>>& v, std::vector<T>& res,\
    \ int ind, T cur) {\n\tif (ind == (int)v.size()) res.push_back(cur);\n\telse {\n\
    \t\tT mul = 1;\n\t\tfor (int i = 0; i < v[ind].second + 1; i++) {\n\t\t\ttour(v,\
    \ res, ind + 1, cur * mul);\n\t\t\tmul *= v[ind].first;\n\t\t}\n\t}\n}\n\ntemplate\
    \ <class T> std::vector<T> get_divisor(T x) {\n\tauto v = factor(x);\n\tstd::vector<T>\
    \ res; \n\ttour(v, res, 0, (T) 1);\n\tsort(res.begin(), res.end());\n\treturn\
    \ res;\n}\n\n}\n"
  code: "#pragma once\n\nnamespace FactorBasic {\n\ntemplate <class T> std::vector<std::pair<T,\
    \ int>> factor(T x) {\n\tstd::vector<std::pair<T, int>> pri;\n\tfor (T i = 2;\
    \ i * i <= x; ++i) {\n\t\tif (x % i == 0) {\n\t\t\tint t = 0;\n\t\t\twhile (x\
    \ % i == 0) x /= i, t++;\n\t\t\tpri.push_back({i, t});\n\t\t}\n\t}\n\tif (x >\
    \ 1) pri.push_back({x, 1});\n\treturn pri;\n}\n\ntemplate <class T> T phi(T x)\
    \ {\n\tfor (auto& a : factor(x)) x -= x / a.first;\n\treturn x;\n}\n\ntemplate\
    \ <class T> void tour(std::vector<std::pair<T, int>>& v, std::vector<T>& res,\
    \ int ind, T cur) {\n\tif (ind == (int)v.size()) res.push_back(cur);\n\telse {\n\
    \t\tT mul = 1;\n\t\tfor (int i = 0; i < v[ind].second + 1; i++) {\n\t\t\ttour(v,\
    \ res, ind + 1, cur * mul);\n\t\t\tmul *= v[ind].first;\n\t\t}\n\t}\n}\n\ntemplate\
    \ <class T> std::vector<T> get_divisor(T x) {\n\tauto v = factor(x);\n\tstd::vector<T>\
    \ res; \n\ttour(v, res, 0, (T) 1);\n\tsort(res.begin(), res.end());\n\treturn\
    \ res;\n}\n\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/basic-factor.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:31:52-04:00'
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
