---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-869E-general-fwt.test.cpp
    title: verify/codeforces/codeforces-869E-general-fwt.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x);\
    \ } \n\ntemplate <class T, int ...Ns> struct BIT {\n\tT val = 0; void upd(T v)\
    \ { val += v; }\n\tT query() { return val; }\n};\n\ntemplate <class T, int N,\
    \ int... Ns> struct BIT<T, N, Ns...> {\n\tBIT<T, Ns...> bit[N + 1];\n\n\ttemplate\
    \ <typename... Args> void upd(int pos, Args... args) { \n\t\tassert(pos > 0);\n\
    \t\tfor (; pos <= N; pos += pos & -pos) \n\t\t\tbit[pos].upd(args...); \n\t}\n\
    \n\ttemplate <typename... Args> T sum(int r, Args... args) {\n\t\tT res = 0; \n\
    \t\tfor (; r; r -= r & -r) \n\t\t\tres += bit[r].query(args...); \n\t\treturn\
    \ res; \n\t}\n\n\ttemplate <typename... Args> T query(int l, int r, Args... args)\
    \ { \n\t\treturn sum(r, args...) - sum(l - 1, args...); \n\t}\n\n\tint get_kth(T\
    \ des) { \n\t\tassert(des > 0);\n\t\tint ind = 0;\n\t\tfor (int i = 1 << bits(N);\
    \ i; i /= 2)\n\t\t\tif (ind + i <= N && bit[ind + i].val < des)\n\t\t\t\tdes -=\
    \ bit[ind += i].val;\n\t\tassert(ind < N); return ind + 1;\n\t}\n}; \n\n"
  code: "#pragma once\n\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x);\
    \ } \n\ntemplate <class T, int ...Ns> struct BIT {\n\tT val = 0; void upd(T v)\
    \ { val += v; }\n\tT query() { return val; }\n};\n\ntemplate <class T, int N,\
    \ int... Ns> struct BIT<T, N, Ns...> {\n\tBIT<T, Ns...> bit[N + 1];\n\n\ttemplate\
    \ <typename... Args> void upd(int pos, Args... args) { \n\t\tassert(pos > 0);\n\
    \t\tfor (; pos <= N; pos += pos & -pos) \n\t\t\tbit[pos].upd(args...); \n\t}\n\
    \n\ttemplate <typename... Args> T sum(int r, Args... args) {\n\t\tT res = 0; \n\
    \t\tfor (; r; r -= r & -r) \n\t\t\tres += bit[r].query(args...); \n\t\treturn\
    \ res; \n\t}\n\n\ttemplate <typename... Args> T query(int l, int r, Args... args)\
    \ { \n\t\treturn sum(r, args...) - sum(l - 1, args...); \n\t}\n\n\tint get_kth(T\
    \ des) { \n\t\tassert(des > 0);\n\t\tint ind = 0;\n\t\tfor (int i = 1 << bits(N);\
    \ i; i /= 2)\n\t\t\tif (ind + i <= N && bit[ind + i].val < des)\n\t\t\t\tdes -=\
    \ bit[ind += i].val;\n\t\tassert(ind < N); return ind + 1;\n\t}\n}; \n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/general-fenwick-tree.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:21:48-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-869E-general-fwt.test.cpp
documentation_of: library/data-structures/2d-range-queries/general-fenwick-tree.hpp
layout: document
title: General Fenwick Tree
---

## General Fenwick Tree

Multidimensional Fenwick Tree. 

### Assumptions
- $1$-indexed. 

### Functions
- `upd(pos, ...)`: Update at location of coordinates in $\mathcal O(\log(n)^d).
- `query(l, r, ...)`: Query in "rectangular" region in $\mathcal O(\log(n)^d).

### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/1D%20Range%20Queries%20(9.2)/BitNd.h)
