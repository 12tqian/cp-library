---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class T> struct SegmentTree {\n\tSegmentTree<T>* left,\
    \ * right;\n\tT sum, lazy;\n\n\tSegmentTree(int l, int r) {\n\t\tlazy = 0;\n\t\
    \tif (l == r) {\n\t\t\tsum = 0;\n\t\t} else {\n\t\t\tint m = (l + r) >> 1;\n\t\
    \t\tleft = new SegmentTree<T>(l, m);\n\t\t\tright = new SegmentTree<T>(m + 1,\
    \ r);\n\t\t\tpull();\n\t\t}\n\t}\n\n\tvoid pull() {\n\t\tsum = left->sum + right->sum;\n\
    \t}\n\n\tvoid push(int l, int r) {\n\t\tsum += (r - l + 1) * lazy;\n\t\tif (l\
    \ != r) {\n\t\t\tleft->lazy += lazy;\n\t\t\tright->lazy += lazy;\n\t\t}\n\t\t\
    lazy = 0;\n\t}\n\n\tvoid update(int lo, int hi, T inc, int l, int r) {\n\t\tpush(l,\
    \ r);\n\t\tif (r < lo || hi < l) {\n\t\t\treturn;\n\t\t} else if (lo <= l && r\
    \ <= hi) {\n\t\t\tlazy = inc;\n\t\t\tpush(l, r);\n\t\t} else {\n\t\t\tint m =\
    \ (l + r) >> 1;\n\t\t\tleft->update(lo, hi, inc, l, m);\n\t\t\tright->update(lo,\
    \ hi, inc, m + 1, r);\n\t\t\tpull();\n\t\t}\n\t}\n\n\tT query(int lo, int hi,\
    \ int l, int r) {\n\t\tpush(l, r);\n\t\tif (r < lo || hi < l) {\n\t\t\treturn\
    \ 0;\n\t\t} else if (lo <= l && r <= hi) {\n\t\t\treturn sum;\n\t\t} else {\n\t\
    \t\tint m = (l + r) >> 1;\n\t\t\treturn left->query(lo, hi, l, m) + right->query(lo,\
    \ hi, m + 1, r);\n\t\t}\n\t}\n};\n"
  code: "#pragma once\n\ntemplate <class T> struct SegmentTree {\n\tSegmentTree<T>*\
    \ left, * right;\n\tT sum, lazy;\n\n\tSegmentTree(int l, int r) {\n\t\tlazy =\
    \ 0;\n\t\tif (l == r) {\n\t\t\tsum = 0;\n\t\t} else {\n\t\t\tint m = (l + r) >>\
    \ 1;\n\t\t\tleft = new SegmentTree<T>(l, m);\n\t\t\tright = new SegmentTree<T>(m\
    \ + 1, r);\n\t\t\tpull();\n\t\t}\n\t}\n\n\tvoid pull() {\n\t\tsum = left->sum\
    \ + right->sum;\n\t}\n\n\tvoid push(int l, int r) {\n\t\tsum += (r - l + 1) *\
    \ lazy;\n\t\tif (l != r) {\n\t\t\tleft->lazy += lazy;\n\t\t\tright->lazy += lazy;\n\
    \t\t}\n\t\tlazy = 0;\n\t}\n\n\tvoid update(int lo, int hi, T inc, int l, int r)\
    \ {\n\t\tpush(l, r);\n\t\tif (r < lo || hi < l) {\n\t\t\treturn;\n\t\t} else if\
    \ (lo <= l && r <= hi) {\n\t\t\tlazy = inc;\n\t\t\tpush(l, r);\n\t\t} else {\n\
    \t\t\tint m = (l + r) >> 1;\n\t\t\tleft->update(lo, hi, inc, l, m);\n\t\t\tright->update(lo,\
    \ hi, inc, m + 1, r);\n\t\t\tpull();\n\t\t}\n\t}\n\n\tT query(int lo, int hi,\
    \ int l, int r) {\n\t\tpush(l, r);\n\t\tif (r < lo || hi < l) {\n\t\t\treturn\
    \ 0;\n\t\t} else if (lo <= l && r <= hi) {\n\t\t\treturn sum;\n\t\t} else {\n\t\
    \t\tint m = (l + r) >> 1;\n\t\t\treturn left->query(lo, hi, l, m) + right->query(lo,\
    \ hi, m + 1, r);\n\t\t}\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-08-16 13:21:48-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
---
