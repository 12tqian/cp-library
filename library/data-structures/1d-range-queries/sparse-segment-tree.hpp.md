---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n// bump allocator\r\n\r\nstatic char buf[450 << 20];\r\nvoid*\
    \ operator new(size_t s) {\r\n\tstatic size_t i = sizeof buf;\r\n\tassert(s <\
    \ i);\r\n\treturn (void*)&buf[i -= s];\r\n}\r\nvoid operator delete(void*) {}\r\
    \n\r\nconst int SZ = 1 << 30;\r\n\r\ntemplate <class T> struct Node {\r\n\tT val\
    \ = 0; \r\n\tNode<T>* c[2];\r\n\tNode() { c[0] = c[1] = NULL; }\r\n\r\n\tvoid\
    \ upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\r\n\t\tif (L == ind\
    \ && R == ind) { val += v; return; }\r\n\t\tint M = (L + R) / 2;\r\n\t\tif (ind\
    \ <= M) {\r\n\t\t\tif (!c[0]) c[0] = new Node();\r\n\t\t\tc[0]->upd(ind, v, L,\
    \ M);\r\n\t\t} else {\r\n\t\t\tif (!c[1]) c[1] = new Node();\r\n\t\t\tc[1]->upd(ind,\
    \ v, M + 1, R);\r\n\t\t}\r\n\t\tval = 0; \r\n\t\tfor (int i = 0; i < 2; i++)\r\
    \n\t\t\tif (c[i]) val += c[i]->val;\r\n\t}\r\n\r\n\tT query(int lo, int hi, int\
    \ L = 0, int R = SZ - 1) { // query sum of segment\r\n\t\tif (hi < L || R < lo)\
    \ return 0;\r\n\t\tif (lo <= L && R <= hi) return val;\r\n\t\tint M = (L + R)\
    \ / 2; \r\n\t\tT res = 0;\r\n\t\tif (c[0]) res += c[0]->query(lo, hi, L, M);\r\
    \n\t\tif (c[1]) res += c[1]->query(lo, hi, M + 1, R);\r\n\t\treturn res;\r\n\t\
    }\r\n\r\n\tvoid update_2d(int ind, Node* c0, Node* c1, int L = 0, int R = SZ -\
    \ 1) { // for 2D segtree\r\n\t\tif (L != R)\t {\r\n\t\t\tint M = (L + R) / 2;\r\
    \n\t\t\tif (ind <= M) {\r\n\t\t\t\tif (!c[0]) c[0] = new Node();\r\n\t\t\t\tc[0]->update_2d(ind,\
    \ (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\r\n\t\t\t} else {\r\n\
    \t\t\t\tif (!c[1]) c[1] = new Node();\r\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1]\
    \ : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);\r\n\t\t\t}\r\n\t\t} \r\n\t\tval\
    \ = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n\t}\r\n};\n"
  code: "#pragma once\r\n\r\n// bump allocator\r\n\r\nstatic char buf[450 << 20];\r\
    \nvoid* operator new(size_t s) {\r\n\tstatic size_t i = sizeof buf;\r\n\tassert(s\
    \ < i);\r\n\treturn (void*)&buf[i -= s];\r\n}\r\nvoid operator delete(void*) {}\r\
    \n\r\nconst int SZ = 1 << 30;\r\n\r\ntemplate <class T> struct Node {\r\n\tT val\
    \ = 0; \r\n\tNode<T>* c[2];\r\n\tNode() { c[0] = c[1] = NULL; }\r\n\r\n\tvoid\
    \ upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\r\n\t\tif (L == ind\
    \ && R == ind) { val += v; return; }\r\n\t\tint M = (L + R) / 2;\r\n\t\tif (ind\
    \ <= M) {\r\n\t\t\tif (!c[0]) c[0] = new Node();\r\n\t\t\tc[0]->upd(ind, v, L,\
    \ M);\r\n\t\t} else {\r\n\t\t\tif (!c[1]) c[1] = new Node();\r\n\t\t\tc[1]->upd(ind,\
    \ v, M + 1, R);\r\n\t\t}\r\n\t\tval = 0; \r\n\t\tfor (int i = 0; i < 2; i++)\r\
    \n\t\t\tif (c[i]) val += c[i]->val;\r\n\t}\r\n\r\n\tT query(int lo, int hi, int\
    \ L = 0, int R = SZ - 1) { // query sum of segment\r\n\t\tif (hi < L || R < lo)\
    \ return 0;\r\n\t\tif (lo <= L && R <= hi) return val;\r\n\t\tint M = (L + R)\
    \ / 2; \r\n\t\tT res = 0;\r\n\t\tif (c[0]) res += c[0]->query(lo, hi, L, M);\r\
    \n\t\tif (c[1]) res += c[1]->query(lo, hi, M + 1, R);\r\n\t\treturn res;\r\n\t\
    }\r\n\r\n\tvoid update_2d(int ind, Node* c0, Node* c1, int L = 0, int R = SZ -\
    \ 1) { // for 2D segtree\r\n\t\tif (L != R)\t {\r\n\t\t\tint M = (L + R) / 2;\r\
    \n\t\t\tif (ind <= M) {\r\n\t\t\t\tif (!c[0]) c[0] = new Node();\r\n\t\t\t\tc[0]->update_2d(ind,\
    \ (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\r\n\t\t\t} else {\r\n\
    \t\t\t\tif (!c[1]) c[1] = new Node();\r\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1]\
    \ : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);\r\n\t\t\t}\r\n\t\t} \r\n\t\tval\
    \ = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n\t}\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/sparse-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/sparse-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
---
