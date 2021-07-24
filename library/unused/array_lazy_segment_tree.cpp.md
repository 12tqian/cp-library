---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/unused/array_lazy_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    /**\nmake sure SZ is a power of 2\n*/\ntemplate <class T, int SZ> struct LazySeg\
    \ {\n\tT sum[2 * SZ], lazy[2 * SZ];\n\tLazySeg() {\n\t\tfor (int i = 0; i < 2\
    \ * SZ; i++) {\n\t\t\tsum[i] = 0;\n\t\t\tlazy[i] = 0;\n\t\t}\n\t}\n\tvoid push(int\
    \ ind, int L, int R) {\n\t\tsum[ind] += (R - L + 1) * lazy[ind];\n\t\tif (L !=\
    \ R) {\n\t\t\tlazy[2 * ind] += lazy[ind];\n\t\t\tlazy[2 * ind + 1] += lazy[ind];\n\
    \t\t}\n\t\tlazy[ind] = 0;\n\t}\n\tvoid pull(int ind) {\n\t\tsum[ind] = sum[2 *\
    \ ind] + sum[2 * ind + 1];\n\t}\n\tvoid build() {\n\t\tfor (int i = SZ - 1; i\
    \ >= 1; i--) {\n\t\t\tpull(i);\n\t\t}\n\t}\n\tvoid upd(int lo, int hi, T inc,\
    \ int ind = 1, int L = 0, int R = SZ - 1) {\n\t\tpush(ind, L, R);\n\t\tif (hi\
    \ < L || R < lo) return ;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tlazy[ind] = inc;\n\
    \t\t\tpush(ind, L, R);\n\t\t\treturn;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\tupd(lo,\
    \ hi, inc, 2 * ind, L, M);\n\t\tupd(lo, hi, inc, 2 * ind + 1, M + 1, R);\n\t\t\
    pull(ind);\n\t}\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int R = SZ -\
    \ 1) {\n\t\tpush(ind, L, R);\n\t\tif (lo > R || L > hi) return 0;\n\t\tif (lo\
    \ <= L && R <= hi) return sum[ind];\n\t\tint M = (L + R) / 2;\n\t\treturn qsum(lo,\
    \ hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\n/**\nmake sure SZ is a power of 2\n*/\ntemplate\
    \ <class T, int SZ> struct LazySeg {\n\tT sum[2 * SZ], lazy[2 * SZ];\n\tLazySeg()\
    \ {\n\t\tfor (int i = 0; i < 2 * SZ; i++) {\n\t\t\tsum[i] = 0;\n\t\t\tlazy[i]\
    \ = 0;\n\t\t}\n\t}\n\tvoid push(int ind, int L, int R) {\n\t\tsum[ind] += (R -\
    \ L + 1) * lazy[ind];\n\t\tif (L != R) {\n\t\t\tlazy[2 * ind] += lazy[ind];\n\t\
    \t\tlazy[2 * ind + 1] += lazy[ind];\n\t\t}\n\t\tlazy[ind] = 0;\n\t}\n\tvoid pull(int\
    \ ind) {\n\t\tsum[ind] = sum[2 * ind] + sum[2 * ind + 1];\n\t}\n\tvoid build()\
    \ {\n\t\tfor (int i = SZ - 1; i >= 1; i--) {\n\t\t\tpull(i);\n\t\t}\n\t}\n\tvoid\
    \ upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = SZ - 1) {\n\t\tpush(ind,\
    \ L, R);\n\t\tif (hi < L || R < lo) return ;\n\t\tif (lo <= L && R <= hi) {\n\t\
    \t\tlazy[ind] = inc;\n\t\t\tpush(ind, L, R);\n\t\t\treturn;\n\t\t}\n\t\tint M\
    \ = (L + R) / 2;\n\t\tupd(lo, hi, inc, 2 * ind, L, M);\n\t\tupd(lo, hi, inc, 2\
    \ * ind + 1, M + 1, R);\n\t\tpull(ind);\n\t}\n\tT qsum(int lo, int hi, int ind\
    \ = 1, int L = 0, int R = SZ - 1) {\n\t\tpush(ind, L, R);\n\t\tif (lo > R || L\
    \ > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint M = (L\
    \ + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1,\
    \ M + 1, R);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/unused/array_lazy_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/unused/array_lazy_segment_tree.cpp
layout: document
redirect_from:
- /library/library/unused/array_lazy_segment_tree.cpp
- /library/library/unused/array_lazy_segment_tree.cpp.html
title: library/unused/array_lazy_segment_tree.cpp
---
