---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
    title: library/data-structures/1d-range-queries/lazy-segment-tree.hpp
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
    \ LazySeg {\r\n\tstd::vector<T> sum, lazy;\r\n\tint sz;\r\n\r\n\tvoid init(int\
    \ sz_) {\r\n\t\tsz = 1;\r\n\t\twhile (sz < sz_) sz *= 2;\r\n\t\tsum.assign(2 *\
    \ sz, 0);\r\n\t\tlazy.assign(2 * sz, 0);\r\n\t}\r\n\r\n\tvoid push(int ind, int\
    \ L, int R) {\r\n\t\tsum[ind] += (R - L + 1) * lazy[ind];\r\n\t\tif (L != R) {\r\
    \n\t\t\tlazy[2 * ind] += lazy[ind];\r\n\t\t\tlazy[2 * ind + 1] += lazy[ind];\r\
    \n\t\t}\r\n\t\tlazy[ind] = 0;\r\n\t}\r\n\r\n\tvoid pull(int ind) {\r\n\t\tsum[ind]\
    \ = sum[2 * ind] + sum[2 * ind + 1];\r\n\t}\r\n\r\n\tvoid build() {\r\n\t\tfor\
    \ (int i = sz - 1; i >= 1; i--) {\r\n\t\t\tpull(i);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    void upd(int lo, int hi, T inc, int ind = 1, int L = 0, int R = -1) {\r\n\t\t\
    if (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (hi < L || R < lo) return;\r\
    \n\t\tif (lo <= L && R <= hi) {\r\n\t\t\tlazy[ind] = inc;\r\n\t\t\tpush(ind, L,\
    \ R);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tint M = (L + R) / 2;\r\n\t\tupd(lo, hi,\
    \ inc, 2 * ind, L, M);\r\n\t\tupd(lo, hi, inc, 2 * ind + 1, M + 1, R);\r\n\t\t\
    pull(ind);\r\n\t}\r\n\r\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int\
    \ R = -1) {\r\n\t\tif (R == -1) R += sz;\r\n\t\tpush(ind, L, R);\r\n\t\tif (lo\
    \ > R || L > hi) return 0;\r\n\t\tif (lo <= L && R <= hi) return sum[ind];\r\n\
    \t\tint M = (L + R) / 2;\r\n\t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo,\
    \ hi, 2 * ind + 1, M + 1, R);\r\n\t}\r\n};\n\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, q; \r\n\tcin >> n >> q;\r\
    \n\tLazySeg<long long> seg;\r\n\tseg.init(n);\r\n\tfor (int i = 0; i < n; i++)\
    \ {\r\n\t\tint x;\r\n\t\tcin >> x;\r\n\t\tseg.upd(i, i, x);\r\n\t}\r\n\twhile\
    \ (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p,\
    \ x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tseg.upd(p, p, x);\r\n\t\t} else {\r\n\t\t\
    \tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout << seg.qsum(l,\
    \ r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
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
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-lazy-segment-tree.test.cpp
---
