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
  bundledCode: "\n// bump allocator\n\nstatic char buf[450 << 20];\nvoid* operator\
    \ new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s < i);\n\treturn\
    \ (void*)&buf[i -= s];\n}\nvoid operator delete(void*) {}\n\nconst int SZ = (1\
    \ << 17);\n\ntemplate <class T> struct Node {\n\tT val = 0; \n\tNode<T> *c[2];\n\
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
    \ 2D segtree\n\t\tif (L != R) {\n\t\t\tint M = (L + R) / 2;\n\t\t\tif (ind <=\
    \ M) {\n\t\t\t\tif (!c[0]) c[0] = new Node();\n\t\t\t\tc[0]->update_2d(ind, (c0\
    \ ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\n\t\t\t} else {\n\t\t\t\t\
    if (!c[1]) c[1] = new Node();\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1] : NULL),\
    \ (c1 ? c1->c[1] : NULL), M + 1, R);\n\t\t\t}\n\t\t} \n\t\tval = (c0 ? c0->val\
    \ : 0) + (c1 ? c1->val : 0);\n\t}\n};\n\ntemplate <class T> struct Node2D {\n\t\
    Node<T> seg; \n\tNode2D *c[2];\n\n\tNode2D() { c[0] = c[1] = NULL; }\n\n\tvoid\
    \ upd(int x, int y, T v, int L = 0, int R = SZ - 1) { // add v\n\t\tif (L == x\
    \ && R == x) { seg.upd(y, v); return; }\n\t\tint M = (L + R) / 2;\n\t\tif (x <=\
    \ M) {\n\t\t\tif (!c[0]) c[0] = new Node2D();\n\t\t\tc[0]->upd(x, y, v, L, M);\n\
    \t\t} else {\n\t\t\tif (!c[1]) c[1] = new Node2D();\n\t\t\tc[1]->upd(x, y, v,\
    \ M + 1, R);\n\t\t}\n\t\tseg.upd(y, v); // only for addition\n\t\t// seg.update_2d(y,\
    \ (c[0] ? & c[0]->seg : NULL), (c[1] ? & c[1]->seg : NULL));\n\t}\n\n\tT query(int\
    \ x1, int x2, int y1, int y2, int L = 0, int R = SZ - 1) { // query sum of rectangle\n\
    \t\tif (x1 <= L && R <= x2) return seg.query(y1, y2);\n\t\tif (x2 < L || R < x1)\
    \ return 0;\n\t\tint M = (L + R) / 2; \n\t\tT res = 0;\n\t\tif (c[0]) res += c[0]->query(x1,\
    \ x2, y1, y2, L, M);\n\t\tif (c[1]) res += c[1]->query(x1, x2, y1, y2, M + 1,\
    \ R);\n\t\treturn res;\n\t}\n};\n"
  code: "#pragma once\n\n// bump allocator\n\nstatic char buf[450 << 20];\nvoid* operator\
    \ new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s < i);\n\treturn\
    \ (void*)&buf[i -= s];\n}\nvoid operator delete(void*) {}\n\nconst int SZ = (1\
    \ << 17);\n\ntemplate <class T> struct Node {\n\tT val = 0; \n\tNode<T> *c[2];\n\
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
    \ 2D segtree\n\t\tif (L != R) {\n\t\t\tint M = (L + R) / 2;\n\t\t\tif (ind <=\
    \ M) {\n\t\t\t\tif (!c[0]) c[0] = new Node();\n\t\t\t\tc[0]->update_2d(ind, (c0\
    \ ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL), L, M);\n\t\t\t} else {\n\t\t\t\t\
    if (!c[1]) c[1] = new Node();\n\t\t\t\tc[1]->update_2d(ind, (c0 ? c0->c[1] : NULL),\
    \ (c1 ? c1->c[1] : NULL), M + 1, R);\n\t\t\t}\n\t\t} \n\t\tval = (c0 ? c0->val\
    \ : 0) + (c1 ? c1->val : 0);\n\t}\n};\n\ntemplate <class T> struct Node2D {\n\t\
    Node<T> seg; \n\tNode2D *c[2];\n\n\tNode2D() { c[0] = c[1] = NULL; }\n\n\tvoid\
    \ upd(int x, int y, T v, int L = 0, int R = SZ - 1) { // add v\n\t\tif (L == x\
    \ && R == x) { seg.upd(y, v); return; }\n\t\tint M = (L + R) / 2;\n\t\tif (x <=\
    \ M) {\n\t\t\tif (!c[0]) c[0] = new Node2D();\n\t\t\tc[0]->upd(x, y, v, L, M);\n\
    \t\t} else {\n\t\t\tif (!c[1]) c[1] = new Node2D();\n\t\t\tc[1]->upd(x, y, v,\
    \ M + 1, R);\n\t\t}\n\t\tseg.upd(y, v); // only for addition\n\t\t// seg.update_2d(y,\
    \ (c[0] ? & c[0]->seg : NULL), (c[1] ? & c[1]->seg : NULL));\n\t}\n\n\tT query(int\
    \ x1, int x2, int y1, int y2, int L = 0, int R = SZ - 1) { // query sum of rectangle\n\
    \t\tif (x1 <= L && R <= x2) return seg.query(y1, y2);\n\t\tif (x2 < L || R < x1)\
    \ return 0;\n\t\tint M = (L + R) / 2; \n\t\tT res = 0;\n\t\tif (c[0]) res += c[0]->query(x1,\
    \ x2, y1, y2, L, M);\n\t\tif (c[1]) res += c[1]->query(x1, x2, y1, y2, M + 1,\
    \ R);\n\t\treturn res;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:49:44-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
- /library/library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp.html
title: library/data-structures/2d-range-queries/2d-sparse-segment-tree.hpp
---
