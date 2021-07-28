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
    \n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class T> struct SegmentTree {\n\tconst T ID = 0;\n\n\tT comb(T a,\
    \ T b) {\n\t\treturn a + b;\n\t}\n\n\tint n;\n\tstd::vector<T> seg;\n\n\tvoid\
    \ init(int _n) {\n\t\tn = _n;\n\t\tseg.assign(2 * n, ID);\n\t}\n\n\tvoid pull(int\
    \ p) {\n\t\tseg[p] = comb(seg[2 * p], seg[2 * p + 1]);\n\t}\n\n\tvoid upd(int\
    \ p, T val) {\n\t\tseg[p += n] = val;\n\t\tfor (p /= 2; p; p /= 2) pull(p);\n\t\
    }\n\n\tvoid add(int p, T val) {\n\t\tseg[p += n] += val;\n\t\tfor (p /= 2; p;\
    \ p /= 2) pull(p);\n\t}\n\n\tT query(int l, int r) {\n\t\tT ra = ID, rb = ID;\n\
    \t\tfor (l += n, r += n + 1; l < r; l /= 2, r /= 2) {\n\t\t\tif (l & 1) ra = comb(ra,\
    \ seg[l++]);\n\t\t\tif (r & 1) rb = comb(seg[--r], rb);\n\t\t}\n\t\treturn comb(ra,\
    \ rb);\n\t}\n};\n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\
    \tint n, q; \n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tSegmentTree<long\
    \ long> seg; \n\tseg.init(n);\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i],\
    \ seg.add(i, a[i]);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t ==\
    \ 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\tseg.add(p, x);\n\t\t} else\
    \ {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--r;\n\t\t\tcout << seg.query(l,\
    \ r) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/point-update-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; \n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tSegmentTree<long long>\
    \ seg; \n\tseg.init(n);\n\tfor (int i = 0; i < n; i++) \n\t\tcin >> a[i], seg.add(i,\
    \ a[i]);\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t == 0) {\n\t\t\t\
    int p, x;\n\t\t\tcin >> p >> x;\n\t\t\tseg.add(p, x);\n\t\t} else {\n\t\t\tint\
    \ l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--r;\n\t\t\tcout << seg.query(l, r) << '\\\
    n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/point-update-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-28 02:34:55-04:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_sum-point-update-segment-tree.test.cpp
---
