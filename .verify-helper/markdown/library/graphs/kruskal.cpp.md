---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library\\\\graphs\\\\kruskal.cpp\"\n#include <bits/stdc++.h>\r\
    \nstruct DSU {\r\n    std::vector<int> e;\r\n    void init(int n) {\r\n      \
    \  e = std::vector<int>(n, -1);\r\n    }\r\n    int get(int x) {\r\n        return\
    \ e[x] < 0 ? x : e[x] = get(e[x]);\r\n    }\r\n    bool same_set(int a, int b)\
    \ {\r\n        return get(a) == get(b);\r\n    }\r\n    int size(int x) {\r\n\
    \        return -e[get(x)];\r\n    }\r\n    bool unite(int x, int y) {\r\n   \
    \     x = get(x), y = get(y);\r\n        if (x == y) return false;\r\n       \
    \ if (e[x] > e[y]) std::swap(x, y);\r\n        e[x] += e[y]; e[y] = x;\r\n   \
    \     return true;\r\n    }\r\n};\r\n\r\n//weight, start, end\r\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\r\n    DSU D;\r\n    int n = 0;\r\n    for (auto a : edge) {\r\n\
    \        n = std::max(n, a[1]);\r\n        n = std::max(n, a[2]);\r\n    }\r\n\
    \    ++n;\r\n    D.init(n);\r\n    sort(edge.begin(), edge.end());\r\n    long\
    \ long ans = 0;\r\n    for (auto a : edge) {\r\n        if (D.unite(a[1], a[2]))\
    \ {\r\n            ans += a[0];\r\n        }\r\n    }\r\n    return ans;\r\n}\r\
    \n\r\nint main() {\r\n    return 0;\r\n}\r\n\r\n"
  code: "#include <bits/stdc++.h>\r\nstruct DSU {\r\n    std::vector<int> e;\r\n \
    \   void init(int n) {\r\n        e = std::vector<int>(n, -1);\r\n    }\r\n  \
    \  int get(int x) {\r\n        return e[x] < 0 ? x : e[x] = get(e[x]);\r\n   \
    \ }\r\n    bool same_set(int a, int b) {\r\n        return get(a) == get(b);\r\
    \n    }\r\n    int size(int x) {\r\n        return -e[get(x)];\r\n    }\r\n  \
    \  bool unite(int x, int y) {\r\n        x = get(x), y = get(y);\r\n        if\
    \ (x == y) return false;\r\n        if (e[x] > e[y]) std::swap(x, y);\r\n    \
    \    e[x] += e[y]; e[y] = x;\r\n        return true;\r\n    }\r\n};\r\n\r\n//weight,\
    \ start, end\r\nlong long kruskal(std::vector<std::array<int, 3>> edge) {\r\n\
    \    DSU D;\r\n    int n = 0;\r\n    for (auto a : edge) {\r\n        n = std::max(n,\
    \ a[1]);\r\n        n = std::max(n, a[2]);\r\n    }\r\n    ++n;\r\n    D.init(n);\r\
    \n    sort(edge.begin(), edge.end());\r\n    long long ans = 0;\r\n    for (auto\
    \ a : edge) {\r\n        if (D.unite(a[1], a[2])) {\r\n            ans += a[0];\r\
    \n        }\r\n    }\r\n    return ans;\r\n}\r\n\r\nint main() {\r\n    return\
    \ 0;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library\graphs\kruskal.cpp
  requiredBy: []
  timestamp: '2020-11-24 21:14:14-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library\graphs\kruskal.cpp
layout: document
redirect_from:
- /library\library\graphs\kruskal.cpp
- /library\library\graphs\kruskal.cpp.html
title: library\graphs\kruskal.cpp
---
