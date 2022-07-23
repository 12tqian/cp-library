---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-TDKPRIME.test.cpp
    title: verify/spoj/spoj-TDKPRIME.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <int N> struct LinearSieve {\r\n\tstd::bitset<N> pri;\r\
    \n\tstd::vector<int> pr;\r\n\t\r\n\tLinearSieve() {\r\n\t\tpri.set();\r\n\t\t\
    pri[0] = pri[1] = 0;\r\n\t\tfor (int i = 2; i < N; ++i) {\r\n\t\t\tif (pri[i])\
    \ \r\n\t\t\t\tpr.push_back(i);\r\n\t\t\tfor (int j = 0; j < (int)pr.size() &&\
    \ i * pr[j] < N; ++j) {\r\n\t\t\t\tpri[i * pr[j]] = 0;\r\n\t\t\t\tif (i % pr[j]\
    \ == 0) \r\n\t\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <int N> struct LinearSieve {\r\n\tstd::bitset<N>\
    \ pri;\r\n\tstd::vector<int> pr;\r\n\t\r\n\tLinearSieve() {\r\n\t\tpri.set();\r\
    \n\t\tpri[0] = pri[1] = 0;\r\n\t\tfor (int i = 2; i < N; ++i) {\r\n\t\t\tif (pri[i])\
    \ \r\n\t\t\t\tpr.push_back(i);\r\n\t\t\tfor (int j = 0; j < (int)pr.size() &&\
    \ i * pr[j] < N; ++j) {\r\n\t\t\t\tpri[i * pr[j]] = 0;\r\n\t\t\t\tif (i % pr[j]\
    \ == 0) \r\n\t\t\t\t\tbreak;\r\n\t\t\t}\r\n\t\t}\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/linear-sieve.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-TDKPRIME.test.cpp
documentation_of: library/number-theory/linear-sieve.hpp
layout: document
title: Linear Sieve
---

## Linear Sieve

Computes all the primes less than $N$ in $\mathcal O(N)$ time. 

The way it works is it crosses out composite numbers exactly once by checking by smallest prime factors. In this manner, it is possible to compute multiplicative functions for all $N$ in a range in linear time, as shown in the CF blog post under resources.

### Resources
- [Codeforces](https://codeforces.com/blog/entry/54090)
