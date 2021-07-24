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
  bundledCode: "\ntemplate <class T> struct SegmentTree {\n\tconst T ID = 0;\n\n\t\
    T comb(T a, T b) {\n\t\treturn a + b;\n\t}\n\n\tint n;\n\tstd::vector<T> seg;\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tseg.assign(2 * n, ID);\n\t}\n\n\tvoid\
    \ pull(int p) {\n\t\tseg[p] = comb(seg[2 * p], seg[2 * p + 1]);\n\t}\n\n\tvoid\
    \ upd(int p, T val) {\n\t\tseg[p += n] = val;\n\t\tfor (p /= 2; p; p /= 2) pull(p);\n\
    \t}\n\n\tvoid add(int p, T val) {\n\t\tseg[p += n] += val;\n\t\tfor (p /= 2; p;\
    \ p /= 2) pull(p);\n\t}\n\n\tT query(int l, int r) {\n\t\tT ra = ID, rb = ID;\n\
    \t\tfor (l += n, r += n + 1; l < r; l /= 2, r /= 2) {\n\t\t\tif (l & 1) ra = comb(ra,\
    \ seg[l++]);\n\t\t\tif (r & 1) rb = comb(seg[--r], rb);\n\t\t}\n\t\treturn comb(ra,\
    \ rb);\n\t}\n};\n\nint main() {\n\treturn 0;\n}\n"
  code: "#pragma once\n\ntemplate <class T> struct SegmentTree {\n\tconst T ID = 0;\n\
    \n\tT comb(T a, T b) {\n\t\treturn a + b;\n\t}\n\n\tint n;\n\tstd::vector<T> seg;\n\
    \n\tvoid init(int _n) {\n\t\tn = _n;\n\t\tseg.assign(2 * n, ID);\n\t}\n\n\tvoid\
    \ pull(int p) {\n\t\tseg[p] = comb(seg[2 * p], seg[2 * p + 1]);\n\t}\n\n\tvoid\
    \ upd(int p, T val) {\n\t\tseg[p += n] = val;\n\t\tfor (p /= 2; p; p /= 2) pull(p);\n\
    \t}\n\n\tvoid add(int p, T val) {\n\t\tseg[p += n] += val;\n\t\tfor (p /= 2; p;\
    \ p /= 2) pull(p);\n\t}\n\n\tT query(int l, int r) {\n\t\tT ra = ID, rb = ID;\n\
    \t\tfor (l += n, r += n + 1; l < r; l /= 2, r /= 2) {\n\t\t\tif (l & 1) ra = comb(ra,\
    \ seg[l++]);\n\t\t\tif (r & 1) rb = comb(seg[--r], rb);\n\t\t}\n\t\treturn comb(ra,\
    \ rb);\n\t}\n};\n\nint main() {\n\treturn 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/point-update-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/point-update-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
---
