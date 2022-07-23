---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
    title: verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n/**\r\n * x \\in [0, sz)\r\n * y \\in [0, sz)\r\n * First do all\
    \ the updates, then call init\r\n * Afterwards, do the updates again, and now\
    \ you can mix in the queries too\r\n */\r\n\r\ntemplate <class T> struct Offline2DBIT\
    \ { \r\n\tbool mode = false; // mode = 1 -> initialized\r\n\tint sz;\r\n\tstd::vector<std::pair<int,\
    \ int>> todo;\r\n\tstd::vector<int> cnt, st, val;\r\n\tstd::vector<T> bit;\r\n\
    \r\n\tvoid init(int sz_) {\r\n\t\tsz = sz_;\r\n\t\tsz++;\r\n\t\tcnt.assign(sz,\
    \ 0);\r\n\t\tst.assign(sz, 0);\r\n\t\tassert(!mode); mode = 1;\r\n\t\tstd::vector<int>\
    \ lst(sz, 0);\r\n\t\tcnt.assign(sz, 0);\r\n\t\tsort(todo.begin(), todo.end(),\
    \ [](const std::pair<int, int>& a, const std::pair<int, int>& b) { \r\n\t\t\t\
    return a.second < b.second; });\r\n\t\tfor (auto& t : todo) \r\n\t\t\tfor (int\
    \ x = t.first; x < sz; x += x & -x)\r\n\t\t\t\tif (lst[x] != t.second)\r\n\t\t\
    \t\t\tlst[x] = t.second, cnt[x]++;\r\n\t\tint sum = 0; \r\n\t\tfor (int i = 0;\
    \ i < sz; i++)\r\n\t\t\tlst[i] = 0, st[i] = (sum += cnt[i]);\r\n\t\tval.resize(sum);\
    \ bit.resize(sum);\r\n\t\treverse(todo.begin(), todo.end());\r\n\t\tfor (auto&\
    \ t : todo) \r\n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\r\n\t\t\t\tif\
    \ (lst[x] != t.second)\r\n\t\t\t\t\tlst[x] = t.second, val[--st[x]] = t.second;\r\
    \n\t}\r\n\r\n\tint rank(int y, int l, int r) {\r\n\t\treturn std::upper_bound(val.begin()\
    \ + l, val.begin() + r, y) - val.begin() - l;\r\n\t}\r\n\r\n\tvoid inner_update(int\
    \ x, int y, T t) {\r\n\t\tfor (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x];\
    \ y += y & -y)\r\n\t\t\tbit[st[x] + y - 1] += t;\r\n\t}\r\n\r\n\tvoid update(int\
    \ x, int y, T t) {\r\n\t\tx++, y++;\r\n\t\tif (!mode) todo.push_back({x, y});\r\
    \n\t\telse \r\n\t\t\tfor (; x < sz; x += x & -x)\r\n\t\t\t\tinner_update(x, y,\
    \ t);\r\n\t}\r\n\r\n\tT inner_query(int x, int y) {\r\n\t\tT res = 0;\r\n\t\t\
    for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y)\r\n\t\t\tres += bit[st[x]\
    \ + y - 1];\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT query(int x, int y) {\r\n\t\t\
    x++, y++;\r\n\t\tassert(mode);\r\n\t\tT res = 0;\r\n\t\tfor (; x; x -= x & -x)\
    \ \r\n\t\t\tres += inner_query(x, y);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tT query(int\
    \ xl, int xr, int yl, int yr) {\r\n\t\treturn query(xr, yr) - query(xl - 1, yr)\
    \ - query(xr, yl - 1) + query(xl - 1, yl - 1);\r\n\t}\r\n};\r\n"
  code: "#pragma once\r\n\r\n/**\r\n * x \\in [0, sz)\r\n * y \\in [0, sz)\r\n * First\
    \ do all the updates, then call init\r\n * Afterwards, do the updates again, and\
    \ now you can mix in the queries too\r\n */\r\n\r\ntemplate <class T> struct Offline2DBIT\
    \ { \r\n\tbool mode = false; // mode = 1 -> initialized\r\n\tint sz;\r\n\tstd::vector<std::pair<int,\
    \ int>> todo;\r\n\tstd::vector<int> cnt, st, val;\r\n\tstd::vector<T> bit;\r\n\
    \r\n\tvoid init(int sz_) {\r\n\t\tsz = sz_;\r\n\t\tsz++;\r\n\t\tcnt.assign(sz,\
    \ 0);\r\n\t\tst.assign(sz, 0);\r\n\t\tassert(!mode); mode = 1;\r\n\t\tstd::vector<int>\
    \ lst(sz, 0);\r\n\t\tcnt.assign(sz, 0);\r\n\t\tsort(todo.begin(), todo.end(),\
    \ [](const std::pair<int, int>& a, const std::pair<int, int>& b) { \r\n\t\t\t\
    return a.second < b.second; });\r\n\t\tfor (auto& t : todo) \r\n\t\t\tfor (int\
    \ x = t.first; x < sz; x += x & -x)\r\n\t\t\t\tif (lst[x] != t.second)\r\n\t\t\
    \t\t\tlst[x] = t.second, cnt[x]++;\r\n\t\tint sum = 0; \r\n\t\tfor (int i = 0;\
    \ i < sz; i++)\r\n\t\t\tlst[i] = 0, st[i] = (sum += cnt[i]);\r\n\t\tval.resize(sum);\
    \ bit.resize(sum);\r\n\t\treverse(todo.begin(), todo.end());\r\n\t\tfor (auto&\
    \ t : todo) \r\n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\r\n\t\t\t\tif\
    \ (lst[x] != t.second)\r\n\t\t\t\t\tlst[x] = t.second, val[--st[x]] = t.second;\r\
    \n\t}\r\n\r\n\tint rank(int y, int l, int r) {\r\n\t\treturn std::upper_bound(val.begin()\
    \ + l, val.begin() + r, y) - val.begin() - l;\r\n\t}\r\n\r\n\tvoid inner_update(int\
    \ x, int y, T t) {\r\n\t\tfor (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x];\
    \ y += y & -y)\r\n\t\t\tbit[st[x] + y - 1] += t;\r\n\t}\r\n\r\n\tvoid update(int\
    \ x, int y, T t) {\r\n\t\tx++, y++;\r\n\t\tif (!mode) todo.push_back({x, y});\r\
    \n\t\telse \r\n\t\t\tfor (; x < sz; x += x & -x)\r\n\t\t\t\tinner_update(x, y,\
    \ t);\r\n\t}\r\n\r\n\tT inner_query(int x, int y) {\r\n\t\tT res = 0;\r\n\t\t\
    for (y = rank(y, st[x], st[x] + cnt[x]); y; y -= y & -y)\r\n\t\t\tres += bit[st[x]\
    \ + y - 1];\r\n\t\treturn res;\r\n\t}\r\n\r\n\tT query(int x, int y) {\r\n\t\t\
    x++, y++;\r\n\t\tassert(mode);\r\n\t\tT res = 0;\r\n\t\tfor (; x; x -= x & -x)\
    \ \r\n\t\t\tres += inner_query(x, y);\r\n\t\treturn res;\r\n\t}\r\n\t\r\n\tT query(int\
    \ xl, int xr, int yl, int yr) {\r\n\t\treturn query(xr, yr) - query(xl - 1, yr)\
    \ - query(xr, yl - 1) + query(xl - 1, yl - 1);\r\n\t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
  requiredBy: []
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/yosupo/yosupo-rectangle_sum-offline-2d-bit.test.cpp
documentation_of: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
layout: document
title: Offline 2D BIT
---

## Offline 2D BIT

This works decently fast, requires you to know locations of all updates first though. 

### Assumptions
- $x, y \in [0, sz)$

### Functions
- `update(x, y, t)`: Updates at location `(x, y)` with `t`. Call first to store locations, and again later for actual updates. 
- `init(sz)`: Needs to be called after all updates have been called. 
- `query(xl, xr, yl, yr)`: Queries sum in rectangle with corners `(xl, yl), (xr, yr)`. 


### Resources
- [Benq](https://github.com/bqi343/USACO/blob/master/Implementations/content/data-structures/2D%20Range%20Queries%20(15.2)/BIT2DOff%20(15.2).h)