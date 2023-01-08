---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class T>\r\nstruct SegmentTree {\r\n  const T ID = 0;\r\
    \n\r\n  T comb(T a, T b) { return a + b; }\r\n\r\n  int n;\r\n  std::vector<T>\
    \ seg;\r\n\r\n  SegmentTree() = default;\r\n  SegmentTree(int n) { init(n); }\r\
    \n\r\n  void init(int _n) {\r\n    n = _n;\r\n    seg.assign(2 * n, ID);\r\n \
    \ }\r\n\r\n  void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }\r\
    \n\r\n  void upd(int p, T val) {\r\n    seg[p += n] = val;\r\n    for (p /= 2;\
    \ p; p /= 2) pull(p);\r\n  }\r\n\r\n  void add(int p, T val) {\r\n    seg[p +=\
    \ n] += val;\r\n    for (p /= 2; p; p /= 2) pull(p);\r\n  }\r\n\r\n  T query(int\
    \ l, int r) {\r\n    T ra = ID, rb = ID;\r\n    for (l += n, r += n + 1; l < r;\
    \ l /= 2, r /= 2) {\r\n      if (l & 1) ra = comb(ra, seg[l++]);\r\n      if (r\
    \ & 1) rb = comb(seg[--r], rb);\r\n    }\r\n    return comb(ra, rb);\r\n  }\r\n\
    };\n"
  code: "#pragma once\r\n\r\ntemplate <class T>\r\nstruct SegmentTree {\r\n  const\
    \ T ID = 0;\r\n\r\n  T comb(T a, T b) { return a + b; }\r\n\r\n  int n;\r\n  std::vector<T>\
    \ seg;\r\n\r\n  SegmentTree() = default;\r\n  SegmentTree(int n) { init(n); }\r\
    \n\r\n  void init(int _n) {\r\n    n = _n;\r\n    seg.assign(2 * n, ID);\r\n \
    \ }\r\n\r\n  void pull(int p) { seg[p] = comb(seg[2 * p], seg[2 * p + 1]); }\r\
    \n\r\n  void upd(int p, T val) {\r\n    seg[p += n] = val;\r\n    for (p /= 2;\
    \ p; p /= 2) pull(p);\r\n  }\r\n\r\n  void add(int p, T val) {\r\n    seg[p +=\
    \ n] += val;\r\n    for (p /= 2; p; p /= 2) pull(p);\r\n  }\r\n\r\n  T query(int\
    \ l, int r) {\r\n    T ra = ID, rb = ID;\r\n    for (l += n, r += n + 1; l < r;\
    \ l /= 2, r /= 2) {\r\n      if (l & 1) ra = comb(ra, seg[l++]);\r\n      if (r\
    \ & 1) rb = comb(seg[--r], rb);\r\n    }\r\n    return comb(ra, rb);\r\n  }\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
  requiredBy: []
  timestamp: '2023-01-08 15:53:16-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/point-update-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/point-update-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
---
