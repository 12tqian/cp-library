---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/unverified/offline-2d-binary-indexed-tree.cpp
    title: verify/unverified/offline-2d-binary-indexed-tree.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "\n/**\n * x \\in [0, sz)\n * y \\in [0, sz)\n * First do all the updates,\
    \ then call init\n * Afterwards, do the updates again, and now you can mix in\
    \ the queries too\n */\n\ntemplate <class T> struct Offline2DBIT { \n\tbool mode\
    \ = false; // mode = 1 -> initialized\n\tint sz;\n\tstd::vector<std::pair<int,\
    \ int>> todo;\n\tstd::vector<int> cnt, st, val;\n\tstd::vector<T> bit;\n\n\tvoid\
    \ init(int sz_) {\n\t\tsz = sz_;\n\t\tsz++;\n\t\tcnt.assign(sz, 0);\n\t\tst.assign(sz,\
    \ 0);\n\t\tassert(!mode); mode = 1;\n\t\tstd::vector<int> lst(sz, 0);\n\t\tcnt.assign(sz,\
    \ 0);\n\t\tsort(todo.begin(), todo.end(), [](const std::pair<int, int>& a, const\
    \ std::pair<int, int>& b) { \n\t\t\treturn a.second < b.second; });\n\t\tfor (auto\
    \ &t : todo) \n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\n\t\t\t\tif (lst[x]\
    \ != t.second)\n\t\t\t\t\tlst[x] = t.second, cnt[x]++;\n\t\tint sum = 0; \n\t\t\
    for (int i = 0; i < sz; i++)\n\t\t\tlst[i] = 0, st[i] = (sum += cnt[i]);\n\t\t\
    val.resize(sum); bit.resize(sum);\n\t\treverse(todo.begin(), todo.end());\n\t\t\
    for (auto &t : todo) \n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\n\t\t\t\
    \tif (lst[x] != t.second)\n\t\t\t\t\tlst[x] = t.second, val[--st[x]] = t.second;\n\
    \t}\n\n\tint rank(int y, int l, int r) {\n\t\treturn std::upper_bound(val.begin()\
    \ + l, val.begin() + r, y) - val.begin() - l;\n\t}\n\n\tvoid inner_update(int\
    \ x, int y, T t) {\n\t\tfor (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x];\
    \ y += y & -y)\n\t\t\tbit[st[x] + y - 1] += t;\n\t}\n\n\tvoid update(int x, int\
    \ y, T t) {\n\t\tx++, y++;\n\t\tif (!mode) todo.push_back({x, y});\n\t\telse \n\
    \t\t\tfor (; x < sz; x += x & -x)\n\t\t\t\tinner_update(x, y, t);\n\t}\n\n\tint\
    \ inner_query(int x, int y) {\n\t\tT res = 0;\n\t\tfor (y = rank(y, st[x], st[x]\
    \ + cnt[x]); y; y -= y & -y)\n\t\t\tres += bit[st[x] + y - 1];\n\t\treturn res;\n\
    \t}\n\n\tT query(int x, int y) {\n\t\tx++, y++;\n\t\tassert(mode);\n\t\tT res\
    \ = 0;\n\t\tfor (; x; x -= x & -x) \n\t\t\tres += inner_query(x, y);\n\t\treturn\
    \ res;\n\t}\n\t\n\tT query(int xl, int xr, int yl, int yr) {\n\t\treturn query(xr,\
    \ yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);\n\t}\n\
    };\n"
  code: "#pragma once\n\n/**\n * x \\in [0, sz)\n * y \\in [0, sz)\n * First do all\
    \ the updates, then call init\n * Afterwards, do the updates again, and now you\
    \ can mix in the queries too\n */\n\ntemplate <class T> struct Offline2DBIT {\
    \ \n\tbool mode = false; // mode = 1 -> initialized\n\tint sz;\n\tstd::vector<std::pair<int,\
    \ int>> todo;\n\tstd::vector<int> cnt, st, val;\n\tstd::vector<T> bit;\n\n\tvoid\
    \ init(int sz_) {\n\t\tsz = sz_;\n\t\tsz++;\n\t\tcnt.assign(sz, 0);\n\t\tst.assign(sz,\
    \ 0);\n\t\tassert(!mode); mode = 1;\n\t\tstd::vector<int> lst(sz, 0);\n\t\tcnt.assign(sz,\
    \ 0);\n\t\tsort(todo.begin(), todo.end(), [](const std::pair<int, int>& a, const\
    \ std::pair<int, int>& b) { \n\t\t\treturn a.second < b.second; });\n\t\tfor (auto\
    \ &t : todo) \n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\n\t\t\t\tif (lst[x]\
    \ != t.second)\n\t\t\t\t\tlst[x] = t.second, cnt[x]++;\n\t\tint sum = 0; \n\t\t\
    for (int i = 0; i < sz; i++)\n\t\t\tlst[i] = 0, st[i] = (sum += cnt[i]);\n\t\t\
    val.resize(sum); bit.resize(sum);\n\t\treverse(todo.begin(), todo.end());\n\t\t\
    for (auto &t : todo) \n\t\t\tfor (int x = t.first; x < sz; x += x & -x)\n\t\t\t\
    \tif (lst[x] != t.second)\n\t\t\t\t\tlst[x] = t.second, val[--st[x]] = t.second;\n\
    \t}\n\n\tint rank(int y, int l, int r) {\n\t\treturn std::upper_bound(val.begin()\
    \ + l, val.begin() + r, y) - val.begin() - l;\n\t}\n\n\tvoid inner_update(int\
    \ x, int y, T t) {\n\t\tfor (y = rank(y, st[x], st[x] + cnt[x]); y <= cnt[x];\
    \ y += y & -y)\n\t\t\tbit[st[x] + y - 1] += t;\n\t}\n\n\tvoid update(int x, int\
    \ y, T t) {\n\t\tx++, y++;\n\t\tif (!mode) todo.push_back({x, y});\n\t\telse \n\
    \t\t\tfor (; x < sz; x += x & -x)\n\t\t\t\tinner_update(x, y, t);\n\t}\n\n\tint\
    \ inner_query(int x, int y) {\n\t\tT res = 0;\n\t\tfor (y = rank(y, st[x], st[x]\
    \ + cnt[x]); y; y -= y & -y)\n\t\t\tres += bit[st[x] + y - 1];\n\t\treturn res;\n\
    \t}\n\n\tT query(int x, int y) {\n\t\tx++, y++;\n\t\tassert(mode);\n\t\tT res\
    \ = 0;\n\t\tfor (; x; x -= x & -x) \n\t\t\tres += inner_query(x, y);\n\t\treturn\
    \ res;\n\t}\n\t\n\tT query(int xl, int xr, int yl, int yr) {\n\t\treturn query(xr,\
    \ yr) - query(xl - 1, yr) - query(xr, yl - 1) + query(xl - 1, yl - 1);\n\t}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
  requiredBy:
  - verify/unverified/offline-2d-binary-indexed-tree.cpp
  timestamp: '2021-07-25 00:42:29-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
layout: document
redirect_from:
- /library/library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
- /library/library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp.html
title: library/data-structures/2d-range-queries/offline-2d-binary-indexed-tree.hpp
---
