---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    \ntemplate <class T> struct SegmentTree {\n\tSegmentTree<T> *left, *right;\n\t\
    T sum, lazy;\n\n\tSegmentTree(int l, int r) {\n\t\tlazy = 0;\n\t\tif (l == r)\
    \ {\n\t\t\tsum = 0;\n\t\t} else {\n\t\t\tint m = (l + r) >> 1;\n\t\t\tleft = new\
    \ SegmentTree<T>(l, m);\n\t\t\tright = new SegmentTree<T>(m + 1, r);\n\t\t\tpull();\n\
    \t\t}\n\t}\n\n\tvoid pull() {\n\t\tsum = left->sum + right->sum;\n\t}\n\n\tvoid\
    \ push(int l, int r) {\n\t\tsum += (r - l + 1) * lazy;\n\t\tif (l != r) {\n\t\t\
    \tleft->lazy += lazy;\n\t\t\tright->lazy += lazy;\n\t\t}\n\t\tlazy = 0;\n\t}\n\
    \n\tvoid update(int lo, int hi, T inc, int l, int r) {\n\t\tpush(l, r);\n\t\t\
    if (r < lo || hi < l) {\n\t\t\treturn;\n\t\t} else if (lo <= l && r <= hi) {\n\
    \t\t\tlazy = inc;\n\t\t\tpush(l, r);\n\t\t} else {\n\t\t\tint m = (l + r) >> 1;\n\
    \t\t\tleft->update(lo, hi, inc, l, m);\n\t\t\tright->update(lo, hi, inc, m + 1,\
    \ r);\n\t\t\tpull();\n\t\t}\n\t}\n\n\tT query(int lo, int hi, int l, int r) {\n\
    \t\tpush(l, r);\n\t\tif (r < lo || hi < l) {\n\t\t\treturn 0;\n\t\t} else if (lo\
    \ <= l && r <= hi) {\n\t\t\treturn sum;\n\t\t} else {\n\t\t\tint m = (l + r) >>\
    \ 1;\n\t\t\treturn left->query(lo, hi, l, m) + right->query(lo, hi, m + 1, r);\n\
    \t\t}\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, q; \n\tcin >> n >> q;\n\tSegmentTree<long long> *seg = new SegmentTree<long\
    \ long>(0, n - 1);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint a; \n\t\tcin >> a;\n\
    \t\tseg->update(i, i, a, 0, n - 1);\n\t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin\
    \ >> t;\n\t\tif (t == 0) {  \n\t\t\tint p, x; \n\t\t\tcin >> p >> x;\n\t\t\tseg->update(p,\
    \ p, x, 0, n - 1);\n\t\t} else {\n\t\t\tint l, r; \n\t\t\tcin >> l >> r;\n\t\t\
    \t--r;\n\t\t\tcout << seg->query(l, r, 0, n - 1) << '\\n';\n\t\t}\n\t}\n\treturn\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; \n\tcin >> n >> q;\n\tSegmentTree<long long> *seg = new SegmentTree<long\
    \ long>(0, n - 1);\n\tfor (int i = 0; i < n; ++i) {\n\t\tint a; \n\t\tcin >> a;\n\
    \t\tseg->update(i, i, a, 0, n - 1);\n\t}\n\twhile (q--) {\n\t\tint t;\n\t\tcin\
    \ >> t;\n\t\tif (t == 0) {  \n\t\t\tint p, x; \n\t\t\tcin >> p >> x;\n\t\t\tseg->update(p,\
    \ p, x, 0, n - 1);\n\t\t} else {\n\t\t\tint l, r; \n\t\t\tcin >> l >> r;\n\t\t\
    \t--r;\n\t\t\tcout << seg->query(l, r, 0, n - 1) << '\\n';\n\t\t}\n\t}\n\treturn\
    \ 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
---
