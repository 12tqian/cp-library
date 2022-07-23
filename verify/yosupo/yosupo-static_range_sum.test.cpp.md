---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/associative-range-query.hpp
    title: library/data-structures/1d-range-queries/associative-range-query.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\
    \r\n\r\n\r\n#include <algorithm>\r\n#include <array>\r\n#include <bitset>\r\n\
    #include <cassert>\r\n#include <chrono>\r\n#include <cmath>\r\n#include <complex>\r\
    \n#include <cstdio>\r\n#include <cstdlib>\r\n#include <cstring>\r\n#include <ctime>\r\
    \n#include <deque>\r\n#include <iostream>\r\n#include <iomanip>\r\n#include <list>\r\
    \n#include <map>\r\n#include <numeric>\r\n#include <queue>\r\n#include <random>\r\
    \n#include <set>\r\n#include <stack>\r\n#include <string>\r\n#include <unordered_map>\r\
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T> struct\
    \ RangeQuery {\r\n\tint sz; \r\n\tstd::vector<std::vector<T>> st;\r\n\tT id =\
    \ 0;\r\n\tstd::vector<T> a;\r\n\r\n\tT comb(T a, T b) { return a + b; }  \r\n\r\
    \n\tvoid fill(int l, int r, int ind) {\r\n\t\tif (ind < 0) return;\r\n\t\tint\
    \ m = (l + r) >> 1;\r\n\t\tT prod = id;\r\n\t\tfor (int i = m - 1; i >= l; i--)\
    \ \r\n\t\t\tst[i][ind] = prod = comb(a[i], prod);\r\n\t\tprod = id;\r\n\t\tfor\
    \ (int i = m; i < r; i++) \r\n\t\t\tst[i][ind] = prod = comb(prod, a[i]);\r\n\t\
    \tfill(l, m, ind - 1);\r\n\t\tfill(m, r, ind - 1);\r\n\t}\r\n\r\n\tvoid init(std::vector<T>\
    \ a_) {\r\n\t\ta = a_;\r\n\t\tsz = 1;\r\n\t\twhile ((1 << sz) < (int)a.size())\
    \ sz++;\r\n\t\tst = std::vector<std::vector<T>>((1 << sz), std::vector<T>(sz));\r\
    \n\t\ta.resize(1 << sz);\r\n\t\tfill(0, (1 << sz), sz - 1);\r\n\t}\r\n\r\n\tT\
    \ query(int l, int r) {\r\n\t\tif (l == r) return a[l];\r\n\t\tint t = 31 - __builtin_clz(r\
    \ ^ l);\r\n\t\treturn comb(st[l][t], st[r][t]);\r\n\t}\r\n};\r\n\r\nint main()\
    \ {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n,\
    \ q; cin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tfor (int i = 0; i < n; i++)\
    \ \r\n\t\tcin >> a[i];\r\n\tRangeQuery<long long> R; \r\n\tR.init(a);\r\n\twhile\
    \ (q--) {\r\n\t\tint l, r; cin >> l >> r;\r\n\t\tr--;\r\n\t\tcout << R.query(l,\
    \ r) << '\\n';\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\r\n\r\
    \n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/associative-range-query.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; cin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tfor (int i = 0;\
    \ i < n; i++) \r\n\t\tcin >> a[i];\r\n\tRangeQuery<long long> R; \r\n\tR.init(a);\r\
    \n\twhile (q--) {\r\n\t\tint l, r; cin >> l >> r;\r\n\t\tr--;\r\n\t\tcout << R.query(l,\
    \ r) << '\\n';\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/associative-range-query.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-static_range_sum.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-static_range_sum.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-static_range_sum.test.cpp
- /verify/verify/yosupo/yosupo-static_range_sum.test.cpp.html
title: verify/yosupo/yosupo-static_range_sum.test.cpp
---
