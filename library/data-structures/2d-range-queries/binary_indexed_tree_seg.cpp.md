---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/2d-range-queries/binary_indexed_tree_seg.cpp\"\
    \n#include<bits/stdc++.h>\n// bump allocator\nstatic char buf[450 << 20];\nvoid*\
    \ operator new(size_t s) {\n    static size_t i = sizeof buf;\n    assert(s <\
    \ i);\n    return (void*) & buf[i -= s];\n}\nvoid operator delete(void*) {}\n\
    const int SZ = (1 << 18);\n\n// [0, SZ - 1) queries for each axis\ntemplate <class\
    \ T> struct Node {\n    T val = 0; \n    Node<T>* c[2];\n    Node() { c[0] = c[1]\
    \ = NULL; }\n    void upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\n\
    \        if (L == ind && R == ind) { val += v; return; }\n        int M = (L +\
    \ R) / 2;\n        if (ind <= M) {\n            if (!c[0]) c[0] = new Node();\n\
    \            c[0]->upd(ind, v, L, M);\n        } else {\n            if (!c[1])\
    \ c[1] = new Node();\n            c[1]->upd(ind, v, M + 1, R);\n        }\n  \
    \      val = 0; \n        for (int i = 0; i < 2; i++)\n            if (c[i]) val\
    \ += c[i]->val;\n    }\n    T query(int lo, int hi, int L = 0, int R = SZ - 1)\
    \ { // query sum of segment\n        if (hi < L || R < lo) return 0;\n       \
    \ if (lo <= L && R <= hi) return val;\n        int M = (L + R) / 2; \n       \
    \ T res = 0;\n        if (c[0]) res += c[0]->query(lo, hi, L, M);\n        if\
    \ (c[1]) res += c[1]->query(lo, hi, M + 1, R);\n        return res;\n    }\n \
    \   void update_2d(int ind, Node* c0, Node* c1, int L = 0, int R = SZ - 1) { //\
    \ for 2D segtree\n        if (L != R) {\n            int M = (L + R) / 2;\n  \
    \          if (ind <= M) {\n                if (!c[0]) c[0] = new Node();\n  \
    \              c[0]->update_2d(ind, (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL),\
    \ L, M);\n            } else {\n                if (!c[1]) c[1] = new Node();\n\
    \                c[1]->update_2d(ind, (c0 ? c0->c[1] : NULL), (c1 ? c1->c[1] :\
    \ NULL), M + 1, R);\n            }\n        } \n        val = (c0 ? c0->val :\
    \ 0) + (c1 ? c1->val : 0);\n    }\n};\ntemplate <class T> struct BITSeg { // 0-indexed\
    \ implicitly\n    std::vector<Node<T>> seg;\n    BITSeg() { \n        seg.resize(SZ\
    \ + 1);\n        for (int i = 0; i < SZ; i++)\n            seg[i] = Node<T>();\n\
    \    }\n    void upd(int x, int y, int v) { // add v\n        x++;\n        for\
    \ (; x < SZ + 1; x += x & -x) \n            seg[x].upd(y, v); \n    }\n    T query(int\
    \ x, int y1, int y2) {\n        if (x <= 0) return 0;\n        T res = 0; \n \
    \       for (; x; x -= x & -x) \n            res += seg[x].query(y1, y2);\n  \
    \      return res; \n    }\n    T query(int x1, int x2, int y1, int y2) { // query\
    \ sum of rectangle\n        x1++, x2++;\n        return query(x2, y1, y2) - query(x1\
    \ - 1, y1, y2); \n    }\n};\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n// bump allocator\nstatic char buf[450 << 20];\n\
    void* operator new(size_t s) {\n    static size_t i = sizeof buf;\n    assert(s\
    \ < i);\n    return (void*) & buf[i -= s];\n}\nvoid operator delete(void*) {}\n\
    const int SZ = (1 << 18);\n\n// [0, SZ - 1) queries for each axis\ntemplate <class\
    \ T> struct Node {\n    T val = 0; \n    Node<T>* c[2];\n    Node() { c[0] = c[1]\
    \ = NULL; }\n    void upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\n\
    \        if (L == ind && R == ind) { val += v; return; }\n        int M = (L +\
    \ R) / 2;\n        if (ind <= M) {\n            if (!c[0]) c[0] = new Node();\n\
    \            c[0]->upd(ind, v, L, M);\n        } else {\n            if (!c[1])\
    \ c[1] = new Node();\n            c[1]->upd(ind, v, M + 1, R);\n        }\n  \
    \      val = 0; \n        for (int i = 0; i < 2; i++)\n            if (c[i]) val\
    \ += c[i]->val;\n    }\n    T query(int lo, int hi, int L = 0, int R = SZ - 1)\
    \ { // query sum of segment\n        if (hi < L || R < lo) return 0;\n       \
    \ if (lo <= L && R <= hi) return val;\n        int M = (L + R) / 2; \n       \
    \ T res = 0;\n        if (c[0]) res += c[0]->query(lo, hi, L, M);\n        if\
    \ (c[1]) res += c[1]->query(lo, hi, M + 1, R);\n        return res;\n    }\n \
    \   void update_2d(int ind, Node* c0, Node* c1, int L = 0, int R = SZ - 1) { //\
    \ for 2D segtree\n        if (L != R) {\n            int M = (L + R) / 2;\n  \
    \          if (ind <= M) {\n                if (!c[0]) c[0] = new Node();\n  \
    \              c[0]->update_2d(ind, (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL),\
    \ L, M);\n            } else {\n                if (!c[1]) c[1] = new Node();\n\
    \                c[1]->update_2d(ind, (c0 ? c0->c[1] : NULL), (c1 ? c1->c[1] :\
    \ NULL), M + 1, R);\n            }\n        } \n        val = (c0 ? c0->val :\
    \ 0) + (c1 ? c1->val : 0);\n    }\n};\ntemplate <class T> struct BITSeg { // 0-indexed\
    \ implicitly\n    std::vector<Node<T>> seg;\n    BITSeg() { \n        seg.resize(SZ\
    \ + 1);\n        for (int i = 0; i < SZ; i++)\n            seg[i] = Node<T>();\n\
    \    }\n    void upd(int x, int y, int v) { // add v\n        x++;\n        for\
    \ (; x < SZ + 1; x += x & -x) \n            seg[x].upd(y, v); \n    }\n    T query(int\
    \ x, int y1, int y2) {\n        if (x <= 0) return 0;\n        T res = 0; \n \
    \       for (; x; x -= x & -x) \n            res += seg[x].query(y1, y2);\n  \
    \      return res; \n    }\n    T query(int x1, int x2, int y1, int y2) { // query\
    \ sum of rectangle\n        x1++, x2++;\n        return query(x2, y1, y2) - query(x1\
    \ - 1, y1, y2); \n    }\n};\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/binary_indexed_tree_seg.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/binary_indexed_tree_seg.cpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/binary_indexed_tree_seg.cpp
- /library/library/data-structures/2d-range-queries/binary_indexed_tree_seg.cpp.html
title: library/data-structures/2d-range-queries/binary_indexed_tree_seg.cpp
---
