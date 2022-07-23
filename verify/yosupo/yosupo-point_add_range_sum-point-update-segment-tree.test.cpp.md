---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
    title: library/data-structures/1d-range-queries/point-update-segment-tree.hpp
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
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ SegmentTree {\r\n\tconst T ID = 0;\r\n\r\n\tT comb(T a, T b) {\r\n\t\treturn\
    \ a + b;\r\n\t}\r\n\r\n\tint n;\r\n\tstd::vector<T> seg;\r\n\r\n\tvoid init(int\
    \ _n) {\r\n\t\tn = _n;\r\n\t\tseg.assign(2 * n, ID);\r\n\t}\r\n\r\n\tvoid pull(int\
    \ p) {\r\n\t\tseg[p] = comb(seg[2 * p], seg[2 * p + 1]);\r\n\t}\r\n\r\n\tvoid\
    \ upd(int p, T val) {\r\n\t\tseg[p += n] = val;\r\n\t\tfor (p /= 2; p; p /= 2)\
    \ pull(p);\r\n\t}\r\n\r\n\tvoid add(int p, T val) {\r\n\t\tseg[p += n] += val;\r\
    \n\t\tfor (p /= 2; p; p /= 2) pull(p);\r\n\t}\r\n\r\n\tT query(int l, int r) {\r\
    \n\t\tT ra = ID, rb = ID;\r\n\t\tfor (l += n, r += n + 1; l < r; l /= 2, r /=\
    \ 2) {\r\n\t\t\tif (l & 1) ra = comb(ra, seg[l++]);\r\n\t\t\tif (r & 1) rb = comb(seg[--r],\
    \ rb);\r\n\t\t}\r\n\t\treturn comb(ra, rb);\r\n\t}\r\n};\n\r\nint main() {\r\n\
    \tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, q; \r\n\
    \tcin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tSegmentTree<long long> seg;\
    \ \r\n\tseg.init(n);\r\n\tfor (int i = 0; i < n; i++) \r\n\t\tcin >> a[i], seg.add(i,\
    \ a[i]);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0)\
    \ {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tseg.add(p, x);\r\n\t\t\
    } else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout\
    \ << seg.query(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/point-update-segment-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tSegmentTree<long\
    \ long> seg; \r\n\tseg.init(n);\r\n\tfor (int i = 0; i < n; i++) \r\n\t\tcin >>\
    \ a[i], seg.add(i, a[i]);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\
    \t\tif (t == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tseg.add(p,\
    \ x);\r\n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\
    \n\t\t\tcout << seg.query(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/point-update-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
---
