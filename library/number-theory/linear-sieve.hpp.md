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
  bundledCode: "\ntemplate <int N> struct LinearSieve {\n\tstd::bitset<N> pri;\n\t\
    std::vector<int> pr;\n\t\n\tLinearSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1]\
    \ = 0;\n\t\tfor (int i = 2; i < N; ++i) {\n\t\t\tif (pri[i]) \n\t\t\t\tpr.push_back(i);\n\
    \t\t\tfor (int j = 0; j < (int)pr.size() && i * pr[j] < N; ++j) {\n\t\t\t\tpri[i\
    \ * pr[j]] = 0;\n\t\t\t\tif (i % pr[j] == 0) \n\t\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    }\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <int N> struct LinearSieve {\n\tstd::bitset<N> pri;\n\
    \tstd::vector<int> pr;\n\t\n\tLinearSieve() {\n\t\tpri.set();\n\t\tpri[0] = pri[1]\
    \ = 0;\n\t\tfor (int i = 2; i < N; ++i) {\n\t\t\tif (pri[i]) \n\t\t\t\tpr.push_back(i);\n\
    \t\t\tfor (int j = 0; j < (int)pr.size() && i * pr[j] < N; ++j) {\n\t\t\t\tpri[i\
    \ * pr[j]] = 0;\n\t\t\t\tif (i % pr[j] == 0) \n\t\t\t\t\tbreak;\n\t\t\t}\n\t\t\
    }\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/number-theory/linear-sieve.hpp
  requiredBy: []
  timestamp: '2021-08-16 14:40:22-04:00'
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
