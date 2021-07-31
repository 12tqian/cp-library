---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    \n\n\n#include <algorithm>\n#include <array>\n#include <bitset>\n#include <cassert>\n\
    #include <chrono>\n#include <cmath>\n#include <complex>\n#include <cstdio>\n#include\
    \ <cstdlib>\n#include <cstring>\n#include <ctime>\n#include <deque>\n#include\
    \ <iostream>\n#include <iomanip>\n#include <list>\n#include <map>\n#include <numeric>\n\
    #include <queue>\n#include <random>\n#include <set>\n#include <stack>\n#include\
    \ <string>\n#include <unordered_map>\n#include <vector>\n\nusing namespace std;\n\
    \ntemplate <class D, class Op> struct SegmentTree {\n\tD e;\n\tOp op;\n\tint n,\
    \ sz, lg;  \n\tstd::vector<D> d;\n\n\tSegmentTree(const std::vector<D>& v, D _e,\
    \ Op _op) : e(_e), op(_op) {\n\t\tn = int(v.size());\n\t\tlg = 1;\n\t\twhile ((1\
    \ << lg) < n) lg++;\n\t\tsz = 1 << lg;\n\t\td = std::vector<D>(2 * sz, e);\n\t\
    \tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\n\t\tfor (int i = sz - 1; i >=\
    \ 0; i--) {\n\t\t\tupdate(i);\n\t\t}\n\t}\n\n\tvoid update(int k) { d[k] = op(d[2\
    \ * k], d[2 * k + 1]); }\n\n\tvoid set(int p, D x) {\n\t\tassert(0 <= p && p <\
    \ n);\n\t\tp += sz;\n\t\td[p] = x;\n\t\tfor (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n\t}\n\n\tvoid add(int p, D x) {\n\t\tassert(0 <= p && p < n);\n\t\t\
    p += sz;\n\t\td[p] = op(d[p], x);\n\t\tfor (int i = 1; i <= lg; i++) update(p\
    \ >> i);\n\t}\n\n\tD single(int p) const {\n\t\tassert(0 <= p && p < n);\n\t\t\
    return d[p + sz];\n\t}\n\n\tD all_sum() const { return d[1]; }\n\t\n\tD sum(int\
    \ a, int b) const {\n\t\t++b;\n\t\tassert(a <= b);\n\t\tD sml = e, smr = e;\n\t\
    \ta += sz;\n\t\tb += sz;\n\t\twhile (a < b) {\n\t\t\tif (a & 1) sml = op(sml,\
    \ d[a++]);\n\t\t\tif (b & 1) smr = op(d[--b], smr);\n\t\t\ta >>= 1;\n\t\t\tb >>=\
    \ 1;\n\t\t}\n\t\treturn op(sml, smr);\n\t}\n\n\t// min i s.t. f(d[a] + d[a+1]\
    \ + ... d[i]) == true (or return n + 1)\n\ttemplate <class Comp> int search_left(int\
    \ a, Comp f) {\n\t\ta += sz;\n\t\tD sm = e;\n\t\tif (f(e)) return a;\n\t\twhile\
    \ (true) {\n\t\t\tif (f(op(sm, d[a]))) {\n\t\t\t\twhile (a < sz) {\n\t\t\t\t\t\
    a *= 2;\n\t\t\t\t\tif (!f(op(sm, d[a]))) {\n\t\t\t\t\t\tsm = op(sm, d[a]);\n\t\
    \t\t\t\t\ta++;\n\t\t\t\t\t}\n\t\t\t\t}\n\t\t\t\ta = a + 1 - sz;\n\t\t\t\treturn\
    \ a;\n\t\t\t}\n\t\t\tif (a & 1) {\n\t\t\t\tsm = op(sm, d[a]);\n\t\t\t\ta++;\n\t\
    \t\t\tif ((a & -a) == a) break;\n\t\t\t}\n\t\t\ta >>= 1;\n\t\t}\n\t\treturn n\
    \ + 1;\n\t}\n};\n\ntemplate <class D, class Op>\nSegmentTree<D, Op> get_segment_tree(std::vector<D>\
    \ v, D e, Op op) {\n\treturn SegmentTree<D, Op>(v, e, op);\n}\n\nint main() {\n\
    \tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\tint n, q; \n\tcin\
    \ >> n >> q;\n\tvector<long long> a(n);\n\tfor (int i = 0; i < n; i++) \n\t\t\
    cin >> a[i];\n\tauto seg = get_segment_tree(a, 0LL, [&](long long x, long long\
    \ y) { return x + y; });\n\twhile (q--) {\n\t\tint t;\n\t\tcin >> t;\n\t\tif (t\
    \ == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\tseg.add(p, x);\n\t\t}\
    \ else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--r;\n\t\t\tcout << seg.sum(l,\
    \ r) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../library/contest/template-minimal.hpp\"\n#include \"../../library/data-structures/1d-range-queries/general-simple-segment-tree.hpp\"\
    \n\nint main() {\n\tusing namespace std;\n\tcin.tie(0)->sync_with_stdio(0);\n\t\
    int n, q; \n\tcin >> n >> q;\n\tvector<long long> a(n);\n\tfor (int i = 0; i <\
    \ n; i++) \n\t\tcin >> a[i];\n\tauto seg = get_segment_tree(a, 0LL, [&](long long\
    \ x, long long y) { return x + y; });\n\twhile (q--) {\n\t\tint t;\n\t\tcin >>\
    \ t;\n\t\tif (t == 0) {\n\t\t\tint p, x;\n\t\t\tcin >> p >> x;\n\t\t\tseg.add(p,\
    \ x);\n\t\t} else {\n\t\t\tint l, r;\n\t\t\tcin >> l >> r;\n\t\t\t--r;\n\t\t\t\
    cout << seg.sum(l, r) << '\\n';\n\t\t}\n\t}\n\treturn 0;\n}"
  dependsOn:
  - library/contest/template-minimal.hpp
  - library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
  isVerificationFile: true
  path: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
  requiredBy: []
  timestamp: '2021-07-31 03:46:28-04:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
layout: document
redirect_from:
- /verify/verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
- /verify/verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp.html
title: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
---
