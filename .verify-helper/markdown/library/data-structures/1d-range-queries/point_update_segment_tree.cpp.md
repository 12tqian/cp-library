---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/point_update_segment_tree.cpp\"\
    \n#include<bits/stdc++.h>\r\n\r\ntemplate <class T> struct SegTree {\r\n    const\
    \ T ID = 0;\r\n    T comb(T a, T b) {\r\n        return a + b;\r\n    }\r\n  \
    \  int n;\r\n    std::vector<T> seg;\r\n    void init(int _n) {\r\n        n =\
    \ _n;\r\n        seg.assign(2 * n, ID);\r\n    }\r\n    void pull(int p) {\r\n\
    \        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);\r\n    }\r\n    void upd(int\
    \ p, T val) {\r\n        seg[p += n] = val;\r\n        for (p /= 2; p; p /= 2)\
    \ pull(p);\r\n    }\r\n    void add(int p, T val) {\r\n        seg[p += n] +=\
    \ val;\r\n        for (p /= 2; p; p /= 2) pull(p);\r\n    }\r\n    T query(int\
    \ l, int r) {\r\n        T ra = ID, rb = ID;\r\n        for (l += n, r += n +\
    \ 1; l < r; l /= 2, r /= 2) {\r\n            if (l & 1) ra = comb(ra, seg[l++]);\r\
    \n            if (r & 1) rb = comb(seg[--r], rb);\r\n        }\r\n        return\
    \ comb(ra, rb);\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\ntemplate <class T> struct SegTree {\r\n  \
    \  const T ID = 0;\r\n    T comb(T a, T b) {\r\n        return a + b;\r\n    }\r\
    \n    int n;\r\n    std::vector<T> seg;\r\n    void init(int _n) {\r\n       \
    \ n = _n;\r\n        seg.assign(2 * n, ID);\r\n    }\r\n    void pull(int p) {\r\
    \n        seg[p] = comb(seg[2 * p], seg[2 * p + 1]);\r\n    }\r\n    void upd(int\
    \ p, T val) {\r\n        seg[p += n] = val;\r\n        for (p /= 2; p; p /= 2)\
    \ pull(p);\r\n    }\r\n    void add(int p, T val) {\r\n        seg[p += n] +=\
    \ val;\r\n        for (p /= 2; p; p /= 2) pull(p);\r\n    }\r\n    T query(int\
    \ l, int r) {\r\n        T ra = ID, rb = ID;\r\n        for (l += n, r += n +\
    \ 1; l < r; l /= 2, r /= 2) {\r\n            if (l & 1) ra = comb(ra, seg[l++]);\r\
    \n            if (r & 1) rb = comb(seg[--r], rb);\r\n        }\r\n        return\
    \ comb(ra, rb);\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/point_update_segment_tree.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:53:10-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/point_update_segment_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/point_update_segment_tree.cpp
- /library/library/data-structures/1d-range-queries/point_update_segment_tree.cpp.html
title: library/data-structures/1d-range-queries/point_update_segment_tree.cpp
---
