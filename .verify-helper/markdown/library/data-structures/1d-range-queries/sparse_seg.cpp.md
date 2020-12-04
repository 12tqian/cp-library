---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/data-structures/1d-range-queries/sparse_seg.cpp\"\
    \n#include<bits/stdc++.h>\r\n// bump allocator\r\nstatic char buf[450 << 20];\r\
    \nvoid* operator new(size_t s) {\r\n    static size_t i = sizeof buf;\r\n    assert(s\
    \ < i);\r\n    return (void*) & buf[i -= s];\r\n}\r\nvoid operator delete(void*)\
    \ {}\r\nconst int SZ = 1 << 30;\r\ntemplate <class T> struct Node {\r\n    T val\
    \ = 0; \r\n    Node<T>* c[2];\r\n    Node() { c[0] = c[1] = NULL; }\r\n    void\
    \ upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\r\n        if (L ==\
    \ ind && R == ind) { val += v; return; }\r\n        int M = (L + R) / 2;\r\n \
    \       if (ind <= M) {\r\n            if (!c[0]) c[0] = new Node();\r\n     \
    \       c[0]->upd(ind, v, L, M);\r\n        } else {\r\n            if (!c[1])\
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
    \n        val = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n    }\r\n};\r\nint\
    \ main() {\r\n    using namespace std;\r\n    typedef long long ll;\r\n    int\
    \ n, q; cin >> n >> q;\r\n    vector<ll> a(n);\r\n    Node<ll> seg;\r\n    for\
    \ (int i = 0; i < n; i++) \r\n        cin >> a[i], seg.upd(i, a[i]);\r\n    while\
    \ (q--) {\r\n        int t; cin >> t;\r\n        if (t == 0) {\r\n           \
    \ int p, x;\r\n            cin >> p >> x;\r\n            seg.upd(p, x);\r\n  \
    \      } else {\r\n            int l, r; cin >> l >> r;\r\n            cout <<\
    \ seg.query(l, r - 1) << '\\n';\r\n        }\r\n    }\r\n    return 0;\r\n}\n"
  code: "#include<bits/stdc++.h>\r\n// bump allocator\r\nstatic char buf[450 << 20];\r\
    \nvoid* operator new(size_t s) {\r\n    static size_t i = sizeof buf;\r\n    assert(s\
    \ < i);\r\n    return (void*) & buf[i -= s];\r\n}\r\nvoid operator delete(void*)\
    \ {}\r\nconst int SZ = 1 << 30;\r\ntemplate <class T> struct Node {\r\n    T val\
    \ = 0; \r\n    Node<T>* c[2];\r\n    Node() { c[0] = c[1] = NULL; }\r\n    void\
    \ upd(int ind, T v, int L = 0, int R = SZ - 1) { // add v\r\n        if (L ==\
    \ ind && R == ind) { val += v; return; }\r\n        int M = (L + R) / 2;\r\n \
    \       if (ind <= M) {\r\n            if (!c[0]) c[0] = new Node();\r\n     \
    \       c[0]->upd(ind, v, L, M);\r\n        } else {\r\n            if (!c[1])\
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
    \n        val = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n    }\r\n};\r\nint\
    \ main() {\r\n    using namespace std;\r\n    typedef long long ll;\r\n    int\
    \ n, q; cin >> n >> q;\r\n    vector<ll> a(n);\r\n    Node<ll> seg;\r\n    for\
    \ (int i = 0; i < n; i++) \r\n        cin >> a[i], seg.upd(i, a[i]);\r\n    while\
    \ (q--) {\r\n        int t; cin >> t;\r\n        if (t == 0) {\r\n           \
    \ int p, x;\r\n            cin >> p >> x;\r\n            seg.upd(p, x);\r\n  \
    \      } else {\r\n            int l, r; cin >> l >> r;\r\n            cout <<\
    \ seg.query(l, r - 1) << '\\n';\r\n        }\r\n    }\r\n    return 0;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/sparse_seg.cpp
  requiredBy: []
  timestamp: '2020-11-28 19:53:19-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/1d-range-queries/sparse_seg.cpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/sparse_seg.cpp
- /library/library/data-structures/1d-range-queries/sparse_seg.cpp.html
title: library/data-structures/1d-range-queries/sparse_seg.cpp
---
