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
    \n#include<bits/stdc++.h>\n\ntemplate <class T> struct SegmentTree {\n    const\
    \ T ID = 0;\n\n    T comb(T a, T b) {\n        return a + b;\n    }\n\n    int\
    \ n;\n    std::vector<T> seg;\n\n    void init(int _n) {\n        n = _n;\n  \
    \      seg.assign(2 * n, ID);\n    }\n\n    void pull(int p) {\n        seg[p]\
    \ = comb(seg[2 * p], seg[2 * p + 1]);\n    }\n\n    void upd(int p, T val) {\n\
    \        seg[p += n] = val;\n        for (p /= 2; p; p /= 2) pull(p);\n    }\n\
    \n    void add(int p, T val) {\n        seg[p += n] += val;\n        for (p /=\
    \ 2; p; p /= 2) pull(p);\n    }\n\n    T query(int l, int r) {\n        T ra =\
    \ ID, rb = ID;\n        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {\n  \
    \          if (l & 1) ra = comb(ra, seg[l++]);\n            if (r & 1) rb = comb(seg[--r],\
    \ rb);\n        }\n        return comb(ra, rb);\n    }\n};\n\nint main() {\n \
    \   return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\ntemplate <class T> struct SegmentTree {\n    const\
    \ T ID = 0;\n\n    T comb(T a, T b) {\n        return a + b;\n    }\n\n    int\
    \ n;\n    std::vector<T> seg;\n\n    void init(int _n) {\n        n = _n;\n  \
    \      seg.assign(2 * n, ID);\n    }\n\n    void pull(int p) {\n        seg[p]\
    \ = comb(seg[2 * p], seg[2 * p + 1]);\n    }\n\n    void upd(int p, T val) {\n\
    \        seg[p += n] = val;\n        for (p /= 2; p; p /= 2) pull(p);\n    }\n\
    \n    void add(int p, T val) {\n        seg[p += n] += val;\n        for (p /=\
    \ 2; p; p /= 2) pull(p);\n    }\n\n    T query(int l, int r) {\n        T ra =\
    \ ID, rb = ID;\n        for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {\n  \
    \          if (l & 1) ra = comb(ra, seg[l++]);\n            if (r & 1) rb = comb(seg[--r],\
    \ rb);\n        }\n        return comb(ra, rb);\n    }\n};\n\nint main() {\n \
    \   return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/point_update_segment_tree.cpp
  requiredBy: []
  timestamp: '2021-01-09 11:49:29-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/point_update_segment_tree.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/point_update_segment_tree.cpp
- /library/library/data-structures/1d-range-queries/point_update_segment_tree.cpp.html
title: library/data-structures/1d-range-queries/point_update_segment_tree.cpp
---
