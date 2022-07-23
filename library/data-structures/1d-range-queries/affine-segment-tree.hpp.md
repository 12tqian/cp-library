---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-981G.test.cpp
    title: verify/codeforces/codeforces-981G.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
    title: verify/yosupo/yosupo-range_affine_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct AffineSegmentTree {\r\n\tint sz;\r\n\
    \tstd::vector<T> sum, mult, add;\r\n\r\n\tvoid push(int ind, int L, int R) { //\
    \ modify values for current node\r\n\t\tsum[ind] *= mult[ind]; sum[ind] += (R\
    \ - L + 1) * add[ind];\r\n\t\tif (L != R) {\r\n\t\t\tmult[2 * ind] *= mult[ind];\
    \ mult[2 * ind + 1] *= mult[ind];\r\n\t\t\tadd[2 * ind] *= mult[ind]; add[2 *\
    \ ind] += add[ind];\r\n\t\t\tadd[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] +=\
    \ add[ind];\r\n\t\t}\r\n\t\tadd[ind] = 0; mult[ind] = 1;\r\n\t}\r\n\r\n\tvoid\
    \ init(int n) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < n) sz *= 2;\r\n\t\tmult.assign(2\
    \ * sz, 1);\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tadd.assign(2 * sz, 0);\r\n\t\
    }\r\n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind +\
    \ 1];\r\n\t}\r\n\r\n\t// t == 0 is add, t == 1 is for multiplying\r\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R\
    \ == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi < L || R < lo) return;\r\
    \n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tif(t == 0) add[ind] = inc;  \r\n\t\t\t\
    else mult[ind] = inc;\r\n\t\t\tpush(ind, L, R); return;\r\n\t\t}\r\n\t\tint M\
    \ = (L + R) / 2;\r\n\t\tupd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc,\
    \ 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\t\r\n\tT qsum(int lo, int\
    \ hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\
    \tpush(ind, L, R);\r\n\t\tif (lo > R || L > hi) return 0;\r\n\t\tif (lo <= L &&\
    \ R <= hi) return sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct AffineSegmentTree {\r\n\tint\
    \ sz;\r\n\tstd::vector<T> sum, mult, add;\r\n\r\n\tvoid push(int ind, int L, int\
    \ R) { // modify values for current node\r\n\t\tsum[ind] *= mult[ind]; sum[ind]\
    \ += (R - L + 1) * add[ind];\r\n\t\tif (L != R) {\r\n\t\t\tmult[2 * ind] *= mult[ind];\
    \ mult[2 * ind + 1] *= mult[ind];\r\n\t\t\tadd[2 * ind] *= mult[ind]; add[2 *\
    \ ind] += add[ind];\r\n\t\t\tadd[2 * ind + 1] *= mult[ind]; add[2 * ind + 1] +=\
    \ add[ind];\r\n\t\t}\r\n\t\tadd[ind] = 0; mult[ind] = 1;\r\n\t}\r\n\r\n\tvoid\
    \ init(int n) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < n) sz *= 2;\r\n\t\tmult.assign(2\
    \ * sz, 1);\r\n\t\tsum.assign(2 * sz, 0);\r\n\t\tadd.assign(2 * sz, 0);\r\n\t\
    }\r\n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind +\
    \ 1];\r\n\t}\r\n\r\n\t// t == 0 is add, t == 1 is for multiplying\r\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R\
    \ == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi < L || R < lo) return;\r\
    \n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tif(t == 0) add[ind] = inc;  \r\n\t\t\t\
    else mult[ind] = inc;\r\n\t\t\tpush(ind, L, R); return;\r\n\t\t}\r\n\t\tint M\
    \ = (L + R) / 2;\r\n\t\tupd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc,\
    \ 2 * ind + 1, M + 1, R);\r\n\t\tpull(ind);\r\n\t}\r\n\t\r\n\tT qsum(int lo, int\
    \ hi, int ind = 1, int L = 0, int R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\
    \tpush(ind, L, R);\r\n\t\tif (lo > R || L > hi) return 0;\r\n\t\tif (lo <= L &&\
    \ R <= hi) return sum[ind];\r\n\t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/affine-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/codeforces/codeforces-981G.test.cpp
  - verify/yosupo/yosupo-range_affine_range_sum.test.cpp
documentation_of: library/data-structures/1d-range-queries/affine-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/affine-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/affine-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/affine-segment-tree.hpp
---
