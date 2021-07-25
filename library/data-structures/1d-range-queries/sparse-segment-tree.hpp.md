---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/sparse-segment-tree.test.cpp
    title: test/sparse-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\n// bump allocator\n\nstatic char buf[450 << 20];\nvoid* operator\
    \ new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s < i);\n\treturn\
    \ (void*)&buf[i -= s];\n}\nvoid operator delete(void*) {}\n\nconst int SZ = 1\
    \ << 30;\n\ntemplate <class T> struct Node {\n\tT val = 0; \n\tNode<T> *c[2];\n\
    \tNode() { c[0] = c[1] = NULL; }\n\n\tvoid upd(int ind, T v, int L = 0, int R\
    \ = SZ - 1) { // add v\n\t\tif (L == ind && R == ind) { val += v; return; }\n\t\
    \tint M = (L + R) / 2;\n\t\tif (ind <= M) {\n\t\t\tif (!c[0]) c[0] = new Node();\n\
    \t\t\tc[0]->upd(ind, v, L, M);\n\t\t} else {\n\t\t\tif (!c[1]) c[1] = new Node();\n\
    \t\t\tc[1]->upd(ind, v, M + 1, R);\n\t\t}\n\t\tval = 0; \n\t\tfor (int i = 0;\
    \ i < 2; i++)\n\t\t\tif (c[i]) val += c[i]->val;\n\t}\n\n\tT query(int lo, int\
    \ hi, int L = 0, int R = SZ - 1) { // query sum of segment\n\t\tif (hi < L ||\
    \ R < lo) return 0;\n\t\tif (lo <= L && R <= hi) return val;\n\t\tint M = (L +\
    \ R) / 2; \n\t\tT res = 0;\n\t\tif (c[0]) res += c[0]->query(lo, hi, L, M);\n\t\
    \tif (c[1]) res += c[1]->query(lo, hi, M + 1, R);\n\t\treturn res;\n\t}\n\n\t\
    void update_2d(int ind, Node *c0, Node *c1, int L = 0, int R = SZ - 1) { // for\
    \ 2D segtree\n\t\tif (L != R)\t {\n\t\t\tint M = (L + R) / 2;\n\t\t\tif (ind <=\
    \ M) {\n\t\t\t\tif (!c[0]) c[0] = new Node();\n\t\t\t\tc[0]->update_2d(ind, (c0\
    \ ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\n\t\t\t} else {\n\t\t\t\t\
    if (!c[1]) c[1] = new Node();\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1] : NULL),\
    \ (c1 ? c1->c[1] : NULL), M + 1, R);\n\t\t\t}\n\t\t} \n\t\tval = (c0 ? c0->val\
    \ : 0) + (c1 ? c1->val : 0);\n\t}\n};\n"
  code: "#pragma once\n\n// bump allocator\n\nstatic char buf[450 << 20];\nvoid* operator\
    \ new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s < i);\n\treturn\
    \ (void*)&buf[i -= s];\n}\nvoid operator delete(void*) {}\n\nconst int SZ = 1\
    \ << 30;\n\ntemplate <class T> struct Node {\n\tT val = 0; \n\tNode<T> *c[2];\n\
    \tNode() { c[0] = c[1] = NULL; }\n\n\tvoid upd(int ind, T v, int L = 0, int R\
    \ = SZ - 1) { // add v\n\t\tif (L == ind && R == ind) { val += v; return; }\n\t\
    \tint M = (L + R) / 2;\n\t\tif (ind <= M) {\n\t\t\tif (!c[0]) c[0] = new Node();\n\
    \t\t\tc[0]->upd(ind, v, L, M);\n\t\t} else {\n\t\t\tif (!c[1]) c[1] = new Node();\n\
    \t\t\tc[1]->upd(ind, v, M + 1, R);\n\t\t}\n\t\tval = 0; \n\t\tfor (int i = 0;\
    \ i < 2; i++)\n\t\t\tif (c[i]) val += c[i]->val;\n\t}\n\n\tT query(int lo, int\
    \ hi, int L = 0, int R = SZ - 1) { // query sum of segment\n\t\tif (hi < L ||\
    \ R < lo) return 0;\n\t\tif (lo <= L && R <= hi) return val;\n\t\tint M = (L +\
    \ R) / 2; \n\t\tT res = 0;\n\t\tif (c[0]) res += c[0]->query(lo, hi, L, M);\n\t\
    \tif (c[1]) res += c[1]->query(lo, hi, M + 1, R);\n\t\treturn res;\n\t}\n\n\t\
    void update_2d(int ind, Node *c0, Node *c1, int L = 0, int R = SZ - 1) { // for\
    \ 2D segtree\n\t\tif (L != R)\t {\n\t\t\tint M = (L + R) / 2;\n\t\t\tif (ind <=\
    \ M) {\n\t\t\t\tif (!c[0]) c[0] = new Node();\n\t\t\t\tc[0]->update_2d(ind, (c0\
    \ ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\n\t\t\t} else {\n\t\t\t\t\
    if (!c[1]) c[1] = new Node();\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1] : NULL),\
    \ (c1 ? c1->c[1] : NULL), M + 1, R);\n\t\t\t}\n\t\t} \n\t\tval = (c0 ? c0->val\
    \ : 0) + (c1 ? c1->val : 0);\n\t}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:39:13-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/sparse-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/sparse-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/sparse-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
---
