---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/contest/template-minimal.hpp
    title: library/contest/template-minimal.hpp
  - icon: ':heavy_check_mark:'
    path: library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
    title: library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
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
    \n#include <vector>\r\n\r\nusing namespace std;\n\r\ntemplate <class D, class\
    \ Op> struct SegmentTree {\r\n\tD e;\r\n\tOp op;\r\n\tint n, sz, lg;  \r\n\tstd::vector<D>\
    \ d;\r\n\r\n\tvoid init(const std::vector<D>& v) {\r\n\t\tn = int(v.size());\r\
    \n\t\tlg = 1;\r\n\t\twhile ((1 << lg) < n) lg++;\r\n\t\tsz = 1 << lg;\r\n\t\t\
    d = std::vector<D>(2 * sz, e);\r\n\t\tfor (int i = 0; i < n; i++) d[sz + i] =\
    \ v[i];\r\n\t\tfor (int i = sz - 1; i >= 0; i--) {\r\n\t\t\tupdate(i);\r\n\t\t\
    }\r\n\t}\r\n\r\n\tSegmentTree(const std::vector<D>& v, D _e, Op _op) : e(_e),\
    \ op(_op) { init(v); }\r\n\r\n\tvoid update(int k) { d[k] = op(d[2 * k], d[2 *\
    \ k + 1]); }\r\n\r\n\tvoid set(int p, D x) {\r\n\t\tassert(0 <= p && p < n);\r\
    \n\t\tp += sz;\r\n\t\td[p] = x;\r\n\t\tfor (int i = 1; i <= lg; i++) update(p\
    \ >> i);\r\n\t}\r\n\r\n\tvoid add(int p, D x) {\r\n\t\tassert(0 <= p && p < n);\r\
    \n\t\tp += sz;\r\n\t\td[p] = op(d[p], x);\r\n\t\tfor (int i = 1; i <= lg; i++)\
    \ update(p >> i);\r\n\t}\r\n\r\n\tD single(int p) const {\r\n\t\tassert(0 <= p\
    \ && p < n);\r\n\t\treturn d[p + sz];\r\n\t}\r\n\r\n\tD all_sum() const { return\
    \ d[1]; }\r\n\t\r\n\tD sum(int a, int b) const {\r\n\t\t++b;\r\n\t\tassert(a <=\
    \ b);\r\n\t\tD sml = e, smr = e;\r\n\t\ta += sz;\r\n\t\tb += sz;\r\n\t\twhile\
    \ (a < b) {\r\n\t\t\tif (a & 1) sml = op(sml, d[a++]);\r\n\t\t\tif (b & 1) smr\
    \ = op(d[--b], smr);\r\n\t\t\ta >>= 1;\r\n\t\t\tb >>= 1;\r\n\t\t}\r\n\t\treturn\
    \ op(sml, smr);\r\n\t}\r\n\r\n\t// min i s.t. f(d[a] + d[a+1] + ... d[i]) == true\
    \ (or return n + 1)\r\n\ttemplate <class Comp> int search_left(int a, Comp f)\
    \ {\r\n\t\ta += sz;\r\n\t\tD sm = e;\r\n\t\tif (f(e)) return a;\r\n\t\twhile (true)\
    \ {\r\n\t\t\tif (f(op(sm, d[a]))) {\r\n\t\t\t\twhile (a < sz) {\r\n\t\t\t\t\t\
    a *= 2;\r\n\t\t\t\t\tif (!f(op(sm, d[a]))) {\r\n\t\t\t\t\t\tsm = op(sm, d[a]);\r\
    \n\t\t\t\t\t\ta++;\r\n\t\t\t\t\t}\r\n\t\t\t\t}\r\n\t\t\t\ta = a + 1 - sz;\r\n\t\
    \t\t\treturn a;\r\n\t\t\t}\r\n\t\t\tif (a & 1) {\r\n\t\t\t\tsm = op(sm, d[a]);\r\
    \n\t\t\t\ta++;\r\n\t\t\t\tif ((a & -a) == a) break;\r\n\t\t\t}\r\n\t\t\ta >>=\
    \ 1;\r\n\t\t}\r\n\t\treturn n + 1;\r\n\t}\r\n};\r\n\r\ntemplate <class D, class\
    \ Op>\r\nSegmentTree<D, Op> get_segment_tree(std::vector<D> v, D e, Op op) {\r\
    \n\treturn SegmentTree<D, Op>(v, e, op);\r\n}\r\n\r\nint main() {\r\n\tusing namespace\
    \ std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\n\tint n, q; \r\n\tcin >> n >> q;\r\
    \n\tvector<long long> a(n);\r\n\tfor (int i = 0; i < n; i++) \r\n\t\tcin >> a[i];\r\
    \n\tauto seg = get_segment_tree(a, 0LL, [&](long long x, long long y) { return\
    \ x + y; });\r\n\twhile (q--) {\r\n\t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t ==\
    \ 0) {\r\n\t\t\tint p, x;\r\n\t\t\tcin >> p >> x;\r\n\t\t\tseg.add(p, x);\r\n\t\
    \t} else {\r\n\t\t\tint l, r;\r\n\t\t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\t\
    cout << seg.sum(l, r) << '\\n';\r\n\t\t}\r\n\t}\r\n\treturn 0;\r\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\r\
    \n\r\n#include \"../../library/contest/template-minimal.hpp\"\r\n#include \"../../library/data-structures/1d-range-queries/general-simple-segment-tree.hpp\"\
    \r\n\r\nint main() {\r\n\tusing namespace std;\r\n\tcin.tie(0)->sync_with_stdio(0);\r\
    \n\tint n, q; \r\n\tcin >> n >> q;\r\n\tvector<long long> a(n);\r\n\tfor (int\
    \ i = 0; i < n; i++) \r\n\t\tcin >> a[i];\r\n\tauto seg = get_segment_tree(a,\
    \ 0LL, [&](long long x, long long y) { return x + y; });\r\n\twhile (q--) {\r\n\
    \t\tint t;\r\n\t\tcin >> t;\r\n\t\tif (t == 0) {\r\n\t\t\tint p, x;\r\n\t\t\t\
    cin >> p >> x;\r\n\t\t\tseg.add(p, x);\r\n\t\t} else {\r\n\t\t\tint l, r;\r\n\t\
    \t\tcin >> l >> r;\r\n\t\t\t--r;\r\n\t\t\tcout << seg.sum(l, r) << '\\n';\r\n\t\
    \t}\r\n\t}\r\n\treturn 0;\r\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
---
