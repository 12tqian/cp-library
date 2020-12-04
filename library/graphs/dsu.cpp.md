---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dsu.cpp\"\n#include<bits/stdc++.h>\n\nstruct\
    \ DSU {\n    std::vector<int> e;\n    void init(int n) {\n        e = std::vector<int>(n,\
    \ -1);\n    }\n    int get(int x) {\n        return e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \    }\n    bool same_set(int a, int b) {\n        return get(a) == get(b);\n\
    \    }\n    int size(int x) {\n        return -e[get(x)];\n    }\n    bool unite(int\
    \ x, int y) {\n        x = get(x), y = get(y);\n        if (x == y) return false;\n\
    \        if (e[x] > e[y]) std::swap(x, y);\n        e[x] += e[y]; e[y] = x;\n\
    \        return true;\n    }\n};\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\n\nstruct DSU {\n    std::vector<int> e;\n    void\
    \ init(int n) {\n        e = std::vector<int>(n, -1);\n    }\n    int get(int\
    \ x) {\n        return e[x] < 0 ? x : e[x] = get(e[x]);\n    }\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n    int size(int x) {\n\
    \        return -e[get(x)];\n    }\n    bool unite(int x, int y) {\n        x\
    \ = get(x), y = get(y);\n        if (x == y) return false;\n        if (e[x] >\
    \ e[y]) std::swap(x, y);\n        e[x] += e[y]; e[y] = x;\n        return true;\n\
    \    }\n};\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dsu.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dsu.cpp
layout: document
redirect_from:
- /library/library/graphs/dsu.cpp
- /library/library/graphs/dsu.cpp.html
title: library/graphs/dsu.cpp
---
