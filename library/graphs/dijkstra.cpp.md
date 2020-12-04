---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/graphs/dijkstra.cpp\"\n#include<bits/stdc++.h>\n\
    template <class C, bool directed> struct Dijkstra {\n    int SZ; std::vector<C>\
    \ dist;\n    std::vector<std::vector<std::pair<int, C>>> adj;\n    void init(int\
    \ _SZ) {\n        SZ = _SZ;\n        adj.clear();\n        adj.resize(SZ);\n \
    \   }\n    void ae(int u, int v, C cost) {\n        adj[u].emplace_back(v, cost);\n\
    \        if (!directed) adj[v].emplace_back(u, cost);\n    }\n    void gen(int\
    \ st) {\n        dist = std::vector<C>(SZ, std::numeric_limits<C>::max());\n \
    \       typedef std::pair<C, int> T;\n        std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> pq;\n        auto ad = [&](int a, C b) {\n            if (dist[a]\
    \ <= b) return;\n            pq.push({dist[a] = b, a});\n        };\n        ad(st,\
    \ 0);\n        while (!pq.empty()) {\n            auto x = pq.top();\n       \
    \     pq.pop();\n            if (dist[x.second] < x.first) continue;\n       \
    \     for (auto& y: adj[x.second]) {\n                ad(y.first, x.first + y.second);\n\
    \            }\n        }\n    }\n};\nint main() {\n    return 0;\n}\n"
  code: "#include<bits/stdc++.h>\ntemplate <class C, bool directed> struct Dijkstra\
    \ {\n    int SZ; std::vector<C> dist;\n    std::vector<std::vector<std::pair<int,\
    \ C>>> adj;\n    void init(int _SZ) {\n        SZ = _SZ;\n        adj.clear();\n\
    \        adj.resize(SZ);\n    }\n    void ae(int u, int v, C cost) {\n       \
    \ adj[u].emplace_back(v, cost);\n        if (!directed) adj[v].emplace_back(u,\
    \ cost);\n    }\n    void gen(int st) {\n        dist = std::vector<C>(SZ, std::numeric_limits<C>::max());\n\
    \        typedef std::pair<C, int> T;\n        std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> pq;\n        auto ad = [&](int a, C b) {\n            if (dist[a]\
    \ <= b) return;\n            pq.push({dist[a] = b, a});\n        };\n        ad(st,\
    \ 0);\n        while (!pq.empty()) {\n            auto x = pq.top();\n       \
    \     pq.pop();\n            if (dist[x.second] < x.first) continue;\n       \
    \     for (auto& y: adj[x.second]) {\n                ad(y.first, x.first + y.second);\n\
    \            }\n        }\n    }\n};\nint main() {\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/graphs/dijkstra.cpp
  requiredBy: []
  timestamp: '2020-12-04 02:43:09-05:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graphs/dijkstra.cpp
layout: document
redirect_from:
- /library/library/graphs/dijkstra.cpp
- /library/library/graphs/dijkstra.cpp.html
title: library/graphs/dijkstra.cpp
---
