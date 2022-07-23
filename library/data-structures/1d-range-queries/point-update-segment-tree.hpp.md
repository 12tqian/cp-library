---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T> struct SegmentTree {\r\n\tconst T ID = 0;\r\
    \n\r\n\tT comb(T a, T b) {\r\n\t\treturn a + b;\r\n\t}\r\n\r\n\tint n;\r\n\tstd::vector<T>\
    \ seg;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\tseg.assign(2 * n, ID);\r\
    \n\t}\r\n\r\n\tvoid pull(int p) {\r\n\t\tseg[p] = comb(seg[2 * p], seg[2 * p +\
    \ 1]);\r\n\t}\r\n\r\n\tvoid upd(int p, T val) {\r\n\t\tseg[p += n] = val;\r\n\t\
    \tfor (p /= 2; p; p /= 2) pull(p);\r\n\t}\r\n\r\n\tvoid add(int p, T val) {\r\n\
    \t\tseg[p += n] += val;\r\n\t\tfor (p /= 2; p; p /= 2) pull(p);\r\n\t}\r\n\r\n\
    \tT query(int l, int r) {\r\n\t\tT ra = ID, rb = ID;\r\n\t\tfor (l += n, r +=\
    \ n + 1; l < r; l /= 2, r /= 2) {\r\n\t\t\tif (l & 1) ra = comb(ra, seg[l++]);\r\
    \n\t\t\tif (r & 1) rb = comb(seg[--r], rb);\r\n\t\t}\r\n\t\treturn comb(ra, rb);\r\
    \n\t}\r\n};\n"
  code: "#pragma once\r\n\r\ntemplate <class T> struct SegmentTree {\r\n\tconst T\
    \ ID = 0;\r\n\r\n\tT comb(T a, T b) {\r\n\t\treturn a + b;\r\n\t}\r\n\r\n\tint\
    \ n;\r\n\tstd::vector<T> seg;\r\n\r\n\tvoid init(int _n) {\r\n\t\tn = _n;\r\n\t\
    \tseg.assign(2 * n, ID);\r\n\t}\r\n\r\n\tvoid pull(int p) {\r\n\t\tseg[p] = comb(seg[2\
    \ * p], seg[2 * p + 1]);\r\n\t}\r\n\r\n\tvoid upd(int p, T val) {\r\n\t\tseg[p\
    \ += n] = val;\r\n\t\tfor (p /= 2; p; p /= 2) pull(p);\r\n\t}\r\n\r\n\tvoid add(int\
    \ p, T val) {\r\n\t\tseg[p += n] += val;\r\n\t\tfor (p /= 2; p; p /= 2) pull(p);\r\
    \n\t}\r\n\r\n\tT query(int l, int r) {\r\n\t\tT ra = ID, rb = ID;\r\n\t\tfor (l\
    \ += n, r += n + 1; l < r; l /= 2, r /= 2) {\r\n\t\t\tif (l & 1) ra = comb(ra,\
    \ seg[l++]);\r\n\t\t\tif (r & 1) rb = comb(seg[--r], rb);\r\n\t\t}\r\n\t\treturn\
    \ comb(ra, rb);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/point-update-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/point-update-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
---
