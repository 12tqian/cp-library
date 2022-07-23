---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graphs/heavy-light-decomposition2.hpp
    title: Old Heavy Light Decomposition
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
    title: verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct LazySeg {\r\n\tstd::vector<T> sum, lazy;\r\
    \n\tint sz;\r\n\r\n\tvoid init(int sz_) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < sz_)\
    \ sz *= 2;\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tlazy.assign(2 * sz, 0);\r\n\t\
    }\r\n\r\n\tvoid push(int ind, int L, int R) {\r\n\t\tsum[ind] += (R - L + 1) *\
    \ lazy[ind];\r\n\t\tif (L != R) {\r\n\t\t\tlazy[2 * ind] += lazy[ind];\r\n\t\t\
    \tlazy[2 * ind + 1] += lazy[ind];\r\n\t\t}\r\n\t\tlazy[ind] = 0;\r\n\t}\r\n\r\n\
    \tvoid pull(int ind) {\r\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\n\t\
    }\r\n\r\n\tvoid build() {\r\n\t\tfor (int i = sz - 1; i >= 1; i--) {\r\n\t\t\t\
    pull(i);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid upd(int lo, int hi, T inc, int ind = 1,\
    \ int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\
    \n\t\tif (hi < L || R < lo) return;\r\n\t\tif (lo <= L && R <= hi) {\r\n\t\t\t\
    lazy[ind] = inc;\r\n\t\t\tpush(ind, L, R);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tint\
    \ M = (L + R) / 2;\r\n\t\tupd(lo, hi, inc, 2 * ind, L, M);\r\n\t\tupd(lo, hi,\
    \ inc, 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\r\n\tT qsum(int lo,\
    \ int hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\
    \n\t\tpush(ind, L, R);\r\n\t\tif (lo > R || L > hi) return 0;\r\n\t\tif (lo <=\
    \ L && R <= hi) return sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct LazySeg {\r\n\tstd::vector<T>\
    \ sum, lazy;\r\n\tint sz;\r\n\r\n\tvoid init(int sz_) {\r\n\t\tsz = 1;\r\n\t\t\
    while (sz < sz_) sz *= 2;\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tlazy.assign(2 *\
    \ sz, 0);\r\n\t}\r\n\r\n\tvoid push(int ind, int L, int R) {\r\n\t\tsum[ind] +=\
    \ (R - L + 1) * lazy[ind];\r\n\t\tif (L != R) {\r\n\t\t\tlazy[2 * ind] += lazy[ind];\r\
    \n\t\t\tlazy[2 * ind + 1] += lazy[ind];\r\n\t\t}\r\n\t\tlazy[ind] = 0;\r\n\t}\r\
    \n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\r\
    \n\t}\r\n\r\n\tvoid build() {\r\n\t\tfor (int i = sz - 1; i >= 1; i--) {\r\n\t\
    \t\tpull(i);\r\n\t\t}\r\n\t}\r\n\r\n\tvoid upd(int lo, int hi, T inc, int ind\
    \ = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind,\
    \ L, R);\r\n\t\tif (hi < L || R < lo) return;\r\n\t\tif (lo <= L && R <= hi) {\r\
    \n\t\t\tlazy[ind] = inc;\r\n\t\t\tpush(ind, L, R);\r\n\t\t\treturn;\r\n\t\t}\r\
    \n\t\tint M = (L + R) / 2;\r\n\t\tupd(lo, hi, inc, 2 * ind, L, M);\r\n\t\tupd(lo,\
    \ hi, inc, 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\r\n\tT qsum(int\
    \ lo, int hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\
    \n\t\tpush(ind, L, R);\r\n\t\tif (lo > R || L > hi) return 0;\r\n\t\tif (lo <=\
    \ L && R <= hi) return sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  requiredBy:
  - library/graphs/heavy-light-decomposition2.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
  - verify/yosupo/yosupo-vertex_add_path_sum.test.cpp
documentation_of: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/lazy-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/lazy-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
---
