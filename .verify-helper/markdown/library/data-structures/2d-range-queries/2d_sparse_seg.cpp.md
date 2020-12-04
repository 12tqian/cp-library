---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\data-structures\\\\2d-range-queries\\\\2d_sparse_seg.cpp\"\
    \n#include<bits/stdc++.h>\r\n// bump allocator\r\nstatic char buf[450 << 20];\r\
    \nvoid* operator new(size_t s) {\r\n    static size_t i = sizeof buf;\r\n    assert(s\
    \ < i);\r\n    return (void*) & buf[i -= s];\r\n}\r\nvoid operator delete(void*)\
    \ {}\r\nconst int SZ = (1 << 17);\r\ntemplate <class T> struct Node {\r\n    T\
    \ val = 0; \r\n    Node<T>* c[2];\r\n    Node() { c[0] = c[1] = NULL; }\r\n  \
    \  void upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\r\n        if\
    \ (L == ind && R == ind) { val += v; return; }\r\n        int M = (L + R) / 2;\r\
    \n        if (ind <= M) {\r\n            if (!c[0]) c[0] = new Node();\r\n   \
    \         c[0]->upd(ind, v, L, M);\r\n        } else {\r\n            if (!c[1])\
    \ c[1] = new Node();\r\n            c[1]->upd(ind, v, M + 1, R);\r\n        }\r\
    \n        val = 0; \r\n        for (int i = 0; i < 2; i++)\r\n            if (c[i])\
    \ val += c[i]->val;\r\n    }\r\n    T query(int lo, int hi, int L = 0, int R =\
    \ SZ - 1) { // query sum of segment\r\n        if (hi < L || R < lo) return 0;\r\
    \n        if (lo <= L && R <= hi) return val;\r\n        int M = (L + R) / 2;\
    \ \r\n        T res = 0;\r\n        if (c[0]) res += c[0]->query(lo, hi, L, M);\r\
    \n        if (c[1]) res += c[1]->query(lo, hi, M + 1, R);\r\n        return res;\r\
    \n    }\r\n    void update_2d(int ind, Node* c0, Node* c1, int L = 0, int R =\
    \ SZ - 1) { // for 2D segtree\r\n        if (L != R) {\r\n            int M =\
    \ (L + R) / 2;\r\n            if (ind <= M) {\r\n                if (!c[0]) c[0]\
    \ = new Node();\r\n                c[0]->update_2d(ind, (c0 ? c0->c[0] : NULL),\
    \ (c1 ? c1->c[0] : NULL), L, M);\r\n            } else {\r\n                if\
    \ (!c[1]) c[1] = new Node();\r\n                c[1]->update_2d(ind, (c0 ? c0->c[1]\
    \ : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);\r\n            }\r\n        } \r\
    \n        val = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n    }\r\n};\r\ntemplate\
    \ <class T> struct Node2D {\r\n    Node<T> seg; \r\n    Node2D* c[2];\r\n    Node2D()\
    \ { c[0] = c[1] = NULL; }\r\n    void upd(int x, int y, T v, int L = 0, int R\
    \ = SZ - 1) { // add v\r\n        if (L == x && R == x) { seg.upd(y, v); return;\
    \ }\r\n        int M = (L + R) / 2;\r\n        if (x <= M) {\r\n            if\
    \ (!c[0]) c[0] = new Node2D();\r\n            c[0]->upd(x, y, v, L, M);\r\n  \
    \      } else {\r\n            if (!c[1]) c[1] = new Node2D();\r\n           \
    \ c[1]->upd(x, y, v, M + 1, R);\r\n        }\r\n        seg.upd(y, v); // only\
    \ for addition\r\n        // seg.update_2d(y, (c[0] ? & c[0]->seg : NULL), (c[1]\
    \ ? & c[1]->seg : NULL));\r\n    }\r\n    T query(int x1, int x2, int y1, int\
    \ y2, int L = 0, int R = SZ - 1) { // query sum of rectangle\r\n        if (x1\
    \ <= L && R <= x2) return seg.query(y1, y2);\r\n        if (x2 < L || R < x1)\
    \ return 0;\r\n        int M = (L + R) / 2; \r\n        T res = 0;\r\n       \
    \ if (c[0]) res += c[0]->query(x1, x2, y1, y2, L, M);\r\n        if (c[1]) res\
    \ += c[1]->query(x1, x2, y1, y2, M + 1, R);\r\n        return res;\r\n    }\r\n\
    };\r\nint main() {\r\n    return 0;\r\n}\n"
  code: "#include<bits/stdc++.h>\r\n// bump allocator\r\nstatic char buf[450 << 20];\r\
    \nvoid* operator new(size_t s) {\r\n    static size_t i = sizeof buf;\r\n    assert(s\
    \ < i);\r\n    return (void*) & buf[i -= s];\r\n}\r\nvoid operator delete(void*)\
    \ {}\r\nconst int SZ = (1 << 17);\r\ntemplate <class T> struct Node {\r\n    T\
    \ val = 0; \r\n    Node<T>* c[2];\r\n    Node() { c[0] = c[1] = NULL; }\r\n  \
    \  void upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\r\n        if\
    \ (L == ind && R == ind) { val += v; return; }\r\n        int M = (L + R) / 2;\r\
    \n        if (ind <= M) {\r\n            if (!c[0]) c[0] = new Node();\r\n   \
    \         c[0]->upd(ind, v, L, M);\r\n        } else {\r\n            if (!c[1])\
    \ c[1] = new Node();\r\n            c[1]->upd(ind, v, M + 1, R);\r\n        }\r\
    \n        val = 0; \r\n        for (int i = 0; i < 2; i++)\r\n            if (c[i])\
    \ val += c[i]->val;\r\n    }\r\n    T query(int lo, int hi, int L = 0, int R =\
    \ SZ - 1) { // query sum of segment\r\n        if (hi < L || R < lo) return 0;\r\
    \n        if (lo <= L && R <= hi) return val;\r\n        int M = (L + R) / 2;\
    \ \r\n        T res = 0;\r\n        if (c[0]) res += c[0]->query(lo, hi, L, M);\r\
    \n        if (c[1]) res += c[1]->query(lo, hi, M + 1, R);\r\n        return res;\r\
    \n    }\r\n    void update_2d(int ind, Node* c0, Node* c1, int L = 0, int R =\
    \ SZ - 1) { // for 2D segtree\r\n        if (L != R) {\r\n            int M =\
    \ (L + R) / 2;\r\n            if (ind <= M) {\r\n                if (!c[0]) c[0]\
    \ = new Node();\r\n                c[0]->update_2d(ind, (c0 ? c0->c[0] : NULL),\
    \ (c1 ? c1->c[0] : NULL), L, M);\r\n            } else {\r\n                if\
    \ (!c[1]) c[1] = new Node();\r\n                c[1]->update_2d(ind, (c0 ? c0->c[1]\
    \ : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);\r\n            }\r\n        } \r\
    \n        val = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n    }\r\n};\r\ntemplate\
    \ <class T> struct Node2D {\r\n    Node<T> seg; \r\n    Node2D* c[2];\r\n    Node2D()\
    \ { c[0] = c[1] = NULL; }\r\n    void upd(int x, int y, T v, int L = 0, int R\
    \ = SZ - 1) { // add v\r\n        if (L == x && R == x) { seg.upd(y, v); return;\
    \ }\r\n        int M = (L + R) / 2;\r\n        if (x <= M) {\r\n            if\
    \ (!c[0]) c[0] = new Node2D();\r\n            c[0]->upd(x, y, v, L, M);\r\n  \
    \      } else {\r\n            if (!c[1]) c[1] = new Node2D();\r\n           \
    \ c[1]->upd(x, y, v, M + 1, R);\r\n        }\r\n        seg.upd(y, v); // only\
    \ for addition\r\n        // seg.update_2d(y, (c[0] ? & c[0]->seg : NULL), (c[1]\
    \ ? & c[1]->seg : NULL));\r\n    }\r\n    T query(int x1, int x2, int y1, int\
    \ y2, int L = 0, int R = SZ - 1) { // query sum of rectangle\r\n        if (x1\
    \ <= L && R <= x2) return seg.query(y1, y2);\r\n        if (x2 < L || R < x1)\
    \ return 0;\r\n        int M = (L + R) / 2; \r\n        T res = 0;\r\n       \
    \ if (c[0]) res += c[0]->query(x1, x2, y1, y2, L, M);\r\n        if (c[1]) res\
    \ += c[1]->query(x1, x2, y1, y2, M + 1, R);\r\n        return res;\r\n    }\r\n\
    };\r\nint main() {\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library\data-structures\2d-range-queries\2d_sparse_seg.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:53:41-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\data-structures\2d-range-queries\2d_sparse_seg.cpp
layout: document
redirect_from:
- /library\library\data-structures\2d-range-queries\2d_sparse_seg.cpp
- /library\library\data-structures\2d-range-queries\2d_sparse_seg.cpp.html
title: library\data-structures\2d-range-queries\2d_sparse_seg.cpp
---
