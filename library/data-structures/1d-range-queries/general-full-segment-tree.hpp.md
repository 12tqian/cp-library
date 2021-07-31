---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-point_set_range_composite.test.cpp
    title: verify/yosupo/yosupo-point_set_range_composite.test.cpp
  - icon: ':x:'
    path: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
    title: verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "\ntemplate <class D, class L, class OpDD, class OpDL, class OpLL>\
    \ struct LazySegmentTree {\n\tD e_d;\n\tL e_l;\n\tOpDD op_dd; \n\tOpDL op_dl;\n\
    \tOpLL op_ll;\n\tint sz, lg;  \n\tstd::vector<D> d;\n\tstd::vector<L> lz;\n\n\t\
    LazySegmentTree(const std::vector<D>& v,\n\t\t\tD _e_d,\n\t\t\tL _e_l,\n\t\t\t\
    OpDD _op_dd,\n\t\t\tOpDL _op_dl,\n\t\t\tOpLL _op_ll)\n\t\t: e_d(_e_d), e_l(_e_l),\
    \ op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {\n\t\tint n = int(v.size());\n\t\
    \tlg = 1;\n\t\twhile ((1 << lg) < n) lg++;\n\t\tsz = 1 << lg;\n\t\td = std::vector<D>(2\
    \ * sz, e_d);\n\t\tlz = std::vector<L>(2 * sz, e_l);\n\t\tfor (int i = 0; i <\
    \ n; i++) d[sz + i] = v[i];\n\t\tfor (int i = sz - 1; i >= 0; i--) {\n\t\t\tupdate(i);\n\
    \t\t}\n\t}\n\n\tvoid all_add(int k, L x) {\n\t\td[k] = op_dl(d[k], x);\n\t\tif\
    \ (k < sz) lz[k] = op_ll(lz[k], x);\n\t}\n\n\tvoid push(int k) {\n\t\tall_add(2\
    \ * k, lz[k]);\n\t\tall_add(2 * k + 1, lz[k]);\n\t\tlz[k] = e_l;\n\t}\n\n\tvoid\
    \ update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }\n\n\tvoid set(int p,\
    \ D x) {\n\t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\n\t\t\
    d[p] = x;\n\t\tfor (int i = 1; i <= lg; i++) update(p >> i);\n\t}\n\n\tvoid add(int\
    \ a, int b, L x, int l, int r, int k) {\n\t\tif (b <= l || r <= a) return;\n\t\
    \tif (a <= l && r <= b) {\n\t\t\tall_add(k, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k);\n\
    \t\tint mid = (l + r) / 2;\n\t\tadd(a, b, x, l, mid, 2 * k);\n\t\tadd(a, b, x,\
    \ mid, r, 2 * k + 1);\n\t\tupdate(k);\n\t}\n\n\tvoid add(int a, int b, L x) {\n\
    \t\t++b;\n\t\ta += sz;\n\t\tb += sz;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\t\
    \tif (((a >> i) << i) != a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\n\t\t}\n\t\t{\n\t\t\tint a2 = a, b2 = b;\n\t\t\twhile (a < b) {\n\
    \t\t\t\tif (a & 1) all_add(a++, x);\n\t\t\t\tif (b & 1) all_add(--b, x);\n\t\t\
    \t\ta >>= 1;\n\t\t\t\tb >>= 1;\n\t\t\t}\n\t\t\ta = a2;\n\t\t\tb = b2;\n\t\t}\n\
    \t\tfor (int i = 1; i <= lg; i++) {\n\t\t\tif (((a >> i) << i) != a) update(a\
    \ >> i);\n\t\t\tif (((b >> i) << i) != b) update((b - 1) >> i);\n\t\t}\n\t}\n\n\
    \tD single(int p) {\n\t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >>\
    \ i);\n\t\treturn d[p];\n\t}\n\n\tD sum(int a, int b, int l, int r, int k) {\n\
    \t\tif (b <= l || r <= a) return e_d;\n\t\tif (a <= l && r <= b) return d[k];\n\
    \t\tpush(k);\n\t\tint mid = (l + r) / 2;\n\t\treturn op_dd(sum(a, b, l, mid, 2\
    \ * k), sum(a, b, mid, r, 2 * k + 1));\n\t}\n\n\tD sum(int a, int b) {\n\t\t++b;\n\
    \t\tif (a == b) return e_d;\n\t\ta += sz;\n\t\tb += sz;\n\t\tfor (int i = lg;\
    \ i >= 1; i--) {\n\t\t\tif (((a >> i) << i) != a) push(a >> i);\n\t\t\tif (((b\
    \ >> i) << i) != b) push((b - 1) >> i);\n\t\t}\n\t\tD sml = e_d, smr = e_d;\n\t\
    \twhile (a < b) {\n\t\t\tif (a & 1) sml = op_dd(sml, d[a++]);\n\t\t\tif (b & 1)\
    \ smr = op_dd(d[--b], smr);\n\t\t\ta >>= 1;\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn\
    \ op_dd(sml, smr);\n\t}\n\n\tD all_sum() const { return d[1]; }\n};\n\ntemplate\
    \ <class D, class L, class OpDD, class OpDL, class OpLL>\nLazySegmentTree<D, L,\
    \ OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D> v,\n\t\t\t\t\t\t\t\t\t\
    \tD e_d,\n\t\t\t\t\t\t\t\t\t\tL e_l,\n\t\t\t\t\t\t\t\t\t\tOpDD op_dd,\n\t\t\t\t\
    \t\t\t\t\t\tOpDL op_dl,\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll) {\n\treturn LazySegmentTree<D,\
    \ L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);\n}\n"
  code: "#pragma once\n\ntemplate <class D, class L, class OpDD, class OpDL, class\
    \ OpLL> struct LazySegmentTree {\n\tD e_d;\n\tL e_l;\n\tOpDD op_dd; \n\tOpDL op_dl;\n\
    \tOpLL op_ll;\n\tint sz, lg;  \n\tstd::vector<D> d;\n\tstd::vector<L> lz;\n\n\t\
    LazySegmentTree(const std::vector<D>& v,\n\t\t\tD _e_d,\n\t\t\tL _e_l,\n\t\t\t\
    OpDD _op_dd,\n\t\t\tOpDL _op_dl,\n\t\t\tOpLL _op_ll)\n\t\t: e_d(_e_d), e_l(_e_l),\
    \ op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {\n\t\tint n = int(v.size());\n\t\
    \tlg = 1;\n\t\twhile ((1 << lg) < n) lg++;\n\t\tsz = 1 << lg;\n\t\td = std::vector<D>(2\
    \ * sz, e_d);\n\t\tlz = std::vector<L>(2 * sz, e_l);\n\t\tfor (int i = 0; i <\
    \ n; i++) d[sz + i] = v[i];\n\t\tfor (int i = sz - 1; i >= 0; i--) {\n\t\t\tupdate(i);\n\
    \t\t}\n\t}\n\n\tvoid all_add(int k, L x) {\n\t\td[k] = op_dl(d[k], x);\n\t\tif\
    \ (k < sz) lz[k] = op_ll(lz[k], x);\n\t}\n\n\tvoid push(int k) {\n\t\tall_add(2\
    \ * k, lz[k]);\n\t\tall_add(2 * k + 1, lz[k]);\n\t\tlz[k] = e_l;\n\t}\n\n\tvoid\
    \ update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }\n\n\tvoid set(int p,\
    \ D x) {\n\t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >> i);\n\t\t\
    d[p] = x;\n\t\tfor (int i = 1; i <= lg; i++) update(p >> i);\n\t}\n\n\tvoid add(int\
    \ a, int b, L x, int l, int r, int k) {\n\t\tif (b <= l || r <= a) return;\n\t\
    \tif (a <= l && r <= b) {\n\t\t\tall_add(k, x);\n\t\t\treturn;\n\t\t}\n\t\tpush(k);\n\
    \t\tint mid = (l + r) / 2;\n\t\tadd(a, b, x, l, mid, 2 * k);\n\t\tadd(a, b, x,\
    \ mid, r, 2 * k + 1);\n\t\tupdate(k);\n\t}\n\n\tvoid add(int a, int b, L x) {\n\
    \t\t++b;\n\t\ta += sz;\n\t\tb += sz;\n\t\tfor (int i = lg; i >= 1; i--) {\n\t\t\
    \tif (((a >> i) << i) != a) push(a >> i);\n\t\t\tif (((b >> i) << i) != b) push((b\
    \ - 1) >> i);\n\t\t}\n\t\t{\n\t\t\tint a2 = a, b2 = b;\n\t\t\twhile (a < b) {\n\
    \t\t\t\tif (a & 1) all_add(a++, x);\n\t\t\t\tif (b & 1) all_add(--b, x);\n\t\t\
    \t\ta >>= 1;\n\t\t\t\tb >>= 1;\n\t\t\t}\n\t\t\ta = a2;\n\t\t\tb = b2;\n\t\t}\n\
    \t\tfor (int i = 1; i <= lg; i++) {\n\t\t\tif (((a >> i) << i) != a) update(a\
    \ >> i);\n\t\t\tif (((b >> i) << i) != b) update((b - 1) >> i);\n\t\t}\n\t}\n\n\
    \tD single(int p) {\n\t\tp += sz;\n\t\tfor (int i = lg; i >= 1; i--) push(p >>\
    \ i);\n\t\treturn d[p];\n\t}\n\n\tD sum(int a, int b, int l, int r, int k) {\n\
    \t\tif (b <= l || r <= a) return e_d;\n\t\tif (a <= l && r <= b) return d[k];\n\
    \t\tpush(k);\n\t\tint mid = (l + r) / 2;\n\t\treturn op_dd(sum(a, b, l, mid, 2\
    \ * k), sum(a, b, mid, r, 2 * k + 1));\n\t}\n\n\tD sum(int a, int b) {\n\t\t++b;\n\
    \t\tif (a == b) return e_d;\n\t\ta += sz;\n\t\tb += sz;\n\t\tfor (int i = lg;\
    \ i >= 1; i--) {\n\t\t\tif (((a >> i) << i) != a) push(a >> i);\n\t\t\tif (((b\
    \ >> i) << i) != b) push((b - 1) >> i);\n\t\t}\n\t\tD sml = e_d, smr = e_d;\n\t\
    \twhile (a < b) {\n\t\t\tif (a & 1) sml = op_dd(sml, d[a++]);\n\t\t\tif (b & 1)\
    \ smr = op_dd(d[--b], smr);\n\t\t\ta >>= 1;\n\t\t\tb >>= 1;\n\t\t}\n\t\treturn\
    \ op_dd(sml, smr);\n\t}\n\n\tD all_sum() const { return d[1]; }\n};\n\ntemplate\
    \ <class D, class L, class OpDD, class OpDL, class OpLL>\nLazySegmentTree<D, L,\
    \ OpDD, OpDL, OpLL> get_lazy_segment_tree(std::vector<D> v,\n\t\t\t\t\t\t\t\t\t\
    \tD e_d,\n\t\t\t\t\t\t\t\t\t\tL e_l,\n\t\t\t\t\t\t\t\t\t\tOpDD op_dd,\n\t\t\t\t\
    \t\t\t\t\t\tOpDL op_dl,\n\t\t\t\t\t\t\t\t\t\tOpLL op_ll) {\n\treturn LazySegmentTree<D,\
    \ L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
  requiredBy: []
  timestamp: '2021-07-30 22:48:36-04:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/yosupo/yosupo-vertex_add_path_sum-new-hld.test.cpp
  - verify/yosupo/yosupo-point_set_range_composite.test.cpp
documentation_of: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/general-full-segment-tree.hpp
- /library/library/data-structures/1d-range-queries/general-full-segment-tree.hpp.html
title: library/data-structures/1d-range-queries/general-full-segment-tree.hpp
---
