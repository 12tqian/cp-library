---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
    title: verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n// Set to minimums, negate for maximums\r\n\r\ntemplate <class\
    \ T> struct LiChaoTree {\r\n\tstruct Line {\r\n\t\tT slope, intercept;\r\n\t\t\
    Line(T slope, T intercept) : slope(slope), intercept(intercept) {}\r\n\t\tinline\
    \ T get(T x) const { return slope * x + intercept; }\r\n\t\tinline bool over(const\
    \ Line& other, const T& x) {\r\n\t\t\treturn get(x) < other.get(x);\r\n\t\t}\r\
    \n\t};\r\n\r\n\tstd::vector<T> xset;\r\n\tstd::vector<Line> seg;\r\n\tint sz;\r\
    \n\r\n\tLiChaoTree(const std::vector<T>& x) : xset(x) {\r\n\t\tsort(xset.begin(),\
    \ xset.end());\r\n\t\txset.erase(unique(xset.begin(), xset.end()), xset.end());\r\
    \n\t\tsz = 1;\r\n\t\twhile (sz < (int) xset.size()) sz <<= 1;\r\n\t\twhile ((int)\
    \ xset.size() < sz) xset.push_back(xset.back());\r\n\t\tseg.assign(2 * sz, Line(0,\
    \ std::numeric_limits<T>::max()));\r\n\t}\r\n\r\n\tint get_more_idx(T k) {\r\n\
    \t\treturn lower_bound(xset.begin(), xset.end(), k) - xset.begin();\r\n\t}\r\n\
    \r\n\tint get_less_idx(T k) {\r\n\t\tint ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\r\n\t\treturn std::max(0, ret - 1);\r\n\t}\r\n\r\n\tvoid\
    \ inner_update(T a, T b, int ind, int L, int R) {\r\n\t\tLine line(a, b);\r\n\t\
    \twhile (true) {\r\n\t\t\tint M = (L + R) >> 1;\r\n\t\t\tbool l_over = line.over(seg[ind],\
    \ xset[L]);\r\n\t\t\tbool r_over = line.over(seg[ind], xset[R - 1]);\r\n\t\t\t\
    if (l_over == r_over) {\r\n\t\t\t\tif (l_over) std::swap(seg[ind], line);\r\n\t\
    \t\t\treturn;\r\n\t\t\t}\r\n\t\t\tbool m_over = line.over(seg[ind], xset[M]);\r\
    \n\t\t\tif (m_over) std::swap(seg[ind], line);\r\n\t\t\tif (l_over != m_over)\
    \ \r\n\t\t\t\tind = (ind << 1), R = M;\r\n\t\t\telse \r\n\t\t\t\tind = (ind <<\
    \ 1) | 1, L = M;\r\n\r\n\t\t}\r\n\t}\r\n\r\n\tvoid inner_update(T a, T b, int\
    \ ind) {\r\n\t\tint L, R;\r\n\t\tint up = 31 - __builtin_clz(ind);\r\n\t\tL =\
    \ (sz >> up) * (ind - (1 << up));\r\n\t\tR = L + (sz >> up);\r\n\t\tinner_update(a,\
    \ b, ind, L, R);\r\n\t}\r\n\r\n\tvoid update(T a, T b) { inner_update(a, b, 1,\
    \ 0, sz); }\r\n\r\n\tvoid update_segment(T a, T b, T lo, T hi) {\r\n\t\tint L\
    \ = get_more_idx(lo) + sz;\r\n\t\tint R = get_less_idx(hi) + sz + 1;\r\n\t\tfor\
    \ (; L < R; L >>= 1, R >>= 1) {\r\n\t\t\tif (L & 1) inner_update(a, b, L++);\r\
    \n\t\t\tif (R & 1) inner_update(a, b, --R);\r\n\t\t}\r\n\t}\r\n\r\n\tT inner_query(T\
    \ x, int ind) {\r\n\t\tT ret = seg[ind].get(x);\r\n\t\twhile (ind > 1) {\r\n\t\
    \t\tind = ind >> 1;\r\n\t\t\tret = std::min(ret, seg[ind].get(x));\r\n\t\t}\r\n\
    \t\treturn ret;\r\n\t}\r\n\r\n\tT query_idx(int k) {\r\n\t\tconst T x = xset[k];\r\
    \n\t\tk += sz;\r\n\t\treturn inner_query(x, k);\r\n\t}\r\n\t\r\n\tT query(T x)\
    \ { return query_idx(get_more_idx(x)); }\r\n};\n"
  code: "#pragma once\r\n\r\n// Set to minimums, negate for maximums\r\n\r\ntemplate\
    \ <class T> struct LiChaoTree {\r\n\tstruct Line {\r\n\t\tT slope, intercept;\r\
    \n\t\tLine(T slope, T intercept) : slope(slope), intercept(intercept) {}\r\n\t\
    \tinline T get(T x) const { return slope * x + intercept; }\r\n\t\tinline bool\
    \ over(const Line& other, const T& x) {\r\n\t\t\treturn get(x) < other.get(x);\r\
    \n\t\t}\r\n\t};\r\n\r\n\tstd::vector<T> xset;\r\n\tstd::vector<Line> seg;\r\n\t\
    int sz;\r\n\r\n\tLiChaoTree(const std::vector<T>& x) : xset(x) {\r\n\t\tsort(xset.begin(),\
    \ xset.end());\r\n\t\txset.erase(unique(xset.begin(), xset.end()), xset.end());\r\
    \n\t\tsz = 1;\r\n\t\twhile (sz < (int) xset.size()) sz <<= 1;\r\n\t\twhile ((int)\
    \ xset.size() < sz) xset.push_back(xset.back());\r\n\t\tseg.assign(2 * sz, Line(0,\
    \ std::numeric_limits<T>::max()));\r\n\t}\r\n\r\n\tint get_more_idx(T k) {\r\n\
    \t\treturn lower_bound(xset.begin(), xset.end(), k) - xset.begin();\r\n\t}\r\n\
    \r\n\tint get_less_idx(T k) {\r\n\t\tint ret = upper_bound(xset.begin(), xset.end(),\
    \ k) - xset.begin();\r\n\t\treturn std::max(0, ret - 1);\r\n\t}\r\n\r\n\tvoid\
    \ inner_update(T a, T b, int ind, int L, int R) {\r\n\t\tLine line(a, b);\r\n\t\
    \twhile (true) {\r\n\t\t\tint M = (L + R) >> 1;\r\n\t\t\tbool l_over = line.over(seg[ind],\
    \ xset[L]);\r\n\t\t\tbool r_over = line.over(seg[ind], xset[R - 1]);\r\n\t\t\t\
    if (l_over == r_over) {\r\n\t\t\t\tif (l_over) std::swap(seg[ind], line);\r\n\t\
    \t\t\treturn;\r\n\t\t\t}\r\n\t\t\tbool m_over = line.over(seg[ind], xset[M]);\r\
    \n\t\t\tif (m_over) std::swap(seg[ind], line);\r\n\t\t\tif (l_over != m_over)\
    \ \r\n\t\t\t\tind = (ind << 1), R = M;\r\n\t\t\telse \r\n\t\t\t\tind = (ind <<\
    \ 1) | 1, L = M;\r\n\r\n\t\t}\r\n\t}\r\n\r\n\tvoid inner_update(T a, T b, int\
    \ ind) {\r\n\t\tint L, R;\r\n\t\tint up = 31 - __builtin_clz(ind);\r\n\t\tL =\
    \ (sz >> up) * (ind - (1 << up));\r\n\t\tR = L + (sz >> up);\r\n\t\tinner_update(a,\
    \ b, ind, L, R);\r\n\t}\r\n\r\n\tvoid update(T a, T b) { inner_update(a, b, 1,\
    \ 0, sz); }\r\n\r\n\tvoid update_segment(T a, T b, T lo, T hi) {\r\n\t\tint L\
    \ = get_more_idx(lo) + sz;\r\n\t\tint R = get_less_idx(hi) + sz + 1;\r\n\t\tfor\
    \ (; L < R; L >>= 1, R >>= 1) {\r\n\t\t\tif (L & 1) inner_update(a, b, L++);\r\
    \n\t\t\tif (R & 1) inner_update(a, b, --R);\r\n\t\t}\r\n\t}\r\n\r\n\tT inner_query(T\
    \ x, int ind) {\r\n\t\tT ret = seg[ind].get(x);\r\n\t\twhile (ind > 1) {\r\n\t\
    \t\tind = ind >> 1;\r\n\t\t\tret = std::min(ret, seg[ind].get(x));\r\n\t\t}\r\n\
    \t\treturn ret;\r\n\t}\r\n\r\n\tT query_idx(int k) {\r\n\t\tconst T x = xset[k];\r\
    \n\t\tk += sz;\r\n\t\treturn inner_query(x, k);\r\n\t}\r\n\t\r\n\tT query(T x)\
    \ { return query_idx(get_more_idx(x)); }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-segment_add_get_min-li-chao-tree-offline.test.cpp
documentation_of: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
layout: document
redirect_from:
- /library/library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
- /library/library/data-structures/1d-range-queries/li-chao-tree-offline.hpp.html
title: library/data-structures/1d-range-queries/li-chao-tree-offline.hpp
---
