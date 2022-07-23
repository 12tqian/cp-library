---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graphs/kruskal.hpp
    title: library/graphs/kruskal.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_2_A.test.cpp
    title: verify/aizu/aizu-GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1463E.test.cpp
    title: verify/codeforces/codeforces-1463E.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1494F.test.cpp
    title: verify/codeforces/codeforces-1494F.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/codeforces/codeforces-1553G.test.cpp
    title: verify/codeforces/codeforces-1553G.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yosupo/yosupo-unionfind.test.cpp
    title: verify/yosupo/yosupo-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct DSU {\r\n\tstd::vector<int> e;\r\n\r\n\tvoid init(int n)\
    \ {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint get(int x) {\r\n\t\
    \treturn e[x] < 0 ? x : e[x] = get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int a,\
    \ int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x) {\r\
    \n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tbool unite(int x, int y) {\r\n\t\tx =\
    \ get(x), y = get(y);\r\n\t\tif (x == y) return false;\r\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\r\n\t\te[x] += e[y]; e[y] = x;\r\n\t\treturn true;\r\n\t}\r\
    \n};\r\n\r\n"
  code: "#pragma once\r\n\r\nstruct DSU {\r\n\tstd::vector<int> e;\r\n\r\n\tvoid init(int\
    \ n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint get(int x) {\r\n\
    \t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int\
    \ a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x)\
    \ {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tbool unite(int x, int y) {\r\n\t\
    \tx = get(x), y = get(y);\r\n\t\tif (x == y) return false;\r\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\r\n\t\te[x] += e[y]; e[y] = x;\r\n\t\treturn true;\r\n\t}\r\
    \n};\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu.hpp
  requiredBy:
  - library/graphs/kruskal.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_2_A.test.cpp
  - verify/codeforces/codeforces-1463E.test.cpp
  - verify/codeforces/codeforces-1553G.test.cpp
  - verify/codeforces/codeforces-1494F.test.cpp
  - verify/yosupo/yosupo-unionfind.test.cpp
documentation_of: library/graphs/dsu.hpp
layout: document
redirect_from:
- /library/library/graphs/dsu.hpp
- /library/library/graphs/dsu.hpp.html
title: library/graphs/dsu.hpp
---
