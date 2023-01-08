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
  bundledCode: "\r\nstruct DSU {\r\n  std::vector<int> e;\r\n\r\n  DSU() = default;\r\
    \n  DSU(int n) { init(n); }\r\n\r\n  void init(int n) { e = std::vector<int>(n,\
    \ -1); }\r\n\r\n  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }\r\
    \n\r\n  bool same_set(int a, int b) { return get(a) == get(b); }\r\n\r\n  int\
    \ size(int x) { return -e[get(x)]; }\r\n\r\n  bool unite(int x, int y) {\r\n \
    \   x = get(x), y = get(y);\r\n    if (x == y) return false;\r\n    if (e[x] >\
    \ e[y]) std::swap(x, y);\r\n    e[x] += e[y];\r\n    e[y] = x;\r\n    return true;\r\
    \n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct DSU {\r\n  std::vector<int> e;\r\n\r\n  DSU()\
    \ = default;\r\n  DSU(int n) { init(n); }\r\n\r\n  void init(int n) { e = std::vector<int>(n,\
    \ -1); }\r\n\r\n  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }\r\
    \n\r\n  bool same_set(int a, int b) { return get(a) == get(b); }\r\n\r\n  int\
    \ size(int x) { return -e[get(x)]; }\r\n\r\n  bool unite(int x, int y) {\r\n \
    \   x = get(x), y = get(y);\r\n    if (x == y) return false;\r\n    if (e[x] >\
    \ e[y]) std::swap(x, y);\r\n    e[x] += e[y];\r\n    e[y] = x;\r\n    return true;\r\
    \n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu.hpp
  requiredBy:
  - library/graphs/kruskal.hpp
  timestamp: '2023-01-08 14:16:34-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/codeforces/codeforces-1463E.test.cpp
  - verify/codeforces/codeforces-1553G.test.cpp
  - verify/codeforces/codeforces-1494F.test.cpp
  - verify/aizu/aizu-GRL_2_A.test.cpp
  - verify/yosupo/yosupo-unionfind.test.cpp
documentation_of: library/graphs/dsu.hpp
layout: document
redirect_from:
- /library/library/graphs/dsu.hpp
- /library/library/graphs/dsu.hpp.html
title: library/graphs/dsu.hpp
---
