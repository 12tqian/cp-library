---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/graphs/offline-dynamic-connectivity.hpp
    title: library/graphs/offline-dynamic-connectivity.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/spoj/spoj-DYNACON2.test.cpp
    title: verify/spoj/spoj-DYNACON2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "\r\nstruct DSURollBack {\r\n\tstd::vector<int> e;\r\n\t\r\n\tvoid\
    \ init(int n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint get(int\
    \ x) {\r\n\t\treturn e[x] < 0 ? x : get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int\
    \ a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x)\
    \ {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tstd::vector<std::array<int, 4>>\
    \ mod;\r\n\t\r\n\tbool unite(int x, int y) {\r\n\t\tx = get(x), y = get(y);\r\n\
    \t\tif (x == y) {\r\n\t\t\tmod.push_back({-1, -1, -1, -1});\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\tmod.push_back({x, y, e[x],\
    \ e[y]});\r\n\t\te[x] += e[y], e[y] = x;\r\n\t\treturn true;\r\n\t}\r\n\r\n\t\
    void rollback() {\r\n\t\tauto a = mod.back();\r\n\t\tmod.pop_back();\r\n\t\tif\
    \ (a[0] != -1) {\r\n\t\t\te[a[0]] = a[2];\r\n\t\t\te[a[1]] = a[3];\r\n\t\t}\r\n\
    \t}\r\n};\r\n"
  code: "#pragma once\r\n\r\nstruct DSURollBack {\r\n\tstd::vector<int> e;\r\n\t\r\
    \n\tvoid init(int n) {\r\n\t\te = std::vector<int>(n, -1);\r\n\t}\r\n\r\n\tint\
    \ get(int x) {\r\n\t\treturn e[x] < 0 ? x : get(e[x]);\r\n\t}\r\n\r\n\tbool same_set(int\
    \ a, int b) {\r\n\t\treturn get(a) == get(b);\r\n\t}\r\n\r\n\tint size(int x)\
    \ {\r\n\t\treturn -e[get(x)];\r\n\t}\r\n\r\n\tstd::vector<std::array<int, 4>>\
    \ mod;\r\n\t\r\n\tbool unite(int x, int y) {\r\n\t\tx = get(x), y = get(y);\r\n\
    \t\tif (x == y) {\r\n\t\t\tmod.push_back({-1, -1, -1, -1});\r\n\t\t\treturn 0;\r\
    \n\t\t}\r\n\t\tif (e[x] > e[y]) std::swap(x, y);\r\n\t\tmod.push_back({x, y, e[x],\
    \ e[y]});\r\n\t\te[x] += e[y], e[y] = x;\r\n\t\treturn true;\r\n\t}\r\n\r\n\t\
    void rollback() {\r\n\t\tauto a = mod.back();\r\n\t\tmod.pop_back();\r\n\t\tif\
    \ (a[0] != -1) {\r\n\t\t\te[a[0]] = a[2];\r\n\t\t\te[a[1]] = a[3];\r\n\t\t}\r\n\
    \t}\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu-rollback.hpp
  requiredBy:
  - library/graphs/offline-dynamic-connectivity.hpp
  timestamp: '2022-07-21 16:12:33-04:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/spoj/spoj-DYNACON2.test.cpp
documentation_of: library/graphs/dsu-rollback.hpp
layout: document
redirect_from:
- /library/library/graphs/dsu-rollback.hpp
- /library/library/graphs/dsu-rollback.hpp.html
title: library/graphs/dsu-rollback.hpp
---
