---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/graphs/dsu.hpp
    title: library/graphs/dsu.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aizu/aizu-GRL_2_A.test.cpp
    title: verify/aizu/aizu-GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\n\r\nstruct DSU {\r\n  std::vector<int> e;\r\n\r\n  DSU() = default;\r\
    \n  DSU(int n) { init(n); }\r\n\r\n  void init(int n) { e = std::vector<int>(n,\
    \ -1); }\r\n\r\n  int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }\r\
    \n\r\n  bool same_set(int a, int b) { return get(a) == get(b); }\r\n\r\n  int\
    \ size(int x) { return -e[get(x)]; }\r\n\r\n  bool unite(int x, int y) {\r\n \
    \   x = get(x), y = get(y);\r\n    if (x == y) return false;\r\n    if (e[x] >\
    \ e[y]) std::swap(x, y);\r\n    e[x] += e[y];\r\n    e[y] = x;\r\n    return true;\r\
    \n  }\r\n};\r\n\r\n// weight, start, end\r\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\r\n\tDSU D;\r\n\tint n = 0;\r\n\tfor (auto& a : edge) {\r\n\t\t\
    n = std::max(n, a[1]);\r\n\t\tn = std::max(n, a[2]);\r\n\t}\r\n\t++n;\r\n\tD.init(n);\r\
    \n\tsort(edge.begin(), edge.end());\r\n\tlong long ans = 0;\r\n\tfor (auto& a\
    \ : edge) {\r\n\t\tif (D.unite(a[1], a[2])) {\r\n\t\t\tans += a[0];\r\n\t\t}\r\
    \n\t}\r\n\treturn ans;\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"dsu.hpp\"\r\n\r\n// weight, start, end\r\n\
    long long kruskal(std::vector<std::array<int, 3>> edge) {\r\n\tDSU D;\r\n\tint\
    \ n = 0;\r\n\tfor (auto& a : edge) {\r\n\t\tn = std::max(n, a[1]);\r\n\t\tn =\
    \ std::max(n, a[2]);\r\n\t}\r\n\t++n;\r\n\tD.init(n);\r\n\tsort(edge.begin(),\
    \ edge.end());\r\n\tlong long ans = 0;\r\n\tfor (auto& a : edge) {\r\n\t\tif (D.unite(a[1],\
    \ a[2])) {\r\n\t\t\tans += a[0];\r\n\t\t}\r\n\t}\r\n\treturn ans;\r\n}\r\n"
  dependsOn:
  - library/graphs/dsu.hpp
  isVerificationFile: false
  path: library/graphs/kruskal.hpp
  requiredBy: []
  timestamp: '2023-01-08 14:16:34-05:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aizu/aizu-GRL_2_A.test.cpp
documentation_of: library/graphs/kruskal.hpp
layout: document
redirect_from:
- /library/library/graphs/kruskal.hpp
- /library/library/graphs/kruskal.hpp.html
title: library/graphs/kruskal.hpp
---
