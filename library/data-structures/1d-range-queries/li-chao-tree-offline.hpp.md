---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
    title: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "\n// Set to minimums, negate for maximums\n\ntemplate <class T> struct\
    \ LiChaoTree {\n\tstruct Line {\n\t\tT slope, intercept;\n\t\tLine(T slope, T\
    \ intercept) : slope(slope), intercept(intercept) {}\n\t\tinline T get(T x) const\
    \ { return slope * x + intercept; }\n\t\tinline bool over(const Line &other, const\
    \ T &x) {\n\t\t\treturn get(x) < other.get(x);\n\t\t}\n\t};\n\n\tstd::vector<T>\
    \ xset;\n\tstd::vector<Line> seg;\n\tint sz;\n\n\tLiChaoTree(const std::vector<T>\
    \ &x) : xset(x) {\n\t\tsort(xset.begin(), xset.end());\n\t\txset.erase(unique(xset.begin(),\
    \ xset.end()), xset.end());\n\t\tsz = 1;\n\t\twhile (sz < (int) xset.size()) sz\
    \ <<= 1;\n\t\twhile ((int) xset.size() < sz) xset.push_back(xset.back());\n\t\t\
    seg.assign(2 * sz, Line(0, std::numeric_limits<T>::max()));\n\t}\n\n\tint get_more_idx(T\
    \ k) {\n\t\treturn lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n\t\
    }\n\n\tint get_less_idx(T k) {\n\t\tint ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\n\t\treturn std::max(0, ret - 1);\n\t}\n\n\tvoid inner_update(T\
    \ a, T b, int ind, int L, int R) {\n\t\tLine line(a, b);\n\t\twhile (true) {\n\
    \t\t\tint M = (L + R) >> 1;\n\t\t\tbool l_over = line.over(seg[ind], xset[L]);\n\
    \t\t\tbool r_over = line.over(seg[ind], xset[R - 1]);\n\t\t\tif (l_over == r_over)\
    \ {\n\t\t\t\tif (l_over) std::swap(seg[ind], line);\n\t\t\t\treturn;\n\t\t\t}\n\
    \t\t\tbool m_over = line.over(seg[ind], xset[M]);\n\t\t\tif (m_over) std::swap(seg[ind],\
    \ line);\n\t\t\tif (l_over != m_over) \n\t\t\t\tind = (ind << 1), R = M;\n\t\t\
    \telse \n\t\t\t\tind = (ind << 1) | 1, L = M;\n\n\t\t}\n\t}\n\n\tvoid inner_update(T\
    \ a, T b, int ind) {\n\t\tint L, R;\n\t\tint up = 31 - __builtin_clz(ind);\n\t\
    \tL = (sz >> up) * (ind - (1 << up));\n\t\tR = L + (sz >> up);\n\t\tinner_update(a,\
    \ b, ind, L, R);\n\t}\n\n\tvoid update(T a, T b) { inner_update(a, b, 1, 0, sz);\
    \ }\n\n\tvoid update_segment(T a, T b, T lo, T hi) {\n\t\tint L = get_more_idx(lo)\
    \ + sz;\n\t\tint R = get_less_idx(hi) + sz + 1;\n\t\tfor (; L < R; L >>= 1, R\
    \ >>= 1) {\n\t\t\tif (L & 1) inner_update(a, b, L++);\n\t\t\tif (R & 1) inner_update(a,\
    \ b, --R);\n\t\t}\n\t}\n\n\tT inner_query(T x, int ind) {\n\t\tT ret = seg[ind].get(x);\n\
    \t\twhile (ind > 1) {\n\t\t\tind = ind >> 1;\n\t\t\tret = std::min(ret, seg[ind].get(x));\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\tT query_idx(int k) {\n\t\tconst T x = xset[k];\n\
    \t\tk += sz;\n\t\treturn inner_query(x, k);\n\t}\n\t\n\tT query(T x) { return\
    \ query_idx(get_more_idx(x)); }\n};\n"
  code: "#pragma once\n\n// Set to minimums, negate for maximums\n\ntemplate <class\
    \ T> struct LiChaoTree {\n\tstruct Line {\n\t\tT slope, intercept;\n\t\tLine(T\
    \ slope, T intercept) : slope(slope), intercept(intercept) {}\n\t\tinline T get(T\
    \ x) const { return slope * x + intercept; }\n\t\tinline bool over(const Line\
    \ &other, const T &x) {\n\t\t\treturn get(x) < other.get(x);\n\t\t}\n\t};\n\n\t\
    std::vector<T> xset;\n\tstd::vector<Line> seg;\n\tint sz;\n\n\tLiChaoTree(const\
    \ std::vector<T> &x) : xset(x) {\n\t\tsort(xset.begin(), xset.end());\n\t\txset.erase(unique(xset.begin(),\
    \ xset.end()), xset.end());\n\t\tsz = 1;\n\t\twhile (sz < (int) xset.size()) sz\
    \ <<= 1;\n\t\twhile ((int) xset.size() < sz) xset.push_back(xset.back());\n\t\t\
    seg.assign(2 * sz, Line(0, std::numeric_limits<T>::max()));\n\t}\n\n\tint get_more_idx(T\
    \ k) {\n\t\treturn lower_bound(xset.begin(), xset.end(), k) - xset.begin();\n\t\
    }\n\n\tint get_less_idx(T k) {\n\t\tint ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\n\t\treturn std::max(0, ret - 1);\n\t}\n\n\tvoid inner_update(T\
    \ a, T b, int ind, int L, int R) {\n\t\tLine line(a, b);\n\t\twhile (true) {\n\
    \t\t\tint M = (L + R) >> 1;\n\t\t\tbool l_over = line.over(seg[ind], xset[L]);\n\
    \t\t\tbool r_over = line.over(seg[ind], xset[R - 1]);\n\t\t\tif (l_over == r_over)\
    \ {\n\t\t\t\tif (l_over) std::swap(seg[ind], line);\n\t\t\t\treturn;\n\t\t\t}\n\
    \t\t\tbool m_over = line.over(seg[ind], xset[M]);\n\t\t\tif (m_over) std::swap(seg[ind],\
    \ line);\n\t\t\tif (l_over != m_over) \n\t\t\t\tind = (ind << 1), R = M;\n\t\t\
    \telse \n\t\t\t\tind = (ind << 1) | 1, L = M;\n\n\t\t}\n\t}\n\n\tvoid inner_update(T\
    \ a, T b, int ind) {\n\t\tint L, R;\n\t\tint up = 31 - __builtin_clz(ind);\n\t\
    \tL = (sz >> up) * (ind - (1 << up));\n\t\tR = L + (sz >> up);\n\t\tinner_update(a,\
    \ b, ind, L, R);\n\t}\n\n\tvoid update(T a, T b) { inner_update(a, b, 1, 0, sz);\
    \ }\n\n\tvoid update_segment(T a, T b, T lo, T hi) {\n\t\tint L = get_more_idx(lo)\
    \ + sz;\n\t\tint R = get_less_idx(hi) + sz + 1;\n\t\tfor (; L < R; L >>= 1, R\
    \ >>= 1) {\n\t\t\tif (L & 1) inner_update(a, b, L++);\n\t\t\tif (R & 1) inner_update(a,\
    \ b, --R);\n\t\t}\n\t}\n\n\tT inner_query(T x, int ind) {\n\t\tT ret = seg[ind].get(x);\n\
    \t\twhile (ind > 1) {\n\t\t\tind = ind >> 1;\n\t\t\tret = std::min(ret, seg[ind].get(x));\n\
    \t\t}\n\t\treturn ret;\n\t}\n\n\tT query_idx(int k) {\n\t\tconst T x = xset[k];\n\
    \t\tk += sz;\n\t\treturn inner_query(x, k);\n\t}\n\t\n\tT query(T x) { return\
    \ query_idx(get_more_idx(x)); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
  requiredBy: []
  timestamp: '2021-07-24 21:27:52-04:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
documentation_of: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
- /library/library/data-structures/1d-range-queries/li-chao-tree-offline.hpp.html
title: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
---
