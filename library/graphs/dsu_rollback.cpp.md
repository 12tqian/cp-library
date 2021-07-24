---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dsu_rollback.cpp\"\n#include <bits/stdc++.h>\n\
    \nstruct DSURollBack {\n\tstd::vector<int> e;\n\t\n\tvoid init(int n) {\n\t\t\
    e = std::vector<int>(n, -1);\n\t}\n\n\tint get(int x) {\n\t\treturn e[x] < 0 ?\
    \ x : get(e[x]);\n\t}\n\n\tbool same_set(int a, int b) {\n\t\treturn get(a) ==\
    \ get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\t}\n\n\tstd::vector<std::array<int,\
    \ 4>> mod;\n\t\n\tbool unite(int x, int y) {\n\t\tx = get(x), y = get(y);\n\t\t\
    if (x == y) {\n\t\t\tmod.push_back({-1, -1, -1, -1});\n\t\t\treturn 0;\n\t\t}\n\
    \t\tif (e[x] > e[y]) std::swap(x, y);\n\t\tmod.push_back({x, y, e[x], e[y]});\n\
    \t\te[x] += e[y], e[y] = x;\n\t\treturn true;\n\t}\n\n\tvoid rollback() {\n\t\t\
    auto a = mod.back();\n\t\tmod.pop_back();\n\t\tif (a[0] != -1) {\n\t\t\te[a[0]]\
    \ = a[2];\n\t\t\te[a[1]] = a[3];\n\t\t}\n\t}\n};\n"
  code: "#include <bits/stdc++.h>\n\nstruct DSURollBack {\n\tstd::vector<int> e;\n\
    \t\n\tvoid init(int n) {\n\t\te = std::vector<int>(n, -1);\n\t}\n\n\tint get(int\
    \ x) {\n\t\treturn e[x] < 0 ? x : get(e[x]);\n\t}\n\n\tbool same_set(int a, int\
    \ b) {\n\t\treturn get(a) == get(b);\n\t}\n\n\tint size(int x) {\n\t\treturn -e[get(x)];\n\
    \t}\n\n\tstd::vector<std::array<int, 4>> mod;\n\t\n\tbool unite(int x, int y)\
    \ {\n\t\tx = get(x), y = get(y);\n\t\tif (x == y) {\n\t\t\tmod.push_back({-1,\
    \ -1, -1, -1});\n\t\t\treturn 0;\n\t\t}\n\t\tif (e[x] > e[y]) std::swap(x, y);\n\
    \t\tmod.push_back({x, y, e[x], e[y]});\n\t\te[x] += e[y], e[y] = x;\n\t\treturn\
    \ true;\n\t}\n\n\tvoid rollback() {\n\t\tauto a = mod.back();\n\t\tmod.pop_back();\n\
    \t\tif (a[0] != -1) {\n\t\t\te[a[0]] = a[2];\n\t\t\te[a[1]] = a[3];\n\t\t}\n\t\
    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu_rollback.cpp
  requiredBy: []
  timestamp: '2021-07-24 17:17:14-04:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu_rollback.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu_rollback.cpp
- /library/library/graphs/dsu_rollback.cpp.html
title: library/graphs/dsu_rollback.cpp
---
