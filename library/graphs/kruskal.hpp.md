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
  bundledCode: "\r\n\r\nstruct DSU {\r\n\tstd::vector<int> e;\r\n\r\n\tvoid init(int\
    \ n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint get(int x) {\r\n\
    \t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int\
    \ a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x)\
    \ {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tbool unite(int x, int y) {\r\n\t\
    \tx = get(x), y = get(y);\r\n\t\tif (x == y) return false;\r\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\r\n\t\te[x] += e[y]; e[y] = x;\r\n\t\treturn true;\r\n\t}\r\
    \n};\r\n\r\n\r\n// weight, start, end\r\nlong long kruskal(std::vector<std::array<int,\
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
  timestamp: '2022-07-21 16:12:33-04:00'
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
