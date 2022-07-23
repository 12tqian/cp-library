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
  bundledCode: "\r\ntemplate <class T> struct FenwickTree {\r\n\tstd::vector<T> fwt;\r\
    \n\tint n;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tfwt.assign(n, 0);\r\
    \n\t}\r\n\r\n\tvoid init(std::vector<T>& a) {\r\n\t\tn = (int)a.size();\r\n\t\t\
    fwt.assign(n, 0);\r\n\t\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\t\tadd(i,\
    \ a[i]);\r\n\t\t}\r\n\t}\r\n\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\t\tfor\
    \ (; r >= 0; r = (r & (r + 1)) - 1) \r\n\t\t\tret += fwt[r];\r\n\t\treturn ret;\r\
    \n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn sum(r) - sum(l - 1);\r\n\t\
    }\r\n\t\r\n\tvoid add(int idx, T delta) {\r\n\t\tfor (; idx < n; idx = idx | (idx\
    \ + 1)) \r\n\t\t\tfwt[idx] += delta;\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct FenwickTree {\r\n\tstd::vector<T>\
    \ fwt;\r\n\tint n;\r\n\r\n\tvoid init(int n_) {\r\n\t\tn = n_;\r\n\t\tfwt.assign(n,\
    \ 0);\r\n\t}\r\n\r\n\tvoid init(std::vector<T>& a) {\r\n\t\tn = (int)a.size();\r\
    \n\t\tfwt.assign(n, 0);\r\n\t\tfor (int i = 0; i < (int)a.size(); i++) {\r\n\t\
    \t\tadd(i, a[i]);\r\n\t\t}\r\n\t}\r\n\r\n\tT sum(int r) {\r\n\t\tT ret = 0;\r\n\
    \t\tfor (; r >= 0; r = (r & (r + 1)) - 1) \r\n\t\t\tret += fwt[r];\r\n\t\treturn\
    \ ret;\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\treturn sum(r) - sum(l -\
    \ 1);\r\n\t}\r\n\t\r\n\tvoid add(int idx, T delta) {\r\n\t\tfor (; idx < n; idx\
    \ = idx | (idx + 1)) \r\n\t\t\tfwt[idx] += delta;\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/fenwick-tree.hpp
  requiredBy:
  - library/number-theory/counting-primes.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
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
