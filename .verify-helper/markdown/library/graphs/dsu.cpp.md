---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dsu.cpp\"\n#include<bits/stdc++.h>\r\n\r\n\
    struct DSU {\r\n    std::vector<int> e;\r\n    void init(int n) {\r\n        e\
    \ = std::vector<int>(n, -1);\r\n    }\r\n    int get(int x) {\r\n        return\
    \ e[x] < 0 ? x : e[x] = get(e[x]);\r\n    }\r\n    bool same_set(int a, int b)\
    \ {\r\n        return get(a) == get(b);\r\n    }\r\n    int size(int x) {\r\n\
    \        return -e[get(x)];\r\n    }\r\n    bool unite(int x, int y) {\r\n   \
    \     x = get(x), y = get(y);\r\n        if (x == y) return false;\r\n       \
    \ if (e[x] > e[y]) std::swap(x, y);\r\n        e[x] += e[y]; e[y] = x;\r\n   \
    \     return true;\r\n    }\r\n};\r\nint main() {\r\n    return 0;\r\n}\r\n"
  code: "#include<bits/stdc++.h>\r\n\r\nstruct DSU {\r\n    std::vector<int> e;\r\n\
    \    void init(int n) {\r\n        e = std::vector<int>(n, -1);\r\n    }\r\n \
    \   int get(int x) {\r\n        return e[x] < 0 ? x : e[x] = get(e[x]);\r\n  \
    \  }\r\n    bool same_set(int a, int b) {\r\n        return get(a) == get(b);\r\
    \n    }\r\n    int size(int x) {\r\n        return -e[get(x)];\r\n    }\r\n  \
    \  bool unite(int x, int y) {\r\n        x = get(x), y = get(y);\r\n        if\
    \ (x == y) return false;\r\n        if (e[x] > e[y]) std::swap(x, y);\r\n    \
    \    e[x] += e[y]; e[y] = x;\r\n        return true;\r\n    }\r\n};\r\nint main()\
    \ {\r\n    return 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu.cpp
  requiredBy: []
  timestamp: '2020-11-30 17:44:28-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu.cpp
- /library/library/graphs/dsu.cpp.html
title: library/graphs/dsu.cpp
---
