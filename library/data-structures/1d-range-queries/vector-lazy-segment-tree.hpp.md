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
  bundledCode: "#include <bits/stdc++.h>\n\ntemplate <class T> struct LazySeg {\n\t\
    std::vector<T> sum, lazy;\n\tint sz;\n\n\tvoid init(int sz_) {\n\t\tsz = 1;\n\t\
    \twhile (sz < sz_) sz *= 2;\n\t\tsum.assign(2 * sz, 0);\n\t\tlazy.assign(2 * sz,\
    \ 0);\n\t}\n\n\tvoid push(int ind, int L, int R) {\n\t\tsum[ind] += (R - L + 1)\
    \ * lazy[ind];\n\t\tif (L != R) {\n\t\t\tlazy[2 * ind] += lazy[ind];\n\t\t\tlazy[2\
    \ * ind + 1] += lazy[ind];\n\t\t}\n\t\tlazy[ind] = 0;\n\t}\n\n\tvoid pull(int\
    \ ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n\t}\n\n\tvoid build()\
    \ {\n\t\tfor (int i = sz - 1; i >= 1; i--) {\n\t\t\tpull(i);\n\t\t}\n\t}\n\n\t\
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n\t\tif\
    \ (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L || R < lo) return;\n\
    \t\tif (lo <= L && R <= hi) {\n\t\t\tlazy[ind] = inc;\n\t\t\tpush(ind, L, R);\n\
    \t\t\treturn;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\tupd(lo, hi, inc, 2 * ind,\
    \ L, M);\n\t\tupd(lo, hi, inc, 2 * ind + 1, M + 1, R);\n\t\tpull(ind);\n\t}\n\n\
    \tT qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1)\
    \ R += sz;\n\t\tpush(ind, L, R);\n\t\tif (lo > R || L > hi) return 0;\n\t\tif\
    \ (lo <= L && R <= hi) return sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn\
    \ qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n};\n\
    \nint main() {\n\treturn 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct LazySeg {\n\tstd::vector<T>\
    \ sum, lazy;\n\tint sz;\n\n\tvoid init(int sz_) {\n\t\tsz = 1;\n\t\twhile (sz\
    \ < sz_) sz *= 2;\n\t\tsum.assign(2 * sz, 0);\n\t\tlazy.assign(2 * sz, 0);\n\t\
    }\n\n\tvoid push(int ind, int L, int R) {\n\t\tsum[ind] += (R - L + 1) * lazy[ind];\n\
    \t\tif (L != R) {\n\t\t\tlazy[2 * ind] += lazy[ind];\n\t\t\tlazy[2 * ind + 1]\
    \ += lazy[ind];\n\t\t}\n\t\tlazy[ind] = 0;\n\t}\n\n\tvoid pull(int ind) {\n\t\t\
    sum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n\t}\n\n\tvoid build() {\n\t\tfor\
    \ (int i = sz - 1; i >= 1; i--) {\n\t\t\tpull(i);\n\t\t}\n\t}\n\n\tvoid upd(int\
    \ lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R\
    \ += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L || R < lo) return;\n\t\tif (lo\
    \ <= L && R <= hi) {\n\t\t\tlazy[ind] = inc;\n\t\t\tpush(ind, L, R);\n\t\t\treturn;\n\
    \t\t}\n\t\tint M = (L + R) / 2;\n\t\tupd(lo, hi, inc, 2 * ind, L, M);\n\t\tupd(lo,\
    \ hi, inc, 2 * ind + 1, M + 1, R);\n\t\tpull(ind);\n\t}\n\n\tT qsum(int lo, int\
    \ hi, int ind = 1, int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind,\
    \ L, R);\n\t\tif (lo > R || L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return\
    \ sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M)\
    \ + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n};\n\nint main() {\n\treturn 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/vector-lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:26:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/vector-lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/vector-lazy-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/vector-lazy-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/vector-lazy-segment-tree.hpp
---
