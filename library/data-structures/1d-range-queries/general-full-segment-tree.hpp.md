---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
    title: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\r\ntemplate <class D, class L, class OpDD, class OpDL, class OpLL>\
    \ struct LazySegmentTree {\r\n\tD e_d;\r\n\tL e_l;\r\n\tOpDD op_dd; \r\n\tOpDL\
    \ op_dl;\r\n\tOpLL op_ll;\r\n\tint sz, lg;  \r\n\tstd::vector<D> d;\r\n\tstd::vector<L>\
    \ lz;\r\n\r\n\tvoid init(const std::vector<D>& v) {\r\n\t\tint n = int(v.size());\r\
    \n\t\tlg = 1;\r\n\t\twhile ((1 << lg) < n) lg++;\r\n\t\tsz = 1 << lg;\r\n\t\t\
    d = std::vector<D>(2 * sz, e_d);\r\n\t\tlz = std::vector<L>(2 * sz, e_l);\r\n\t\
    \tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\r\n\t\tfor (int i = sz - 1; i\
    \ >= 0; i--) {\r\n\t\t\tupdate(i);\r\n\t\t}\r\n\t}\r\n\r\n\tLazySegmentTree(const\
    \ std::vector<D>& v,\r\n\t\t\tD _e_d,\r\n\t\t\tL _e_l,\r\n\t\t\tOpDD _op_dd,\r\
    \n\t\t\tOpDL _op_dl,\r\n\t\t\tOpLL _op_ll)\r\n\t\t: e_d(_e_d), e_l(_e_l), op_dd(_op_dd),\
    \ op_dl(_op_dl), op_ll(_op_ll) {\r\n\t\tinit(v);\r\n\t}\r\n\r\n\tvoid all_add(int\
    \ k, L x) {\r\n\t\td[k] = op_dl(d[k], x);\r\n\t\tif (k < sz) lz[k] = op_ll(lz[k],\
    \ x);\r\n\t}\r\n\r\n\tvoid push(int k) {\r\n\t\tall_add(2 * k, lz[k]);\r\n\t\t\
    all_add(2 * k + 1, lz[k]);\r\n\t\tlz[k] = e_l;\r\n\t}\r\n\r\n\tvoid update(int\
    \ k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }\r\n\r\n\tvoid set(int p, D x) {\r\
    \n\t\tp += sz;\r\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\r\n\t\td[p]\
    \ = x;\r\n\t\tfor (int i = 1; i <= lg; i++) update(p >> i);\r\n\t}\r\n\r\n\tvoid\
    \ add(int a, int b, L x, int l, int r, int k) {\r\n\t\tif (b <= l || r <= a) return;\r\
    \n\t\tif (a <= l && r <= b) {\r\n\t\t\tall_add(k, x);\r\n\t\t\treturn;\r\n\t\t\
    }\r\n\t\tpush(k);\r\n\t\tint mid = (l + r) / 2;\r\n\t\tadd(a, b, x, l, mid, 2\
    \ * k);\r\n\t\tadd(a, b, x, mid, r, 2 * k + 1);\r\n\t\tupdate(k);\r\n\t}\r\n\r\
    \n\tvoid add(int a, int b, L x) {\r\n\t\t++b;\r\n\t\ta += sz;\r\n\t\tb += sz;\r\
    \n\t\tfor (int i = lg; i >= 1; i--) {\r\n\t\t\tif (((a >> i) << i) != a) push(a\
    \ >> i);\r\n\t\t\tif (((b >> i) << i) != b) push((b - 1) >> i);\r\n\t\t}\r\n\t\
    \t{\r\n\t\t\tint a2 = a, b2 = b;\r\n\t\t\twhile (a < b) {\r\n\t\t\t\tif (a & 1)\
    \ all_add(a++, x);\r\n\t\t\t\tif (b & 1) all_add(--b, x);\r\n\t\t\t\ta >>= 1;\r\
    \n\t\t\t\tb >>= 1;\r\n\t\t\t}\r\n\t\t\ta = a2;\r\n\t\t\tb = b2;\r\n\t\t}\r\n\t\
    \tfor (int i = 1; i <= lg; i++) {\r\n\t\t\tif (((a >> i) << i) != a) update(a\
    \ >> i);\r\n\t\t\tif (((b >> i) << i) != b) update((b - 1) >> i);\r\n\t\t}\r\n\
    \t}\r\n\r\n\tD single(int p) {\r\n\t\tp += sz;\r\n\t\tfor (int i = lg; i >= 1;\
    \ i--) push(p >> i);\r\n\t\treturn d[p];\r\n\t}\r\n\r\n\tD sum(int a, int b, int\
    \ l, int r, int k) {\r\n\t\tif (b <= l || r <= a) return e_d;\r\n\t\tif (a <=\
    \ l && r <= b) return d[k];\r\n\t\tpush(k);\r\n\t\tint mid = (l + r) / 2;\r\n\t\
    \treturn op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));\r\n\t\
    }\r\n\r\n\tD sum(int a, int b) {\r\n\t\t++b;\r\n\t\tif (a == b) return e_d;\r\n\
    \t\ta += sz;\r\n\t\tb += sz;\r\n\t\tfor (int i = lg; i >= 1; i--) {\r\n\t\t\t\
    if (((a >> i) << i) != a) push(a >> i);\r\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\r\n\t\t}\r\n\t\tD sml = e_d, smr = e_d;\r\n\t\twhile (a < b) {\r\
    \n\t\t\tif (a & 1) sml = op_dd(sml, d[a++]);\r\n\t\t\tif (b & 1) smr = op_dd(d[--b],\
    \ smr);\r\n\t\t\ta >>= 1;\r\n\t\t\tb >>= 1;\r\n\t\t}\r\n\t\treturn op_dd(sml,\
    \ smr);\r\n\t}\r\n\r\n\tD all_sum() const { return d[1]; }\r\n};\r\n\r\ntemplate\
    \ <class D, class L, class OpDD, class OpDL, class OpLL>\r\nLazySegmentTree<D,\
    \ L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D> v,\r\n\t\t\t\t\t\t\
    \t\t\t\tD e_d,\r\n\t\t\t\t\t\t\t\t\t\tL e_l,\r\n\t\t\t\t\t\t\t\t\t\tOpDD op_dd,\r\
    \n\t\t\t\t\t\t\t\t\t\tOpDL op_dl,\r\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll) {\r\n\treturn\
    \ LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class D, class L, class OpDD, class OpDL, class\
    \ OpLL> struct LazySegmentTree {\r\n\tD e_d;\r\n\tL e_l;\r\n\tOpDD op_dd; \r\n\
    \tOpDL op_dl;\r\n\tOpLL op_ll;\r\n\tint sz, lg;  \r\n\tstd::vector<D> d;\r\n\t\
    std::vector<L> lz;\r\n\r\n\tvoid init(const std::vector<D>& v) {\r\n\t\tint n\
    \ = int(v.size());\r\n\t\tlg = 1;\r\n\t\twhile ((1 << lg) < n) lg++;\r\n\t\tsz\
    \ = 1 << lg;\r\n\t\td = std::vector<D>(2 * sz, e_d);\r\n\t\tlz = std::vector<L>(2\
    \ * sz, e_l);\r\n\t\tfor (int i = 0; i < n; i++) d[sz + i] = v[i];\r\n\t\tfor\
    \ (int i = sz - 1; i >= 0; i--) {\r\n\t\t\tupdate(i);\r\n\t\t}\r\n\t}\r\n\r\n\t\
    LazySegmentTree(const std::vector<D>& v,\r\n\t\t\tD _e_d,\r\n\t\t\tL _e_l,\r\n\
    \t\t\tOpDD _op_dd,\r\n\t\t\tOpDL _op_dl,\r\n\t\t\tOpLL _op_ll)\r\n\t\t: e_d(_e_d),\
    \ e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {\r\n\t\tinit(v);\r\n\
    \t}\r\n\r\n\tvoid all_add(int k, L x) {\r\n\t\td[k] = op_dl(d[k], x);\r\n\t\t\
    if (k < sz) lz[k] = op_ll(lz[k], x);\r\n\t}\r\n\r\n\tvoid push(int k) {\r\n\t\t\
    all_add(2 * k, lz[k]);\r\n\t\tall_add(2 * k + 1, lz[k]);\r\n\t\tlz[k] = e_l;\r\
    \n\t}\r\n\r\n\tvoid update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }\r\n\
    \r\n\tvoid set(int p, D x) {\r\n\t\tp += sz;\r\n\t\tfor (int i = lg; i >= 1; i--)\
    \ push(p >> i);\r\n\t\td[p] = x;\r\n\t\tfor (int i = 1; i <= lg; i++) update(p\
    \ >> i);\r\n\t}\r\n\r\n\tvoid add(int a, int b, L x, int l, int r, int k) {\r\n\
    \t\tif (b <= l || r <= a) return;\r\n\t\tif (a <= l && r <= b) {\r\n\t\t\tall_add(k,\
    \ x);\r\n\t\t\treturn;\r\n\t\t}\r\n\t\tpush(k);\r\n\t\tint mid = (l + r) / 2;\r\
    \n\t\tadd(a, b, x, l, mid, 2 * k);\r\n\t\tadd(a, b, x, mid, r, 2 * k + 1);\r\n\
    \t\tupdate(k);\r\n\t}\r\n\r\n\tvoid add(int a, int b, L x) {\r\n\t\t++b;\r\n\t\
    \ta += sz;\r\n\t\tb += sz;\r\n\t\tfor (int i = lg; i >= 1; i--) {\r\n\t\t\tif\
    \ (((a >> i) << i) != a) push(a >> i);\r\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\r\n\t\t}\r\n\t\t{\r\n\t\t\tint a2 = a, b2 = b;\r\n\t\t\twhile (a\
    \ < b) {\r\n\t\t\t\tif (a & 1) all_add(a++, x);\r\n\t\t\t\tif (b & 1) all_add(--b,\
    \ x);\r\n\t\t\t\ta >>= 1;\r\n\t\t\t\tb >>= 1;\r\n\t\t\t}\r\n\t\t\ta = a2;\r\n\t\
    \t\tb = b2;\r\n\t\t}\r\n\t\tfor (int i = 1; i <= lg; i++) {\r\n\t\t\tif (((a >>\
    \ i) << i) != a) update(a >> i);\r\n\t\t\tif (((b >> i) << i) != b) update((b\
    \ - 1) >> i);\r\n\t\t}\r\n\t}\r\n\r\n\tD single(int p) {\r\n\t\tp += sz;\r\n\t\
    \tfor (int i = lg; i >= 1; i--) push(p >> i);\r\n\t\treturn d[p];\r\n\t}\r\n\r\
    \n\tD sum(int a, int b, int l, int r, int k) {\r\n\t\tif (b <= l || r <= a) return\
    \ e_d;\r\n\t\tif (a <= l && r <= b) return d[k];\r\n\t\tpush(k);\r\n\t\tint mid\
    \ = (l + r) / 2;\r\n\t\treturn op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid,\
    \ r, 2 * k + 1));\r\n\t}\r\n\r\n\tD sum(int a, int b) {\r\n\t\t++b;\r\n\t\tif\
    \ (a == b) return e_d;\r\n\t\ta += sz;\r\n\t\tb += sz;\r\n\t\tfor (int i = lg;\
    \ i >= 1; i--) {\r\n\t\t\tif (((a >> i) << i) != a) push(a >> i);\r\n\t\t\tif\
    \ (((b >> i) << i) != b) push((b - 1) >> i);\r\n\t\t}\r\n\t\tD sml = e_d, smr\
    \ = e_d;\r\n\t\twhile (a < b) {\r\n\t\t\tif (a & 1) sml = op_dd(sml, d[a++]);\r\
    \n\t\t\tif (b & 1) smr = op_dd(d[--b], smr);\r\n\t\t\ta >>= 1;\r\n\t\t\tb >>=\
    \ 1;\r\n\t\t}\r\n\t\treturn op_dd(sml, smr);\r\n\t}\r\n\r\n\tD all_sum() const\
    \ { return d[1]; }\r\n};\r\n\r\ntemplate <class D, class L, class OpDD, class\
    \ OpDL, class OpLL>\r\nLazySegmentTree<D, L, OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D>\
    \ v,\r\n\t\t\t\t\t\t\t\t\t\tD e_d,\r\n\t\t\t\t\t\t\t\t\t\tL e_l,\r\n\t\t\t\t\t\
    \t\t\t\t\tOpDD op_dd,\r\n\t\t\t\t\t\t\t\t\t\tOpDL op_dl,\r\n\t\t\t\t\t\t\t\t\t\
    \tOpLL op_ll) {\r\n\treturn LazySegmentTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l,\
    \ op_dd, op_dl, op_ll);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
documentation_of: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/general-full-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/general-full-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
---
