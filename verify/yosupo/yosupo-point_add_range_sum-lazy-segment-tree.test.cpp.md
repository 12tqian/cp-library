---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':x:'
    path: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
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
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class T>\r\nstruct\
    \ LazySeg {\r\n  std::vector<T> sum, lazy;\r\n  int sz;\r\n\r\n  LazySeg(int sz)\
    \ { init(sz); }\r\n\r\n  void init(int sz_) {\r\n    sz = 1;\r\n    while (sz\
    \ < sz_) sz *= 2;\r\n    sum.assign(2 * sz, 0);\r\n    lazy.assign(2 * sz, 0);\r\
    \n  }\r\n\r\n  void push(int ind, int L, int R) {\r\n    sum[ind] += (R - L +\
    \ 1) * lazy[ind];\r\n    if (L != R) {\r\n      lazy[2 * ind] += lazy[ind];\r\n\
    \      lazy[2 * ind + 1] += lazy[ind];\r\n    }\r\n    lazy[ind] = 0;\r\n  }\r\
    \n\r\n  void pull(int ind) { sum[ind] = sum[2 * ind] + sum[2 * ind + 1]; }\r\n\
    \r\n  void build() {\r\n    for (int i = sz - 1; i >= 1; i--) {\r\n      pull(i);\r\
    \n    }\r\n  }\r\n\r\n  void upd(int lo, int hi, T inc, int ind = 1, int L = 0,\
    \ int R = -1) {\r\n    if (R == -1) R += sz;\r\n    push(ind, L, R);\r\n    if\
    \ (hi < L || R < lo) return;\r\n    if (lo <= L && R <= hi) {\r\n      lazy[ind]\
    \ = inc;\r\n      push(ind, L, R);\r\n      return;\r\n    }\r\n    int M = (L\
    \ + R) / 2;\r\n    upd(lo, hi, inc, 2 * ind, L, M);\r\n    upd(lo, hi, inc, 2\
    \ * ind + 1, M + 1, R);\r\n    pull(ind);\r\n  }\r\n\r\n  T qsum(int lo, int hi,\
    \ int ind = 1, int L = 0, int R = -1) {\r\n    if (R == -1) R += sz;\r\n    push(ind,\
    \ L, R);\r\n    if (lo > R || L > hi) return 0;\r\n    if (lo <= L && R <= hi)\
    \ return sum[ind];\r\n    int M = (L + R) / 2;\r\n    return qsum(lo, hi, 2 *\
    \ ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\r\n  }\r\n};\n\r\nint main()\
    \ {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n,\
    \ q; \r\n\tcin >> n >> q;\r\n\tLazySeg<long long> seg;\r\n\tseg.init(n);\r\n\t\
    for (int i = 0; i < n; i++) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\tseg.upd(i,\
    \ i, x);\r\n\t}\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t\
    \ == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tseg.upd(p, p, x);\r\
    \n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\
    \tcout << seg.qsum(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/lazy-segment-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tLazySeg<long long> seg;\r\n\tseg.init(n);\r\
    \n\tfor (int i = 0; i < n; i++) {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\tseg.upd(i,\
    \ i, x);\r\n\t}\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t\
    \ == 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tseg.upd(p, p, x);\r\
    \n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\
    \tcout << seg.qsum(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/lazy-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2023-01-08 14:07:45-05:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
---
