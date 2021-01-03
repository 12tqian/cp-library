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
    \nstruct DSURollBack {\n    std::vector<int> e;\n    void init(int n) {\n    \
    \    e = std::vector<int>(n, -1);\n    }\n    int get(int x) {\n        return\
    \ e[x] < 0 ? x : get(e[x]);\n    }\n    bool same_set(int a, int b) {\n      \
    \  return get(a) == get(b);\n    }\n    int size(int x) {\n        return -e[get(x)];\n\
    \    }\n    std::vector<std::array<int, 4>> mod;\n    bool unite(int x, int y)\
    \ {\n        x = get(x), y = get(y);\n        if (x == y) {\n            mod.push_back({-1,\
    \ -1, -1, -1});\n            return 0;\n        }\n        if (e[x] > e[y]) std::swap(x,\
    \ y);\n        mod.push_back({x, y, e[x], e[y]});\n        e[x] += e[y], e[y]\
    \ = x;\n        return true;\n    }\n    void rollback() {\n        auto a = mod.back();\n\
    \        mod.pop_back();\n        if (a[0] != -1) {\n            e[a[0]] = a[2];\n\
    \            e[a[1]] = a[3];\n        }\n    }\n};\n\nint main() {\n    return\
    \ 0;\n}\n"
  code: "#include <bits/stdc++.h>\n\nstruct DSURollBack {\n    std::vector<int> e;\n\
    \    void init(int n) {\n        e = std::vector<int>(n, -1);\n    }\n    int\
    \ get(int x) {\n        return e[x] < 0 ? x : get(e[x]);\n    }\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n    int size(int x) {\n\
    \        return -e[get(x)];\n    }\n    std::vector<std::array<int, 4>> mod;\n\
    \    bool unite(int x, int y) {\n        x = get(x), y = get(y);\n        if (x\
    \ == y) {\n            mod.push_back({-1, -1, -1, -1});\n            return 0;\n\
    \        }\n        if (e[x] > e[y]) std::swap(x, y);\n        mod.push_back({x,\
    \ y, e[x], e[y]});\n        e[x] += e[y], e[y] = x;\n        return true;\n  \
    \  }\n    void rollback() {\n        auto a = mod.back();\n        mod.pop_back();\n\
    \        if (a[0] != -1) {\n            e[a[0]] = a[2];\n            e[a[1]] =\
    \ a[3];\n        }\n    }\n};\n\nint main() {\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu_rollback.cpp
  requiredBy: []
  timestamp: '2021-01-03 15:14:07-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu_rollback.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu_rollback.cpp
- /library/library/graphs/dsu_rollback.cpp.html
title: library/graphs/dsu_rollback.cpp
---
