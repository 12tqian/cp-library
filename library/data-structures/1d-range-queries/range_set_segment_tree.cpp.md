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
  bundledCode: '#line 1 "library/data-structures/1d-range-queries/range_set_segment_tree.cpp"

    '
  code: "#include <bits/stdc++.h>\n\ntemplate <class T> struct RangeSetSeg {\n\tconst\
    \ T UNUSED = -1;\n\tstd::vector<T> sum, lazy;\n\tint sz;\n\n\t// lazy stores what\
    \ to set to\n\tvoid init(int sz_) {\n\t\tsz = 1;\n\t\twhile (sz < sz_) sz *= 2;\n\
    \t\tsum.assign(2 * sz, 0);\n\t\tlazy.assign(2 * sz, UNUSED);\n\t}\n\n\tvoid push(int\
    \ ind, int L, int R) {\n\t\tif (L != R) {\n\t\t\tif(lazy[ind] != UNUSED){\n\t\t\
    \t\tfor(int i = 0; i < 2; i++){\n\t\t\t\t\tlazy[2 * ind + i] = lazy[ind];\n\t\t\
    \t\t}\n\t\t\t}\n\t\t}\n\t\tif (lazy[ind] != UNUSED) sum[ind] = (R - L + 1) * lazy[ind];\n\
    \t\tlazy[ind] = UNUSED;\n\t}\n\n\tvoid pull(int ind) { sum[ind] = sum[2 * ind]\
    \ + sum[2 * ind + 1]; }\n\n\tvoid range_set(int lo, int hi, T inc, int ind = 1,\
    \ int L = 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\
    \tif (hi < L || R < lo) return;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tlazy[ind]\
    \ = inc;\n\t\t\tpush(ind, L, R); return;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\t\
    range_set(lo, hi, inc, 2 * ind, L, M); range_set(lo, hi, inc, 2 * ind + 1, M +\
    \ 1, R);\n\t\tpull(ind);\n\t}\n\n\tT qsum(int lo, int hi, int ind = 1, int L =\
    \ 0, int R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R); if (lo > R\
    \ || L > hi) return 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint\
    \ M = (L + R) / 2;\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 *\
    \ ind + 1, M + 1, R);\n\t}\n};\n\nint main() {\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/range_set_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-07-10 12:34:57-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/range_set_segment_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/range_set_segment_tree.cpp
- /library/library/data-structures/1d-range-queries/range_set_segment_tree.cpp.html
title: library/data-structures/1d-range-queries/range_set_segment_tree.cpp
---
