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
  bundledCode: "\nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid init(int n) {\n\t\t\
    e = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ?\
    \ x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a)\
    \ == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool\
    \ unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\
    \t\tif (e[x] > e[y]) std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\t\treturn\
    \ true;\n\t}\n};\n\n"
  code: "#pragma once\n\nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid init(int n)\
    \ {\n\t\te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x]\
    \ < 0 ? x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn\
    \ get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\
    \n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\
    \t\treturn true;\n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu.hpp
  requiredBy:
  - library/graphs/kruskal.hpp
  timestamp: '2021-07-24 19:40:07-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1463E.test.cpp
  - verify/codeforces/codeforces-1494F.test.cpp
  - verify/codeforces/codeforces-1553G.test.cpp
  - verify/aizu/aizu-GRL_2_A.test.cpp
  - verify/yosupo/yosupo-unionfind.test.cpp
documentation_of: library/graphs/dsu.hpp
layout: document
redirect_from:
- /library/library/graphs/dsu.hpp
- /library/library/graphs/dsu.hpp.html
title: library/graphs/dsu.hpp
---
