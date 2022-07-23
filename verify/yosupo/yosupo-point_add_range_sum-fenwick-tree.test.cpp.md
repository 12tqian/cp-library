---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/fenwick-tree.hpp
    title: library/data-structures/1d-range-queries/fenwick-tree.hpp
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
    \ FenwickTree {\r\n\tstd::vector<T> fwt;\r\n\tint n;\r\n\r\n\tvoid init(int n_)\
    \ {\r\n\t\tn = n_;\r\n\t\tfwt.assign(n, 0);\r\n\t}\r\n\r\n\tvoid init(std::vector<T>&\
    \ a) {\r\n\t\tn = (int)a.size();\r\n\t\tfwt.assign(n, 0);\r\n\t\tfor (int i =\
    \ 0; i < (int)a.size(); i++) {\r\n\t\t\tadd(i, a[i]);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    T sum(int r) {\r\n\t\tT ret = 0;\r\n\t\tfor (; r >= 0; r = (r & (r + 1)) - 1)\
    \ \r\n\t\t\tret += fwt[r];\r\n\t\treturn ret;\r\n\t}\r\n\r\n\tT query(int l, int\
    \ r) {\r\n\t\treturn sum(r) - sum(l - 1);\r\n\t}\r\n\t\r\n\tvoid add(int idx,\
    \ T delta) {\r\n\t\tfor (; idx < n; idx = idx | (idx + 1)) \r\n\t\t\tfwt[idx]\
    \ += delta;\r\n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) \r\n\t\tcin >> a[i];\r\n\tFenwickTree<long long> F; \r\n\t\
    F.init(a);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0)\
    \ {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tF.add(p, x);\r\n\t\t}\
    \ else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout\
    \ << F.query(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/fenwick-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) \r\n\t\tcin >> a[i];\r\n\tFenwickTree<long long> F; \r\n\t\
    F.init(a);\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0)\
    \ {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tF.add(p, x);\r\n\t\t}\
    \ else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout\
    \ << F.query(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/fenwick-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-fenwick-tree.test.cpp
---
