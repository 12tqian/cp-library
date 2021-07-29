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
  bundledCode: "\n\nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid init(int n) {\n\t\
    \te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0\
    \ ? x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn\
    \ get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\
    \n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x == y) return\
    \ false;\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\
    \t\treturn true;\n\t}\n};\n\n\n// weight, start, end\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\n\tDSU D;\n\tint n = 0;\n\tfor (auto &a : edge) {\n\t\tn = std::max(n,\
    \ a[1]);\n\t\tn = std::max(n, a[2]);\n\t}\n\t++n;\n\tD.init(n);\n\tsort(edge.begin(),\
    \ edge.end());\n\tlong long ans = 0;\n\tfor (auto &a : edge) {\n\t\tif (D.unite(a[1],\
    \ a[2])) {\n\t\t\tans += a[0];\n\t\t}\n\t}\n\treturn ans;\n}\n"
  code: "#pragma once\n\n#include \"dsu.hpp\"\n\n// weight, start, end\nlong long\
    \ kruskal(std::vector<std::array<int, 3>> edge) {\n\tDSU D;\n\tint n = 0;\n\t\
    for (auto &a : edge) {\n\t\tn = std::max(n, a[1]);\n\t\tn = std::max(n, a[2]);\n\
    \t}\n\t++n;\n\tD.init(n);\n\tsort(edge.begin(), edge.end());\n\tlong long ans\
    \ = 0;\n\tfor (auto &a : edge) {\n\t\tif (D.unite(a[1], a[2])) {\n\t\t\tans +=\
    \ a[0];\n\t\t}\n\t}\n\treturn ans;\n}\n"
  dependsOn:
  - library/graphs/dsu.hpp
  isVerificationFile: false
  path: library/graphs/kruskal.hpp
  requiredBy: []
  timestamp: '2021-07-25 00:45:08-04:00'
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
