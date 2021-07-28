---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-static_range_sum.test.cpp
    title: verify/yosupo/yosupo-static_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class T> struct RangeQuery {\n\tint sz; \n\tstd::vector<std::vector<T>>\
    \ st;\n\tT id = 0;\n\tstd::vector<T> a;\n\n\tT comb(T a, T b) { return a + b;\
    \ }  \n\n\tvoid fill(int l, int r, int ind) {\n\t\tif (ind < 0) return;\n\t\t\
    int m = (l + r) >> 1;\n\t\tT prod = id;\n\t\tfor (int i = m - 1; i >= l; i--)\
    \ \n\t\t\tst[i][ind] = prod = comb(a[i], prod);\n\t\tprod = id;\n\t\tfor (int\
    \ i = m; i < r; i++) \n\t\t\tst[i][ind] = prod = comb(prod, a[i]);\n\t\tfill(l,\
    \ m, ind - 1);\n\t\tfill(m, r, ind - 1);\n\t}\n\n\tvoid init(std::vector<T> a_)\
    \ {\n\t\ta = a_;\n\t\tsz = 1;\n\t\twhile ((1 << sz) < (int)a.size()) sz++;\n\t\
    \tst = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\n\t\ta.resize(1\
    \ << sz);\n\t\tfill(0, (1 << sz), sz - 1);\n\t}\n\n\tT query(int l, int r) {\n\
    \t\tif (l == r) return a[l];\n\t\tint t = 31 - __builtin_clz(r ^ l);\n\t\treturn\
    \ comb(st[l][t], st[r][t]);\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct RangeQuery {\n\tint sz; \n\tstd::vector<std::vector<T>>\
    \ st;\n\tT id = 0;\n\tstd::vector<T> a;\n\n\tT comb(T a, T b) { return a + b;\
    \ }  \n\n\tvoid fill(int l, int r, int ind) {\n\t\tif (ind < 0) return;\n\t\t\
    int m = (l + r) >> 1;\n\t\tT prod = id;\n\t\tfor (int i = m - 1; i >= l; i--)\
    \ \n\t\t\tst[i][ind] = prod = comb(a[i], prod);\n\t\tprod = id;\n\t\tfor (int\
    \ i = m; i < r; i++) \n\t\t\tst[i][ind] = prod = comb(prod, a[i]);\n\t\tfill(l,\
    \ m, ind - 1);\n\t\tfill(m, r, ind - 1);\n\t}\n\n\tvoid init(std::vector<T> a_)\
    \ {\n\t\ta = a_;\n\t\tsz = 1;\n\t\twhile ((1 << sz) < (int)a.size()) sz++;\n\t\
    \tst = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\n\t\ta.resize(1\
    \ << sz);\n\t\tfill(0, (1 << sz), sz - 1);\n\t}\n\n\tT query(int l, int r) {\n\
    \t\tif (l == r) return a[l];\n\t\tint t = 31 - __builtin_clz(r ^ l);\n\t\treturn\
    \ comb(st[l][t], st[r][t]);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/associative-range-query.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-static_range_sum.test.cpp
documentation_of: library/data-structures/1d-range-queries/associative-range-query.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/associative-range-query.hpp
- /library/library/data-structures/1d-range-queries/associative-range-query.hpp.html
title: library/data-structures/1d-range-queries/associative-range-query.hpp
---
