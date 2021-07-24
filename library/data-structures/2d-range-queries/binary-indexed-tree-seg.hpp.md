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
  bundledCode: "#include <bits/stdc++.h>\n\n// bump allocator\n\nstatic char buf[450\
    \ << 20];\nvoid* operator new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\t\
    assert(s < i);\n\treturn (void*)&buf[i -= s];\n}\nvoid operator delete(void*)\
    \ {}\n\nconst int SZ = (1 << 18);\n\n// [0, SZ - 1) for x axis, [0, SZ) for y\
    \ axis\ntemplate <class T> struct Node {\n\tT val = 0; \n\tNode<T> *c[2];\n\t\
    Node() { c[0] = c[1] = NULL; }\n\n\tvoid upd(int ind, T v, int L = 0, int R =\
    \ SZ - 1) { // add v\n\t\tif (L == ind && R == ind) { val += v; return; }\n\t\t\
    int M = (L + R) / 2;\n\t\tif (ind <= M) {\n\t\t\tif (!c[0]) c[0] = new Node();\n\
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
    \ : 0) + (c1 ? c1->val : 0);\n\t}\n};\n\ntemplate <class T> struct BITSeg { //\
    \ 0-indexed implicitly\n\tstd::vector<Node<T>> seg;\n\n\tBITSeg() { \n\t\tseg.resize(SZ\
    \ + 1);\n\t\tfor (int i = 0; i < SZ; i++)\n\t\t\tseg[i] = Node<T>();\n\t}\n\n\t\
    void upd(int x, int y, int v) { // add v\n\t\tx++;\n\t\tfor (; x < SZ + 1; x +=\
    \ x & -x) \n\t\t\tseg[x].upd(y, v); \n\t}\n\n\tT query(int x, int y1, int y2)\
    \ {\n\t\tif (x <= 0) return 0;\n\t\tT res = 0; \n\t\tfor (; x; x -= x & -x) \n\
    \t\t\tres += seg[x].query(y1, y2);\n\t\treturn res; \n\t}\n\n\tT query(int x1,\
    \ int x2, int y1, int y2) { // query sum of rectangle\n\t\tx1++, x2++;\n\t\treturn\
    \ query(x2, y1, y2) - query(x1 - 1, y1, y2); \n\t}\n};\n\n"
  code: "#include <bits/stdc++.h>\n\n// bump allocator\n\nstatic char buf[450 << 20];\n\
    void* operator new(size_t s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s <\
    \ i);\n\treturn (void*)&buf[i -= s];\n}\nvoid operator delete(void*) {}\n\nconst\
    \ int SZ = (1 << 18);\n\n// [0, SZ - 1) for x axis, [0, SZ) for y axis\ntemplate\
    \ <class T> struct Node {\n\tT val = 0; \n\tNode<T> *c[2];\n\tNode() { c[0] =\
    \ c[1] = NULL; }\n\n\tvoid upd(int ind, T v, int L = 0, int R = SZ - 1) { // add\
    \ v\n\t\tif (L == ind && R == ind) { val += v; return; }\n\t\tint M = (L + R)\
    \ / 2;\n\t\tif (ind <= M) {\n\t\t\tif (!c[0]) c[0] = new Node();\n\t\t\tc[0]->upd(ind,\
    \ v, L, M);\n\t\t} else {\n\t\t\tif (!c[1]) c[1] = new Node();\n\t\t\tc[1]->upd(ind,\
    \ v, M + 1, R);\n\t\t}\n\t\tval = 0; \n\t\tfor (int i = 0; i < 2; i++)\n\t\t\t\
    if (c[i]) val += c[i]->val;\n\t}\n\n\tT query(int lo, int hi, int L = 0, int R\
    \ = SZ - 1) { // query sum of segment\n\t\tif (hi < L || R < lo) return 0;\n\t\
    \tif (lo <= L && R <= hi) return val;\n\t\tint M = (L + R) / 2; \n\t\tT res =\
    \ 0;\n\t\tif (c[0]) res += c[0]->query(lo, hi, L, M);\n\t\tif (c[1]) res += c[1]->query(lo,\
    \ hi, M + 1, R);\n\t\treturn res;\n\t}\n\n\tvoid update_2d(int ind, Node *c0,\
    \ Node *c1, int L = 0, int R = SZ - 1) { // for 2D segtree\n\t\tif (L != R) {\n\
    \t\t\tint M = (L + R) / 2;\n\t\t\tif (ind <= M) {\n\t\t\t\tif (!c[0]) c[0] = new\
    \ Node();\n\t\t\t\tc[0]->update_2d(ind, (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0]\
    \ : NULL), L, M);\n\t\t\t} else {\n\t\t\t\tif (!c[1]) c[1] = new Node();\n\t\t\
    \t\tc[1]->update_2d(ind, (c0 ? c0->c[1] : NULL), (c1 ? c1->c[1] : NULL), M + 1,\
    \ R);\n\t\t\t}\n\t\t} \n\t\tval = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\n\t\
    }\n};\n\ntemplate <class T> struct BITSeg { // 0-indexed implicitly\n\tstd::vector<Node<T>>\
    \ seg;\n\n\tBITSeg() { \n\t\tseg.resize(SZ + 1);\n\t\tfor (int i = 0; i < SZ;\
    \ i++)\n\t\t\tseg[i] = Node<T>();\n\t}\n\n\tvoid upd(int x, int y, int v) { //\
    \ add v\n\t\tx++;\n\t\tfor (; x < SZ + 1; x += x & -x) \n\t\t\tseg[x].upd(y, v);\
    \ \n\t}\n\n\tT query(int x, int y1, int y2) {\n\t\tif (x <= 0) return 0;\n\t\t\
    T res = 0; \n\t\tfor (; x; x -= x & -x) \n\t\t\tres += seg[x].query(y1, y2);\n\
    \t\treturn res; \n\t}\n\n\tT query(int x1, int x2, int y1, int y2) { // query\
    \ sum of rectangle\n\t\tx1++, x2++;\n\t\treturn query(x2, y1, y2) - query(x1 -\
    \ 1, y1, y2); \n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/binary-indexed-tree-seg.hpp
  requiredBy: []
  timestamp: '2021-07-24 19:26:06-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/binary-indexed-tree-seg.hpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/binary-indexed-tree-seg.hpp
- /library/library/data-structures/2d-range-queries/binary-indexed-tree-seg.hpp.html
title: library/data-structures/2d-range-queries/binary-indexed-tree-seg.hpp
---
