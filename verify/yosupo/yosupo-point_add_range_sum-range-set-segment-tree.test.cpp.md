---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/range-set-segment-tree.hpp
    title: library/data-structures/1d-range-queries/range-set-segment-tree.hpp
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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class T> struct RangeSetSeg {\n\tconst T UNUSED = -1;\n\tstd::vector<T>\
    \ sum, lazy;\n\tint sz;\n\n\t// lazy stores what to set to\n\tvoid init(int sz_)\
    \ {\n\t\tsz = 1;\n\t\twhile (sz < sz_) sz *= 2;\n\t\tsum.assign(2 * sz, 0);\n\t\
    \tlazy.assign(2 * sz, UNUSED);\n\t}\n\n\tvoid push(int ind, int L, int R) {\n\t\
    \tif (L != R) {\n\t\t\tif(lazy[ind] != UNUSED){\n\t\t\t\tfor(int i = 0; i < 2;\
    \ i++){\n\t\t\t\t\tlazy[2 * ind + i] = lazy[ind];\n\t\t\t\t}\n\t\t\t}\n\t\t}\n\
    \t\tif (lazy[ind] != UNUSED) sum[ind] = (R - L + 1) * lazy[ind];\n\t\tlazy[ind]\
    \ = UNUSED;\n\t}\n\n\tvoid pull(int ind) { sum[ind] = sum[2 * ind] + sum[2 * ind\
    \ + 1]; }\n\n\tvoid range_set(int lo, int hi, T inc, int ind = 1, int L = 0, int\
    \ R = -1) {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R);\n\t\tif (hi < L ||\
    \ R < lo) return;\n\t\tif (lo <= L && R <= hi) {\n\t\t\tlazy[ind] = inc;\n\t\t\
    \tpush(ind, L, R); return;\n\t\t}\n\t\tint M = (L + R) / 2;\n\t\trange_set(lo,\
    \ hi, inc, 2 * ind, L, M); range_set(lo, hi, inc, 2 * ind + 1, M + 1, R);\n\t\t\
    pull(ind);\n\t}\n\n\tT qsum(int lo, int hi, int ind = 1, int L = 0, int R = -1)\
    \ {\n\t\tif (R == -1) R += sz;\n\t\tpush(ind, L, R); if (lo > R || L > hi) return\
    \ 0;\n\t\tif (lo <= L && R <= hi) return sum[ind];\n\t\tint M = (L + R) / 2;\n\
    \t\treturn qsum(lo, hi, 2 * ind, L, M) + qsum(lo, hi, 2 * ind + 1, M + 1, R);\n\
    \t}\n};\n\nint main() {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\
    \tcin.tie(nullptr);\n\tint n, q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\
    \tRangeSetSeg<long long> seg; \n\tseg.init(n);\n\tfor (int i = 0; i < n; i++)\
    \ \n\t\tcin >> a[i], seg.range_set(i, i, a[i]);\n\twhile (q--) {\n\t\tint t;\n\
    \t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\t\
    seg.range_set(p, p, x + seg.qsum(p, p));\n\t\t} else {\n\t\t\tint l, r;\n\t\t\t\
    cin >> l >> r;\n\t\t\t--r;\n\t\t\tcout << seg.qsum(l, r) << '\\n';\n\t\t}\n\t\
    }\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/range-set-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tios::sync_with_stdio(false);\n\tcin.tie(nullptr);\n\
    \tint n, q;\n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tRangeSetSeg<long long>\
    \ seg; \n\tseg.init(n);\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i], seg.range_set(i,\
    \ i, a[i]);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\
    \t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\tseg.range_set(p, p, x + seg.qsum(p,\
    \ p));\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--r;\n\t\t\t\
    cout << seg.qsum(l, r) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/range-set-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-29 01:25:37-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-range-set-segment-tree.test.cpp
---
