---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct RangeSetSeg {\r\n\tconst T UNUSED =\
    \ -1;\r\n\tstd::vector<T> sum, lazy;\r\n\tint sz;\r\n\r\n\t// lazy stores what\
    \ to set to\r\n\tvoid init(int sz_) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < sz_) sz\
    \ *= 2;\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tlazy.assign(2 * sz, UNUSED);\r\n\t\
    }\r\n\r\n\tvoid push(int ind, int L, int R) {\r\n\t\tif (L != R) {\r\n\t\t\tif(lazy[ind]\
    \ != UNUSED){\r\n\t\t\t\tfor(int i = 0; i < 2; i++){\r\n\t\t\t\t\tlazy[2 * ind\
    \ + i] = lazy[ind];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (lazy[ind] != UNUSED)\
    \ sum[ind] = (R - L + 1) * lazy[ind];\r\n\t\tlazy[ind] = UNUSED;\r\n\t}\r\n\r\n\
    \tvoid pull(int ind) { sum[ind] = sum[2 * ind] + sum[2 * ind + 1]; }\r\n\r\n\t\
    void range_set(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\r\n\
    \t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi < L || R < lo)\
    \ return;\r\n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tlazy[ind] = inc;\r\n\t\t\t\
    push(ind, L, R); return;\r\n\t\t}\r\n\t\tint M = (L + R) / 2;\r\n\t\trange_set(lo,\
    \ hi, inc, 2 * ind, L, M); range_set(lo, hi, inc, 2 * ind + 1, M + 1, R);\r\n\t\
    \tpull(ind);\r\n\t}\r\n\r\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R); if (lo > R ||\
    \ L > hi) return 0;\r\n\t\tif (lo <= L && R <= hi) return sum[ind];\r\n\t\tint\
    \ M = (L + R) / 2;\r\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2\
    \ * ind + 1, M + 1, R);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct RangeSetSeg {\r\n\tconst T\
    \ UNUSED = -1;\r\n\tstd::vector<T> sum, lazy;\r\n\tint sz;\r\n\r\n\t// lazy stores\
    \ what to set to\r\n\tvoid init(int sz_) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < sz_)\
    \ sz *= 2;\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tlazy.assign(2 * sz, UNUSED);\r\
    \n\t}\r\n\r\n\tvoid push(int ind, int L, int R) {\r\n\t\tif (L != R) {\r\n\t\t\
    \tif(lazy[ind] != UNUSED){\r\n\t\t\t\tfor(int i = 0; i < 2; i++){\r\n\t\t\t\t\t\
    lazy[2 * ind + i] = lazy[ind];\r\n\t\t\t\t}\r\n\t\t\t}\r\n\t\t}\r\n\t\tif (lazy[ind]\
    \ != UNUSED) sum[ind] = (R - L + 1) * lazy[ind];\r\n\t\tlazy[ind] = UNUSED;\r\n\
    \t}\r\n\r\n\tvoid pull(int ind) { sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\
    \ }\r\n\r\n\tvoid range_set(int lo, int hi, T inc, int ind = 1, int L = 0, int\
    \ R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi\
    \ < L || R < lo) return;\r\n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tlazy[ind] =\
    \ inc;\r\n\t\t\tpush(ind, L, R); return;\r\n\t\t}\r\n\t\tint M = (L + R) / 2;\r\
    \n\t\trange_set(lo, hi, inc, 2 * ind, L, M); range_set(lo, hi, inc, 2 * ind +\
    \ 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\r\n\tT qsum(int lo, int hi, int ind\
    \ = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind,\
    \ L, R); if (lo > R || L > hi) return 0;\r\n\t\tif (lo <= L && R <= hi) return\
    \ sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo, hi, 2 * ind, L,\
    \ M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/range-set-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/range-set-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/range-set-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/range-set-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/range-set-segment-tree.hpp
---
