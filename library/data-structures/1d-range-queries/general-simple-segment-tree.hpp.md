---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
    title: verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class D, class Op> struct SegmentTree {\r\n\tD e;\r\n\
    \tOp op;\r\n\tint n, sz, lg;  \r\n\tstd::vector<D> d;\r\n\r\n\tvoid init(const\
    \ std::vector<D>& v) {\r\n\t\tn = int(v.size());\r\n\t\tlg = 1;\r\n\t\twhile ((1\
    \ << lg) < n) lg++;\r\n\t\tsz = 1 << lg;\r\n\t\td = std::vector<D>(2 * sz, e);\r\
    \n\t\tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\r\n\t\tfor (int i = sz - 1;\
    \ i >= 0; i--) {\r\n\t\t\tupdate(i);\r\n\t\t}\r\n\t}\r\n\r\n\tSegmentTree(const\
    \ std::vector<D>& v, D _e, Op _op) : e(_e), op(_op) { init(v); }\r\n\r\n\tvoid\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n\r\n\tvoid set(int p,\
    \ D x) {\r\n\t\tassert(0 <= p && p < n);\r\n\t\tp += sz;\r\n\t\td[p] = x;\r\n\t\
    \tfor (int i = 1; i <= lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tvoid add(int p,\
    \ D x) {\r\n\t\tassert(0 <= p && p < n);\r\n\t\tp += sz;\r\n\t\td[p] = op(d[p],\
    \ x);\r\n\t\tfor (int i = 1; i <= lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tD single(int\
    \ p) const {\r\n\t\tassert(0 <= p && p < n);\r\n\t\treturn d[p + sz];\r\n\t}\r\
    \n\r\n\tD all_sum() const { return d[1]; }\r\n\t\r\n\tD sum(int a, int b) const\
    \ {\r\n\t\t++b;\r\n\t\tassert(a <= b);\r\n\t\tD sml = e, smr = e;\r\n\t\ta +=\
    \ sz;\r\n\t\tb += sz;\r\n\t\twhile (a < b) {\r\n\t\t\tif (a & 1) sml = op(sml,\
    \ d[a++]);\r\n\t\t\tif (b & 1) smr = op(d[--b], smr);\r\n\t\t\ta >>= 1;\r\n\t\t\
    \tb >>= 1;\r\n\t\t}\r\n\t\treturn op(sml, smr);\r\n\t}\r\n\r\n\t// min i s.t.\
    \ f(d[a] + d[a+1] + ... d[i]) == true (or return n + 1)\r\n\ttemplate <class Comp>\
    \ int search_left(int a, Comp f) {\r\n\t\ta += sz;\r\n\t\tD sm = e;\r\n\t\tif\
    \ (f(e)) return a;\r\n\t\twhile (true) {\r\n\t\t\tif (f(op(sm, d[a]))) {\r\n\t\
    \t\t\twhile (a < sz) {\r\n\t\t\t\t\ta *= 2;\r\n\t\t\t\t\tif (!f(op(sm, d[a])))\
    \ {\r\n\t\t\t\t\t\tsm = op(sm, d[a]);\r\n\t\t\t\t\t\ta++;\r\n\t\t\t\t\t}\r\n\t\
    \t\t\t}\r\n\t\t\t\ta = a + 1 - sz;\r\n\t\t\t\treturn a;\r\n\t\t\t}\r\n\t\t\tif\
    \ (a & 1) {\r\n\t\t\t\tsm = op(sm, d[a]);\r\n\t\t\t\ta++;\r\n\t\t\t\tif ((a &\
    \ -a) == a) break;\r\n\t\t\t}\r\n\t\t\ta >>= 1;\r\n\t\t}\r\n\t\treturn n + 1;\r\
    \n\t}\r\n};\r\n\r\ntemplate <class D, class Op>\r\nSegmentTree<D, Op> get_segment_tree(std::vector<D>\
    \ v, D e, Op op) {\r\n\treturn SegmentTree<D, Op>(v, e, op);\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class D, class Op> struct SegmentTree {\r\n\
    \tD e;\r\n\tOp op;\r\n\tint n, sz, lg;  \r\n\tstd::vector<D> d;\r\n\r\n\tvoid\
    \ init(const std::vector<D>& v) {\r\n\t\tn = int(v.size());\r\n\t\tlg = 1;\r\n\
    \t\twhile ((1 << lg) < n) lg++;\r\n\t\tsz = 1 << lg;\r\n\t\td = std::vector<D>(2\
    \ * sz, e);\r\n\t\tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\r\n\t\tfor (int\
    \ i = sz - 1; i >= 0; i--) {\r\n\t\t\tupdate(i);\r\n\t\t}\r\n\t}\r\n\r\n\tSegmentTree(const\
    \ std::vector<D>& v, D _e, Op _op) : e(_e), op(_op) { init(v); }\r\n\r\n\tvoid\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\r\n\r\n\tvoid set(int p,\
    \ D x) {\r\n\t\tassert(0 <= p && p < n);\r\n\t\tp += sz;\r\n\t\td[p] = x;\r\n\t\
    \tfor (int i = 1; i <= lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tvoid add(int p,\
    \ D x) {\r\n\t\tassert(0 <= p && p < n);\r\n\t\tp += sz;\r\n\t\td[p] = op(d[p],\
    \ x);\r\n\t\tfor (int i = 1; i <= lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tD single(int\
    \ p) const {\r\n\t\tassert(0 <= p && p < n);\r\n\t\treturn d[p + sz];\r\n\t}\r\
    \n\r\n\tD all_sum() const { return d[1]; }\r\n\t\r\n\tD sum(int a, int b) const\
    \ {\r\n\t\t++b;\r\n\t\tassert(a <= b);\r\n\t\tD sml = e, smr = e;\r\n\t\ta +=\
    \ sz;\r\n\t\tb += sz;\r\n\t\twhile (a < b) {\r\n\t\t\tif (a & 1) sml = op(sml,\
    \ d[a++]);\r\n\t\t\tif (b & 1) smr = op(d[--b], smr);\r\n\t\t\ta >>= 1;\r\n\t\t\
    \tb >>= 1;\r\n\t\t}\r\n\t\treturn op(sml, smr);\r\n\t}\r\n\r\n\t// min i s.t.\
    \ f(d[a] + d[a+1] + ... d[i]) == true (or return n + 1)\r\n\ttemplate <class Comp>\
    \ int search_left(int a, Comp f) {\r\n\t\ta += sz;\r\n\t\tD sm = e;\r\n\t\tif\
    \ (f(e)) return a;\r\n\t\twhile (true) {\r\n\t\t\tif (f(op(sm, d[a]))) {\r\n\t\
    \t\t\twhile (a < sz) {\r\n\t\t\t\t\ta *= 2;\r\n\t\t\t\t\tif (!f(op(sm, d[a])))\
    \ {\r\n\t\t\t\t\t\tsm = op(sm, d[a]);\r\n\t\t\t\t\t\ta++;\r\n\t\t\t\t\t}\r\n\t\
    \t\t\t}\r\n\t\t\t\ta = a + 1 - sz;\r\n\t\t\t\treturn a;\r\n\t\t\t}\r\n\t\t\tif\
    \ (a & 1) {\r\n\t\t\t\tsm = op(sm, d[a]);\r\n\t\t\t\ta++;\r\n\t\t\t\tif ((a &\
    \ -a) == a) break;\r\n\t\t\t}\r\n\t\t\ta >>= 1;\r\n\t\t}\r\n\t\treturn n + 1;\r\
    \n\t}\r\n};\r\n\r\ntemplate <class D, class Op>\r\nSegmentTree<D, Op> get_segment_tree(std::vector<D>\
    \ v, D e, Op op) {\r\n\treturn SegmentTree<D, Op>(v, e, op);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-point_add_range_general-simple-segment-tree.test.cpp
documentation_of: library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/general-simple-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/general-simple-segment-tree.hpp
---
