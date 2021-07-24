---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/kruskal.cpp\"\n#include <bits/stdc++.h>\n\
    \nstruct DSU {\n\tstd::vector<int> e;\n\tvoid init(int n) {\n\t\te = std::vector<int>(n,\
    \ -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\t\
    int size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool unite(int x, int y) {\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n};\n\n\
    // weight, start, end\nlong long kruskal(std::vector<std::array<int, 3>> edge)\
    \ {\n\tDSU D;\n\tint n = 0;\n\tfor (auto &a : edge) {\n\t\tn = std::max(n, a[1]);\n\
    \t\tn = std::max(n, a[2]);\n\t}\n\t++n;\n\tD.init(n);\n\tsort(edge.begin(), edge.end());\n\
    \tlong long ans = 0;\n\tfor (auto &a : edge) {\n\t\tif (D.unite(a[1], a[2])) {\n\
    \t\t\tans += a[0];\n\t\t}\n\t}\n\treturn ans;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct DSU {\n\tstd::vector<int> e;\n\tvoid init(int\
    \ n) {\n\t\te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn\
    \ e[x] < 0 ? x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\
    \treturn get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\
    \t}\n\n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x ==\
    \ y) return false;\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\te[x] += e[y]; e[y]\
    \ = x;\n\t\treturn true;\n\t}\n};\n\n// weight, start, end\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\n\tDSU D;\n\tint n = 0;\n\tfor (auto &a : edge) {\n\t\tn = std::max(n,\
    \ a[1]);\n\t\tn = std::max(n, a[2]);\n\t}\n\t++n;\n\tD.init(n);\n\tsort(edge.begin(),\
    \ edge.end());\n\tlong long ans = 0;\n\tfor (auto &a : edge) {\n\t\tif (D.unite(a[1],\
    \ a[2])) {\n\t\t\tans += a[0];\n\t\t}\n\t}\n\treturn ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/kruskal.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/kruskal.cpp
layout: document
redirect_from:
- /library/library/graphs/kruskal.cpp
- /library/library/graphs/kruskal.cpp.html
title: library/graphs/kruskal.cpp
---
