---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
    title: library/data-structures/1d-range-queries/sparse-segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\n// bump allocator\r\n\r\n\
    static char buf[450 << 20];\r\nvoid* operator new(size_t s) {\r\n\tstatic size_t\
    \ i = sizeof buf;\r\n\tassert(s < i);\r\n\treturn (void*)&buf[i -= s];\r\n}\r\n\
    void operator delete(void*) {}\r\n\r\nconst int SZ = 1 << 30;\r\n\r\ntemplate\
    \ <class T> struct Node {\r\n\tT val = 0; \r\n\tNode<T>* c[2];\r\n\tNode() { c[0]\
    \ = c[1] = NULL; }\r\n\r\n\tvoid upd(int ind, T v, int L = 0, int R = SZ - 1)\
    \ { // add v\r\n\t\tif (L == ind && R == ind) { val += v; return; }\r\n\t\tint\
    \ M = (L + R) / 2;\r\n\t\tif (ind <= M) {\r\n\t\t\tif (!c[0]) c[0] = new Node();\r\
    \n\t\t\tc[0]->upd(ind, v, L, M);\r\n\t\t} else {\r\n\t\t\tif (!c[1]) c[1] = new\
    \ Node();\r\n\t\t\tc[1]->upd(ind, v, M + 1, R);\r\n\t\t}\r\n\t\tval = 0; \r\n\t\
    \tfor (int i = 0; i < 2; i++)\r\n\t\t\tif (c[i]) val += c[i]->val;\r\n\t}\r\n\r\
    \n\tT query(int lo, int hi, int L = 0, int R = SZ - 1) { // query sum of segment\r\
    \n\t\tif (hi < L || R < lo) return 0;\r\n\t\tif (lo <= L && R <= hi) return val;\r\
    \n\t\tint M = (L + R) / 2; \r\n\t\tT res = 0;\r\n\t\tif (c[0]) res += c[0]->query(lo,\
    \ hi, L, M);\r\n\t\tif (c[1]) res += c[1]->query(lo, hi, M + 1, R);\r\n\t\treturn\
    \ res;\r\n\t}\r\n\r\n\tvoid update_2d(int ind, Node* c0, Node* c1, int L = 0,\
    \ int R = SZ - 1) { // for 2D segtree\r\n\t\tif (L != R)\t {\r\n\t\t\tint M =\
    \ (L + R) / 2;\r\n\t\t\tif (ind <= M) {\r\n\t\t\t\tif (!c[0]) c[0] = new Node();\r\
    \n\t\t\t\tc[0]->update_2d(ind, (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0] : NULL),\
    \ L, M);\r\n\t\t\t} else {\r\n\t\t\t\tif (!c[1]) c[1] = new Node();\r\n\t\t\t\t\
    c[1]->update_2d(ind, (c0 ? c0->c[1] : NULL), (c1 ? c1->c[1] : NULL), M + 1, R);\r\
    \n\t\t\t}\r\n\t\t} \r\n\t\tval = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\r\n\t\
    }\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\ttypedef long long ll;\r\n\tint n, q; \r\n\tcin >> n\
    \ >> q;\r\n\tvector<ll> a(n);\r\n\tNode<ll> seg;\r\n\tfor (int i = 0; i < n; i++)\
    \ \r\n\t\tcin >> a[i], seg.upd(i, a[i]);\r\n\twhile (q--) {\r\n\t\tint t; cin\
    \ >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\
    \tseg.upd(p, x);\r\n\t\t} else {\r\n\t\t\tint l, r; cin >> l >> r;\r\n\t\t\tcout\
    \ << seg.query(l, r - 1) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/sparse-segment-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tios::sync_with_stdio(false);\r\
    \n\tcin.tie(nullptr);\r\n\ttypedef long long ll;\r\n\tint n, q; \r\n\tcin >> n\
    \ >> q;\r\n\tvector<ll> a(n);\r\n\tNode<ll> seg;\r\n\tfor (int i = 0; i < n; i++)\
    \ \r\n\t\tcin >> a[i], seg.upd(i, a[i]);\r\n\twhile (q--) {\r\n\t\tint t; cin\
    \ >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\
    \tseg.upd(p, x);\r\n\t\t} else {\r\n\t\t\tint l, r; cin >> l >> r;\r\n\t\t\tcout\
    \ << seg.query(l, r - 1) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/sparse-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-sparse-segment-tree.test.cpp
---
