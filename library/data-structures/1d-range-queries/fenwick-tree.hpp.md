---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/number-theory/counting-primes.hpp
    title: library/number-theory/counting-primes.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-counting_primes.test.cpp
    title: verify/yosupo/yosupo-counting_primes.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T>\r\nstruct FenwickTree {\r\n  std::vector<T>\
    \ fwt;\r\n  int n;\r\n\r\n  FenwickTree() = default;\r\n  FenwickTree(int n) {\
    \ init(n); }\r\n  FenwickTree(std::vector<T>& a) { init(a); }\r\n\r\n  void init(int\
    \ n_) {\r\n    n = n_;\r\n    fwt.assign(n, 0);\r\n  }\r\n\r\n  void init(std::vector<T>&\
    \ a) {\r\n    n = (int)a.size();\r\n    fwt.assign(n, 0);\r\n    for (int i =\
    \ 0; i < (int)a.size(); i++) {\r\n      add(i, a[i]);\r\n    }\r\n  }\r\n\r\n\
    \  T sum(int r) {\r\n    T ret = 0;\r\n    for (; r >= 0; r = (r & (r + 1)) -\
    \ 1) ret += fwt[r];\r\n    return ret;\r\n  }\r\n\r\n  T query(int l, int r) {\
    \ return sum(r) - sum(l - 1); }\r\n\r\n  void add(int idx, T delta) {\r\n    for\
    \ (; idx < n; idx = idx | (idx + 1)) fwt[idx] += delta;\r\n  }\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T>\r\nstruct FenwickTree {\r\n  std::vector<T>\
    \ fwt;\r\n  int n;\r\n\r\n  FenwickTree() = default;\r\n  FenwickTree(int n) {\
    \ init(n); }\r\n  FenwickTree(std::vector<T>& a) { init(a); }\r\n\r\n  void init(int\
    \ n_) {\r\n    n = n_;\r\n    fwt.assign(n, 0);\r\n  }\r\n\r\n  void init(std::vector<T>&\
    \ a) {\r\n    n = (int)a.size();\r\n    fwt.assign(n, 0);\r\n    for (int i =\
    \ 0; i < (int)a.size(); i++) {\r\n      add(i, a[i]);\r\n    }\r\n  }\r\n\r\n\
    \  T sum(int r) {\r\n    T ret = 0;\r\n    for (; r >= 0; r = (r & (r + 1)) -\
    \ 1) ret += fwt[r];\r\n    return ret;\r\n  }\r\n\r\n  T query(int l, int r) {\
    \ return sum(r) - sum(l - 1); }\r\n\r\n  void add(int idx, T delta) {\r\n    for\
    \ (; idx < n; idx = idx | (idx + 1)) fwt[idx] += delta;\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/fenwick-tree.hpp
  requiredBy:
  - library/number-theory/counting-primes.hpp
  timestamp: '2023-01-08 14:16:34-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
  - verify/yosupo/yosupo-counting_primes.test.cpp
documentation_of: library/data-structures/1d-range-queries/fenwick-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/fenwick-tree.hpp
- /library/library/data-structures/1d-range-queries/fenwick-tree.hpp.html
title: library/data-structures/1d-range-queries/fenwick-tree.hpp
---
