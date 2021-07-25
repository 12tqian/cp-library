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
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \n// bump allocator\n\nstatic char buf[450 << 20];\nvoid* operator new(size_t\
    \ s) {\n\tstatic size_t i = sizeof buf;\n\tassert(s < i);\n\treturn (void*)&buf[i\
    \ -= s];\n}\nvoid operator delete(void*) {}\n\nconst int SZ = 1 << 30;\n\ntemplate\
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
    \ Node *c1, int L = 0, int R = SZ - 1) { // for 2D segtree\n\t\tif (L != R)\t\
    \ {\n\t\t\tint M = (L + R) / 2;\n\t\t\tif (ind <= M) {\n\t\t\t\tif (!c[0]) c[0]\
    \ = new Node();\n\t\t\t\tc[0]->update_2d(ind, (c0 ? c0->c[0] : NULL), (c1 ? c1->c[0]\
    \ : NULL), L, M);\n\t\t\t} else {\n\t\t\t\tif (!c[1]) c[1] = new Node();\n\t\t\
    \t\tc[1]->update_2d(ind, (c0 ? c0->c[1] : NULL), (c1 ? c1->c[1] : NULL), M + 1,\
    \ R);\n\t\t\t}\n\t\t} \n\t\tval = (c0 ? c0->val : 0) + (c1 ? c1->val : 0);\n\t\
    }\n};\n\nint main() {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\ttypedef long long ll;\n\tint n, q; \n\tcin >> n >> q;\n\
    \tvector<ll> a(n);\n\tNode<ll> seg;\n\tfor (int i = 0; i < n; i++) \n\t\tcin >>\
    \ a[i], seg.upd(i, a[i]);\n\twhile (q--) {\n\t\tint t; cin >> t;\n\t\tif (t ==\
    \ 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\tseg.upd(p, x);\n\t\t} else\
    \ {\n\t\t\tint l, r; cin >> l >> r;\n\t\t\tcout << seg.query(l, r - 1) << '\\\
    n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../library/contest/template-minimal.hpp\"\n#include \"../library/data-structures/1d-range-queries/sparse-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \ttypedef long long ll;\n\tint n, q; \n\tcin >> n >> q;\n\tvector<ll> a(n);\n\t\
    Node<ll> seg;\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i], seg.upd(i, a[i]);\n\
    \twhile (q--) {\n\t\tint t; cin >> t;\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\
    \tcin >> p >> x;\n\t\t\tseg.upd(p, x);\n\t\t} else {\n\t\t\tint l, r; cin >> l\
    \ >> r;\n\t\t\tcout << seg.query(l, r - 1) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n\
    }"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/sparse-segment-tree.hpp
  isVerificationFile: true
  path: test/sparse-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-24 23:00:09-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/sparse-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/test/sparse-segment-tree.test.cpp
- /verify/test/sparse-segment-tree.test.cpp.html
title: test/sparse-segment-tree.test.cpp
---
