---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dsu_rollback.cpp\"\n/**\n* Untested still\n\
    */\n\n#include <bits/stdc++.h>\n\nstruct DSURollback {\n    std::vector<int> e;\n\
    \    void init(int n) { e = std::vector<int>(n, -1); }\n    int get(int x) { return\
    \ e[x] < 0 ? x : get(e[x]); }\n    bool same_set(int a, int b) {return get(a)\
    \ == get(b); }\n    int size(int x) { return -e[get(x)]; }\n    std::vector<std::array<int,\
    \ 4>> modify;\n    bool unite(int x, int y) {\n        x = get(x), y = get(y);\n\
    \        if (x == y) {\n            modify.push_back({-1, -1, -1, -1});\n    \
    \        return false;\n        }\n        if (e[x] > e[y]) std::swap(x, y);\n\
    \        modify.push_back({x, y, e[x], e[y]});\n        e[x] == e[y], e[y] = x;\n\
    \        return true;\n    }\n    void rollback() {\n        auto a = modify.back();\n\
    \        modify.pop_back();\n        if (a[0] != -1) \n            e[a[0]] = a[2],\
    \ e[a[1]] = a[3];\n    }\n};\n\n"
  code: "/**\n* Untested still\n*/\n\n#include <bits/stdc++.h>\n\nstruct DSURollback\
    \ {\n    std::vector<int> e;\n    void init(int n) { e = std::vector<int>(n, -1);\
    \ }\n    int get(int x) { return e[x] < 0 ? x : get(e[x]); }\n    bool same_set(int\
    \ a, int b) {return get(a) == get(b); }\n    int size(int x) { return -e[get(x)];\
    \ }\n    std::vector<std::array<int, 4>> modify;\n    bool unite(int x, int y)\
    \ {\n        x = get(x), y = get(y);\n        if (x == y) {\n            modify.push_back({-1,\
    \ -1, -1, -1});\n            return false;\n        }\n        if (e[x] > e[y])\
    \ std::swap(x, y);\n        modify.push_back({x, y, e[x], e[y]});\n        e[x]\
    \ == e[y], e[y] = x;\n        return true;\n    }\n    void rollback() {\n   \
    \     auto a = modify.back();\n        modify.pop_back();\n        if (a[0] !=\
    \ -1) \n            e[a[0]] = a[2], e[a[1]] = a[3];\n    }\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu_rollback.cpp
  requiredBy: []
  timestamp: '2020-12-14 17:44:59-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu_rollback.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu_rollback.cpp
- /library/library/graphs/dsu_rollback.cpp.html
title: library/graphs/dsu_rollback.cpp
---
