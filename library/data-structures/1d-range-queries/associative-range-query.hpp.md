---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-static_range_sum.test.cpp
    title: verify/yosupo/yosupo-static_range_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct RangeQuery {\r\n\tint sz; \r\n\tstd::vector<std::vector<T>>\
    \ st;\r\n\tT id = 0;\r\n\tstd::vector<T> a;\r\n\r\n\tT comb(T a, T b) { return\
    \ a + b; }  \r\n\r\n\tvoid fill(int l, int r, int ind) {\r\n\t\tif (ind < 0) return;\r\
    \n\t\tint m = (l + r) >> 1;\r\n\t\tT prod = id;\r\n\t\tfor (int i = m - 1; i >=\
    \ l; i--) \r\n\t\t\tst[i][ind] = prod = comb(a[i], prod);\r\n\t\tprod = id;\r\n\
    \t\tfor (int i = m; i < r; i++) \r\n\t\t\tst[i][ind] = prod = comb(prod, a[i]);\r\
    \n\t\tfill(l, m, ind - 1);\r\n\t\tfill(m, r, ind - 1);\r\n\t}\r\n\r\n\tvoid init(std::vector<T>\
    \ a_) {\r\n\t\ta = a_;\r\n\t\tsz = 1;\r\n\t\twhile ((1 << sz) < (int)a.size())\
    \ sz++;\r\n\t\tst = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\r\
    \n\t\ta.resize(1 << sz);\r\n\t\tfill(0, (1 << sz), sz - 1);\r\n\t}\r\n\r\n\tT\
    \ query(int l, int r) {\r\n\t\tif (l == r) return a[l];\r\n\t\tint t = 31 - __builtin_clz(r\
    \ ^ l);\r\n\t\treturn comb(st[l][t], st[r][t]);\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct RangeQuery {\r\n\tint sz; \r\
    \n\tstd::vector<std::vector<T>> st;\r\n\tT id = 0;\r\n\tstd::vector<T> a;\r\n\r\
    \n\tT comb(T a, T b) { return a + b; }  \r\n\r\n\tvoid fill(int l, int r, int\
    \ ind) {\r\n\t\tif (ind < 0) return;\r\n\t\tint m = (l + r) >> 1;\r\n\t\tT prod\
    \ = id;\r\n\t\tfor (int i = m - 1; i >= l; i--) \r\n\t\t\tst[i][ind] = prod =\
    \ comb(a[i], prod);\r\n\t\tprod = id;\r\n\t\tfor (int i = m; i < r; i++) \r\n\t\
    \t\tst[i][ind] = prod = comb(prod, a[i]);\r\n\t\tfill(l, m, ind - 1);\r\n\t\t\
    fill(m, r, ind - 1);\r\n\t}\r\n\r\n\tvoid init(std::vector<T> a_) {\r\n\t\ta =\
    \ a_;\r\n\t\tsz = 1;\r\n\t\twhile ((1 << sz) < (int)a.size()) sz++;\r\n\t\tst\
    \ = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\r\n\t\ta.resize(1\
    \ << sz);\r\n\t\tfill(0, (1 << sz), sz - 1);\r\n\t}\r\n\r\n\tT query(int l, int\
    \ r) {\r\n\t\tif (l == r) return a[l];\r\n\t\tint t = 31 - __builtin_clz(r ^ l);\r\
    \n\t\treturn comb(st[l][t], st[r][t]);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/associative-range-query.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-static_range_sum.test.cpp
documentation_of: library/data-structures/1d-range-queries/associative-range-query.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/associative-range-query.hpp
- /library/library/data-structures/1d-range-queries/associative-range-query.hpp.html
title: library/data-structures/1d-range-queries/associative-range-query.hpp
---
