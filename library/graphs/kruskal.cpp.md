---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/kruskal.cpp\"\n#include <bits/stdc++.h>\n\
    struct DSU {\n    std::vector<int> e;\n    void init(int n) {\n        e = std::vector<int>(n,\
    \ -1);\n    }\n    int get(int x) {\n        return e[x] < 0 ? x : e[x] = get(e[x]);\n\
    \    }\n    bool same_set(int a, int b) {\n        return get(a) == get(b);\n\
    \    }\n    int size(int x) {\n        return -e[get(x)];\n    }\n    bool unite(int\
    \ x, int y) {\n        x = get(x), y = get(y);\n        if (x == y) return false;\n\
    \        if (e[x] > e[y]) std::swap(x, y);\n        e[x] += e[y]; e[y] = x;\n\
    \        return true;\n    }\n};\n\n//weight, start, end\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\n    DSU D;\n    int n = 0;\n    for (auto a : edge) {\n       \
    \ n = std::max(n, a[1]);\n        n = std::max(n, a[2]);\n    }\n    ++n;\n  \
    \  D.init(n);\n    sort(edge.begin(), edge.end());\n    long long ans = 0;\n \
    \   for (auto a : edge) {\n        if (D.unite(a[1], a[2])) {\n            ans\
    \ += a[0];\n        }\n    }\n    return ans;\n}\n\nint main() {\n    return 0;\n\
    }\n\n"
  code: "#include <bits/stdc++.h>\nstruct DSU {\n    std::vector<int> e;\n    void\
    \ init(int n) {\n        e = std::vector<int>(n, -1);\n    }\n    int get(int\
    \ x) {\n        return e[x] < 0 ? x : e[x] = get(e[x]);\n    }\n    bool same_set(int\
    \ a, int b) {\n        return get(a) == get(b);\n    }\n    int size(int x) {\n\
    \        return -e[get(x)];\n    }\n    bool unite(int x, int y) {\n        x\
    \ = get(x), y = get(y);\n        if (x == y) return false;\n        if (e[x] >\
    \ e[y]) std::swap(x, y);\n        e[x] += e[y]; e[y] = x;\n        return true;\n\
    \    }\n};\n\n//weight, start, end\nlong long kruskal(std::vector<std::array<int,\
    \ 3>> edge) {\n    DSU D;\n    int n = 0;\n    for (auto a : edge) {\n       \
    \ n = std::max(n, a[1]);\n        n = std::max(n, a[2]);\n    }\n    ++n;\n  \
    \  D.init(n);\n    sort(edge.begin(), edge.end());\n    long long ans = 0;\n \
    \   for (auto a : edge) {\n        if (D.unite(a[1], a[2])) {\n            ans\
    \ += a[0];\n        }\n    }\n    return ans;\n}\n\nint main() {\n    return 0;\n\
    }\n\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/kruskal.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/kruskal.cpp
layout: document
redirect_from:
- /library/library/graphs/kruskal.cpp
- /library/library/graphs/kruskal.cpp.html
title: library/graphs/kruskal.cpp
---
