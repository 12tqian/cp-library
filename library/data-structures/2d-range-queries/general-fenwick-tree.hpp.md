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
  bundledCode: "\r\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 - __builtin_clz(x);\
    \ } \r\n\r\ntemplate <class T, int ...Ns> struct BIT {\r\n\tT val = 0; void upd(T\
    \ v) { val += v; }\r\n\tT query() { return val; }\r\n};\r\n\r\ntemplate <class\
    \ T, int N, int... Ns> struct BIT<T, N, Ns...> {\r\n\tBIT<T, Ns...> bit[N + 1];\r\
    \n\r\n\ttemplate <typename... Args> void upd(int pos, Args... args) { \r\n\t\t\
    assert(pos > 0);\r\n\t\tfor (; pos <= N; pos += pos & -pos) \r\n\t\t\tbit[pos].upd(args...);\
    \ \r\n\t}\r\n\r\n\ttemplate <typename... Args> T sum(int r, Args... args) {\r\n\
    \t\tT res = 0; \r\n\t\tfor (; r; r -= r & -r) \r\n\t\t\tres += bit[r].query(args...);\
    \ \r\n\t\treturn res; \r\n\t}\r\n\r\n\ttemplate <typename... Args> T query(int\
    \ l, int r, Args... args) { \r\n\t\treturn sum(r, args...) - sum(l - 1, args...);\
    \ \r\n\t}\r\n\r\n\tint get_kth(T des) { \r\n\t\tassert(des > 0);\r\n\t\tint ind\
    \ = 0;\r\n\t\tfor (int i = 1 << bits(N); i; i /= 2)\r\n\t\t\tif (ind + i <= N\
    \ && bit[ind + i].val < des)\r\n\t\t\t\tdes -= bit[ind += i].val;\r\n\t\tassert(ind\
    \ < N); return ind + 1;\r\n\t}\r\n}; \r\n\r\n"
  code: "#pragma once\r\n\r\nconstexpr int bits(int x) { return x == 0 ? 0 : 31 -\
    \ __builtin_clz(x); } \r\n\r\ntemplate <class T, int ...Ns> struct BIT {\r\n\t\
    T val = 0; void upd(T v) { val += v; }\r\n\tT query() { return val; }\r\n};\r\n\
    \r\ntemplate <class T, int N, int... Ns> struct BIT<T, N, Ns...> {\r\n\tBIT<T,\
    \ Ns...> bit[N + 1];\r\n\r\n\ttemplate <typename... Args> void upd(int pos, Args...\
    \ args) { \r\n\t\tassert(pos > 0);\r\n\t\tfor (; pos <= N; pos += pos & -pos)\
    \ \r\n\t\t\tbit[pos].upd(args...); \r\n\t}\r\n\r\n\ttemplate <typename... Args>\
    \ T sum(int r, Args... args) {\r\n\t\tT res = 0; \r\n\t\tfor (; r; r -= r & -r)\
    \ \r\n\t\t\tres += bit[r].query(args...); \r\n\t\treturn res; \r\n\t}\r\n\r\n\t\
    template <typename... Args> T query(int l, int r, Args... args) { \r\n\t\treturn\
    \ sum(r, args...) - sum(l - 1, args...); \r\n\t}\r\n\r\n\tint get_kth(T des) {\
    \ \r\n\t\tassert(des > 0);\r\n\t\tint ind = 0;\r\n\t\tfor (int i = 1 << bits(N);\
    \ i; i /= 2)\r\n\t\t\tif (ind + i <= N && bit[ind + i].val < des)\r\n\t\t\t\t\
    des -= bit[ind += i].val;\r\n\t\tassert(ind < N); return ind + 1;\r\n\t}\r\n};\
    \ \r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/general-fenwick-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
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
