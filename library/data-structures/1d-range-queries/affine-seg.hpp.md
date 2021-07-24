---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class T> struct AffineSeg {\n\tint sz;\n\tstd::vector<T>\
    \ sum, mult, add;\n\n\tvoid push(int ind, int L, int R) { // modify values for\
    \ current node\n\t\tsum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n\
    \t\tif (L != R) {\n\t\t\tmult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n\
    \t\t\tadd[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n\t\t\tadd[2 * ind\
    \ + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n\t\t}\n\t\tadd[ind] = 0; mult[ind]\
    \ = 1;\n\t}\n\n\tvoid init(int n) {\n\t\tsz = 1;\n\t\twhile (sz < n) sz *= 2;\n\
    \t\tmult.assign(2 * sz, 1);\n\t\tsum.assign(2 * sz, 0);\n\t\tadd.assign(2 * sz,\
    \ 0);\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n\t}\n\n\t// t == 0 is add, t == 1 is for multiplying\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R ==\
    \ -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L || R < lo) return;\n\t\t\
    if (lo <= L && R <= hi) {\n\t\t\tif(t == 0) add[ind] = inc;  \n\t\t\telse mult[ind]\
    \ = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\t\
    upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);\n\
    \t\tpull(ind);\n\t}\n\t\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo > R ||\
    \ L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint M =\
    \ (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind\
    \ + 1, M + 1, R);\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct AffineSeg {\n\tint sz;\n\tstd::vector<T>\
    \ sum, mult, add;\n\n\tvoid push(int ind, int L, int R) { // modify values for\
    \ current node\n\t\tsum[ind] *= mult[ind]; sum[ind] += (R - L + 1) * add[ind];\n\
    \t\tif (L != R) {\n\t\t\tmult[2 * ind] *= mult[ind]; mult[2 * ind + 1] *= mult[ind];\n\
    \t\t\tadd[2 * ind] *= mult[ind]; add[2 * ind] += add[ind];\n\t\t\tadd[2 * ind\
    \ + 1] *= mult[ind]; add[2 * ind + 1] += add[ind];\n\t\t}\n\t\tadd[ind] = 0; mult[ind]\
    \ = 1;\n\t}\n\n\tvoid init(int n) {\n\t\tsz = 1;\n\t\twhile (sz < n) sz *= 2;\n\
    \t\tmult.assign(2 * sz, 1);\n\t\tsum.assign(2 * sz, 0);\n\t\tadd.assign(2 * sz,\
    \ 0);\n\t}\n\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1];\n\t}\n\n\t// t == 0 is add, t == 1 is for multiplying\n\tvoid upd(int\
    \ t, int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R ==\
    \ -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L || R < lo) return;\n\t\t\
    if (lo <= L && R <= hi) {\n\t\t\tif(t == 0) add[ind] = inc;  \n\t\t\telse mult[ind]\
    \ = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\t\
    upd(t, lo, hi, inc, 2 * ind, L, M); upd(t, lo, hi, inc, 2 * ind + 1, M + 1, R);\n\
    \t\tpull(ind);\n\t}\n\t\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo > R ||\
    \ L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint M =\
    \ (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind\
    \ + 1, M + 1, R);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/affine-seg.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/affine-seg.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/affine-seg.hpp
- /library/library/data-structures/1d-range-queries/affine-seg.hpp.html
title: library/data-structures/1d-range-queries/affine-seg.hpp
---
