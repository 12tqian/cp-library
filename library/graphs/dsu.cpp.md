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
  bundledCode: "#line 1 \"library/graphs/dsu.cpp\"\n#include <bits/stdc++.h>\n\nstruct\
    \ DSU {\n\tstd::vector<int> e;\n\n\tvoid init(int n) {\n\t\te = std::vector<int>(n,\
    \ -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\t\
    int size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tbool unite(int x, int y) {\n\
    \t\tx = get(x), y = get(y);\n\t\tif (x == y) return false;\n\t\tif (e[x] > e[y])\
    \ std::swap(x, y);\n\t\te[x] += e[y]; e[y] = x;\n\t\treturn true;\n\t}\n};\n\n"
  code: "#include <bits/stdc++.h>\n\nstruct DSU {\n\tstd::vector<int> e;\n\n\tvoid\
    \ init(int n) {\n\t\te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\
    \t\treturn e[x] < 0 ? x : e[x] = get(e[x]);\n\t}\n\n\tbool same_set(int a, int\
    \ b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\
    \t}\n\n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\tif (x ==\
    \ y) return false;\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\t\te[x] += e[y]; e[y]\
    \ = x;\n\t\treturn true;\n\t}\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu.cpp
- /library/library/graphs/dsu.cpp.html
title: library/graphs/dsu.cpp
---
