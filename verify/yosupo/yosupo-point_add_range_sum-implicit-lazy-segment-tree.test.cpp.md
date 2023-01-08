---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
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
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ SegmentTree {\r\n\tSegmentTree<T>* left, * right;\r\n\tT sum, lazy;\r\n\r\n\t\
    SegmentTree(int l, int r) {\r\n\t\tlazy = 0;\r\n\t\tif (l == r) {\r\n\t\t\tsum\
    \ = 0;\r\n\t\t} else {\r\n\t\t\tint m = (l + r) >> 1;\r\n\t\t\tleft = new SegmentTree<T>(l,\
    \ m);\r\n\t\t\tright = new SegmentTree<T>(m + 1, r);\r\n\t\t\tpull();\r\n\t\t\
    }\r\n\t}\r\n\r\n\tvoid pull() {\r\n\t\tsum = left->sum + right->sum;\r\n\t}\r\n\
    \r\n\tvoid push(int l, int r) {\r\n\t\tsum += (r - l + 1) * lazy;\r\n\t\tif (l\
    \ != r) {\r\n\t\t\tleft->lazy += lazy;\r\n\t\t\tright->lazy += lazy;\r\n\t\t}\r\
    \n\t\tlazy = 0;\r\n\t}\r\n\r\n\tvoid update(int lo, int hi, T inc, int l, int\
    \ r) {\r\n\t\tpush(l, r);\r\n\t\tif (r < lo || hi < l) {\r\n\t\t\treturn;\r\n\t\
    \t} else if (lo <= l && r <= hi) {\r\n\t\t\tlazy = inc;\r\n\t\t\tpush(l, r);\r\
    \n\t\t} else {\r\n\t\t\tint m = (l + r) >> 1;\r\n\t\t\tleft->update(lo, hi, inc,\
    \ l, m);\r\n\t\t\tright->update(lo, hi, inc, m + 1, r);\r\n\t\t\tpull();\r\n\t\
    \t}\r\n\t}\r\n\r\n\tT query(int lo, int hi, int l, int r) {\r\n\t\tpush(l, r);\r\
    \n\t\tif (r < lo || hi < l) {\r\n\t\t\treturn 0;\r\n\t\t} else if (lo <= l &&\
    \ r <= hi) {\r\n\t\t\treturn sum;\r\n\t\t} else {\r\n\t\t\tint m = (l + r) >>\
    \ 1;\r\n\t\t\treturn left->query(lo, hi, l, m) + right->query(lo, hi, m + 1, r);\r\
    \n\t\t}\r\n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tSegmentTree<long long> *seg = new SegmentTree<long\
    \ long>(0, n - 1);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tint a; \r\n\t\tcin\
    \ >> a;\r\n\t\tseg->update(i, i, a, 0, n - 1);\r\n\t}\r\n\twhile (q--) {\r\n\t\
    \tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {  \r\n\t\t\tint p, x; \r\n\t\t\t\
    cin >> p >> x;\r\n\t\t\tseg->update(p, p, x, 0, n - 1);\r\n\t\t} else {\r\n\t\t\
    \tint l, r; \r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout << seg->query(l,\
    \ r, 0, n - 1) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tSegmentTree<long long> *seg = new SegmentTree<long\
    \ long>(0, n - 1);\r\n\tfor (int i = 0; i < n; ++i) {\r\n\t\tint a; \r\n\t\tcin\
    \ >> a;\r\n\t\tseg->update(i, i, a, 0, n - 1);\r\n\t}\r\n\twhile (q--) {\r\n\t\
    \tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {  \r\n\t\t\tint p, x; \r\n\t\t\t\
    cin >> p >> x;\r\n\t\t\tseg->update(p, p, x, 0, n - 1);\r\n\t\t} else {\r\n\t\t\
    \tint l, r; \r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout << seg->query(l,\
    \ r, 0, n - 1) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/implicit-lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-implicit-lazy-segment-tree.test.cpp
---
