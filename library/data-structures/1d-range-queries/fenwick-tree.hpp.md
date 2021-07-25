---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/fenwick-tree.test.cpp
    title: test/fenwick-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T> fwt;\n\
    \tint n;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\t}\n\n\
    \tvoid init(std::vector<T> &a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n, 0);\n\
    \t\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t}\n\t\
    }\n\n\tT sum(int r) {\n\t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1)) -\
    \ 1) \n\t\t\tret += fwt[r];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r) {\n\
    \t\treturn sum(r) - sum(l - 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\t\t\
    for (; idx < n; idx = idx | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct FenwickTree {\n\tstd::vector<T>\
    \ fwt;\n\tint n;\n\n\tvoid init(int n_) {\n\t\tn = n_;\n\t\tfwt.assign(n, 0);\n\
    \t}\n\n\tvoid init(std::vector<T> &a) {\n\t\tn = (int)a.size();\n\t\tfwt.assign(n,\
    \ 0);\n\t\tfor (int i = 0; i < (int)a.size(); i++) {\n\t\t\tadd(i, a[i]);\n\t\t\
    }\n\t}\n\n\tT sum(int r) {\n\t\tT ret = 0;\n\t\tfor (; r >= 0; r = (r & (r + 1))\
    \ - 1) \n\t\t\tret += fwt[r];\n\t\treturn ret;\n\t}\n\n\tT query(int l, int r)\
    \ {\n\t\treturn sum(r) - sum(l - 1);\n\t}\n\t\n\tvoid add(int idx, T delta) {\n\
    \t\tfor (; idx < n; idx = idx | (idx + 1)) \n\t\t\tfwt[idx] += delta;\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/fenwick-tree.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:09:23-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/fenwick-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/fenwick-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/fenwick-tree.hpp
- /library/library/data-structures/1d-range-queries/fenwick-tree.hpp.html
title: library/data-structures/1d-range-queries/fenwick-tree.hpp
---
