---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct SegmentTree {\r\n\tSegmentTree<T>* left,\
    \ * right;\r\n\tT sum, lazy;\r\n\r\n\tSegmentTree(int l, int r) {\r\n\t\tlazy\
    \ = 0;\r\n\t\tif (l == r) {\r\n\t\t\tsum = 0;\r\n\t\t} else {\r\n\t\t\tint m =\
    \ (l + r) >> 1;\r\n\t\t\tleft = new SegmentTree<T>(l, m);\r\n\t\t\tright = new\
    \ SegmentTree<T>(m + 1, r);\r\n\t\t\tpull();\r\n\t\t}\r\n\t}\r\n\r\n\tvoid pull()\
    \ {\r\n\t\tsum = left->sum + right->sum;\r\n\t}\r\n\r\n\tvoid push(int l, int\
    \ r) {\r\n\t\tsum += (r - l + 1) * lazy;\r\n\t\tif (l != r) {\r\n\t\t\tleft->lazy\
    \ += lazy;\r\n\t\t\tright->lazy += lazy;\r\n\t\t}\r\n\t\tlazy = 0;\r\n\t}\r\n\r\
    \n\tvoid update(int lo, int hi, T inc, int l, int r) {\r\n\t\tpush(l, r);\r\n\t\
    \tif (r < lo || hi < l) {\r\n\t\t\treturn;\r\n\t\t} else if (lo <= l && r <= hi)\
    \ {\r\n\t\t\tlazy = inc;\r\n\t\t\tpush(l, r);\r\n\t\t} else {\r\n\t\t\tint m =\
    \ (l + r) >> 1;\r\n\t\t\tleft->update(lo, hi, inc, l, m);\r\n\t\t\tright->update(lo,\
    \ hi, inc, m + 1, r);\r\n\t\t\tpull();\r\n\t\t}\r\n\t}\r\n\r\n\tT query(int lo,\
    \ int hi, int l, int r) {\r\n\t\tpush(l, r);\r\n\t\tif (r < lo || hi < l) {\r\n\
    \t\t\treturn 0;\r\n\t\t} else if (lo <= l && r <= hi) {\r\n\t\t\treturn sum;\r\
    \n\t\t} else {\r\n\t\t\tint m = (l + r) >> 1;\r\n\t\t\treturn left->query(lo,\
    \ hi, l, m) + right->query(lo, hi, m + 1, r);\r\n\t\t}\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct SegmentTree {\r\n\tSegmentTree<T>*\
    \ left, * right;\r\n\tT sum, lazy;\r\n\r\n\tSegmentTree(int l, int r) {\r\n\t\t\
    lazy = 0;\r\n\t\tif (l == r) {\r\n\t\t\tsum = 0;\r\n\t\t} else {\r\n\t\t\tint\
    \ m = (l + r) >> 1;\r\n\t\t\tleft = new SegmentTree<T>(l, m);\r\n\t\t\tright =\
    \ new SegmentTree<T>(m + 1, r);\r\n\t\t\tpull();\r\n\t\t}\r\n\t}\r\n\r\n\tvoid\
    \ pull() {\r\n\t\tsum = left->sum + right->sum;\r\n\t}\r\n\r\n\tvoid push(int\
    \ l, int r) {\r\n\t\tsum += (r - l + 1) * lazy;\r\n\t\tif (l != r) {\r\n\t\t\t\
    left->lazy += lazy;\r\n\t\t\tright->lazy += lazy;\r\n\t\t}\r\n\t\tlazy = 0;\r\n\
    \t}\r\n\r\n\tvoid update(int lo, int hi, T inc, int l, int r) {\r\n\t\tpush(l,\
    \ r);\r\n\t\tif (r < lo || hi < l) {\r\n\t\t\treturn;\r\n\t\t} else if (lo <=\
    \ l && r <= hi) {\r\n\t\t\tlazy = inc;\r\n\t\t\tpush(l, r);\r\n\t\t} else {\r\n\
    \t\t\tint m = (l + r) >> 1;\r\n\t\t\tleft->update(lo, hi, inc, l, m);\r\n\t\t\t\
    right->update(lo, hi, inc, m + 1, r);\r\n\t\t\tpull();\r\n\t\t}\r\n\t}\r\n\r\n\
    \tT query(int lo, int hi, int l, int r) {\r\n\t\tpush(l, r);\r\n\t\tif (r < lo\
    \ || hi < l) {\r\n\t\t\treturn 0;\r\n\t\t} else if (lo <= l && r <= hi) {\r\n\t\
    \t\treturn sum;\r\n\t\t} else {\r\n\t\t\tint m = (l + r) >> 1;\r\n\t\t\treturn\
    \ left->query(lo, hi, l, m) + right->query(lo, hi, m + 1, r);\r\n\t\t}\r\n\t}\r\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
---
