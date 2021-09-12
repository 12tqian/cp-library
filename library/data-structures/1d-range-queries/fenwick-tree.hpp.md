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
  bundledCode: "\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T> fwt;\n\
    \tint n;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\t}\n\n\
    \tvoid init(std::vector<T>& a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n, 0);\n\
    \t\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t}\n\t\
    }\n\n\tT sum(int r) {\n\t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1)) -\
    \ 1) \n\t\t\tret += fwt[r];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) {\n\
    \t\treturn sum(r) - sum(l - 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\t\t\
    for (; idx < n; idx = idx | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T>\
    \ fwt;\n\tint n;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\
    \t}\n\n\tvoid init(std::vector<T>& a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t\
    }\n\t}\n\n\tT sum(int r) {\n\t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1))\
    \ - 1) \n\t\t\tret += fwt[r];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\treturn sum(r) - sum(l - 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\
    \t\tfor (; idx < n; idx = idx | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/fenwick-tree.hpp
  requiredBy:
  - library/number-theory/counting-primes.hpp
  timestamp: '2021-08-16 13:21:48-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-counting_primes.test.cpp
  - verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/fenwick-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/fenwick-tree.hpp
- /library/library/data-structures/1d-range-queries/fenwick-tree.hpp.html
title: library/data-structures/1d-range-queries/fenwick-tree.hpp
---
